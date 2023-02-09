#pragma once

#include <cassert>

#include "sxt/algorithm/base/reducer.h"

namespace sxt::algr {
//--------------------------------------------------------------------------------------------------
// warp_reduce
//--------------------------------------------------------------------------------------------------
/**
 * Efficiently reduce at most 32 elements in shared memory.
 *
 * Following nvidia's guidelines on efficient parallel reductions, we use
 * volatile for the shared memory which allows us to avoid calling __syncthreads().
 *
 * See https://developer.download.nvidia.com/assets/cuda/files/reduction.pdf, page 22
 */
template <algb::reducer Reducer, unsigned int BlockSize>
__device__ void warp_reduce(volatile typename Reducer::value_type* shared_data,
                            unsigned int thread_index) {
  assert(thread_index < 32 && "can only be called on an individual warp");
  if constexpr (BlockSize >= 64) {
    Reducer::accumulate(shared_data[thread_index], shared_data[thread_index + 32]);
  }
  if constexpr (BlockSize >= 32) {
    if (thread_index < 16) {
      Reducer::accumulate(shared_data[thread_index], shared_data[thread_index + 16]);
    }
  }
  if constexpr (BlockSize >= 16) {
    if (thread_index < 8) {
      Reducer::accumulate(shared_data[thread_index], shared_data[thread_index + 8]);
    }
  }
  if constexpr (BlockSize >= 8) {
    if (thread_index < 4) {
      Reducer::accumulate(shared_data[thread_index], shared_data[thread_index + 4]);
    }
  }
  if constexpr (BlockSize >= 4) {
    if (thread_index < 2) {
      Reducer::accumulate(shared_data[thread_index], shared_data[thread_index + 2]);
    }
  }
  if constexpr (BlockSize >= 2) {
    if (thread_index < 1) {
      Reducer::accumulate(shared_data[thread_index], shared_data[thread_index + 1]);
    }
  }
}
} // namespace sxt::algr