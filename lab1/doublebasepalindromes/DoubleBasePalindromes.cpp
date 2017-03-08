//
// Created by Mateusz on 07.03.2017.
//

#include "DoubleBasePalindromes.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
bool is_palindrome(std::string str);
bool convert(int value);

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {

     long int tmp;
    uint64_t suma=0;

    if(max_vaule_exculsive<1 || max_vaule_exculsive>10000000){
        suma=0;}
    else {
        for (long int i = 1; i <= max_vaule_exculsive; i++) {
                std::string tmp;
                sprintf((char *) tmp.c_str(), "%d", i);
                std::string str = tmp.c_str();
                if (is_palindrome(str)) {
                    if (convert(i)) {
                        suma = suma + i;
                    }
                }
        }
    }
    return suma;
}
bool is_palindrome(std::string str) {

    size_t size = str.size();
    std::string nowy;
    for(size_t i = 0; i < size; ++i){
        nowy += str[size-i-1];
    }
    if(str==nowy){
        return true;
    }
    else{
        return false;
    }

}

bool convert(int value){
    std::string wynik;
    while(value) {
        if (value % 2) {
            wynik = "1" + wynik;
        } else {
            wynik = "0" + wynik;
        }
        value /= 2;
    }
    if(is_palindrome(wynik)){
        return true;
    }
    else if(!is_palindrome(wynik)) {
        return false;
    }
}