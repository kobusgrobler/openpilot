#include "system/camerad/cameras/camera_common.h"

#include <cassert>

#include "common/params.h"
#include "common/util.h"
#include "system/hardware/hw.h"

int main(int argc, char *argv[]) {
  if (Hardware::PC()) {
    printf("camerad is not meant to run on PC\n");
    camerad_thread();
    return 0;
  }

  int ret;
  ret = util::set_realtime_priority(53);
  assert(ret == 0);
  ret = util::set_core_affinity({6});
  assert(ret == 0 || Params().getBool("IsOffroad")); // failure ok while offroad due to offlining cores

  camerad_thread();
  return 0;
}
