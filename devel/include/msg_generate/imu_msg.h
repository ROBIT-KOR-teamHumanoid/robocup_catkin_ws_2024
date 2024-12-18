// Generated by gencpp from file msg_generate/imu_msg.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_IMU_MSG_H
#define MSG_GENERATE_MESSAGE_IMU_MSG_H


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
struct imu_msg_
{
  typedef imu_msg_<ContainerAllocator> Type;

  imu_msg_()
    : roll(0.0)
    , pitch(0.0)
    , yaw(0.0)
    , roll_acc(0.0)
    , pitch_acc(0.0)
    , yaw_acc(0.0)  {
    }
  imu_msg_(const ContainerAllocator& _alloc)
    : roll(0.0)
    , pitch(0.0)
    , yaw(0.0)
    , roll_acc(0.0)
    , pitch_acc(0.0)
    , yaw_acc(0.0)  {
  (void)_alloc;
    }



   typedef float _roll_type;
  _roll_type roll;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _roll_acc_type;
  _roll_acc_type roll_acc;

   typedef float _pitch_acc_type;
  _pitch_acc_type pitch_acc;

   typedef float _yaw_acc_type;
  _yaw_acc_type yaw_acc;





  typedef boost::shared_ptr< ::msg_generate::imu_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::imu_msg_<ContainerAllocator> const> ConstPtr;

}; // struct imu_msg_

typedef ::msg_generate::imu_msg_<std::allocator<void> > imu_msg;

typedef boost::shared_ptr< ::msg_generate::imu_msg > imu_msgPtr;
typedef boost::shared_ptr< ::msg_generate::imu_msg const> imu_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::imu_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::imu_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::imu_msg_<ContainerAllocator1> & lhs, const ::msg_generate::imu_msg_<ContainerAllocator2> & rhs)
{
  return lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch &&
    lhs.yaw == rhs.yaw &&
    lhs.roll_acc == rhs.roll_acc &&
    lhs.pitch_acc == rhs.pitch_acc &&
    lhs.yaw_acc == rhs.yaw_acc;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::imu_msg_<ContainerAllocator1> & lhs, const ::msg_generate::imu_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::imu_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::imu_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::imu_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::imu_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::imu_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::imu_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::imu_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7a5074fa2c7055370ef50e1051a0c7bf";
  }

  static const char* value(const ::msg_generate::imu_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7a5074fa2c705537ULL;
  static const uint64_t static_value2 = 0x0ef50e1051a0c7bfULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::imu_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/imu_msg";
  }

  static const char* value(const ::msg_generate::imu_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::imu_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 roll\n"
"float32 pitch\n"
"float32 yaw\n"
"float32 roll_acc\n"
"float32 pitch_acc\n"
"float32 yaw_acc\n"
;
  }

  static const char* value(const ::msg_generate::imu_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::imu_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.roll);
      stream.next(m.pitch);
      stream.next(m.yaw);
      stream.next(m.roll_acc);
      stream.next(m.pitch_acc);
      stream.next(m.yaw_acc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct imu_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::imu_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::imu_msg_<ContainerAllocator>& v)
  {
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "roll_acc: ";
    Printer<float>::stream(s, indent + "  ", v.roll_acc);
    s << indent << "pitch_acc: ";
    Printer<float>::stream(s, indent + "  ", v.pitch_acc);
    s << indent << "yaw_acc: ";
    Printer<float>::stream(s, indent + "  ", v.yaw_acc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_IMU_MSG_H
