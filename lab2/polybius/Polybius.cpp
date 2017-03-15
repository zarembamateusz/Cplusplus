//
// Created by Mateusz on 13.03.2017.
//
#include <iostream>
#include "Polybius.h"
#include <sstream>

//using std::string;

std::string PolybiusCrypt(std::string message) {
    std::string crypt;
    size_t size = message.size();
    std::stringstream tmp;
    char **tab = alokuj(5, 5);
    tab[0][0] = 'a';
    tab[0][1] = 'b';
    tab[0][2] = 'c';
    tab[0][3] = 'd';
    tab[0][4] = 'e';
    tab[1][0] = 'f';
    tab[1][1] = 'g';
    tab[1][2] = 'h';
    tab[1][3] = 'j';
    tab[1][4] = 'k';
    tab[2][0] = 'l';
    tab[2][1] = 'm';
    tab[2][2] = 'n';
    tab[2][3] = 'o';
    tab[2][4] = 'p';
    tab[3][0] = 'q';
    tab[3][1] = 'r';
    tab[3][2] = 's';
    tab[3][3] = 't';
    tab[3][4] = 'u';
    tab[4][0] = 'v';
    tab[4][1] = 'w';
    tab[4][2] = 'x';
    tab[4][3] = 'y';
    tab[4][4] = 'z';

    for (int k = 0; k < size; k++) {
        message[k] = tolower(message[k]);
        if (message[k] == 'i') {
            message[k] = 'j';
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (message[k] == tab[i][j]) {
                    tmp << i + 1;
                    tmp << j + 1;
                }
            }
        }
    }
    tmp >> crypt;
    zwolnij_pamiec(tab, 5, 5);
    return crypt;
}

char **alokuj(int rozmiar1, int rozmiar2) {
    char **tablica;
    tablica = new char *[rozmiar1];
    for (int i = 0; i < rozmiar1; i++) {
        tablica[i] = new char[rozmiar2];
    }
    return (tablica);
}


void zwolnij_pamiec(char **tablica, int rozmiar1, int rozmiar2) {
    for (int i = 0; i < rozmiar1; i++) delete[] tablica[i];
    delete[] tablica;
}

std::string PolybiusDecrypt(std::string crypted) {
    int k, l;
    size_t size = crypted.size();
    std::string decrypted;
    char **tab = alokuj(5, 5);
    tab[0][0] = 'a';
    tab[0][1] = 'b';
    tab[0][2] = 'c';
    tab[0][3] = 'd';
    tab[0][4] = 'e';
    tab[1][0] = 'f';
    tab[1][1] = 'g';
    tab[1][2] = 'h';
    tab[1][3] = 'i';
    tab[1][4] = 'k';
    tab[2][0] = 'l';
    tab[2][1] = 'm';
    tab[2][2] = 'n';
    tab[2][3] = 'o';
    tab[2][4] = 'p';
    tab[3][0] = 'q';
    tab[3][1] = 'r';
    tab[3][2] = 's';
    tab[3][3] = 't';
    tab[3][4] = 'u';
    tab[4][0] = 'v';
    tab[4][1] = 'w';
    tab[4][2] = 'x';
    tab[4][3] = 'y';
    tab[4][4] = 'z';
    for (int j = 0; j < size; j = j + 2) {
        int k = (int) crypted[j] - 48;
        int l = (int) crypted[j + 1] - 48;
        decrypted += tab[k - 1][l - 1];
    }
    zwolnij_pamiec(tab, 5, 5);
    return decrypted;
}