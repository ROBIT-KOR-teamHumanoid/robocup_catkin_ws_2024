// Generated by gencpp from file msg_generate/support_onestep_msg.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_SUPPORT_ONESTEP_MSG_H
#define MSG_GENERATE_MESSAGE_SUPPORT_ONESTEP_MSG_H


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
struct support_onestep_msg_
{
  typedef support_onestep_msg_<ContainerAllocator> Type;

  support_onestep_msg_()
    : onestep_checker(0)  {
    }
  support_onestep_msg_(const ContainerAllocator& _alloc)
    : onestep_checker(0)  {
  (void)_alloc;
    }



   typedef int32_t _onestep_checker_type;
  _onestep_checker_type onestep_checker;





  typedef boost::shared_ptr< ::msg_generate::support_onestep_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::support_onestep_msg_<ContainerAllocator> const> ConstPtr;

}; // struct support_onestep_msg_

typedef ::msg_generate::support_onestep_msg_<std::allocator<void> > support_onestep_msg;

typedef boost::shared_ptr< ::msg_generate::support_onestep_msg > support_onestep_msgPtr;
typedef boost::shared_ptr< ::msg_generate::support_onestep_msg const> support_onestep_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::support_onestep_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::support_onestep_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::support_onestep_msg_<ContainerAllocator1> & lhs, const ::msg_generate::support_onestep_msg_<ContainerAllocator2> & rhs)
{
  return lhs.onestep_checker == rhs.onestep_checker;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::support_onestep_msg_<ContainerAllocator1> & lhs, const ::msg_generate::support_onestep_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::support_onestep_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::support_onestep_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::support_onestep_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "260ab72f5eacc5be420032b06460a43f";
  }

  static const char* value(const ::msg_generate::support_onestep_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x260ab72f5eacc5beULL;
  static const uint64_t static_value2 = 0x420032b06460a43fULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/support_onestep_msg";
  }

  static const char* value(const ::msg_generate::support_onestep_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 onestep_checker\n"
;
  }

  static const char* value(const ::msg_generate::support_onestep_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.onestep_checker);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct support_onestep_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::support_onestep_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::support_onestep_msg_<ContainerAllocator>& v)
  {
    s << indent << "onestep_checker: ";
    Printer<int32_t>::stream(s, indent + "  ", v.onestep_checker);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_SUPPORT_ONESTEP_MSG_H