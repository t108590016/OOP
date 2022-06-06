#include <string>
#ifndef DOT
#define DOT

using namespace std;

double dot(double *a, int len1, double *b, int len2){
  int result = 0;
  if(len1!=len2){
    throw string("undefined!");
  }
  else{
    for(int i=0;i<len1;i++){
      result += a[i]*b[i];
    }
  }
  return result;
}
#endif
