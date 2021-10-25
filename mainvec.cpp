#include <iostream>
#include "Vector3D.h"
using namespace std;

int main(){
  Vector3D v(3.,2.,4.);
  Vector3D c(2.,6.,5.);
  Vector3D f(0.,0.,0.);
  double t=0.;
  double a=v.angle(c);
  
  cout<<"vector v"<<endl;
  v.print();
  cout<<"vector c"<<endl;
  c.print();
  t=v.scalarProduct(c);
  cout<<"f=v^c"<<endl;
  cout<<t<<endl;
  f=vectorProduct(v,c);
  cout<<"f=vxc"<<endl;
  f.print();
  f=vectorProduct(c,v);
  cout<<"f=cxv"<<endl;
  f.print();
  f=vectorProduct(c,v);
  cout<<"f=vxc"<<endl;
  f.print();
  Vector3D d=f;
  cout<<"d=f"<<endl;
  f.print();
  cout<<"angle between v&c"<<endl;
  cout<<a<<endl;
  f=v+c;
  cout<<"f=v+c"<<endl;
  f.print();
  f=v-c;
  cout<<"f=v-c"<<endl;
  f.print();
  f=v*2;
  cout<<"f=v*2"<<endl;
  f.print();
  f=c/2;
  cout<<"f=c/2"<<endl;
  f.print();

  return 0;
}
