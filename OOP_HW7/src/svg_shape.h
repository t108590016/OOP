#ifndef SVGSHAPE
#define SVGSHAPE
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class SvgShape {
  public:
    SvgShape(){
      _strokeWidth = 0;
      _fillColor = "black";
      _strokeColor = "black";
    }
    void setFillColor(std::string fillColor) {
      _fillColor = fillColor;
    }
    void setStroke(double strokeWidth, std::string strokeColor) {
      _strokeWidth = strokeWidth;
      _strokeColor = strokeColor;
    }
    virtual std::string toSVG() const = 0;

  protected:
    //...

  //private:

    double _strokeWidth;
    std::string _fillColor, _strokeColor;
};
void setSvgShapeStyle(SvgShape * shape, double strokeWidth, std::string strokeColor, std::string fillColor){
    shape->setFillColor(fillColor);
    shape->setStroke(strokeWidth, strokeColor);
}
string makeSvgOutput(int width, int height, vector<SvgShape *> const & shape){
  stringstream ss;
  ss << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"";
  ss << width;
  ss << "\" height=\"";
  ss << height;
  ss << "\" viewBox=\"0 0 100 100\">";
  for(int i=0; i<shape.size();i++){
    ss << shape[i]->toSVG();
  }
  ss << "</svg>";
  return ss.str();
}

#endif
