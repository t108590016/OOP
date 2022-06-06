#include "term.h"
#include <iostream>
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_


class Polynomial{
  private:
    Term* _terms;
    int _degree;

  public:

    Polynomial(Term terms[], int degree){
      if(terms != NULL){
        _terms = new Term [degree];
        for(int i=0;i<=degree;i++){
          _terms[i]=terms[i];
        }
        _degree=degree;
      }
    }

    Polynomial(Polynomial const &p){
      _terms = new Term [p.getDegree()];
      if(p._terms != NULL){
        int count=0;
        for(int i=0;i<=p.getDegree();i++){
          if(p.getTermByExponent(i).getCoefficient()!=0){
              _terms[count]=p.getTermByExponent(i);
              count++;
          }
        }
        _degree=p.getDegree();
      }
    }
    /*
    bool isNULL(){
      if(terms==NULL){
        retrun true;
      }
      return false;
    }
    */
    ~Polynomial(){
      if(_terms != NULL) {
        delete [] _terms;
      }
    }

    Term getTermByExponent(int ex) const{
      for(int i=0;i<=_degree;i++){
        if(_terms[i].getExponent()==ex){
          return _terms[i];
        }
      }
      Term t=Term(0,ex);
      return t;
    }

    Polynomial operator + (const Polynomial &p){
      int d=0;
      if(_degree>p.getDegree()){
        d=_degree;
      }
      else{
        d=p.getDegree();
      }
      int i=d;
      Term terms[i];
      int count=0;
      while(i>=0){
        Term term = Term(getTermByExponent(i).getCoefficient()+p.getTermByExponent(i).getCoefficient(),i);
        if (term.getCoefficient()!=0){
          terms[count]=term;
          count++;
        }
        i--;

      }
      Polynomial result = Polynomial(terms,d);
      return result;
    }

    double evaluate(double base){ //將x以數字取代
      double result=0;
      for(int i=0;i<_degree;i++){
        result+=_terms[i].evaluate(base);
      }
      return result;
    }

    int getDegree() const{
      return _degree;
    }

    Polynomial operator = (Polynomial input){
      //printf("copy assignment \n");
      if(_terms != NULL) {
        delete [] _terms;
      }
      _degree = input._degree;
      Term* _terms;
      int count=0;
      _terms = new Term [_degree];
      for(int i=0;i<=_degree;i++){
        Term t= Term(input.getTermByExponent(i).getCoefficient(),i);
        if(t.getCoefficient()!=0){
          _terms[count] = input.getTermByExponent(i);
          count+=1;
        }
      }
      return *this; // we will discuss more abuot this
    }
};
#endif
