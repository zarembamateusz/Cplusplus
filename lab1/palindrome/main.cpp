//
// Created by Mateusz on 06.03.2017.
//
#include <iostream>
#include <string>
#include "Palindrome.h"
    using namespace std;

    int main() {
        string tekst;
        int i=-1;

        while (i!=1 && i!=2) {
            cout<<"Press 1 to check or press 2 to exit "<<endl;
            cin>>i;
        }
        if(i==1) {
            cout<<"Enter text"<<endl;
            cin>>tekst;
            cout<<endl;
            if (is_palindrome(tekst))
                cout <<tekst<<" is palindrome " << endl;
            else
                cout <<tekst<< " is not palindrome ";
        }
        return 0;

}