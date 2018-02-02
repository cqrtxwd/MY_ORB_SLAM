#include<MapPoint.h>

long int MapPoint::id=0;

MapPoint::MapPoint()
{
  id++;
}


MapPoint::MapPoint(Vector3d pos):mPos(pos)
{
  id++;
}

MapPoint::MapPoint(double x, double y, double z)
{
  mPos=Vector3d(x,y,z);
  id++;
}

