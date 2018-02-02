#ifndef MAPPOINT_H
#define MAPPOINT_H

#include<common_include.h>
#include<Frame.h>
class Frame;

class MapPoint 
{
public:
  //constructor
  MapPoint();
  MapPoint(Vector3d pos);
  MapPoint(double x,double y,double z);
  
  
  bool bisGood();
  
public:
  static long int id;
  long int mFirstFrameId;
  int mFirstKFId;
  Vector3d mPos;
  bool bisOptimized=0;
  list<Frame*> mlObservedFrame;
  

};







#endif