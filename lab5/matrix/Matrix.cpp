//
// Created by Mateusz on 02.04.2017.
//

#include <string>
#include <cstring>
#include "Matrix.h"


namespace algebra {
    std::complex<double> **alokuj(int rozmiar1, int rozmiar2) {
        std::complex<double> **tablica;
        tablica = new std::complex<double> *[rozmiar1];
        for (int i = 0; i < rozmiar1; i++) {
            tablica[i] = new std::complex<double>[rozmiar2];
        }
        return (tablica);
    }

    Matrix::Matrix() : roz1(3), roz2(3) {

    }

    Matrix::Matrix(const int &fir, const int &sec) : roz1(fir), roz2(sec) {

    }

    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements): roz1((int)elements.size()),roz2((int)elements.begin()->size()){

        int k=0,w=0;
        for(auto v:elements) {
            for (int i = 0; i < v.size(); i++) {
                tab[k][w]=v.at(i);
                w++;
            }
            k++;
            w=0;
        }
    }

    Matrix::Matrix(const std::string &str) : roz1(3), roz2(3) {

        nowy = str;
        tmp += '\"';
        tmp += "[";
        int i = 0;
        int zes = 0;
        while (i < nowy.length()) {
            int k = i;
            int zes = 0;
            int img = 0;
            tmp2 = "";
            while (nowy[i] != ',' && nowy[i] != '}' && nowy[i] != '{') {

                if (nowy[i] == 'i') {
                    img = 1;
                }
                if (nowy[i] == ' ') {

                } else if (nowy[i] == '+') {
                    tmp2 += ":";
                    zes = 1;
                } else {
                    tmp2 += nowy[i];
                }
                i++;
            }

            int j = 0;
            while (j < tmp2.length()) {
                if (tmp2 == "0.") {
                    tmp += "0i0";
                    j = tmp2.length();
                } else {
                    if (zes == 1) {
                        if (tmp2[j] == '.') {
                            j++;
                        } else if (tmp2[j] != ':') {
                            tmp += tmp2[j];
                            j++;
                        } else if (tmp2[j] == ':') {
                            tmp += 'i';
                            j++;
                            while (tmp2[j] != '.' && tmp2[j] != 'i') {
                                tmp += tmp2[j];
                                j++;
                            }
                            j = tmp2.length();
                        }
                    } else {
                        if (img == 1) {
                            tmp += "0i";
                            while (tmp2[j] != '.') {
                                tmp += tmp2[j];
                                j++;
                            }
                            j = tmp2.length();
                        } else {
                            while (tmp2[j] != '.') {
                                tmp += tmp2[j];
                                j++;
                            }
                            tmp += "i0";
                            j = tmp2.length();

                        }
                    }
                }

            }
            if (nowy[i] == '}') {
                tmp += ";";
                if (i != nowy.length() - 1)
                    tmp += " ";
            } else if (nowy[i] == ',' && tmp2.length() > 0) {
                tmp += ",";
                tmp += ' ';
            }
            i++;
        }
        tmp += "]";
        tmp += '\"';
        int k = 0, w = 0;
        i = 2;
        std::string liczba_;

        while (i < tmp.length() - 1) {
            int real = 0;
            int img = 0;
            liczba_ = "";
            while (tmp[i] != 'i') {
                liczba_ += tmp[i];
                i++;
            }
            i++;

            std::istringstream ss(liczba_);
            ss >> real;

            liczba_ = "";
            while (tmp[i] != ',' && tmp[i] != ';') {
                liczba_ += tmp[i];
                i++;
            }

            std::istringstream ii(liczba_);
            ii >> img;

            std::complex<double> one(real, img);
            tab[k][w] = one;

            w++;
            if (tmp[i] == ';') {
                k++;
                w = 0;
            }
            i += 2;

        }
    }
    Matrix::~Matrix(){
        for (int i = 0; i < roz1; i++)
            delete[] tab[i];
        delete[] tab;
    }

    std::pair<size_t ,size_t > Matrix::Size(){
        std::pair<size_t ,size_t >one;
        one.first=roz1;
        one.second=roz2;
        return one;
    }
    Matrix Matrix::Add(const Matrix &m2) const
    {
        Matrix m3(roz1,roz2);
        for (int i = 0; i < roz1; i++) {
            for (int j = 0; j < roz2; j++) {
                m3.tab[i][j] = tab[i][j]+ m2.tab[i][j];
            }
        }
        return m3;
    }
    Matrix Matrix::Sub(const Matrix &m2) const {
        Matrix m3(roz1,roz2);

        for (int i = 0; i < roz1; i++) {
            for (int j = 0; j < roz2; j++) {
                m3.tab[i][j] = tab[i][j] - m2.tab[i][j];
            }
        }
        return m3;
    }

    Matrix Matrix::Mul(const Matrix &m2) const{
        Matrix m3(roz1,m2.roz2);
        if(roz2!=m2.roz1){
            for (int i = 0; i < m3.roz1; i++)
                delete[] m3.tab[i];
            delete[] m3.tab;
            m3.roz1=0;
            m3.roz2=0;
            **m3.tab=**alokuj(m3.roz1,m3.roz2);

        } else {
            for (int i = 0; i < roz1; i++) {
                for (int j = 0; j < m2.roz2; j++) {
                    std::complex<double> one (0,0);
                    m3.tab[i][j] = one;
                    for (int k = 0; k < roz2; k++) {
                        m3.tab[i][j] = m3.tab[i][j] + tab[i][k] * m2.tab[k][j];
                    }
                }
            }
        }
        return m3;
    }

    Matrix Matrix::Pow(int n) {
        Matrix m3(roz1,roz2);
        if(roz2!=roz1){
            for (int i = 0; i < m3.roz1; i++)
                delete[] m3.tab[i];
            delete[] m3.tab;
            m3.roz1=0;
            m3.roz2=0;
            **m3.tab=**alokuj(m3.roz1,m3.roz2);
        } else {
            Matrix m4(roz1,roz2);
            Matrix m5(roz1,roz2);
            if(n>0) {
                int l=1;
                while(l<=n) {
                    if(l==1){
                        for (int i = 0; i < roz1; i++){
                            for (int j = 0; j < roz2; j++) {
                                m5.tab[i][j]=tab[i][j];
                                m3.tab[i][j]=tab[i][j];
                            }
                        }
                    }else {
                        for(int i = 0; i < m3.roz1; i++){
                            for (int j = 0; j < m3.roz2; j++) {
                                std::complex<double> one(0, 0);
                                m4.tab[i][j] = one;
                                for (int k = 0; k < m3.roz2; k++) {
                                    m4.tab[i][j] = m4.tab[i][j] + m3.tab[i][k] * m5.tab[k][j];
                                }
                            }
                        }
                        for (int i = 0; i < m4.roz1; i++) {
                            for (int j = 0; j < m4.roz2; j++){
                                m3.tab[i][j]=m4.tab[i][j];

                            }
                        }
                    }
                    l++;
                }
            }else if(n==0){
                std::complex<double> one(0, 0);
                std::complex<double> sec(1, 0);
                for (int i = 0; i < roz1; i++) {
                    for (int j = 0; j < roz2; j++) {
                        if(i==j) {
                            m3.tab[i][j] = sec;
                        }
                        else{
                            m3.tab[i][j] = one;
                        }
                    }
                }
            }
        }
        return m3;
    }

    std::string Matrix::Print()const {
        std::string printowany="[";
        std::string printowany2;

        for (int g = 0; g < roz1; g++) {
            for (int h = 0; h < roz2; h++) {
                std::stringstream strumien;
                strumien << tab[g][h].real();
                strumien << "i";
                strumien << tab[g][h].imag();
                if (h < roz2 - 1) {
                    strumien << ",";
                } else {
                    if(g == roz1 - 1 && h == roz2- 1){
                    } else
                        strumien << ";";
                }
                strumien >> printowany2;

                if (g == roz1 - 1 && h == roz2 - 1) {

                } else
                    printowany2 += " ";
                printowany += printowany2;
            }
        }
        printowany+="]";
        return printowany;
    }
}