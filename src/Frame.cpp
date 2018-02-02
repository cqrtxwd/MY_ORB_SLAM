#include"Frame.h"

int Frame::id=0;

//constructors
Frame::Frame()
{
  cout<<"test: Frame class works fine"<<endl;
}

Frame::Frame(cv::Mat imageLeft,cv::Mat imageRight,double timeStamp):mimageLeft(imageLeft),mimageRight(imageRight),mtimeStamp(timeStamp){id++;};


void Frame::computeORB()
{
  morbExtractor=ORB::create();
  morbExtractor->detectAndCompute(mimageLeft,Mat(),mvkpsLeft,mdiscriptorLeft,0);
  morbExtractor->detectAndCompute(mimageRight,Mat(),mvkpsRight,mdiscriptorRight,0);
  //morbExtractor->detect(mimageLeft,mvkpsLeft);
  //morbExtractor->compute(mimageLeft,mvkpsLeft,mdiscriptorLeft);
  //morbExtractor->detect(mimageRight,mvkpsRight);
  //morbExtractor->compute(mimageRight,mvkpsRight,mdiscriptorRight);
  
  cout<<"Frame "<<id<<" orb computting done"<<endl;
}

void Frame::findMatch()
{
  //brute force method
  vector<DMatch> vtempMatches;
  BFMatcher matcher(NORM_HAMMING);
  matcher.match(mdiscriptorLeft,mdiscriptorRight,vtempMatches);
  
  //find good matches,delete the wrong matches
  double min_distance=100000,max_distance=0;
  for(int i=0;i<vtempMatches.size();i++)
  {
    double dist=vtempMatches[i].distance;
    if(dist<min_distance) min_distance=dist; 
    if(dist>max_distance) max_distance=dist;   
  }
  
  for(int i=0;i<vtempMatches.size();i++)
  {
    if(vtempMatches[i].distance<max(2*min_distance,30.0))
      if(abs(mvkpsLeft[vtempMatches[i].queryIdx].pt.y-mvkpsRight[vtempMatches[i].trainIdx].pt.y)<30)
      {
	mvMatches.push_back(vtempMatches[i]);
	mvPairedkpsLeft.push_back(mvkpsLeft[vtempMatches[i].queryIdx]);
	mvPairedkpsRight.push_back(mvkpsRight[vtempMatches[i].trainIdx]);
      }
  } 
  cout<<"Frame "<<id<<" keypoints matching done,"<<endl<<mvMatches.size()<<" pair matched points totally"<<endl;
  
}

void Frame::drawMatch()
{
  Mat imageMatches;
  drawMatches(mimageLeft,mvkpsLeft,mimageRight,mvkpsRight,mvMatches,imageMatches);
  imshow("orb feature points",imageMatches);
  waitKey(1);
}


