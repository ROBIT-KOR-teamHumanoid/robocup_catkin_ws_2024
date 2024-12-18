# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from msg_generate/kuro_cotton_candy.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class kuro_cotton_candy(genpy.Message):
  _md5sum = "d9f3ac83b00612092e5b577721e3b2ac"
  _type = "msg_generate/kuro_cotton_candy"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """bool ready
bool start
bool stop
float64 timer 
"""
  __slots__ = ['ready','start','stop','timer']
  _slot_types = ['bool','bool','bool','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       ready,start,stop,timer

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(kuro_cotton_candy, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.ready is None:
        self.ready = False
      if self.start is None:
        self.start = False
      if self.stop is None:
        self.stop = False
      if self.timer is None:
        self.timer = 0.
    else:
      self.ready = False
      self.start = False
      self.stop = False
      self.timer = 0.

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
      buff.write(_get_struct_3Bd().pack(_x.ready, _x.start, _x.stop, _x.timer))
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
      end += 11
      (_x.ready, _x.start, _x.stop, _x.timer,) = _get_struct_3Bd().unpack(str[start:end])
      self.ready = bool(self.ready)
      self.start = bool(self.start)
      self.stop = bool(self.stop)
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
      buff.write(_get_struct_3Bd().pack(_x.ready, _x.start, _x.stop, _x.timer))
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
      end += 11
      (_x.ready, _x.start, _x.stop, _x.timer,) = _get_struct_3Bd().unpack(str[start:end])
      self.ready = bool(self.ready)
      self.start = bool(self.start)
      self.stop = bool(self.stop)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3Bd = None
def _get_struct_3Bd():
    global _struct_3Bd
    if _struct_3Bd is None:
        _struct_3Bd = struct.Struct("<3Bd")
    return _struct_3Bd
