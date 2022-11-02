set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Gui Core Network Concurrent Multimedia Quick Qml QuickWidgets Location Positioning
        DBus REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

add_executable(replay
        main.cc
        replay.cc
        "consoleui.cc"
        "camera.cc"
        "filereader.cc"
        "logreader.cc"
        "framereader.cc"
        "route.cc"
        "util.cc")

target_link_directories(replay PRIVATE ${OPENPILOT}/selfdrive/ui/)

target_link_libraries(replay pthread dl bz2 curl yuv ncurses ssl crypto avutil avcodec avformat
        Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Network Qt5::Concurrent Qt5::Multimedia Qt5::Quick Qt5::Qml
        Qt5::QuickWidgets Qt5::Location Qt5::Positioning Qt5::DBus
        OpenCL capnp zmq kj cereal visionipc messaging common gpucommon transformations SNPE json11 qt_util)
target_compile_definitions(replay PRIVATE _REENTRANT QT_NO_DEBUG)
