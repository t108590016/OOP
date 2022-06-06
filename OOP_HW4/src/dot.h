#include <string>
#ifndef DOT
#define DOT

using namespace std;

double dot(double *u, int dim_u, double *v, int dim_v){
  int result = 0;
  if(dim_u!=dim_v){
    throw string("undefined");
  }
  else{
    for(int i=0;i<dim_u;i++){
      result += u[i]*v[i];
    }
  }
  return result;
}
#endif
