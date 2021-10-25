#ifndef Vector_h
#define Vector_h

#include<iostream>
#include<cmath>

class Vector3D{
 public:
  //constructors
  Vector3D(){//defining empty costructor
    Cx_=0.; Cy_=0.; Cz_=0.;
    Smod_=0.; Stheta_=0.; Sphi_=0.;
  };
  Vector3D(double x, double y, double z);
  static Vector3D Cartesian(double x, double y, double z);//constructor vector in cartesian coordinates
  static Vector3D Spherical(double mod, double theta, double phi);//constructor vector in spherical coordinates
  Vector3D(const Vector3D& vec); //redefining a vector from a vector

  //getters

  double x() const;
  double y() const;
  double z() const;
  double magnitude() const;
  double theta() const;
  double phi() const;
  


 private:
  double Cx_;
  double Cy_;
  double Cz_;
  double Smod_;
  double Stheta_;
  double Sphi_;
  Vector3D vec_(double x, double y, double z){Cx_=x; Cy_=y; Cz_=z;}

};



#endif
