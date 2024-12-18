# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from msg_generate/udp_helper_msg.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class udp_helper_msg(genpy.Message):
  _md5sum = "6961c7de19af71cbd4139ee3940f46a0"
  _type = "msg_generate/udp_helper_msg"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """int64 robot_num
int64 robot_case

int64 robot_x_order
int64 robot_y_order 

int64 robot_ik_x_order
int64 robot_ik_y_order
int64 robot_ik_yaw_order

int64 ball_x
int64 ball_y
int64 ballDist
int64 ballTheta
"""
  __slots__ = ['robot_num','robot_case','robot_x_order','robot_y_order','robot_ik_x_order','robot_ik_y_order','robot_ik_yaw_order','ball_x','ball_y','ballDist','ballTheta']
  _slot_types = ['int64','int64','int64','int64','int64','int64','int64','int64','int64','int64','int64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       robot_num,robot_case,robot_x_order,robot_y_order,robot_ik_x_order,robot_ik_y_order,robot_ik_yaw_order,ball_x,ball_y,ballDist,ballTheta

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(udp_helper_msg, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.robot_num is None:
        self.robot_num = 0
      if self.robot_case is None:
        self.robot_case = 0
      if self.robot_x_order is None:
        self.robot_x_order = 0
      if self.robot_y_order is None:
        self.robot_y_order = 0
      if self.robot_ik_x_order is None:
        self.robot_ik_x_order = 0
      if self.robot_ik_y_order is None:
        self.robot_ik_y_order = 0
      if self.robot_ik_yaw_order is None:
        self.robot_ik_yaw_order = 0
      if self.ball_x is None:
        self.ball_x = 0
      if self.ball_y is None:
        self.ball_y = 0
      if self.ballDist is None:
        self.ballDist = 0
      if self.ballTheta is None:
        self.ballTheta = 0
    else:
      self.robot_num = 0
      self.robot_case = 0
      self.robot_x_order = 0
      self.robot_y_order = 0
      self.robot_ik_x_order = 0
      self.robot_ik_y_order = 0
      self.robot_ik_yaw_order = 0
      self.ball_x = 0
      self.ball_y = 0
      self.ballDist = 0
      self.ballTheta = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_11q().pack(_x.robot_num, _x.robot_case, _x.robot_x_order, _x.robot_y_order, _x.robot_ik_x_order, _x.robot_ik_y_order, _x.robot_ik_yaw_order, _x.ball_x, _x.ball_y, _x.ballDist, _x.ballTheta))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 88
      (_x.robot_num, _x.robot_case, _x.robot_x_order, _x.robot_y_order, _x.robot_ik_x_order, _x.robot_ik_y_order, _x.robot_ik_yaw_order, _x.ball_x, _x.ball_y, _x.ballDist, _x.ballTheta,) = _get_struct_11q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_11q().pack(_x.robot_num, _x.robot_case, _x.robot_x_order, _x.robot_y_order, _x.robot_ik_x_order, _x.robot_ik_y_order, _x.robot_ik_yaw_order, _x.ball_x, _x.ball_y, _x.ballDist, _x.ballTheta))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 88
      (_x.robot_num, _x.robot_case, _x.robot_x_order, _x.robot_y_order, _x.robot_ik_x_order, _x.robot_ik_y_order, _x.robot_ik_yaw_order, _x.ball_x, _x.ball_y, _x.ballDist, _x.ballTheta,) = _get_struct_11q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_11q = None
def _get_struct_11q():
    global _struct_11q
    if _struct_11q is None:
        _struct_11q = struct.Struct("<11q")
    return _struct_11q
