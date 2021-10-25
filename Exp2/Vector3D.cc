#include "Vector3D.h"
using namespace std;

//constructors

Vector3D::Vector3D(double x, double y, double z){
  Cx_=x; Cy_=y; Cz_=z;
  Smod_=Vector3D::magnitude(); Stheta_=Vector3D::theta(); Sphi_=Vector3D::phi();
}

 Vector3D Vector3D::Vector3D::Cartesian(double x, double y, double z){
   return Vector3D(x,y,z);
}

Vector3D Vector3D::Vector3D::Spherical(double mod, double theta, double phi){
  double cx_=mod*cos(theta)*sin(phi);
  double cy_=mod*sin(theta)*sin(phi);
  double cz_=mod*cos(phi);
  return Vector3D(cx_,cy_,cz_);
}

Vector3D::Vector3D(const Vector3D& vec){
  Cx_=vec.Cx_; Cy_=vec.Cy_; Cz_=vec.Cz_;
  Smod_=vec.Smod_; Stheta_=vec.Stheta_; Sphi_=vec.Sphi_;
}

//getters

double Vector3D::x() const{return Smod_*cos(Stheta_)*sin(Sphi_);}
double Vector3D::y() const{return Smod_*sin(Stheta_)*sin(Sphi_);}
double Vector3D::z() const{return Smod_*sin(Sphi_);}
double Vector3D::magnitude() const{return sqrt(Cx_*Cx_+Cy_*Cy_+Cz_*Cz_);}
double Vector3D::theta() const{
  using namespace std;
  if(Cx_==0.&& Cy_>0.){return M_PI/2;}
  else if(Cx_==0.&& Cy_<0.){return 3*M_PI/2;}
  else if(Cx_==0.&& Cy_==0.){ cout<<"Attention: theta is not defined for a vector with no projection on xy plane"<< endl;  return 0.;}
  else{return (atan(Cy_/Cx_));}
}
double Vector3D::phi() const{
  if(Cx_==0.&& Cy_==0.&& Cz_==0.){
    cout<<"Attention: angle phi is not defined for a null vector."<< endl;
    return 0;
  }
  else{ return (acos(Cz_/sqrt(Cx_*Cx_+Cy_*Cy_+Cz_*Cz_)));
		}
    }
