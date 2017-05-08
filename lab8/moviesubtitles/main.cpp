//
// Created by Mateusz on 02.05.2017.
//

#include <MovieSubtitles.h>
#include <SubRipSubtitles.h>
#include <memory>
#include <iostream>

using ::moviesubs::SubRipSubtitles;

int main(){

    /*auto subs = std::make_unique<MicroDvdSubtitles>();
    std::stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;

    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
    std::stringstream out;
    out<<"kooot"<<"\\"<<"\n"<<"kot";
    std::string tmp2;
    out>>tmp2;
    std::cout<<tmp2.c_str();*/

    auto subs = std::make_unique<SubRipSubtitles>();
   // std::stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
    std::stringstream out;
    //subs->ShiftAllSubtitlesBy(300, 24, &in, &out);

    std::stringstream in {"1\n00:00:10,345 --> 00:00:12,678\nTEXT\n\n4\n00:19:14,141 --> 00:21:20,100\nTT\n"};
    subs->ShiftAllSubtitlesBy(-1140, 25, &in, &out);
    std::cout<<out.str();
    return 0;
}
