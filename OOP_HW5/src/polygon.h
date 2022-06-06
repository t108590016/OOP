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
      Vector c = centroid(input, numVertices);
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
  double perimeter() const{
    double per = 0;
    for(int i=0 ; i<_numVertices-1 ; i++){
      per += (_vertices[i]-_vertices[i+1]).length();
    }
    per += (_vertices[0]-_vertices[_numVertices-1]).length();
    return per;
  }
  ~Polygon() override{
    if(_vertices != NULL){
      delete [] _vertices;
    }
  }
/*
  double area(Vector u, Vector v, Vector w){
    if(u.dim() != v.dim() || u.dim() != w.dim()){
      throw("Dimension error in area (use 3 vectors).");
    }
    double A = distance(u, v);
    double B = distance(v, w);
    double C = distance(u, w);
    double S = (A + B + C) / 2;
    printf("%f\n", sqrt(S * (S - A) * (S - B) * (S - C)));
    return sqrt(S * (S - A) * (S - B) * (S - C));
  }
  */
  double area() const {
    /*
    Vector c = centroid(_vertices, _numVertices);
    Vector b = _vertices[0] - c;
    angleComparator comp = angleComparator(c, b);
    double result = 0;
    bubbleSort<Vector*, angleComparator>(_vertices, _vertices+_numVertices, comp);
    //sort(a, a+sides, comp);
    for(int i = 1 ; i < _numVertices-1 ; i++){
      result += area(_vertices[0], _vertices[i], _vertices[i+1]);
    }
    return result;
    */
    return Area(_vertices, _numVertices);
  }

};

#endif
