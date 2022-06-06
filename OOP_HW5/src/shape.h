#ifndef SHAPE
#define SHAPE
#include "vector.h"
#include <vector>
using namespace std;
class Shape{
protected:

public:
  Shape(){
  }
  virtual ~Shape(){
  }
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
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
