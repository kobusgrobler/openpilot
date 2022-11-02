
include_directories(models)
include_directories(runners)
include_directories(thneed)
include_directories(thneed/include)
include_directories(transforms)


add_compile_definitions(USE_ONNX_MODEL)

add_executable(modeld
        models/commonmodel.cc
        models/commonmodel.h
        models/driving.cc
        models/driving.h
        runners/onnxmodel.cc
        runners/onnxmodel.h
        runners/run.h
        runners/runmodel.h
        runners/snpemodel.cc
        runners/snpemodel.h
        transforms/loadyuv.cc
        transforms/loadyuv.h
        transforms/transform.cc
        transforms/transform.h
        modeld.cc)

# 'gsl', 'CB', 'pthread', 'dl'

target_link_libraries(modeld pthread dl OpenCL capnp zmq kj cereal visionipc messaging common gpucommon transformations SNPE json11)
target_compile_definitions(modeld PUBLIC WEBCAM MODEL_TEST)

add_executable(dmonitoringmodeld
        models/commonmodel.cc
        models/commonmodel.h
        models/dmonitoring.cc
        models/dmonitoring.h
        models/driving.cc
        models/driving.h
        runners/onnxmodel.cc
        runners/onnxmodel.h
        runners/run.h
        runners/runmodel.h
        runners/snpemodel.cc
        runners/snpemodel.h
        runners/thneedmodel.cc
        runners/thneedmodel.h
        #        tests/dmon_lag/repro.cc
        #        tests/snpe_benchmark/benchmark.cc
        #        tests/tf_test/main.cc
#        thneed/include/msm_kgsl.h
#        thneed/serialize.cc
#        thneed/thneed.h
#        thneed/thneed_common.cc
#        thneed/thneed_pc.cc
        #        thneed/thneed_qcom2.cc
        transforms/loadyuv.cc
        transforms/loadyuv.h
        transforms/transform.cc
        transforms/transform.h
        dmonitoringmodeld.cc)
