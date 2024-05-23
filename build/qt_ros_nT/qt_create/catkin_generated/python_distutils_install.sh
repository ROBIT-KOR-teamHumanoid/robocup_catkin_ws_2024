#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/robit/catkin_ws/src/qt_ros_nT/qt_create"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/robit/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/robit/catkin_ws/install/lib/python2.7/dist-packages:/home/robit/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/robit/catkin_ws/build" \
    "/usr/bin/python2" \
    "/home/robit/catkin_ws/src/qt_ros_nT/qt_create/setup.py" \
     \
    build --build-base "/home/robit/catkin_ws/build/qt_ros_nT/qt_create" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/robit/catkin_ws/install" --install-scripts="/home/robit/catkin_ws/install/bin"
