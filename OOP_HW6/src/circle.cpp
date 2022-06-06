#include "circle.h"
//Undefined reference to Class::Function()
//與makefile有關!!
double Circle::perimeter() const{
  return 2*M_PI*_radius;
}
double Circle::area() const{
  return M_PI*_radius*_radius;
}
