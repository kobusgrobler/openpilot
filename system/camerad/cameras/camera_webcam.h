#pragma once

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

#include "system/camerad/cameras/camera_common.h"

#define FRAME_BUF_COUNT 16

typedef struct CameraState {
    CameraInfo ci;
    int camera_num;
    int camera_id;
    int fps;
    float digital_gain;
    CameraBuf buf;
} CameraState;


typedef struct MultiCameraState {
    CameraState road_cam;
    CameraState driver_cam;

    SubMaster *sm;
    PubMaster *pm;
} MultiCameraState;
