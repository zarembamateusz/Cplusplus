//
// Created by Mateusz on 13.03.2017.
//
#include "XorCypherBreaker.h"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

int main(){
    int k=3;
    vector<char> cryptogram
            {93, 65, 76, 47, 7, 25, 15, 4, 76, 34, 0, 30, 30, 6, 31, 76, 12, 13, 2, 79, 24, 13, 4, 9, 76, 28, 15, 30, 10, 9,
             2, 28, 4, 3, 27, 76, 3, 9, 76, 4, 6, 31, 76, 13, 0, 25, 10, 76, 31, 12, 30, 9, 10, 2, 76, 0, 10, 76, 11, 9, 13,
             27, 4, 76, 93, 66, 76, 63, 30, 3, 8, 30, 13, 2, 1, 9, 29, 76, 68, 1, 3, 25, 1, 66, 69, 79, 45, 76, 31, 9, 30, 28,
             3, 2, 79, 27, 4, 0, 76, 10, 6, 20, 9, 11, 76, 13, 79, 28, 30, 0, 14, 0, 10, 1, 76, 22, 3, 25, 79, 8, 3, 79, 2, 3,
             27, 76, 7, 1, 3, 27, 79, 21, 3, 26, 76, 4, 14, 26, 9, 67, 76, 5, 1, 76, 13, 79, 27, 13, 22, 76, 21, 0, 25, 76,
             11, 3, 76, 1, 3, 24, 79, 25, 2, 11, 9, 30, 28, 24, 13, 1, 8, 66};

    vector<string> dictionary {"the", "of", "and", "to", "a", "in", "is", "you", "are", "for", "that", "or", "it", "as", "be", "on",
                               "your", "with", "can", "have", "this", "an", "by", "not", "but", "at", "from", "I", "they", "more",
                               "will", "if", "some", "there", "what", "about", "which", "when", "one", "their", "all", "also",
                               "how", "many", "do", "has", "most", "people", "other", "time", "so", "was", "we", "these", "may",
                               "like", "use", "into", "than", "up", "out", "who", "them", "make", "because", "such", "through",
                               "get", "work", "even", "different", "its", "no", "our", "new", "film", "just", "only", "see", "used",
                               "good", "water", "been", "need", "should", "very", "any", "history", "often", "way", "well", "art",
                               "know", "were", "then", "my", "first", "would", "money", "each", "over", "world", "information", "map",
                               "find", "where", "much", "take", "two", "want", "important", "family", "those", "example", "while",
                               "he", "look", "government", "before", "help", "between", "go", "own", "however", "business", "us",
                               "great", "his", "being", "another", "health", "same", "study", "why", "few", "game", "might", "think",
                               "free", "too", "had", "hi", "right", "still", "system", "after", "computer", "best", "must", "her",
                               "life", "since", "could", "does", "now", "during", "learn", "around", "usually", "form", "meat", "air",
                               "day", "place", "become", "number", "public", "read", "keep", "part", "start"};

    std::cout<<XorCypherBreaker(cryptogram,k,dictionary);

    return 0;
}