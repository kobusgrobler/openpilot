include_directories(/usr/include/opencv4/)

include_directories(cameras)
include_directories(imgproc)
include_directories(include)

add_executable(camerad
        cameras/camera_common.cc
        cameras/camera_common.h
        cameras/camera_webcam.cc
        cameras/camera_webcam.h
        cameras/camera_util.cc
        cameras/camera_util.h
        cameras/sensor2_i2c.h
        main.cc)

target_compile_definitions(camerad PUBLIC WEBCAM)

# 'gsl', 'CB', 'pthread', 'dl'

target_link_libraries(camerad pthread dl opencv_core opencv_imgproc opencv_videoio OpenCL capnp zmq kj cereal visionipc messaging
        common gpucommon transformations SNPE json11 jpeg)
