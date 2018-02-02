#ifndef MAP_H
#define MAP_H
#include<common_include.h>
#include<MapPoint.h>
#include<KeyFrame.h>

class Map 
{
public:
  Map();
  
public:
  long int mnMapPointCount;
  
  KeyFrame* mpcurrentKeyFrame;
  
  //all the MapPoint,
  vector<MapPoint> mvMapPoint;
  
  //all the KeyFrame
  vector<KeyFrame> mvKeyFrame;
  
  //add a MapPoint
  void addMapPoint(MapPoint* pMP);
  
  //add a KeyFrame
  void addKeyFrame(KeyFrame* pKF);
  

};

#endif