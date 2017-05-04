//
// Created by Mateusz on 02.05.2017.
//

#include "MicroDvdSubtitles.h"
#include "Wyjatki.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

namespace moviesubs {


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        std::stringstream tmp;
        std::string in_string;
        std::stringstream out_stream;
        if(fps<0)
            throw std::invalid_argument("Invalid argument");
        int j=1;
        while(getline (*in, in_string)) {
           int i = 0;
           while (i < in_string.size()) {
               std::string tmp_string;
               if (in_string[i] == '{' &&((int)in_string[i+1]-48)<10) {
                   out_stream << '{';
                   i++;
                   while (in_string[i] != '}') {
                       tmp_string += in_string[i];
                       i++;
                   }
                   int a = atoi(tmp_string.c_str());
                   tmp_string = "";
                   int b = floor(delay / (1000 / fps));
                   int tmp_int = (a + b);
                   if(tmp_int<0)
                       throw NegativeFrameAfterShift();

                   out_stream << tmp_int;
                   out_stream << '}';
                   i++;
               } else {
                   out_stream << in_string[i];
                   i++;
               }

           }
           out_stream<<'\n';
           j++;
       }
        swap(*out,out_stream);
    }
}