// Generated by gencpp from file msg_generate/robocupvision.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_ROBOCUPVISION_H
#define MSG_GENERATE_MESSAGE_ROBOCUPVISION_H


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
struct robocupvision_
{
  typedef robocupvision_<ContainerAllocator> Type;

  robocupvision_()
    : ballX(0)
    , ballY(0)
    , ballDist(0)
    , ballTheta(0.0)  {
    }
  robocupvision_(const ContainerAllocator& _alloc)
    : ballX(0)
    , ballY(0)
    , ballDist(0)
    , ballTheta(0.0)  {
  (void)_alloc;
    }



   typedef int64_t _ballX_type;
  _ballX_type ballX;

   typedef int64_t _ballY_type;
  _ballY_type ballY;

   typedef int64_t _ballDist_type;
  _ballDist_type ballDist;

   typedef double _ballTheta_type;
  _ballTheta_type ballTheta;





  typedef boost::shared_ptr< ::msg_generate::robocupvision_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::robocupvision_<ContainerAllocator> const> ConstPtr;

}; // struct robocupvision_

typedef ::msg_generate::robocupvision_<std::allocator<void> > robocupvision;

typedef boost::shared_ptr< ::msg_generate::robocupvision > robocupvisionPtr;
typedef boost::shared_ptr< ::msg_generate::robocupvision const> robocupvisionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::robocupvision_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::robocupvision_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::robocupvision_<ContainerAllocator1> & lhs, const ::msg_generate::robocupvision_<ContainerAllocator2> & rhs)
{
  return lhs.ballX == rhs.ballX &&
    lhs.ballY == rhs.ballY &&
    lhs.ballDist == rhs.ballDist &&
    lhs.ballTheta == rhs.ballTheta;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::robocupvision_<ContainerAllocator1> & lhs, const ::msg_generate::robocupvision_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::robocupvision_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::robocupvision_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::robocupvision_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::robocupvision_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::robocupvision_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::robocupvision_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::robocupvision_<ContainerAllocator> >
{
  static const char* value()
  {
    return "42c32a1bbbff9d4d2593036e1e947112";
  }

  static const char* value(const ::msg_generate::robocupvision_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x42c32a1bbbff9d4dULL;
  static const uint64_t static_value2 = 0x2593036e1e947112ULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::robocupvision_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/robocupvision";
  }

  static const char* value(const ::msg_generate::robocupvision_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::robocupvision_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 ballX\n"
"int64 ballY\n"
"int64 ballDist\n"
"float64 ballTheta\n"
"\n"
;
  }

  static const char* value(const ::msg_generate::robocupvision_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::robocupvision_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ballX);
      stream.next(m.ballY);
      stream.next(m.ballDist);
      stream.next(m.ballTheta);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct robocupvision_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::robocupvision_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::robocupvision_<ContainerAllocator>& v)
  {
    s << indent << "ballX: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ballX);
    s << indent << "ballY: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ballY);
    s << indent << "ballDist: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ballDist);
    s << indent << "ballTheta: ";
    Printer<double>::stream(s, indent + "  ", v.ballTheta);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_ROBOCUPVISION_H