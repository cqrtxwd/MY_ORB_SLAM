#ifndef FRAME_H
#define FRAME_H

#include<common_include.h>
#include<KeyFrame.h>

class KeyFrame;

class Frame
{
public:
  //constructor
  Frame();
  Frame(cv::Mat imageLeft,cv::Mat imageRight,double timeStamp);
  
  //id of this frame
  static int id;
  
  double mtimeStamp;
  
  //image of two eyes
  cv::Mat mimageLeft;
  cv::Mat mimageRight;
  
  //orb exetractor
  cv::Ptr<cv::ORB> morbExtractor;
  
  //pose of camera,left and right
  cv::Mat mposeLeft;
  cv::Mat mposeRight;
  
  //if this frame is a KeyFrame
  bool isKeyFrame=0;
  
  //total number of keypoints if this frame
  int mkeypointCount;
  
  //keypoints stored in 2 vector
  vector<cv::KeyPoint> mvkpsLeft;
  vector<cv::KeyPoint> mvkpsRight;
  
  //matched KeyPoints in 2 vector
  vector<KeyPoint> mvPairedkpsLeft;
  vector<KeyPoint> mvPairedkpsRight;
  
  //discriptors of left and right
  cv::Mat mdiscriptorLeft;
  cv::Mat mdiscriptorRight;
  vector<cv::DMatch> mvMatches;
  
  KeyFrame* mrefferenceKeyFrame;
  
  //functions
  //rectiify the images
  void rectImage();
  
  //compute the orb keypoints
  void computeORB();
  
  //match the keypoints of left image and right image
  void findMatch();
  
  //draw the matched points,and show them
  void drawMatch();
  
  
private:
  
};

#endif