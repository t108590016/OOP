#include "./svg_shape.h"
#ifndef SVGPOLYGON
#define SVGPOLYGON

class SvgPolygon : public SvgShape {
  public:
    SvgPolygon(std::vector<double *> const & v){
      _v = v;
    }
    std::string toSVG() const {
      stringstream ss;
      ss << "<polygon points=\"";
      //ss <<
      for(int i=0; i<_v.size();i++){
        ss << to_string(_v.at(i)[0]) << " " << to_string(_v.at(i)[1]);
        if(i!=_v.size()-1){
          ss << " ";
        }
      }
      ss << "\" stroke-width=\"";
      ss << to_string(_strokeWidth);
      ss << "\" stroke=\"";
      ss << _strokeColor;
      ss << "\" fill=\"";
      ss << _fillColor;
      ss << "\"/>";
      return ss.str();
    }
  private:
    std::vector<double *> _v;
};

#endif
