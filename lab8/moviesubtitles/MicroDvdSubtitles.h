//
// Created by Mateusz on 02.05.2017.
//

#ifndef JIMP_EXERCISES_MICRODVD_H
#define JIMP_EXERCISES_MICRODVD_H

#include <sstream>
#include "inherited_function.h"


namespace moviesubs {

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in,std::stringstream *out) override ;

    };
}

#endif //JIMP_EXERCISES_MICRODVD_H
