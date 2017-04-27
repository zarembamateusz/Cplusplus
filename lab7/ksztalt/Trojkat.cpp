//
// Created by Mateusz on 23.04.2017.
//

#include <iostream>
#include "Trojkat.h"
namespace ksztalty {
    void Trojkat::rysuj() const {
        std::cout << "- - + - -" << std::endl;
        std::cout << "- + + + -" << std::endl;
        std::cout << "+ + + + +" << std::endl;
    }
}
