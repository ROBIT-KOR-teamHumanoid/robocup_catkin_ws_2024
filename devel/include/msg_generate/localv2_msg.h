// Generated by gencpp from file msg_generate/localv2_msg.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_LOCALV2_MSG_H
#define MSG_GENERATE_MESSAGE_LOCALV2_MSG_H


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
struct localv2_msg_
{
  typedef localv2_msg_<ContainerAllocator> Type;

  localv2_msg_()
    : robot_num(0)
    , robot_case(0)
    , local_x(0)
    , local_y(0)
    , local_yaw(0)
    , ball_x(0)
    , ball_y(0)
    , ballDist(0)
    , ballTheta(0)  {
    }
  localv2_msg_(const ContainerAllocator& _alloc)
    : robot_num(0)
    , robot_case(0)
    , local_x(0)
    , local_y(0)
    , local_yaw(0)
    , ball_x(0)
    , ball_y(0)
    , ballDist(0)
    , ballTheta(0)  {
  (void)_alloc;
    }



   typedef int64_t _robot_num_type;
  _robot_num_type robot_num;

   typedef int64_t _robot_case_type;
  _robot_case_type robot_case;

   typedef int64_t _local_x_type;
  _local_x_type local_x;

   typedef int64_t _local_y_type;
  _local_y_type local_y;

   typedef int64_t _local_yaw_type;
  _local_yaw_type local_yaw;

   typedef int64_t _ball_x_type;
  _ball_x_type ball_x;

   typedef int64_t _ball_y_type;
  _ball_y_type ball_y;

   typedef int64_t _ballDist_type;
  _ballDist_type ballDist;

   typedef int64_t _ballTheta_type;
  _ballTheta_type ballTheta;





  typedef boost::shared_ptr< ::msg_generate::localv2_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::localv2_msg_<ContainerAllocator> const> ConstPtr;

}; // struct localv2_msg_

typedef ::msg_generate::localv2_msg_<std::allocator<void> > localv2_msg;

typedef boost::shared_ptr< ::msg_generate::localv2_msg > localv2_msgPtr;
typedef boost::shared_ptr< ::msg_generate::localv2_msg const> localv2_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::localv2_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::localv2_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::localv2_msg_<ContainerAllocator1> & lhs, const ::msg_generate::localv2_msg_<ContainerAllocator2> & rhs)
{
  return lhs.robot_num == rhs.robot_num &&
    lhs.robot_case == rhs.robot_case &&
    lhs.local_x == rhs.local_x &&
    lhs.local_y == rhs.local_y &&
    lhs.local_yaw == rhs.local_yaw &&
    lhs.ball_x == rhs.ball_x &&
    lhs.ball_y == rhs.ball_y &&
    lhs.ballDist == rhs.ballDist &&
    lhs.ballTheta == rhs.ballTheta;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::localv2_msg_<ContainerAllocator1> & lhs, const ::msg_generate::localv2_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::localv2_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::localv2_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::localv2_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::localv2_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::localv2_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::localv2_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::localv2_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d38b9edd3a71a67cf30bc44ca69d472a";
  }

  static const char* value(const ::msg_generate::localv2_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd38b9edd3a71a67cULL;
  static const uint64_t static_value2 = 0xf30bc44ca69d472aULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::localv2_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/localv2_msg";
  }

  static const char* value(const ::msg_generate::localv2_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::localv2_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 robot_num\n"
"int64 robot_case\n"
"\n"
"int64 local_x\n"
"int64 local_y \n"
"int64 local_yaw\n"
"\n"
"int64 ball_x\n"
"int64 ball_y\n"
"int64 ballDist\n"
"int64 ballTheta\n"
"\n"
;
  }

  static const char* value(const ::msg_generate::localv2_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::localv2_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robot_num);
      stream.next(m.robot_case);
      stream.next(m.local_x);
      stream.next(m.local_y);
      stream.next(m.local_yaw);
      stream.next(m.ball_x);
      stream.next(m.ball_y);
      stream.next(m.ballDist);
      stream.next(m.ballTheta);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct localv2_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::localv2_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::localv2_msg_<ContainerAllocator>& v)
  {
    s << indent << "robot_num: ";
    Printer<int64_t>::stream(s, indent + "  ", v.robot_num);
    s << indent << "robot_case: ";
    Printer<int64_t>::stream(s, indent + "  ", v.robot_case);
    s << indent << "local_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.local_x);
    s << indent << "local_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.local_y);
    s << indent << "local_yaw: ";
    Printer<int64_t>::stream(s, indent + "  ", v.local_yaw);
    s << indent << "ball_x: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ball_x);
    s << indent << "ball_y: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ball_y);
    s << indent << "ballDist: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ballDist);
    s << indent << "ballTheta: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ballTheta);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_LOCALV2_MSG_H