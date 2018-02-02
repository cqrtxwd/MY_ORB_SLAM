#include<System.h>

System::System()
{
  mpMap=new Map();
}

void System::startTracking(cv::Mat imageLeft,cv::Mat imageRight,double timeStamp)
{
  cout<<"Now the slam system start working on: "<<timeStamp<<endl;
  //create a new frame
  mpcurrentFrame=createFrame(imageLeft,imageRight,timeStamp);
  //cout<<mpcurrentFrame->mtimeStamp<<"ok"<<endl;
  mpcurrentFrame->computeORB();
  mpcurrentFrame->findMatch();
  mpcurrentFrame->drawMatch();

  //create KeyFrame:
  //check if need a new KF, if yes,create a KF from currentFrame
  //if(needNewKF())
  if((mpcurrentFrame->id)%5==1) //add a KF every 5 frame(for now)
  {
    mprefKeyFrame=createKF();
    mpMap->mpcurrentKeyFrame=mprefKeyFrame;//pass the KF pointer to Map
    mprefKeyFrame->findDepth();
    //generate MapPoints to Map from this KeyFrame
    generateMapPointstoMap();
    //cout<<mpMap->mvMapPoint.size()<<" MapPoints are in this Map now"<<endl;
    
    delete mprefKeyFrame;
  }
  // release memory;
  delete mpcurrentFrame;
};

Frame* System::createFrame(cv::Mat imageLeft, cv::Mat imageRight, double timeStamp)
{
  return new Frame(imageLeft,imageRight,timeStamp);
}

KeyFrame* System::createKF()
{
  return new KeyFrame(mpcurrentFrame);
}

void System::generateMapPointstoMap()
{
  //Function usage:
  //gennerate all the point detected in currentKF to Map
  for(Vector3d v:mprefKeyFrame->mvPointsSterero)
    mpMap->addMapPoint(new MapPoint(v));
}




