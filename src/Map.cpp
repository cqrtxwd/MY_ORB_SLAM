#include<Map.h>

Map::Map()
{

}

void Map::addMapPoint(MapPoint* pMP)
{
  mvMapPoint.push_back(*pMP);
}
