//
// Created by Mateusz on 23.04.2017.
//

#ifndef JIMP_EXERCISES_PUNKT3D_H
#define JIMP_EXERCISES_PUNKT3D_H

#include "Point.h"

namespace points {
    class Punkt3D : public Point {
    public:
        Punkt3D(double x, double y, double z);
        ~Punkt3D();
        double Distance(const Punkt3D &other) const;
        double GetZ() const;


    private:
        double z_;

    };


}


#endif //JIMP_EXERCISES_PUNKT3D_H
