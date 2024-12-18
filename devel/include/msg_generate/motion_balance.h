// Generated by gencpp from file msg_generate/motion_balance.msg
// DO NOT EDIT!


#ifndef MSG_GENERATE_MESSAGE_MOTION_BALANCE_H
#define MSG_GENERATE_MESSAGE_MOTION_BALANCE_H


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
struct motion_balance_
{
  typedef motion_balance_<ContainerAllocator> Type;

  motion_balance_()
    : Left_10(0.0)
    , Right_11(0.0)
    , Left_14(0.0)
    , Right_15(0.0)
    , Left_16(0.0)
    , Right_17(0.0)
    , Left_18(0.0)
    , Right_19(0.0)
    , Left_20(0.0)
    , Right_21(0.0)
    , support_L(false)
    , support_R(false)
    , support_B(false)  {
    }
  motion_balance_(const ContainerAllocator& _alloc)
    : Left_10(0.0)
    , Right_11(0.0)
    , Left_14(0.0)
    , Right_15(0.0)
    , Left_16(0.0)
    , Right_17(0.0)
    , Left_18(0.0)
    , Right_19(0.0)
    , Left_20(0.0)
    , Right_21(0.0)
    , support_L(false)
    , support_R(false)
    , support_B(false)  {
  (void)_alloc;
    }



   typedef float _Left_10_type;
  _Left_10_type Left_10;

   typedef float _Right_11_type;
  _Right_11_type Right_11;

   typedef float _Left_14_type;
  _Left_14_type Left_14;

   typedef float _Right_15_type;
  _Right_15_type Right_15;

   typedef float _Left_16_type;
  _Left_16_type Left_16;

   typedef float _Right_17_type;
  _Right_17_type Right_17;

   typedef float _Left_18_type;
  _Left_18_type Left_18;

   typedef float _Right_19_type;
  _Right_19_type Right_19;

   typedef float _Left_20_type;
  _Left_20_type Left_20;

   typedef float _Right_21_type;
  _Right_21_type Right_21;

   typedef uint8_t _support_L_type;
  _support_L_type support_L;

   typedef uint8_t _support_R_type;
  _support_R_type support_R;

   typedef uint8_t _support_B_type;
  _support_B_type support_B;





  typedef boost::shared_ptr< ::msg_generate::motion_balance_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_generate::motion_balance_<ContainerAllocator> const> ConstPtr;

}; // struct motion_balance_

typedef ::msg_generate::motion_balance_<std::allocator<void> > motion_balance;

typedef boost::shared_ptr< ::msg_generate::motion_balance > motion_balancePtr;
typedef boost::shared_ptr< ::msg_generate::motion_balance const> motion_balanceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_generate::motion_balance_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_generate::motion_balance_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_generate::motion_balance_<ContainerAllocator1> & lhs, const ::msg_generate::motion_balance_<ContainerAllocator2> & rhs)
{
  return lhs.Left_10 == rhs.Left_10 &&
    lhs.Right_11 == rhs.Right_11 &&
    lhs.Left_14 == rhs.Left_14 &&
    lhs.Right_15 == rhs.Right_15 &&
    lhs.Left_16 == rhs.Left_16 &&
    lhs.Right_17 == rhs.Right_17 &&
    lhs.Left_18 == rhs.Left_18 &&
    lhs.Right_19 == rhs.Right_19 &&
    lhs.Left_20 == rhs.Left_20 &&
    lhs.Right_21 == rhs.Right_21 &&
    lhs.support_L == rhs.support_L &&
    lhs.support_R == rhs.support_R &&
    lhs.support_B == rhs.support_B;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_generate::motion_balance_<ContainerAllocator1> & lhs, const ::msg_generate::motion_balance_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_generate

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::motion_balance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_generate::motion_balance_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::motion_balance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_generate::motion_balance_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::motion_balance_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_generate::motion_balance_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_generate::motion_balance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "03d17ac032478d225abd4895f2c60b7c";
  }

  static const char* value(const ::msg_generate::motion_balance_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x03d17ac032478d22ULL;
  static const uint64_t static_value2 = 0x5abd4895f2c60b7cULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_generate::motion_balance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_generate/motion_balance";
  }

  static const char* value(const ::msg_generate::motion_balance_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_generate::motion_balance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 Left_10\n"
"float32 Right_11\n"
"float32 Left_14\n"
"float32 Right_15\n"
"float32 Left_16\n"
"float32 Right_17\n"
"float32 Left_18\n"
"float32 Right_19\n"
"float32 Left_20\n"
"float32 Right_21\n"
"\n"
"bool support_L\n"
"bool support_R\n"
"bool support_B\n"
;
  }

  static const char* value(const ::msg_generate::motion_balance_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_generate::motion_balance_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Left_10);
      stream.next(m.Right_11);
      stream.next(m.Left_14);
      stream.next(m.Right_15);
      stream.next(m.Left_16);
      stream.next(m.Right_17);
      stream.next(m.Left_18);
      stream.next(m.Right_19);
      stream.next(m.Left_20);
      stream.next(m.Right_21);
      stream.next(m.support_L);
      stream.next(m.support_R);
      stream.next(m.support_B);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct motion_balance_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_generate::motion_balance_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_generate::motion_balance_<ContainerAllocator>& v)
  {
    s << indent << "Left_10: ";
    Printer<float>::stream(s, indent + "  ", v.Left_10);
    s << indent << "Right_11: ";
    Printer<float>::stream(s, indent + "  ", v.Right_11);
    s << indent << "Left_14: ";
    Printer<float>::stream(s, indent + "  ", v.Left_14);
    s << indent << "Right_15: ";
    Printer<float>::stream(s, indent + "  ", v.Right_15);
    s << indent << "Left_16: ";
    Printer<float>::stream(s, indent + "  ", v.Left_16);
    s << indent << "Right_17: ";
    Printer<float>::stream(s, indent + "  ", v.Right_17);
    s << indent << "Left_18: ";
    Printer<float>::stream(s, indent + "  ", v.Left_18);
    s << indent << "Right_19: ";
    Printer<float>::stream(s, indent + "  ", v.Right_19);
    s << indent << "Left_20: ";
    Printer<float>::stream(s, indent + "  ", v.Left_20);
    s << indent << "Right_21: ";
    Printer<float>::stream(s, indent + "  ", v.Right_21);
    s << indent << "support_L: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.support_L);
    s << indent << "support_R: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.support_R);
    s << indent << "support_B: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.support_B);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GENERATE_MESSAGE_MOTION_BALANCE_H
