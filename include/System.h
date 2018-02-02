#ifndef SYSTEM_H
#define SYSTEM_H

#include<common_include.h>

#include<Frame.h>
#include<KeyFrame.h>
#include<Map.h>
class Map;
class System 
{
public:
  //constructor
  System();
    //start tracking base on the images from camera
    void startTracking(cv::Mat imageLeft,cv::Mat imageRight,double timeStamp);
    Frame* createFrame(cv::Mat imageLeft,cv::Mat imageRight,double timeStamp);
    KeyFrame* createKF();
    void generateMapPointstoMap();

    

public:
  Frame* mpcurrentFrame;
  KeyFrame* mprefKeyFrame;
  Map* mpMap;
  


};



#endif

