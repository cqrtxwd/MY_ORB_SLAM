#include<KeyFrame.h>

int KeyFrame::id=0;

KeyFrame::KeyFrame()
{
  cout<<"class KeyFrame works fine"<<endl;
}


KeyFrame::KeyFrame(Frame* pF):mtimeStamp(pF->mtimeStamp),mimageLeft(pF->mimageLeft),mimageRight(pF->mimageRight),
mposeLeft(pF->mposeLeft),mposeRight(pF->mposeRight),mvkpsLeft(pF->mvkpsLeft),mvkpsRight(pF->mvkpsRight),
mdiscriptorLeft(pF->mdiscriptorLeft),mdiscriptorRight(pF->mdiscriptorRight),mvMatches(pF->mvMatches)
{
  id++;
  cout<<"a new KF was created,its id is "<<id<<endl;
  
}

void KeyFrame::findDepth()
{
  //baseline=0.11 ,no rotation between 2 camera,fx,fy,cx,cy=458.654, 457.296, 367.215, 248.375
  Mat K=(Mat_<double>(3,3)<<
  458.654,0,367.215,
  0,457.296,248.375,
  0,0,1 );
  
  Mat T1=(Mat_<double>(3,4)<<
    1,0,0,0,
    0,1,0,0,
    0,0,1,0
  );
  
  Mat T2=(Mat_<double>(3,4)<<
    1,0,0,0.11,
    0,1,0,0,
    0,0,1,0
  );
 
  
  //get all the pixel cordinates,stored in 2 vector
  vector<Point2d> vpointLeft,vpointRight;
  for(DMatch m:mvMatches)
  {
    vpointLeft.push_back(Pixel2Cam(mvkpsLeft[m.queryIdx].pt,K));
    vpointRight.push_back(Pixel2Cam(mvkpsRight[m.trainIdx].pt,K));
  }
  
  //trianguate
  Mat points_coordinate;
  triangulatePoints(T1,T2,vpointLeft,vpointRight,points_coordinate);
  cout<<"trianulate done"<<endl<<points_coordinate<<endl;
  cout<<points_coordinate.cols<<endl;
  for(int i=0;i<points_coordinate.cols;i++)
  {
    Mat temp=points_coordinate.col(i);
    mvPointsSterero.push_back
    (
      Vector3d
      (
	temp.at<double>(0,0),
       temp.at<double>(0,1),
       temp.at<double>(0,2)
      )
    );
  }
  

}

Point2d Pixel2Cam(Point2d p,Mat K)
{
  return Point2d
  (
    (p.x-K.at<double>(0,2))/K.at<double>(0,0),
    (p.y-K.at<double>(1,2))/K.at<double>(1,1)
  );
}


