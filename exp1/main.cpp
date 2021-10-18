#include"Complex.h"

int main(){
  Complex c1(3, 2);
  Complex c2=Complex::Polar(4,0.5);
  Complex c3=c1.opmin(c2);
  Complex c4=c1.optimes(c2);
  Complex c5=c1.opdivide(c2);
  Complex c6=Complex(c5);
  c1.print();  
  c1.opmineq(c2);
  c1.print();

  c3.print();
  //c6.print();
  //c5.print();
  return 0;
}
