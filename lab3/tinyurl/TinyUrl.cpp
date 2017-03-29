//
// Created by Mateusz on 16.03.2017.
//

#include "TinyUrl.h"
#include <iostream>
#include <vector>
#include <string>

namespace tinyurl {
    using ::std::string;

    std::unique_ptr<TinyUrlCodec> Init() {
        auto pointer = std::make_unique<TinyUrlCodec>();
        pointer->dane.insert(std::pair<std::string, std::string>("brak", "000000"));

        return pointer;
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        int k = 1;
        std::array<char, 6> array_tmp;
        for (auto v: (*codec)->dane) {
            if ((*codec)->dane.size() == k) {
                for (int i = 0; i < 6; i++)
                    array_tmp.at(i) = v.second[i];
            }
            k++;
        }
        NextHash(&array_tmp);
        std::string sshort;
        for (int j = 0; j < 6; j++) {
            sshort[j] = array_tmp.at(j);
        }
        (*codec)->dane.insert(std::pair<std::string, std::string>(url, sshort));
        return sshort;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        string tmp;
        for (auto v:codec->dane) {
            if (v.second == hash)
                tmp = v.first;
        }
        return tmp;
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
