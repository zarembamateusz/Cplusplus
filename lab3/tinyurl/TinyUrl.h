//
// Created by Mateusz on 16.03.2017.
//
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
#include <vector>
#include <string>

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H





#endif //JIMP_EXERCISES_TINYURL_H
namespace tinyurl{
    struct TinyUrlCodec{
        std::map<std::string,std::string> dane;
    };
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}