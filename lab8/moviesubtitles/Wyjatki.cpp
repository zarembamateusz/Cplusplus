//
// Created by Mateusz on 04.05.2017.
//

#include "Wyjatki.h"

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(int *e): e_(0){
    e_=*e;
}

int const moviesubs::SubtitleEndBeforeStart::LineAt() {
    return e_;
}
