#ifndef KEYFRAME_H
#define KEYFRAME_H

#include<common_include.h>
#include<Frame.h>

class Frame;
Point2d Pixel2Cam(Point2d p,Mat K);

class KeyFrame
{
public:
  KeyFrame();
  KeyFrame(Frame* pF);
  
  //find the depth of keypoints in this frame;
  void findDepth();
  
  //compute the coordinate from pixel to camera
  friend Point2d Pixel2Cam(Point2d p,Mat K);
  
  
public:
  static int id;
  
  double mtimeStamp;
  
  //image of two eyes
  cv::Mat mimageLeft;
  cv::Mat mimageRight;
  //pose
  cv::Mat mposeLeft;
  cv::Mat mposeRight;
  
   //keypoints stored in 2 vector
  vector<cv::KeyPoint> mvkpsLeft;
  vector<cv::KeyPoint> mvkpsRight;
  
  //discriptors of left and right
  cv::Mat mdiscriptorLeft;
  cv::Mat mdiscriptorRight;
  vector<cv::DMatch> mvMatches;
  
  //number of paired point
  int nPairedCount;
  
  //coordinate of Paired points in this keyframe
  vector<Vector3d> mvPointsSterero;
  
  
private:
  
};

#endif