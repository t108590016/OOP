#include <cmath>
#ifndef VECTOR
#define VECTOR
class  mathVector{

  private:
    double * _vector;
    int _dim;
  public:
    mathVector(double * a, int dim){ //constructor
      _dim=dim;
      _vector = new double [_dim];
      for(int i=0; i<dim ;i++){
        _vector[i]=a[i];
      }
    }
    double component(int p){
      return _vector[p-1];
    }
    bool isZero(){
      bool result = true;
      for(int i=0;i<_dim;i++){
        if(_vector[i]!=0){
          result = false;
          break;
        }
      }
      return result;
    }
    double length() const{
      double _result=0;
      for(int i=0;i<_dim;i++){
        _result+=_vector[i]*_vector[i];
      }
      return sqrt(_result);
    }
    int dimension() const{
      return _dim;
    }
    ~mathVector(){
      if(_vector != NULL){
        delete [] _vector;
      }
    }
};
#endif
