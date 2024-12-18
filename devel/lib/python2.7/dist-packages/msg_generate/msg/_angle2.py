# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from msg_generate/angle2.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class angle2(genpy.Message):
  _md5sum = "fb3bce9c774e8adb8b04618b1b2cb9fc"
  _type = "msg_generate/angle2"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float64 ang_r_0
float64 ang_r_1
float64 ang_r_2
float64 ang_r_3
float64 ang_r_4
float64 ang_r_5
float64 ang_l_0
float64 ang_l_1
float64 ang_l_2
float64 ang_l_3
float64 ang_l_4
float64 ang_l_5
"""
  __slots__ = ['ang_r_0','ang_r_1','ang_r_2','ang_r_3','ang_r_4','ang_r_5','ang_l_0','ang_l_1','ang_l_2','ang_l_3','ang_l_4','ang_l_5']
  _slot_types = ['float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       ang_r_0,ang_r_1,ang_r_2,ang_r_3,ang_r_4,ang_r_5,ang_l_0,ang_l_1,ang_l_2,ang_l_3,ang_l_4,ang_l_5

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(angle2, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.ang_r_0 is None:
        self.ang_r_0 = 0.
      if self.ang_r_1 is None:
        self.ang_r_1 = 0.
      if self.ang_r_2 is None:
        self.ang_r_2 = 0.
      if self.ang_r_3 is None:
        self.ang_r_3 = 0.
      if self.ang_r_4 is None:
        self.ang_r_4 = 0.
      if self.ang_r_5 is None:
        self.ang_r_5 = 0.
      if self.ang_l_0 is None:
        self.ang_l_0 = 0.
      if self.ang_l_1 is None:
        self.ang_l_1 = 0.
      if self.ang_l_2 is None:
        self.ang_l_2 = 0.
      if self.ang_l_3 is None:
        self.ang_l_3 = 0.
      if self.ang_l_4 is None:
        self.ang_l_4 = 0.
      if self.ang_l_5 is None:
        self.ang_l_5 = 0.
    else:
      self.ang_r_0 = 0.
      self.ang_r_1 = 0.
      self.ang_r_2 = 0.
      self.ang_r_3 = 0.
      self.ang_r_4 = 0.
      self.ang_r_5 = 0.
      self.ang_l_0 = 0.
      self.ang_l_1 = 0.
      self.ang_l_2 = 0.
      self.ang_l_3 = 0.
      self.ang_l_4 = 0.
      self.ang_l_5 = 0.

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
      buff.write(_get_struct_12d().pack(_x.ang_r_0, _x.ang_r_1, _x.ang_r_2, _x.ang_r_3, _x.ang_r_4, _x.ang_r_5, _x.ang_l_0, _x.ang_l_1, _x.ang_l_2, _x.ang_l_3, _x.ang_l_4, _x.ang_l_5))
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
      end += 96
      (_x.ang_r_0, _x.ang_r_1, _x.ang_r_2, _x.ang_r_3, _x.ang_r_4, _x.ang_r_5, _x.ang_l_0, _x.ang_l_1, _x.ang_l_2, _x.ang_l_3, _x.ang_l_4, _x.ang_l_5,) = _get_struct_12d().unpack(str[start:end])
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
      buff.write(_get_struct_12d().pack(_x.ang_r_0, _x.ang_r_1, _x.ang_r_2, _x.ang_r_3, _x.ang_r_4, _x.ang_r_5, _x.ang_l_0, _x.ang_l_1, _x.ang_l_2, _x.ang_l_3, _x.ang_l_4, _x.ang_l_5))
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
      end += 96
      (_x.ang_r_0, _x.ang_r_1, _x.ang_r_2, _x.ang_r_3, _x.ang_r_4, _x.ang_r_5, _x.ang_l_0, _x.ang_l_1, _x.ang_l_2, _x.ang_l_3, _x.ang_l_4, _x.ang_l_5,) = _get_struct_12d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_12d = None
def _get_struct_12d():
    global _struct_12d
    if _struct_12d is None:
        _struct_12d = struct.Struct("<12d")
    return _struct_12d
