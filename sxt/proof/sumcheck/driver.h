/** Proofs GPU - Space and Time's cryptographic proof algorithms on the CPU and GPU.
 *
 * Copyright 2025-present Space and Time Labs, Inc.
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
#pragma once

#include <memory>

#include "sxt/base/container/span.h"
#include "sxt/base/field/element.h"
#include "sxt/execution/async/future_fwd.h"
#include "sxt/proof/sumcheck/workspace.h"

namespace sxt::prfsk {
//--------------------------------------------------------------------------------------------------
// driver
//--------------------------------------------------------------------------------------------------
template <basfld::element T> class driver {
public:
  virtual ~driver() noexcept = default;

  virtual xena::future<std::unique_ptr<workspace>>
  make_workspace(basct::cspan<T> mles, basct::cspan<std::pair<T, unsigned>> product_table,
                 basct::cspan<unsigned> product_terms, unsigned n) const noexcept = 0;

  virtual xena::future<> sum(basct::span<T> polynomial, workspace& ws) const noexcept = 0;

  virtual xena::future<> fold(workspace& ws, const T& r) const noexcept = 0;
};
} // namespace sxt::prfsk
