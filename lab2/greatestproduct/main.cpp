//
// Created by Mateusz on 13.03.2017.
//
#include "GreatestProduct.h"
#include <vector>
#include <iostream>
#include <fstream>
using std::ifstream
using std::vector
using std::cout
using std::endl
int main(){
    ifstream myfile("arg[1]");
    char word[64];
    if(!myfile)
        cout << "Nie można otworzyć pliku!" << endl;
    while(myfile >> word)
        cout << word;





    vector < int > dane={-11, -90, -4, -5, -9, -1, -3, -1};
    cout<<GreatestProduct(dane,3);


    myfile.close();
    return 0;
}
