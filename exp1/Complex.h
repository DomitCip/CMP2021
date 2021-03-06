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
  Complex(double x, double y);
  static  Complex Cartesian(double x, double y); //general constructor for complex in cartesian coords
  static Complex Polar(double mod, double theta);// general constructor for complex in polar coords
  Complex(const Complex& comp); //redefining a complex from a complex 

  //getters
  double re() const; //<-get real part
  double im() const; //<-get immaginary part 
  double mag() const; //<-get magnitude
  double phase() const;//<-get phase
  double r() const;  
  double phi() const;//^rinse and repeat
  
  void print() const; //<- cout overloading for complex numbers
  //setters

  void setComplex(const Complex& comp);
  void setRe(const double re);
  void setIm(const double im);
  void setMag(const double mag);
  void setPhase(const double phase);
  //operator overloading for two complex numbers

  Complex opplus(const Complex& c1); //plus
  Complex opmin(const Complex& c1); //minus
  Complex optimes(const Complex& c1);//times
  Complex opdivide(const Complex& c1);// divide
  //operator overloading for complex number and double
  Complex opplus(const double& num); //plus
  Complex opmin(const double& num); //minus
  Complex optimes(const double& num);//times
  Complex opdivide(const double& num);// divide

  //overloading equal (=) operators
  bool opeqq(const Complex& c1); //<- this is a Boolean operator gives back true or false
  void oppluseq(const Complex& c1);
  void opmineq(const Complex& c1);
  void optimeseq(const Complex& c1);
  void opdivideq(const Complex& c1);
  
 private:
  double pRe_;
  double pIm_;
  double Mod_;
  double Theta_;
  Complex Comp_(double x, double y);
};

#endif
