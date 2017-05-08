//
// Created by Mateusz on 04.05.2017.
//

#ifndef JIMP_EXERCISES_WYJATKI_H
#define JIMP_EXERCISES_WYJATKI_H

#include <stdexcept>
namespace moviesubs { 
    class NegativeFrameAfterShift {

    };
    class SubtitleEndBeforeStart: public std::runtime_error {
    public:
        SubtitleEndBeforeStart(const std::string &m, int line): std::runtime_error("At line " + std::to_string(line) + ": " + m) { 
            line_ = line; 
        }
        int LineAt() const { return line_;};

    private:
           int line_ = 0;
    };
    class InvalidSubtitleLineFormat {

    };
    class OutOfOrderFrames {

    };
}


#endif //JIMP_EXERCISES_WYJATKI_H
