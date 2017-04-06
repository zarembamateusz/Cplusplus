//
// Created by Mateusz on 03.04.2017.
//
#include <initializer_list>;
#include <string>;
#include <experimental/string_view>;
#include <set>;
#include <cstring>
#include "TextPool.h"
namespace pool{

   TextPool & TextPool::operator=(TextPool&& xxx) {
       if (this == &xxx) {
           return xxx;
       }
       mapa.clear();
       std::swap(mapa,xxx.mapa);
   }

    TextPool::TextPool(TextPool&& tPoolMove){
        std::swap(mapa,tPoolMove.mapa);
    }

    TextPool::TextPool(const std::initializer_list<std::string> &elements){
        for(auto v:elements){
            this->Intern(v);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str){
        auto it=mapa.insert(str);
        return *it.first;

    }

    size_t TextPool::StoredStringCount() const{
        size_t size =mapa.size();

        return size;

    }
}
