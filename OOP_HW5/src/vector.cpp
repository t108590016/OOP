#include "vector.h"
Vector Vector::operator - (Vector const & u) const{
  if(_dimension != u.dim()){
    throw("Dimension Error!");
  }
  else{
    Vector result = *this;
    for(int i=1;i<=_dimension;i++){
      result.at(i)-=u.at(i);
    }
    return result;
  }
}
