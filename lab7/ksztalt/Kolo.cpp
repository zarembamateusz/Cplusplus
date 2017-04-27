//
// Created by Mateusz on 23.04.2017.
//

#include <iostream>
#include "Kolo.h"

namespace ksztalty {
    void Kolo::rysuj() const {
        std::cout << "- - + - -" << std::endl;
        std::cout << "- + - + -" << std::endl;
        std::cout << "+ - - - +" << std::endl;
        std::cout << "- + - + -" << std::endl;
        std::cout << "- - + - -" << std::endl;

    }
}