load(
    "//bazel:sxt_component.bzl",
    "sxt_cc_component",
)

sxt_cc_component(
    name = "available_device",
    impl_deps = [
        "//sxt/execution/async:future",
        "//sxt/execution/schedule:scheduler",
        "//sxt/execution/schedule:pending_event",
    ],
    test_deps = [
        ":test_kernel",
        ":synchronization",
        "//sxt/execution/async:coroutine",
        "//sxt/base/test:unit_test",
        "//sxt/base/device:stream",
        "//sxt/memory/management:managed_array",
    ],
    deps = [
        "//sxt/execution/async:future_fwd",
    ],
)

sxt_cc_component(
    name = "test_kernel",
    impl_deps = [
        "//sxt/base/device:property",
        "//sxt/base/device:memory_utility",
        "//sxt/base/num:divide_up",
        "//sxt/base/device:stream",
        "//sxt/memory/resource:async_device_resource",
        "//sxt/memory/management:managed_array",
    ],
    is_cuda = True,
    with_test = False,
    deps = [
        "//sxt/base/type:raw_stream",
    ],
)

sxt_cc_component(
    name = "computation_event",
    test_deps = [
        ":test_kernel",
        "//sxt/execution/async:future",
        "//sxt/base/device:stream",
        "//sxt/execution/schedule:scheduler",
        "//sxt/base/device:event_utility",
        "//sxt/base/device:memory_utility",
        "//sxt/base/test:unit_test",
        "//sxt/memory/management:managed_array",
        "//sxt/memory/resource:async_device_resource",
        "//sxt/memory/resource:pinned_resource",
    ],
    deps = [
        ":computation_handle",
        "//sxt/base/device:event",
        "//sxt/execution/async:promise",
        "//sxt/execution/schedule:pollable_event",
    ],
)

sxt_cc_component(
    name = "computation_handle",
    impl_deps = [
        "//sxt/base/device:synchronization",
        "//sxt/base/device:stream_handle",
        "//sxt/base/device:stream_pool",
        "//sxt/base/device:stream",
        "//sxt/base/error:assert",
    ],
    test_deps = [
        ":test_kernel",
        "//sxt/base/device:stream_handle",
        "//sxt/base/device:stream_pool",
        "//sxt/base/device:stream",
        "//sxt/base/device:memory_utility",
        "//sxt/base/test:unit_test",
        "//sxt/memory/management:managed_array",
        "//sxt/memory/resource:device_resource",
        "//sxt/memory/resource:pinned_resource",
    ],
)

sxt_cc_component(
    name = "synchronization",
    test_deps = [
        ":test_kernel",
        "//sxt/execution/async:coroutine",
        "//sxt/base/test:unit_test",
        "//sxt/memory/management:managed_array",
    ],
    deps = [
        ":computation_event",
        "//sxt/base/device:event",
        "//sxt/base/device:event_utility",
        "//sxt/base/device:property",
        "//sxt/base/device:stream",
        "//sxt/base/type:raw_stream",
        "//sxt/execution/async:future",
        "//sxt/execution/async:promise",
        "//sxt/execution/schedule:scheduler",
    ],
)