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
  double perimeter() const;
  double area() const;
};

#endif
