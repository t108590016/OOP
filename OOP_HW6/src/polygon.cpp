#include "polygon.h"

double Polygon::perimeter() const{
  double per = 0;
  for(int i=0 ; i<_numVertices-1 ; i++){
    per += (_vertices[i]-_vertices[i+1]).length();
  }
  per += (_vertices[0]-_vertices[_numVertices-1]).length();
  return per;
}

double Polygon::area(Vector u, Vector v, Vector w) const{
  if(u.dim() != v.dim() || u.dim() != w.dim()){
    throw("Dimension error in area (use 3 vectors).");
  }
  double A = Polygon::distance(u, v);
  double B = Polygon::distance(v, w);
  double C = Polygon::distance(u, w);
  double S = (A + B + C) / 2;
  printf("%f\n", sqrt(S * (S - A) * (S - B) * (S - C)));
  return sqrt(S * (S - A) * (S - B) * (S - C));
}

double Polygon::area() const{

  Vector c = Polygon::centroid(_vertices, _numVertices);
  Vector b = _vertices[0] - c;
  angleComparator comp = angleComparator(c, b);
  double result = 0;
  bubbleSort<Vector*, angleComparator>(_vertices, _vertices+_numVertices, comp);
  //sort(a, a+sides, comp);
  for(int i = 1 ; i < _numVertices-1 ; i++){
    result += area(_vertices[0], _vertices[i], _vertices[i+1]);
  }
  return result;

  //return Area(_vertices, _numVertices);
}
