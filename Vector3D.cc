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

double Vector3D::x() const{return Cx_;}

double Vector3D::y() const{return Cy_;}

double Vector3D::z() const{return Cz_;}

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

//printing a vector

void Vector3D::print() const{
  using namespace std;
  cout<<"the vector components are("<<Cx_<<", "<<Cy_<< ",  "<<Cz_<<")"<<endl;
  cout<<"Its modulus, phi and theta are:"<<Smod_<<", "<<Sphi_<<", "<<Stheta_<<endl;
}

//setters

void Vector3D::setVector3D(const Vector3D& vec){
  Cx_=vec.Cx_; Cy_=vec.Cy_; Cz_=vec.Cz_;
  Smod_=vec.Smod_; Stheta_=vec.Stheta_; Sphi_=vec.Sphi_;}

void Vector3D::setx(const double x){Cx_=x;}

void Vector3D::sety(const double y){Cy_=y;}

void Vector3D::setz(const double z){Cz_=z;}

void Vector3D::setmod(const double mod){Smod_=mod;}

void Vector3D::settheta(const double theta){Stheta_=theta;}

void Vector3D::setphi(const double phi){ Sphi_=phi;}

 //implementing functions scalarProduct(), vectorProduct() and angle()

double Vector3D::scalarProduct(const Vector3D& v1) const{
  double scalar=Cx_*v1.Cx_+Cy_*v1.Cy_+Cz_*v1.Cz_;
  return scalar;
}

double Vector3D::angle(const Vector3D& v1) const{
  double angle=acos((Vector3D::scalarProduct(v1))/(Smod_*v1.Smod_));
    return angle;
}

Vector3D& Vector3D::operator=(const Vector3D& v1){
  Cx_=v1.Cx_;
  Cy_=v1.Cy_;
  Cz_=v1.Cz_;
  return *this;
}

Vector3D vectorProduct(const Vector3D& v1,  const Vector3D& v2){
  double X=v1.y()*v2.z()-v1.z()*v2.y();
  double Y=v1.z()*v2.x()-v1.x()*v2.z();
  double Z=v1.x()*v2.y()-v1.y()*v2.x();
  Vector3D v(X,Y,Z);
  return v;
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2){
  double X=v1.x()+v2.x();
  double Y=v1.y()+v2.y();
  double Z=v1.z()+v2.z();
  Vector3D v(X,Y,Z);
  return v;
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2){
  double X=v1.x()-v2.x();
  double Y=v1.y()-v2.y();
  double Z=v1.z()-v2.z();
  Vector3D v(X,Y,Z);
  return v;
}

Vector3D operator*(const Vector3D& v1, double v2){
  double X=v1.x()*v2;
  double Y=v1.y()*v2;
  double Z=v1.z()*v2;
  Vector3D v(X,Y,Z);
  return v;
}
Vector3D operator/(const Vector3D& v1, double v2){
  double X=v1.x()/v2;
  double Y=v1.y()/v2;
  double Z=v1.z()/v2;
  Vector3D v(X,Y,Z);
  return v;
}
