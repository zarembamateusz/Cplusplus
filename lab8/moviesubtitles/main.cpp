//
// Created by Mateusz on 02.05.2017.
//

#include <MovieSubtitles.h>
#include <memory>
#include <iostream>

using ::moviesubs::MicroDvdSubtitles;

int main(){

    /*auto subs = std::make_unique<MicroDvdSubtitles>();
    std::stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;

    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);*/
    std::stringstream out;
    out<<"kooot"<<"\\"<<"\n"<<"kot";
    std::string tmp2;
    out>>tmp2;
    std::cout<<tmp2.c_str();


    return 0;
}
