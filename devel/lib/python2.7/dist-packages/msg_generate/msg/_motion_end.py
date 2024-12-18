# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from msg_generate/motion_end.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class motion_end(genpy.Message):
  _md5sum = "25f699e9aaf9930abdbe2aaa9b5b0063"
  _type = "msg_generate/motion_end"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """int32 motion_end
int32 motion_ing
int32 motion_start_ing
int32 motion_end_ing

int32 motion_num

"""
  __slots__ = ['motion_end','motion_ing','motion_start_ing','motion_end_ing','motion_num']
  _slot_types = ['int32','int32','int32','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       motion_end,motion_ing,motion_start_ing,motion_end_ing,motion_num

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(motion_end, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.motion_end is None:
        self.motion_end = 0
      if self.motion_ing is None:
        self.motion_ing = 0
      if self.motion_start_ing is None:
        self.motion_start_ing = 0
      if self.motion_end_ing is None:
        self.motion_end_ing = 0
      if self.motion_num is None:
        self.motion_num = 0
    else:
      self.motion_end = 0
      self.motion_ing = 0
      self.motion_start_ing = 0
      self.motion_end_ing = 0
      self.motion_num = 0

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
      buff.write(_get_struct_5i().pack(_x.motion_end, _x.motion_ing, _x.motion_start_ing, _x.motion_end_ing, _x.motion_num))
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
      end += 20
      (_x.motion_end, _x.motion_ing, _x.motion_start_ing, _x.motion_end_ing, _x.motion_num,) = _get_struct_5i().unpack(str[start:end])
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
      buff.write(_get_struct_5i().pack(_x.motion_end, _x.motion_ing, _x.motion_start_ing, _x.motion_end_ing, _x.motion_num))
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
      end += 20
      (_x.motion_end, _x.motion_ing, _x.motion_start_ing, _x.motion_end_ing, _x.motion_num,) = _get_struct_5i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_5i = None
def _get_struct_5i():
    global _struct_5i
    if _struct_5i is None:
        _struct_5i = struct.Struct("<5i")
    return _struct_5i
