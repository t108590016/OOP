#include "./svg_shape.h"
#ifndef SVGLINE
#define SVGLINE
class SvgLine : public SvgShape {
  public:
    SvgLine(double x1, double y1, double x2, double y2) {
      _x1 = x1;
      _y1 = y1;
      _x2 = x2;
      _y2 = y2;
    }
    std::string toSVG() const {
      stringstream ss;
      ss << "<line x1=\"";
      ss << to_string(_x1);
      ss << "\" y1=\"";
      ss << to_string(_y1);
      ss << "\" x2=\"";
      ss << to_string(_x2);
      ss << "\" y2=\"";
      ss << to_string(_y2);
      ss << "\" stroke-width=\"";
      ss << to_string(_strokeWidth);
      ss << "\" stroke=\"";
      ss << _strokeColor;      
      ss << "\" fill=\"";
      ss << _fillColor;
      ss<< "\"/>";
      //ss <<
      return ss.str();
    }
  private:
    double _x1, _y1, _x2, _y2;
};

#endif
