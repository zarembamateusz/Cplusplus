//
// Created by Mateusz on 12.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
namespace datastructures {

    class Word {
    public:
        Word();
        Word(std::string dana);
        std::string word_;
    };

    class Counts {
    public:
        Counts();
        Counts(int);
        int counts_;
        Counts operator++ ();
    };

    class WordCounter {
    public:
        WordCounter ();
        WordCounter (const std::initializer_list<Word> &elements);
        Counts operator[](std::string napis);
        WordCounter FromInputStream (std::ifstream &stream_) const;
        void AddWord(std::string word_);
        int TotalWords();
        int DistinctWords();
        std::set<Word> Words();

    private:
        std::vector<std::pair<Word,Counts>> slownik;
    };

    bool operator< (const Counts& klasa,const Counts& klasa2);
    bool operator> (const Counts& klasa,const Counts& klasa2);
    bool operator== (const Counts& klasa,const Counts& klasa2);
    bool operator==(const Word &L, const Word &R);
    bool operator<(const Word &L, const Word &R);
    bool operator>(const Word &L, const Word &R);

}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
