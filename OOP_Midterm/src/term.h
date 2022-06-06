#ifndef _TERM_H_
#define _TERM_H_


class Term{
  private:
    double _coefficient;
    int _exponent;
  public:
    Term(){
      _coefficient=0;
      _exponent=0;
    }
    Term(double t, int d){
      _coefficient = t;
      _exponent = d;
    }


    Term operator = (Term const &input){
       _coefficient=input.getCoefficient();
       _exponent=input.getExponent();
      return *this;
    }

    Term operator + (Term const &input){
      if(_exponent!=input.getExponent()){
          throw ("Exponent is different!");
      }
      else{
        Term result=Term(_coefficient+input.getCoefficient(),_exponent);
        return result;
      }
    }

    Term operator - (Term const &input){
      if(_exponent!=input.getExponent()){
          throw ("Exponent is different!");
      }
      else{
        Term result=Term(_coefficient-input.getCoefficient(),_exponent);
        return result;
      }
    }
    Term operator * (Term const &input){
      Term result=Term(_coefficient*input.getCoefficient(),_exponent*input.getExponent());
      return result;
    }

    bool operator == (Term const &input){
      if(_coefficient==input.getCoefficient() && _exponent==input.getExponent()){
        return true;
      }
      else{
        return false;
      }
    }

    double getCoefficient() const{
      return _coefficient;
    }


    int getExponent() const{
      return _exponent;
    }


    double evaluate(double input){
      double result=_coefficient;
      for(int i=0;i<_exponent;i++){
        result*=input;
      }
      return result;
    }
};
#endif
