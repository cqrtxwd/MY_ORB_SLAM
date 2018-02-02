# Eigen
include_directories( "/usr/include/eigen3" )
# OpenCV
find_package( OpenCV 3.3 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Sophus 
find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )


#将自己的cpp库建成库，并且链接相应的第三方库
add_library(my_slam_lib 
Frame.cpp
KeyFrame.cpp
Camera.cpp
System.cpp
MapPoint.cpp
Map.cpp
Veiwer.cpp
)

target_link_libraries(my_slam_lib ${OpenCV_LIBS})


add_executable(my_slam_test test.cpp)
target_link_libraries(my_slam_test my_slam_lib)
