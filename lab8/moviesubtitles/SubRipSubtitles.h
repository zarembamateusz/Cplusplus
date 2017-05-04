//
// Created by Mateusz on 02.05.2017.
//

#ifndef JIMP_EXERCISES_SUBRIP_H
#define JIMP_EXERCISES_SUBRIP_H

namespace moviesubs {
    class SubRipSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in,std::stringstream *out);

    };
}

#endif //JIMP_EXERCISES_SUBRIP_H
