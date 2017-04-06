//
// Created by Mateusz on 03.04.2017.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
namespace pool {

    class TextPool {
    public:

        TextPool(){};
        TextPool(TextPool&& xxx);
        TextPool &operator=(TextPool &&xxx);
        TextPool(const std::initializer_list<std::string> &elements);
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:

        std::set<std::string> mapa;

    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
