#ifndef POLYGON
#define POLYGON
#include "bubble_sort.h"
#include "shape.h"
class Polygon : public Shape{
private:
  int _numVertices;
  Vector *_vertices;
public:
  Polygon(Vector *vecs, int numVertices){
    _numVertices = numVertices;
    _vertices = new Vector [_numVertices];
    for(int i=0 ; i<_numVertices ; i++){
      _vertices[i] = vecs[i];
    }
  }
  static Polygon CreatePolygon(Vector * input, int numVertices){
      Vector c = Polygon::centroid(input, numVertices);
      Vector b = input[0] - c;
      angleComparator comp = angleComparator(c, b);
      //std::sort(input,input+numVertices,comp);
      bubbleSort(input,input+numVertices,comp);
      return Polygon(input, numVertices);
  }
  Polygon(){
    _numVertices = 0;
    _vertices = new Vector [_numVertices];
  }

  ~Polygon() override{
    if(_vertices != NULL){
      delete [] _vertices;
    }
  }

  double perimeter() const;
  static Vector centroid(Vector *vertices, int numVertices) {
    Vector c = Vector(2);
    int d = vertices[0].dim();
    for(int i = 0 ; i < numVertices ; i++){
      if(d != vertices[i].dim()){
        throw("Dimension error in centroid.");
      }
      c.at(1) += vertices[i].at(1);
      c.at(2) += vertices[i].at(2);
    }
    c.at(1) /= numVertices;
    c.at(2) /= numVertices;
    return c;
  }

  static double distance(Vector u, Vector v) {
    if(u.dim() != v.dim()){
      throw("Dimension error in distance.");
    }
    Vector w = u - v;
    double d = 0;
    for(int i = 1 ; i <= w.dim() ; i++){
      d += w.at(i) * w.at(i);
    }
    return sqrt(d);
  }
  double area(Vector u, Vector v, Vector w) const;
  double area() const;

};

#endif
