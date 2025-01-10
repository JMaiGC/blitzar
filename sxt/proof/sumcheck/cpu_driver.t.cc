/** Proofs GPU - Space and Time's cryptographic proof algorithms on the CPU and GPU.
 *
 * Copyright 2024-present Space and Time Labs, Inc.
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
#include "sxt/proof/sumcheck/cpu_driver.h"

#include <vector>

#include "sxt/base/test/unit_test.h"
#include "sxt/proof/sumcheck/driver_test.h"

using namespace sxt;
using namespace sxt::prfsk;

TEST_CASE("we can perform the primitive operations for sumcheck proofs") {
  cpu_driver drv;
  exercise_driver(drv);
}