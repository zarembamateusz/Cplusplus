//
// Created by Mateusz on 04.05.2017.
//

#ifndef JIMP_EXERCISES_WYJATKI_H
#define JIMP_EXERCISES_WYJATKI_H

namespace moviesubs {
    class NegativeFrameAfterShift {

    };

    class SubtitleEndBeforeStart {
    public:
        SubtitleEndBeforeStart(std::string line, int *e);
        int const LineAt();
        int e_;

    };

    class InvalidSubtitleLineFormat {

    };
}

#endif //JIMP_EXERCISES_WYJATKI_H
