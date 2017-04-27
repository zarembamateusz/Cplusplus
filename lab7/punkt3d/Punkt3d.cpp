//
// Created by Mateusz on 23.04.2017.

#include "Punkt3d.h"
namespace points{

    Punkt3D::Punkt3D(double x, double y, double z) : Point(x,y) {
        cout << "Konstruktor w klasie 3d";
        cout << endl;
        z_ = z;
    }
    Punkt3D::~Punkt3D(){
        cout << "Destruktor w klasie 3d";
        cout << endl;
    }
    double Punkt3D::Distance(const Punkt3D &other) const{
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2)+pow(GetZ() - other.GetZ(), 2));
    }

    double Punkt3D::GetZ() const{
        return z_;
    }



}
