#include "./svg_shape.h"
#ifndef SVGCIRCLE
#define SVGCIRCLE

class SvgCircle : public SvgShape {
  public:
    SvgCircle(double x, double y, double r){
      _x = x;
      _y = y;
      _r = r;
    }
    std::string toSVG() const {
      stringstream ss;
      ss << "<circle cx=\"";
      ss << to_string(_x);
      ss << "\" cy=\"";
      ss << to_string(_y);
      ss << "\" r=\"";
      ss << to_string(_r);
      ss << "\" stroke-width=\"";
      ss << to_string(_strokeWidth);
      ss << "\" stroke=\"";
      ss << _strokeColor;
      ss << "\" fill=\"";
      ss << _fillColor;
      ss<< "\"/>";
      return ss.str();
    }
  private:
    double _x, _y, _r;
};

#endif
