#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_
#include <cmath>
#include <ostream>
#include <iostream>
using ::std::ostream;
using ::std::endl;
using ::std::cout;
using ::std::pow;
using ::std::sqrt;
namespace points {

    class Point {
    public:

        Point();
        Point(double x, double y);
        ~Point();


        //void ToString(std::ostream *out) const;
        double Distance(const Point &other) const;
        double GetX() const;
        double GetY() const;
        //void SetX(double x);
        //void SetY(double y);
    private:
        double x_, y_;
    };
}
#endif  // PROJECTNAME_PATH_POINT_H_