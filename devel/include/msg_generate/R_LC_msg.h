// Generated by gencpp from file msg_generate/R_LC_msg.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_R_LC_MSG_H
#define MSG_GENERATE_MESSAGE_R_LC_MSG_H


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
struct R_LC_msg_
{
  typedef R_LC_msg_<ContainerAllocator> Type;

  R_LC_msg_()
    : R_LC_Data()  {
    }
  R_LC_msg_(const ContainerAllocator& _alloc)
    : R_LC_Data(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> _R_LC_Data_type;
  _R_LC_Data_type R_LC_Data;





  typedef boost::shared_ptr< ::msg_generate::R_LC_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::R_LC_msg_<ContainerAllocator> const> ConstPtr;

}; // struct R_LC_msg_

typedef ::msg_generate::R_LC_msg_<std::allocator<void> > R_LC_msg;

typedef boost::shared_ptr< ::msg_generate::R_LC_msg > R_LC_msgPtr;
typedef boost::shared_ptr< ::msg_generate::R_LC_msg const> R_LC_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::R_LC_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::R_LC_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::R_LC_msg_<ContainerAllocator1> & lhs, const ::msg_generate::R_LC_msg_<ContainerAllocator2> & rhs)
{
  return lhs.R_LC_Data == rhs.R_LC_Data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::R_LC_msg_<ContainerAllocator1> & lhs, const ::msg_generate::R_LC_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::R_LC_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::R_LC_msg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::R_LC_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::R_LC_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::R_LC_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::R_LC_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::R_LC_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1d93107f948628f0a69348074e2aa35d";
  }

  static const char* value(const ::msg_generate::R_LC_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1d93107f948628f0ULL;
  static const uint64_t static_value2 = 0xa69348074e2aa35dULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::R_LC_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/R_LC_msg";
  }

  static const char* value(const ::msg_generate::R_LC_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::R_LC_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32[] R_LC_Data\n"
;
  }

  static const char* value(const ::msg_generate::R_LC_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::R_LC_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.R_LC_Data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct R_LC_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::R_LC_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::R_LC_msg_<ContainerAllocator>& v)
  {
    s << indent << "R_LC_Data[]" << std::endl;
    for (size_t i = 0; i < v.R_LC_Data.size(); ++i)
    {
      s << indent << "  R_LC_Data[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.R_LC_Data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_R_LC_MSG_H