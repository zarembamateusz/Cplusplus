//
// Created by Mateusz on 06.03.2017.
//

#include "Palindrome.h"
#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(std::string str){

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