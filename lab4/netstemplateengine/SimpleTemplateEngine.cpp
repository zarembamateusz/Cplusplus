//
// Created by Mateusz on 27.03.2017.
//

#include <iostream>
#include "SimpleTemplateEngine.h"
namespace nets{
#include <string>
#include <unordered_map>

    View::View(const std::string &str){
        out_=str;
    }

   std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
       int i = 0;//iterator po while
       std::string tmp;//wyjsciowy string
       std::string tmp2;//string sprawdzajacy wyraz w nawiasach
       while (i < out_.size()) {
           tmp2="";//czyszczenie przed rozpoczeciem petli
           int domykanie = 0;//sprawda czy po dwóch wasatych nie ma wasatego
           int stop=0;//wartosc 1 gdy wchodzi do nawiasów wasatych, 2 gdy wyraz w wasatych pasuje do schematu podmiany
           int kopia_i = 0;//kopia iteratora petli
           if ((out_[i] == '{') && (out_[i + 1] == '{')) {
               kopia_i=i;//tworzenie kopii
               kopia_i=kopia_i+2;//przechodzenie do wyrazu poza nawiasami
               while (stop != 1) {//petla szukajaca wyrazu w nawiasie
                   if ((out_[kopia_i] == '}') && (out_[kopia_i + 1] == '}')) {//szuka konca nawiasów wasatych
                       stop = 1;//jeden jesli znajdzie
                   }
                   else {//to dodaje teks pomiedy do tmp2 i sprawda domkniecie pojedyncze wasa praz zwiksza itereator kopia _i o 1
                       tmp2 += out_[kopia_i];
                       if((int(out_[kopia_i])<48)||(int(out_[kopia_i])>122))
                               domykanie = 1;
                       kopia_i++;
                   }
               }
               for(auto v:model){
                   if(tmp2==v.first) {
                       tmp += v.second;
                       kopia_i=kopia_i+2;
                       i=kopia_i;
                       stop=2;
                   }
               }
               if(stop==1) {
                   if(domykanie==1) {
                       tmp += out_[i];
                       i++;
                   }
                   else
                       i=kopia_i+2;

               }
           }
           else {
               tmp += out_[i];
               i++;
           }
       }
       return tmp;
    }
}


