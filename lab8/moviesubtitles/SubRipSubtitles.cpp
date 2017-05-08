//
// Created by Mateusz on 02.05.2017.
//

#include <iosfwd>
#include <sstream>
#include <regex>
#include <iostream>
#include "SubRipSubtitles.h"
#include <string>
#include <math.h>

namespace moviesubs {
    using std::cout;
    using std::endl;
    using std::string;
    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
        std::stringstream tmp;
        std::string in_string;
        std::stringstream out_stream;
        if(fps<0)
            throw std::invalid_argument("Invalid argument");
        int i=1;
        int line=0;
        while (getline(*in, in_string)) {
            if(i!=2){
                if(i==1)
                    if((int)in_string[0]-48!=line+1)
                        throw OutOfOrderFrames();
                if(in_string.size()==0)
                    i=1;
                out_stream<<in_string;
                out_stream<<'\n';
                i++;
                if(in_string.size()==0)
                    i=1;
                continue;
            }else if(i==2) {
                std::regex pattern{R"((\d{2}):(\d{2}):(\d{2}),(\d{3})\s{1}-->\s{1}(\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
                std::smatch matches;
                if (regex_match(in_string, matches, pattern)) {
                    line++;
                    std::string result=matches[2].str();
                    std::vector<string> result_string;
                    std::vector<int> result_int;
                    for(int i=1;i<9;i++){
                        result_string.push_back(matches[i].str());
                        result_int.push_back(stoi(result_string[i-1]));
                    }
                    if(stoi(result_string[2]+result_string[3])+delay<0)
                        throw NegativeFrameAfterShift();
                    if(result_int[3]+delay>1000) {
                        result_int[2] = result_int[2]+1;
                        result_int[3]= result_int[3] + delay-1000;
                    }else{
                        result_int[3]= result_int[3] + delay;
                    }
                    if(result_int[7]+delay>1000) {
                        result_int[6] = result_int[6]+1;
                        result_int[7]= result_int[7] + delay-1000;
                    }else{
                        result_int[7]= result_int[7] + delay;
                    }
                    for(int i=0;i<8;i++) {
                        if(i!=3&&i!=7){
                            if(result_int[i]<10){
                                out_stream<<0;
                            }
                        out_stream <<result_int[i];
                        } else{
                            if(result_int[i]<10){
                                out_stream<<0;
                            }
                            if(result_int[i]<100)
                                out_stream<<0;
                            out_stream <<result_int[i];
                        }
                        if(i<2||(i>3&&i<6))
                            out_stream<<":";
                        if(i==2||i==6)
                            out_stream<<",";
                        if(i==3)
                            out_stream<<" --> ";
                    }
                    if(result_int[1]>result_int[5])
                        throw SubtitleEndBeforeStart(matches[0].str(),line);
                } else
                    throw InvalidSubtitleLineFormat();
                i++;
                out_stream<<'\n';
            }
        }
        swap(*out,out_stream);
    }
}
