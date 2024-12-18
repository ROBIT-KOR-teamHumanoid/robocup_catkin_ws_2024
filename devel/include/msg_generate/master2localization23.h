// Generated by gencpp from file msg_generate/master2localization23.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_MASTER2LOCALIZATION23_H
#define MSG_GENERATE_MESSAGE_MASTER2LOCALIZATION23_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace msg_generate
{
template <class ContainerAllocator>
struct master2localization23_
{
  typedef master2localization23_<ContainerAllocator> Type;

  master2localization23_()
    : goal_x(0)
    , goal_y(0)
    , target_x(0)
    , target_y(0)
    , robot_allowance_error(0)
    , robot_cali_radius(0)
    , mf_robot_x(0)
    , mf_robot_y(0)
    , mf_ball_x(0)
    , mf_ball_y(0)  {
    }
  master2localization23_(const ContainerAllocator& _alloc)
    : goal_x(0)
    , goal_y(0)
    , target_x(0)
    , target_y(0)
    , robot_allowance_error(0)
    , robot_cali_radius(0)
    , mf_robot_x(0)
    , mf_robot_y(0)
    , mf_ball_x(0)
    , mf_ball_y(0)  {
  (void)_alloc;
    }



   typedef int64_t _goal_x_type;
  _goal_x_type goal_x;

   typedef int64_t _goal_y_type;
  _goal_y_type goal_y;

   typedef int64_t _target_x_type;
  _target_x_type target_x;

   typedef int64_t _target_y_type;
  _target_y_type target_y;

   typedef int64_t _robot_allowance_error_type;
  _robot_allowance_error_type robot_allowance_error;

   typedef int64_t _robot_cali_radius_type;
  _robot_cali_radius_type robot_cali_radius;

   typedef int64_t _mf_robot_x_type;
  _mf_robot_x_type mf_robot_x;

   typedef int64_t _mf_robot_y_type;
  _mf_robot_y_type mf_robot_y;

   typedef int64_t _mf_ball_x_type;
  _mf_ball_x_type mf_ball_x;

   typedef int64_t _mf_ball_y_type;
  _mf_ball_y_type mf_ball_y;





  typedef boost::shared_ptr< ::msg_generate::master2localization23_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::master2localization23_<ContainerAllocator> const> ConstPtr;

}; // struct master2localization23_

typedef ::msg_generate::master2localization23_<std::allocator<void> > master2localization23;

typedef boost::shared_ptr< ::msg_generate::master2localization23 > master2localization23Ptr;
typedef boost::shared_ptr< ::msg_generate::master2localization23 const> master2localization23ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::master2localization23_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::master2localization23_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::master2localization23_<ContainerAllocator1> & lhs, const ::msg_generate::master2localization23_<ContainerAllocator2> & rhs)
{
  return lhs.goal_x == rhs.goal_x &&
    lhs.goal_y == rhs.goal_y &&
    lhs.target_x == rhs.target_x &&
    lhs.target_y == rhs.target_y &&
    lhs.robot_allowance_error == rhs.robot_allowance_error &&
    lhs.robot_cali_radius == rhs.robot_cali_radius &&
    lhs.mf_robot_x == rhs.mf_robot_x &&
    lhs.mf_robot_y == rhs.mf_robot_y &&
    lhs.mf_ball_x == rhs.mf_ball_x &&
    lhs.mf_ball_y == rhs.mf_ball_y;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::master2localization23_<ContainerAllocator1> & lhs, const ::msg_generate::master2localization23_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::master2localization23_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::master2localization23_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::master2localization23_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::master2localization23_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::master2localization23_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::master2localization23_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::master2localization23_<ContainerAllocator> >
{
  static const char* value()
  {
    return "be324128966108ecba95dfb7b6938f0f";
  }

  static const char* value(const ::msg_generate::master2localization23_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbe324128966108ecULL;
  static const uint64_t static_value2 = 0xba95dfb7b6938f0fULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::master2localization23_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/master2localization23";
  }

  static const char* value(const ::msg_generate::master2localization23_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::master2localization23_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 goal_x\n"
"int64 goal_y\n"
"int64 target_x\n"
"int64 target_y\n"
"int64 robot_allowance_error\n"
"int64 robot_cali_radius\n"
"int64 mf_robot_x\n"
"int64 mf_robot_y\n"
"int64 mf_ball_x\n"
"int64 mf_ball_y\n"
;
  }

  static const char* value(const ::msg_generate::master2localization23_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::master2localization23_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.goal_x);
      stream.next(m.goal_y);
      stream.next(m.target_x);
      stream.next(m.target_y);
      stream.next(m.robot_allowance_error);
      stream.next(m.robot_cali_radius);
      stream.next(m.mf_robot_x);
      stream.next(m.mf_robot_y);
      stream.next(m.mf_ball_x);
      stream.next(m.mf_ball_y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct master2localization23_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::master2localization23_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::master2localization23_<ContainerAllocator>& v)
  {
    s << indent << "goal_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.goal_x);
    s << indent << "goal_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.goal_y);
    s << indent << "target_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.target_x);
    s << indent << "target_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.target_y);
    s << indent << "robot_allowance_error: ";
    Printer<int64_t>::stream(s, indent + "  ", v.robot_allowance_error);
    s << indent << "robot_cali_radius: ";
    Printer<int64_t>::stream(s, indent + "  ", v.robot_cali_radius);
    s << indent << "mf_robot_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.mf_robot_x);
    s << indent << "mf_robot_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.mf_robot_y);
    s << indent << "mf_ball_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.mf_ball_x);
    s << indent << "mf_ball_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.mf_ball_y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_MASTER2LOCALIZATION23_H
