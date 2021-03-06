#include "Complex.h"

//constructors

Complex::Complex(double x, double y){
  pRe_=x; pIm_=y;
  Mod_=Complex::mag(); Theta_=Complex::phase();
}
Complex Complex::Complex::Cartesian(double x, double y){
  return Complex(x,y);
}
Complex Complex::Complex::Polar(double mod, double theta){

  double pre_=mod*cos(theta); double pim_=mod*sin(theta);
  return Complex(pre_,pim_);
}

Complex::Complex(const Complex& comp){
  pRe_=comp.pRe_; pIm_=comp.pIm_;
  Mod_=comp.Mod_; Theta_=comp.Theta_;
}
//getters
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
    return 0.;
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
//print overloading
void Complex::print() const{
  using namespace std;
  cout<<"The complex number is:  "<<pRe_<<"  +  "<<pIm_<< " i "<<endl;
  cout<<"Its modulus and phase are:   "<<Mod_<<"   "<<Theta_<<endl;
}

//setters
void Complex::setComplex(const Complex& comp){
 pRe_=comp.pRe_; pIm_=comp.pIm_;
  Mod_=comp.Mod_; Theta_=comp.Theta_;
}


void Complex::setRe(const double re){
  pRe_=re;
  // if(pIm_=!0.){
  //Mod_=Complex::mag(); Theta_=Complex::phase();
  //}
}
void Complex::setIm(const double im){
  pIm_=im;
  // if(pRe=!0.){
  //Mod_=Complex::mag(); Theta_=Complex::phase();
  //}
}

void Complex::setMag(const double mag){
  Mod_=mag;
}

void Complex::setPhase(const double phase){
  Theta_=phase;
}

//operator overloading for two complex numbers



Complex Complex::opplus(const Complex& c1){
  double pre= pRe_+c1.pRe_;
  double pim= pIm_+c1.pIm_;
  return Cartesian(pre,pim);
}

Complex Complex::opmin(const Complex& c1){
  double pre= pRe_-c1.pRe_;
  double pim= pIm_-c1.pIm_;
  return Cartesian(pre,pim);
}

Complex Complex::optimes(const Complex& c1){
  double pre= pRe_*c1.pRe_-pIm_*c1.pIm_;
  double pim= pRe_*c1.pIm_+pIm_*c1.pRe_;
  return Cartesian(pre,pim);
}

Complex Complex::opdivide(const Complex& c1){
  double pre= (pRe_*c1.pRe_+pIm_*c1.pIm_)/(c1.Mod_*c1.Mod_);
  double pim= (pRe_*c1.pIm_-pIm_*c1.pRe_)/(c1.Mod_*c1.Mod_);
  return Cartesian(pre,pim);
}

//operator overloading for a complex number and a double


Complex Complex::opplus(const double& num){
  double pre= pRe_+ num;
  return Cartesian(pre,pIm_);
}

Complex Complex::opmin(const double& num){
  double pre= pRe_- num;
  return Cartesian(pre,pIm_);
}
Complex Complex::optimes(const double& num){
  double pre= pRe_*num;
  double pim=pIm_*num;
  return Cartesian(pre,pim);
}
Complex Complex::opdivide(const double& num){
  double pre= pRe_/num;
  double pim=pIm_/num;
  return Cartesian(pre,pim);
}

//overloading equal (=) operators
bool Complex::opeqq(const Complex& c1){
  if(pRe_==c1.pRe_ && pIm_==c1.pIm_ ){
    return true;
  }
  else{return false;}
}

void Complex::oppluseq(const Complex& c1){
  Complex::setComplex(Complex::opplus(c1));
  
}

void Complex::opmineq(const Complex& c1){
 Complex::setComplex(Complex::opmin(c1));
}

void Complex::optimeseq(const Complex& c1){
 Complex::setComplex(Complex::optimes(c1));

}

void Complex::opdivideq(const Complex& c1){
  Complex::setComplex(Complex::opdivide(c1));

}
