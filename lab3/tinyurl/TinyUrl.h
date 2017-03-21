//
// Created by Mateusz on 16.03.2017.
//
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
#include <vector>

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H





#endif //JIMP_EXERCISES_TINYURL_H
namespace tinyurl{
    struct TinyUrlCodec{
        //std::map<std::string,string> dane;
        //std::string llong;
        //std::string sshort;
        //std::unique_ptr <TinyUrlCodec> next;
        std::vector<std::string> llong;
        std::vector<std::string> sshort;
        int licznik;


    };
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}