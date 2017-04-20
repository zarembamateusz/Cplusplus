//
// Created by Mateusz on 12.04.2017.
//

#include "WordCounter.h"

namespace datastructures {
    WordCounter::WordCounter() {};
    Word::Word() {};
    Counts::Counts() {};

    WordCounter::WordCounter(const std::initializer_list<Word> &elements) {
        for (auto v:elements)
            AddWord(v.word_);
    }

    Counts WordCounter::operator[](std::string napis) {
        Counts tmp;
        int z = 0;
        for (auto v:slownik) {
            if (v.first.word_ == napis) {
                z = 1;
                tmp = v.second;
            }
        }
        if (z == 0)
            tmp = Counts(0);
        return tmp;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> tmp;
        for (auto v:slownik)
            tmp.insert(v.first);
        return tmp;
    }


    Word::Word(std::string dana) {
        word_ = dana;

    }

    Counts Counts::operator++() {
        Counts new_counts(this->counts_);
        ++(this->counts_);
        return new_counts;
    }

    Counts::Counts(int dana) {
        counts_ = dana;
    }

    bool operator<(const Counts &klasa, const Counts &klasa2) {
        return klasa.counts_ < klasa2.counts_;
    };

    bool operator>(const Counts &klasa, const Counts &klasa2) {
        return klasa.counts_ > klasa2.counts_;
    };

    bool operator==(const Counts &klasa, const Counts &klasa2) {
        return klasa.counts_ == klasa2.counts_;
    };

    bool operator==(const Word &L, const Word &R) {
        return L.word_ == R.word_;
    };

    bool operator<(const Word &L, const Word &R) {
        return L.word_ < R.word_;
    };

    bool operator>(const Word &L, const Word &R) {
        return L.word_ > R.word_;
    };

    int WordCounter::TotalWords() {
        int tmp = 0;
        for (auto v:slownik)
            tmp += v.second.counts_;
        return tmp;
    };

    int WordCounter::DistinctWords() {
        return slownik.size();
    }


    void WordCounter::AddWord(std::string new_word_) {
        int tmp = 0;
        int i = 0;
        for (auto k:slownik) {
            if (new_word_ == k.first.word_) {
                tmp = 1;
                auto counts_copy = k.second;
                ++counts_copy;
                std::pair<Word, Counts> new_pair;
                new_pair.first = k.first;
                new_pair.second = counts_copy;
                slownik.at(i) = new_pair;
            }
            i++;
        }
        if (tmp == 0) {
            std::pair<Word, Counts> new_pair;
            new_pair.first =Word(new_word_);
            new_pair.second = Counts(1);
            slownik.push_back(new_pair);
        }

    }

    WordCounter WordCounter::FromInputStream(std::ifstream &stream_) const{
        std::string stream_string_;
        while(!stream_.eof()){
            getline(stream_,stream_string_);
        }
        WordCounter new_counts;
        std::string word_;
        for(int i=0;i<stream_string_.size();i++){

            if((int)stream_string_[i]==32) {
                new_counts.AddWord(word_);
                word_ = "";

            }else if(((int)stream_string_[i]>47&&(int)stream_string_[i]<58)||((int)stream_string_[i]>64&&(int)stream_string_[i]<91)||((int)stream_string_[i]>96&&(int)stream_string_[i]<1230)){
                word_+=stream_string_[i];
            }
        }
        return new_counts;
    }
}
