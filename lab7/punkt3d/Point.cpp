//Definicja znajduje się w pliku Point.cpp

#include "Point.h"
namespace points {



/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::" 
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
    Point::Point() : x_(0), y_(0) {
      cout << "Konstruktor w klasie 2d" << endl;
    }

    Point::Point(double x, double y) {
      cout << "Konstruktor parametrowy w klasie 2d " << endl;
      x_ = x;
      y_ = y;
    }

    Point::~Point() {
      cout << "Destruktor w  klasie 2d";
      cout << endl;
    }

    double Point::Distance(const Point &other) const {
      return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    /*void Point::ToString(ostream *out) const {
      (*out) << "(" << GetX() << ";" << GetY() << ")";
    }*/
    double Point::GetY() const{
        return y_;
    }
    double Point::GetX() const{
        return x_;
    }
}