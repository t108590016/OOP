#ifndef SHAPE
#define SHAPE
#include "vector.h"
#include <vector>
#include <string>
using namespace std;
class Shape{
protected:
  string _name;
public:
  Shape(){
  }
  virtual ~Shape(){
  }
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  string getName();
};

template <class RandomAccessIterator, class Condition>
vector<Shape *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond){
  //寫在class外面!!
  vector<Shape *> result;
  for (int i = 0; i < end-begin; i++){
    if (cond(*(begin+i))){
      result.push_back(*(begin+i));
    }
  }
  return result;
}

#endif
