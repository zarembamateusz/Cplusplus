//
// Created by Mateusz on 02.05.2017.
//

#include "MicroDvdSubtitles.h"
#include "Wyjatki.h"
#include <math.h>
#include <iostream>

namespace moviesubs {


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        std::stringstream tmp;
        std::string in_string;
        std::stringstream out_stream;
        if (fps < 0)
            throw std::invalid_argument("Invalid argument");
        int line = 1;
        while (getline(*in, in_string)) {
            int i = 0;
            std::string tmp_string1;
            std::string tmp_string2;
            int n = 0;
            while (i < in_string.size()) {
                std::string tmp_string;
                if (in_string[i] == '{' && ((int) in_string[i + 1] - 48) < 10) {
                    n++;
                    out_stream << '{';
                    i++;
                    while (in_string[i] != '}') {
                        if((int)in_string[i]<123&&(int)in_string[i]>64)
                            throw InvalidSubtitleLineFormat();
                        tmp_string += in_string[i];
                        i++;
                    }
                    int a = atoi(tmp_string.c_str());
                    if (n == 1)
                        tmp_string1 = tmp_string;
                    else
                        tmp_string2 = tmp_string;
                    tmp_string = "";
                    int b = floor(delay / (1000 / fps));
                    int tmp_int = (a + b);
                    if (tmp_int < 0)
                        throw NegativeFrameAfterShift();
                    out_stream << tmp_int;
                    out_stream << '}';
                    i++;
                } else {
                    out_stream << in_string[i];
                    i++;
                }
            }
            if (tmp_string1.size() == 0 || tmp_string2.size() == 0)
                throw InvalidSubtitleLineFormat();
            if (atoi(tmp_string2.c_str()) - atoi(tmp_string1.c_str()) < 0)
                throw SubtitleEndBeforeStart(in_string, line);
            out_stream << '\n';
            line++;
        }
        swap(*out, out_stream);
    }
}