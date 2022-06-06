#ifndef CIRCLE
#define CIRCLE
#include "shape.h"
#include <cmath>
class Circle : public Shape{
private:
  double _radius;
public:
  Circle(double radius) : _radius(radius){

  }
  ~Circle() override{

  }
  double perimeter() const{
    return 2*M_PI*_radius;
  }
  double area() const{
    return M_PI*_radius*_radius;
  }
};

#endif
