# Install script for directory: /home/robit/catkin_ws/src/msg_generate

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/robit/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/msg_generate/msg" TYPE FILE FILES
    "/home/robit/catkin_ws/src/msg_generate/msg/pan_tilt_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/imu_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/motion_end.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/serial_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Motor_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/motionNum_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/ikcoordinate_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/position_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/ik_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/robocup23_master2udp.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/ikend_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/yaw_set.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/support_onestep_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Mt2Serial_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/tune2walk.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/zmp_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/localization_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/robocupcontroller.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/robocupvision.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/udp_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/udp_order.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/eom_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/angle2.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/wheel_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Motion_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Step_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Running_2020_vision.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/motion_stop.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Local_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Local_Info.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/scv_vision.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/walk_pattern.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/kuro_cotton_candy.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/master2hanoi_vision2019msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Serial2LC_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/L_LC_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/R_LC_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/com_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/ik_angle_sim.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/localv2_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/motion_balance.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/udp_msg_TC_Helper.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/udp_msg_TC_Kicker.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Motor_msg_pt.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/Landing_Time_Control.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/master2vision_msg.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/game_control_data.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/game_control_return_data.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/srcirc23gcdata.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/basketball_vision23.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/running_vision23.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/motion_operator_data.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/master_2_robocup_vision23.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/robocup_vision23.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/robocup_localization23.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/robocup_vision23_feature.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/master2localization23.msg"
    "/home/robit/catkin_ws/src/msg_generate/msg/pid_tuning.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/msg_generate/cmake" TYPE FILE FILES "/home/robit/catkin_ws/build/msg_generate/catkin_generated/installspace/msg_generate-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/robit/catkin_ws/devel/include/msg_generate")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/robit/catkin_ws/devel/share/roseus/ros/msg_generate")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/robit/catkin_ws/devel/share/common-lisp/ros/msg_generate")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/robit/catkin_ws/devel/share/gennodejs/ros/msg_generate")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/robit/catkin_ws/devel/lib/python2.7/dist-packages/msg_generate")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/robit/catkin_ws/devel/lib/python2.7/dist-packages/msg_generate")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/robit/catkin_ws/build/msg_generate/catkin_generated/installspace/msg_generate.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/msg_generate/cmake" TYPE FILE FILES "/home/robit/catkin_ws/build/msg_generate/catkin_generated/installspace/msg_generate-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/msg_generate/cmake" TYPE FILE FILES
    "/home/robit/catkin_ws/build/msg_generate/catkin_generated/installspace/msg_generateConfig.cmake"
    "/home/robit/catkin_ws/build/msg_generate/catkin_generated/installspace/msg_generateConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/msg_generate" TYPE FILE FILES "/home/robit/catkin_ws/src/msg_generate/package.xml")
endif()

