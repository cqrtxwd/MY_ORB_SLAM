#ifndef CAMERA_H
#define CAMERA_H

#include<iostream>
#include<opencv2/opencv.hpp>
#include<eigen3/Eigen/Geometry>
#include<sophus/so3.h>
#include<sophus/se3.h>
using namespace std;

class Camera
{
public:
  //camera parameters
  double _fx=458.654;
  double _fy=457.296;
  double _cx=367.215;
  double _cy=248.375;
  //double _depth=1;
  
  //constructor
  Camera();
  Camera(double fx,double fy,double cx,double cy,double depth):_fx(fx),_fy(fy),_cx(cx),_cy(cy){}
  
  
  
private:
  
};

#endif