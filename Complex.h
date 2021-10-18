#ifndef Complex_h
#define Complex_h

#include<iostream>
#include<cmath>

class Complex{
 public:
  Complex(){
    pRe_=0.; pIm_=0.;   //defining an empty constructor
    Mod_=0.; Theta_=0.;
  };
 static  Complex Cartesian(double x, double y); //general constructor for complex in cartesian coords
  static Complex Polar(double mod, double theta);// general constructor for complex in polar coords
  Complex(const Complex& comp); //redefining a complex from a complex 
  double re(){return pRe_;} const; //<-get real part
  double im(){return pIm_;} const; //<-get immaginary part 
  double mag() const; //<-get magnitude
  double phase() const;//<-get phase
  double r() const;  
  double phi() const;//^rinse and repeat
  void print() const; //<- cout overloading for complex numbers
  void setRe(const double ) const;//various setters for real and imaginary parts
  void setIm() const;
  void setmag() const;
  void setphase() const;
  
 private:
  double pRe_;
  double pIm_;
  double Mod_;
  double Theta_;
