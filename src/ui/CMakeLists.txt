cmake_minimum_required(VERSION 3.0.2)
project(ui)
##
##
##
##
## ----Qt6 FOLDERINIZ NEREDEYSE ONE GÖRE MODİFİYE ETMENİZ GEREKİYOR---- ###
###########################################################################
                                                                        ###
set(Qt6_DIR "/home/abdullahbilici/Qt/6.4.3/gcc_64/lib/cmake/Qt6/")      ###
                                                                        ### 
###########################################################################
##
##
##
##
##

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Widgets Gui Qml)

catkin_package(CATKIN_DEPENDS roscpp rospy std_msgs)

include_directories(${catkin_INCLUDE_DIRS}) 

add_executable(app src/app.cpp)

target_link_libraries(app
  ${catkin_LIBRARIES}
  Qt6::Core
  Qt6::Widgets
  Qt6::Gui
  Qt6::Qml
  Qt6::Quick
)

catkin_install_python(PROGRAMS
  src/hello_world_pub.py
  src/num1_pub.py
  src/num2_pub.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
