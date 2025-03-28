/** Proofs GPU - Space and Time's cryptographic proof algorithms on the CPU and GPU.
 *
 * Copyright 2023-present Space and Time Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "sxt/base/device/property.h"

#include <cuda.h>
#include <cuda_runtime.h>

#include "sxt/base/error/panic.h"
#include "sxt/base/log/log.h"

namespace sxt::basdv {
//--------------------------------------------------------------------------------------------------
// get_num_devices
//--------------------------------------------------------------------------------------------------
unsigned get_num_devices() noexcept {
  static unsigned num_devices = []() noexcept {
    int res;
    auto rcode = cudaGetDeviceCount(&res);
    if (rcode != cudaSuccess) {
      basl::error("cudaGetDeviceCount failed: {}", cudaGetErrorString(rcode));
      return 0u;
    }
    return static_cast<unsigned>(res);
  }();
  return num_devices;
}

//--------------------------------------------------------------------------------------------------
// get_latest_cuda_version_supported_by_driver
//--------------------------------------------------------------------------------------------------
int get_latest_cuda_version_supported_by_driver() noexcept {
  static int version = []() noexcept {
    int res;
    auto rcode = cudaDriverGetVersion(&res);
    if (rcode != cudaSuccess) {
      baser::panic("cudaDriverGetVersion failed: {}", cudaGetErrorString(rcode));
    }
    return res;
  }();
  return version;
}

//--------------------------------------------------------------------------------------------------
// get_cuda_version
//--------------------------------------------------------------------------------------------------
int get_cuda_version() noexcept {
  static int version = []() noexcept {
    int res;
    auto rcode = cudaRuntimeGetVersion(&res);
    if (rcode != cudaSuccess) {
      baser::panic("cudaRuntimeGetVersion failed: {}", cudaGetErrorString(rcode));
    }
    return res;
  }();
  return version;
}

//--------------------------------------------------------------------------------------------------
// get_device_mem_info
//--------------------------------------------------------------------------------------------------
void get_device_mem_info(size_t& bytes_free, size_t& bytes_total) noexcept {
  auto rcode = cudaMemGetInfo(&bytes_free, &bytes_total);
  if (rcode != cudaSuccess) {
    baser::panic("cudaMemGetInfo failed: {}", cudaGetErrorString(rcode));
  }
}

//--------------------------------------------------------------------------------------------------
// get_total_device_memory
//--------------------------------------------------------------------------------------------------
size_t get_total_device_memory() noexcept {
  static size_t res = []() noexcept {
    size_t bytes_free, bytes_total;
    get_device_mem_info(bytes_free, bytes_total);
    return bytes_total;
  }();
  return res;
}
} // namespace sxt::basdv
