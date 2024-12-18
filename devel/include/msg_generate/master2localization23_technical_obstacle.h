// Generated by gencpp from file msg_generate/master2localization23_technical_obstacle.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_MASTER2LOCALIZATION23_TECHNICAL_OBSTACLE_H
#define MSG_GENERATE_MESSAGE_MASTER2LOCALIZATION23_TECHNICAL_OBSTACLE_H


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
struct master2localization23_technical_obstacle_
{
  typedef master2localization23_technical_obstacle_<ContainerAllocator> Type;

  master2localization23_technical_obstacle_()
    : sector(0)
    , obs_1(0)
    , obs_2(0)  {
    }
  master2localization23_technical_obstacle_(const ContainerAllocator& _alloc)
    : sector(0)
    , obs_1(0)
    , obs_2(0)  {
  (void)_alloc;
    }



   typedef int64_t _sector_type;
  _sector_type sector;

   typedef int64_t _obs_1_type;
  _obs_1_type obs_1;

   typedef int64_t _obs_2_type;
  _obs_2_type obs_2;





  typedef boost::shared_ptr< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> const> ConstPtr;

}; // struct master2localization23_technical_obstacle_

typedef ::msg_generate::master2localization23_technical_obstacle_<std::allocator<void> > master2localization23_technical_obstacle;

typedef boost::shared_ptr< ::msg_generate::master2localization23_technical_obstacle > master2localization23_technical_obstaclePtr;
typedef boost::shared_ptr< ::msg_generate::master2localization23_technical_obstacle const> master2localization23_technical_obstacleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator1> & lhs, const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator2> & rhs)
{
  return lhs.sector == rhs.sector &&
    lhs.obs_1 == rhs.obs_1 &&
    lhs.obs_2 == rhs.obs_2;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator1> & lhs, const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "84cbbda57e228d1e1a9085de32393705";
  }

  static const char* value(const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x84cbbda57e228d1eULL;
  static const uint64_t static_value2 = 0x1a9085de32393705ULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/master2localization23_technical_obstacle";
  }

  static const char* value(const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 sector\n"
"int64 obs_1\n"
"int64 obs_2\n"
"\n"
;
  }

  static const char* value(const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sector);
      stream.next(m.obs_1);
      stream.next(m.obs_2);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct master2localization23_technical_obstacle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::master2localization23_technical_obstacle_<ContainerAllocator>& v)
  {
    s << indent << "sector: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sector);
    s << indent << "obs_1: ";
    Printer<int64_t>::stream(s, indent + "  ", v.obs_1);
    s << indent << "obs_2: ";
    Printer<int64_t>::stream(s, indent + "  ", v.obs_2);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_MASTER2LOCALIZATION23_TECHNICAL_OBSTACLE_H
