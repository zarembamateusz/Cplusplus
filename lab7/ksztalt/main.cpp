//
// Created by Mateusz on 23.04.2017.
//
#include <list>
#include <iostream>
#include "Kolo.h"
#include "Kula.h"
#include "Trojkat.h"
#include "Ksztalt.h"
using namespace ksztalty;
int main(){
    Kula nowa;
    nowa.rysuj();
    std::list<Ksztalt*> lista_ksztaltow;
    lista_ksztaltow.emplace_back(new Kula);
    lista_ksztaltow.emplace_back(new Kolo);
    lista_ksztaltow.emplace_back(new Trojkat);
    lista_ksztaltow.emplace_back(new Kula);
    lista_ksztaltow.emplace_back(new Kolo);
    lista_ksztaltow.emplace_back(new Trojkat);
    for(auto v: lista_ksztaltow){
        v->rysuj();
        std::cout<<"\n";
    }
    return 0;
}

// program ten bediz rysował odpowiedznie kształty na ekranie zgodnie z kolejnym elemantem
// funkcja rysuje jest nadpisana w kazdej figurze wiec gdy sie wywołuje to wywoływane jest
// odpowiedznie dla niej nadpisanie