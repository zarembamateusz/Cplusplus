//
// Created by Mateusz on 02.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H
#include <complex.h>;
#include <string>;
#include <iostream>;
#include <math.h>
#include <vector>


namespace algebra{


    //using std::cout;
    //using std::endl;

    std::complex<double> **alokuj(int rozmiar1, int rozmiar2);

    class Matrix {
    public:
        Matrix();
        //1. konstruktor kopiujący
        //Matrix(const Matrix &other_matrix);


        Matrix(const int &fir,const int &sec);
        Matrix(const std::string &str);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);
        ~Matrix();

        Matrix Add(const Matrix &m2) const;
        Matrix Sub(const Matrix &m2) const;
        Matrix Mul(const Matrix &m2) const;
        //Matrix Sub(Matrix mac) const;
        std::pair<size_t,size_t >Size();
        //Matrix Mul(Matrix mac);
        Matrix Div(Matrix mac);
        Matrix Pow(int n);
        std::string Print()const;
        int roz1,roz2;
    private:
        std::string nowy;

        std::string tmp;
        std::string tmp2;
        std::complex<double> **tab=alokuj(roz1,roz2);


    };
}


#endif //JIMP_EXERCISES_MATRIX_H
