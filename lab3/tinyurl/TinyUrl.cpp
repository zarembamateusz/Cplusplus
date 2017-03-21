//
// Created by Mateusz on 16.03.2017.
//

#include "TinyUrl.h"
#include <iostream>
#include <vector>

namespace tinyurl {
    using ::std::string;

    std::unique_ptr<TinyUrlCodec> Init() {
        auto pointer = std::make_unique<TinyUrlCodec>();
        pointer->licznik = 0;
        std::string tmp="brak";
        pointer->llong.push_back(tmp);
        tmp="000000";
        pointer->sshort.push_back(tmp);


        return pointer;
    }

std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
     int tmp_licznik=(*codec)->licznik;
    (*codec)->licznik=tmp_licznik+1;

     std::vector<std::string> tmp=(*codec)->llong;;
     tmp.push_back(url);
    (*codec)->llong=tmp;

     tmp=(*codec)->sshort;
     std::string short_tmp=tmp[(*codec)->licznik];
     std::array<char, 6> array_tmp;
     for(int i=0;i<6;i++){
         array_tmp.at(i)=short_tmp[i];
     }

     NextHash(&array_tmp);
     for(int j=0;j<6;j++){
         short_tmp[j]=array_tmp.at(j);
     }

     tmp.push_back(short_tmp);
    (*codec)->sshort=tmp;

     return tmp.at((*codec)->licznik);
}

std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
    int k=-1;

    for(auto v:codec->sshort){
        k++;
        if(v==hash){
            int n=k;
        }
    }
    std::vector<string> tmp=codec->llong;

    return tmp.at(k);
}


void NextHash(std::array<char, 6> *state) {
    std::string tablica = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                           'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                           'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                           'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                           'z'};
    int j = 5;
    for (int i = 0; i < tablica.size(); i++) {

        if (tablica[i] == state->at(j)) {
            if (i == tablica.size() - 1) {
                state->at(j) = tablica[0];
                j--;
                i = -1;
            } else {
                state->at(j) = tablica[i + 1];
                i = tablica.size();
            }
        }

    }
}

}
