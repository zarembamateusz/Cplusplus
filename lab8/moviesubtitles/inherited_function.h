//
// Created by Mateusz on 08.05.2017.
//

#ifndef JIMP_EXERCISES_INHERITED_FUNCTION_H
#define JIMP_EXERCISES_INHERITED_FUNCTION_H
namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps,std::stringstream *in,std::stringstream *out)=0;

    };
}
#endif //JIMP_EXERCISES_INHERITED_FUNCTION_H
