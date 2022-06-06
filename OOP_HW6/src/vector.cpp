#include "./vector.h"
void Vector::subtract(Vector const & v){
  if(_dimension != v.dim()){
    throw("Dimension Error!");
  }
  else{
    for(int i=0;i<_dimension;i++){
      _contents[i]-=v.at(i+1);
    }
  }
}

void Vector::add(Vector const & v){
  if(_dimension != v.dim()){
    throw("Dimension Error!");
  }
  else{
    for(int i=0;i<_dimension;i++){
      _contents[i]+=v.at(i+1);
    }
  }
}

double* Vector::contents() const {
  return _contents;
}

Vector & Vector::operator = (Vector const & u){
  if(_contents != NULL){
    delete [] _contents;
  }
  _dimension = u.dim();
  _contents = new double [_dimension];
  for(int i=0;i<_dimension;i++){
    _contents[i] = u.at(i+1);
  }
  return *this;
}

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

Vector Vector::operator + (Vector const & u) const{
  if(_dimension != u.dim()){
    throw("Dimension Error!");
  }
  else{
    Vector result = *this;
    for(int i=1;i<=_dimension;i++){
      result.at(i)+=u.at(i);
    }
    return result;
  }
}

int Vector::dim() const{
  return _dimension;
}

double & Vector::at(int index) const{
  return _contents[index - 1];
}

double Vector::length() const{
  double result=0;
  for(int i=0;i<_dimension;i++){
    result+=_contents[i]*_contents[i];
  }
  result=sqrt(result);
  return result;
}

double Vector::dot(Vector input){
  double d = 0;
  for(int i=0 ; i<_dimension ; i++){
    d += _contents[i]*input.at(i+1);
  }
  return d;
}

double Vector::angle(Vector input){
  double sum1=0,sum2=0;
  sum1 = this->dot(input);
  sum2 = this->length() * input.length();
  if(this->larger180(input)){
    return 360-acos(sum1/sum2)*180/M_PI;
  }
  return acos(sum1/sum2)*180/M_PI;
}

bool Vector::larger180(Vector input){
  return (this->at(1)*input.at(2) - this->at(2)*input.at(1))>=0;
}

double Vector::slope(Vector input){
  return (this->at(2)+input.at(2))/(this->at(1)+input.at(1));
}

bool Vector::VectorsInline(Vector u, Vector v){
  return this->slope(u) == u.slope(v);
}
