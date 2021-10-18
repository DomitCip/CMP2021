#include "Complex.h"


Complex::Cartesian(double x, double y){
  pRe_=x; pIm_=y;
  Mod_=Complex::mag(); Theta_=Complex::phase();
}
Complex::Polar(double mod, double theta){
  Mod_=mod; Theta_=theta;
  pRe_=Complex::re(); pIm_=Complex::im();
}

Complex::Complex(const Complex& comp){
  pRe=comp.pRe_; pIm_=comp.pIm_;
}

double Complex::re() const{
  return Mod_*cos(Theta_);
}
double Complex::im() const{
  return Mod_*sin(Theta_);
}

double Complex::mag() const{
  return sqrt(pRe_*pRe_+ pIm_*pIm_);
}

double Complex::phase() const{
  using namespace std;
  if(pRe_==0.&& pIm_==0.){
    cout<<"Attention: Phase not defined for a null complex number."<< endl;
  }
  else{ return(atan(pIm_/pRe_));
  }
}
double Complex::r() const{
  return Complex::mag();
}
double Complex::phi() const{
  return Complex::phase();
}

void Complex::print() const{//print overloading
  using namespace std;
  cout<<"The complex number is:  "<<pRe_<<"  +  "<<pIm_<<endl;
  cout<<"Its modulus and phase are:   "<<Mod_<<"   "<<Theta_<<endl;
}

vo
