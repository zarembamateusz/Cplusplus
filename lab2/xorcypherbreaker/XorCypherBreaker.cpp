//
// Created by Mateusz on 13.03.2017.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "XorCypherBreaker.h"

using std::string;
using std::vector;

std::string
XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary) {
    string key;
    vector<int> one_l = {};
    vector<int> two_l = {};
    vector<int> three_l = {};

    for (int i = 97; i < 123; i++) {
        one_l.push_back(i);
        for (int j = 0; j < cryptogram.size(); j = j + 3) {
            if (!is_english(cryptogram[j], i)) {
                one_l.pop_back();
                j = cryptogram.size();
            }
        }
    }
    for (int i = 97; i < 123; i++) {
        two_l.push_back(i);
        for (int j = 1; j < cryptogram.size(); j = j + 3) {
            if (!is_english(cryptogram[j], i)) {
                two_l.pop_back();
                j = cryptogram.size();
            }
        }
    }
    for (int i = 97; i < 123; i++) {
        three_l.push_back(i);
        for (int j = 2; j < cryptogram.size(); j = j + 3) {
            if (!is_english(cryptogram[j], i)) {
                three_l.pop_back();
                j = cryptogram.size();
            }
        }
    }
    key += char(one_l[0]);
    key += char(two_l[0]);
    key += char(three_l[0]);
    return key;
}

bool is_english(char first, int second) {
    int xxor;
    xxor = int(first) ^ second;
    if ((32 <= xxor) && (xxor <= 90)) {
        return true;
    }
    if ((97 <= xxor) && (xxor <= 122)) {
        return true;
    }
    return false;
}
