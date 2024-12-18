// Generated by gencpp from file msg_generate/Step_msg.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_STEP_MSG_H
#define MSG_GENERATE_MESSAGE_STEP_MSG_H


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
struct Step_msg_
{
  typedef Step_msg_<ContainerAllocator> Type;

  Step_msg_()
    : delay(0)
    , time(0)
    , id()
    , position()  {
    }
  Step_msg_(const ContainerAllocator& _alloc)
    : delay(0)
    , time(0)
    , id(_alloc)
    , position(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _delay_type;
  _delay_type delay;

   typedef int32_t _time_type;
  _time_type time;

   typedef std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> _id_type;
  _id_type id;

   typedef std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> _position_type;
  _position_type position;





  typedef boost::shared_ptr< ::msg_generate::Step_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::Step_msg_<ContainerAllocator> const> ConstPtr;

}; // struct Step_msg_

typedef ::msg_generate::Step_msg_<std::allocator<void> > Step_msg;

typedef boost::shared_ptr< ::msg_generate::Step_msg > Step_msgPtr;
typedef boost::shared_ptr< ::msg_generate::Step_msg const> Step_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::Step_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::Step_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::Step_msg_<ContainerAllocator1> & lhs, const ::msg_generate::Step_msg_<ContainerAllocator2> & rhs)
{
  return lhs.delay == rhs.delay &&
    lhs.time == rhs.time &&
    lhs.id == rhs.id &&
    lhs.position == rhs.position;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::Step_msg_<ContainerAllocator1> & lhs, const ::msg_generate::Step_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::Step_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::Step_msg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::Step_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::Step_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::Step_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::Step_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::Step_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a82b6e64922c5569387165da569b0157";
  }

  static const char* value(const ::msg_generate::Step_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa82b6e64922c5569ULL;
  static const uint64_t static_value2 = 0x387165da569b0157ULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::Step_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/Step_msg";
  }

  static const char* value(const ::msg_generate::Step_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::Step_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 delay\n"
"int32 time\n"
"int32[] id\n"
"int32[] position\n"
"\n"
"\n"
;
  }

  static const char* value(const ::msg_generate::Step_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::Step_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.delay);
      stream.next(m.time);
      stream.next(m.id);
      stream.next(m.position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Step_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::Step_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::Step_msg_<ContainerAllocator>& v)
  {
    s << indent << "delay: ";
    Printer<int32_t>::stream(s, indent + "  ", v.delay);
    s << indent << "time: ";
    Printer<int32_t>::stream(s, indent + "  ", v.time);
    s << indent << "id[]" << std::endl;
    for (size_t i = 0; i < v.id.size(); ++i)
    {
      s << indent << "  id[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.id[i]);
    }
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.position[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_STEP_MSG_H
