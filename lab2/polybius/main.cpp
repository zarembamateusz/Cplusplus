//
// Created by Mateusz on 13.03.2017.
//

#include <string>
#include <iostream>
#include "Polybius.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::ios_base;
using std::string;


int main(int argc, char const *argv[]) {

    if (*argv[3] == '1') {
        ifstream myfile1(argv[1]);
        ofstream myfile2(argv[2], ios_base::in | ios_base::app);
        char word[64];
        if (!myfile1)
            cout << "Nie można otworzyć pliku! " << endl;
        while (myfile1 >> word) {
            myfile2 << PolybiusCrypt(word);
        }
        myfile1.close();
        myfile2.close();
    }
    if (*argv[3] == '0') {
        ifstream myfile1(argv[1]);
        ofstream myfile2(argv[2], ios_base::in | ios_base::app);
        char word[64];
        if (!myfile1)
            cout << "Nie można otworzyć pliku!" << endl;
        while (myfile1 >> word) {
            //cout<<"raz "<<endl;
            myfile2 << PolybiusDecrypt(word);
        }
        myfile1.close();
        myfile2.close();
    }
    if(*argv[3]!='1' && *argv[3]!='0') {
        cout << "Podano bledny argument " << endl;
    }
    return 0;
}