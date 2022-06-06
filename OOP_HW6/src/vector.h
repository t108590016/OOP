using namespace std;
#ifndef VECTOR_H
#define VECTOR_H
#include<cmath>
#include <algorithm>
#include <iostream>
#include "bubble_sort.h"

class Vector{
  private:
    int _dimension;
    double *_contents;
    void copy(int dim, double v[]){
      _contents = new double [dim];
      _dimension = dim;
      for(int i=0;i<dim;i++){
        _contents[i] = v[i];
      }
    }
  public:
    Vector(){
      _dimension = 0;
      _contents = new double [0];
    }

    Vector(int dim){
      _dimension = dim;
      _contents = new double [dim];
      for(int i=0 ; i<dim ; i++){
        _contents[i] = 0;
      }
    }

    Vector(double v[], int dim){
      copy(dim , v);
    }

    Vector(Vector const & v){
      copy(v.dim() , v.contents());
    }

    ~Vector(){
      delete [] _contents;
    }

    double* contents() const;
    Vector & operator = (Vector const & u);
    Vector operator - (Vector const & u) const;
    Vector operator + (Vector const & u) const;
    void subtract(Vector const & v);
    void add(Vector const & v);
    int dim() const;
    double & at(int index) const;
    double length() const;
    double dot(Vector input);
    double angle(Vector input);
    bool larger180(Vector input);
    double slope(Vector input);
    bool VectorsInline(Vector u, Vector v);
};


class angleComparator{
  private:
    Vector _a;
    Vector _b;
  public:

    angleComparator(){

    }

    angleComparator(Vector &a, Vector &b){
      _a = a;
      _b = b;
    }

    bool operator ()(Vector &u, Vector &v){
      return _b.angle(u-_a) < _b.angle(v-_a);
    }



};
/*
Vector centroid(Vector vec[], int sides){
  Vector c = Vector(2);
  int d = vec[0].dim();
  for(int i = 0 ; i < sides ; i++){
    if(d != vec[i].dim()){
      throw("Dimension error in centroid.");
    }
    c.at(1) += vec[i].at(1);
    c.at(2) += vec[i].at(2);
  }
  c.at(1) /= sides;
  c.at(2) /= sides;
  return c;
}

double distance(Vector u, Vector v){
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

double Area(Vector u, Vector v, Vector w){
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

double Area(Vector a[], int sides){
  Vector c = centroid(a, sides);
  Vector b = a[0] - c;
  angleComparator comp = angleComparator(c, b);
  double result = 0;
  bubbleSort<Vector*, angleComparator>(a, a+sides, comp);
  //sort(a, a+sides, comp);
  for(int i = 1 ; i < sides-1 ; i++){
    result += Area(a[0], a[i], a[i+1]);
  }
  return result;
}


double perimeter(Vector a[], int sides){
  double p = 0;
  int d = a[0].dim();
  for(int i = 0 ; i < sides - 1 ; i++){
    if(d != a[i].dim()){
      throw("Dimension error in perimeter.");
    }
    p += distance(a[i], a[i+1]);
  }
  p += distance(a[sides - 1], a[0]);
  return p;
}
*/
#endif
