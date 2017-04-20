//
// Created by Mateusz on 12.04.2017.
//
#include "WordCounter.h"
using namespace datastructures;
int main(){
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};

    std::cout<<counter.TotalWords();
    std::cout<<counter.DistinctWords();




    return 0;
}
