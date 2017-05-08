//
// Created by Mateusz on 02.05.2017.
//

#ifndef JIMP_EXERCISES_SUBRIP_H
#define JIMP_EXERCISES_SUBRIP_H

#include "Wyjatki.h"
#include "inherited_function.h"
namespace moviesubs {
    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in,std::stringstream *out) override ;

    };
}

#endif //JIMP_EXERCISES_SUBRIP_H
