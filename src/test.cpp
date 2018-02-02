#include<iostream>
#include<Frame.h>
#include<KeyFrame.h>
#include<Camera.h>
#include<System.h>

#include<fstream>
using namespace std;
using namespace cv;

int main()
{
  //test
  Frame frame1;
  KeyFrame KF1;
  Camera camera;
  cout<<"hello"<<endl;
  
  //load images
  /*
  string imageLeftPath="/home/cqr/MH_01_easy/mav0/cam0/data";
  string imageRightPath="/home/cqr/MH_01_easy/mav0/cam1/data";
  string timeStampPath="/home/cqr/my_slam/MH01.txt";
  */
  
  string imageLeftPath="/home/cqr/my_slam/test_data/cam0";
  string imageRightPath="/home/cqr/my_slam/test_data/cam1";
  string timeStampPath="/home/cqr/my_slam/test_data/test_timestamp.txt";
  
  
  vector<string> vimageLeftNames;
  vector<string> vimageRightNames;
  vector<double> vimageTimeStamp;
  
  ifstream fin(timeStampPath);
  if(!fin)
  {
    cout<<"read no file,please check the file path!!!!!!!"<<endl;
    return 1;
  }
  else
  {
    cout<<"read done"<<endl;
  }
  while(!fin.eof())
  {
    string s;
    fin>>s;
    vimageLeftNames.push_back(imageLeftPath+"/"+s+".png");
    vimageRightNames.push_back(imageRightPath+"/"+s+".png");
    stringstream ss;
    ss<<s;
    double t;
    ss>>t;
    vimageTimeStamp.push_back(t/1e9);
    //cout<<t/1e9<<endl;
  }
  int nImages=vimageTimeStamp.size()-1;
  cout<<"finish loading"<<endl;
  //main loop
  System SLAM;
  for(int i=0;i<nImages;i++)
  {
    Mat img_left=imread(vimageLeftNames[i]);
    Mat img_right=imread(vimageRightNames[i]);
    double timestamp=vimageTimeStamp[i];
    if(img_left.empty()||img_right.empty())
    {
      cout<<"image load fail!!!!"<<endl;
      return -1;
    }
    
    // input the image to the main function,to process the image,trackng;
    
    SLAM.startTracking(img_left,img_right,timestamp);
    
    

  }
  

  cout<<nImages<<" pictures"<<endl;
  
  cout<<"all done, quitting"<<endl;
  
  
}