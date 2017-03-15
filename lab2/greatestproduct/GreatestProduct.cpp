//
// Created by Mateusz on 13.03.2017.
//

#include "GreatestProduct.h"
#include <vector>
#include <iostream>
#include <cmath>

int GreatestProduct(const std::vector<int> &numbers, int k){
    std::vector<int> another_vector={};
    std::vector<int> another_vector2={};
    int licznik_petli=0;
    int zmienna_sterujaca=0;
    int suma= 1;
    int licznik=1;
    int licznik2=1;
    int kopia_k=k;
    int check1=0,check2=0;

    for (int v : numbers){
        if(v>=0){
            zmienna_sterujaca = 0;
            if (another_vector.size() == 0) {
                another_vector.push_back(v);
            } else {
                licznik_petli = 0;
                for (int w : another_vector) {
                    licznik_petli++;
                    if (zmienna_sterujaca == 0) {
                        if (v > w){
                            zmienna_sterujaca = 1;
                            another_vector.insert(another_vector.begin() +  licznik_petli -1, v);
                        }
                    }
                }
                if (zmienna_sterujaca == 0) {
                    another_vector.push_back(v);
                    zmienna_sterujaca = 2;
                }
            }
        }
        else {
            zmienna_sterujaca = 0;
            if (another_vector2.size() == 0) {
                another_vector2.push_back(v);
            } else {
                licznik_petli = 0;
                for (int w : another_vector2) {
                    licznik_petli++;
                    if (zmienna_sterujaca == 0) {
                        if (labs(v) > labs(w)){
                            zmienna_sterujaca = 1;
                            another_vector2.insert(another_vector2.begin() +  licznik_petli-1, v);
                        }
                    }
                }
                if (zmienna_sterujaca == 0) {
                    another_vector2.push_back(v);
                    zmienna_sterujaca = 2;
                }
            }
        }
    }

    while(k>0) {
        check1=0;
        check2=0;
        if(k>1) {
            if (another_vector.size() >= licznik+1)
                check1 = sumuj(another_vector, licznik,licznik+1);
            if (another_vector2.size() >= licznik+1)
                check2 = sumuj(another_vector2, licznik2,licznik2+1);
            if (check1 > check2) {
                suma *= check1;
                licznik+=2;
            }
            else{
                suma *= check2;
                licznik2+=2;
            }
            k-=2;
        }
        else{
            if (another_vector.size() >= licznik)
                check1 = sumuj(another_vector, licznik,licznik);
            if (another_vector2.size() >= licznik)
                check2 = sumuj(another_vector2, licznik2,licznik2);
            if (check1 > check2) {
                suma *= check1;
                licznik+=1;
            }
            else {
                suma *= check2;
                licznik+=1;
            }
            k-=1;
        }
    }

    if((another_vector.size()==0)&&(kopia_k%2!=0)){
        suma=1;
        suma=sumuj(another_vector2,another_vector2.size()-kopia_k+1,another_vector2.size());

    }
    return suma;
}

int sumuj(const std::vector<int> &value, int from,int to){
    int s=1;
    int wynik=1;
    for (int q : value) {
        if ((from<=s)&&(s<= to)){
            wynik*=q;
        }
        s++;


    }
    return wynik;
}