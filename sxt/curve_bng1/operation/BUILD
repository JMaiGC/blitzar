load(
    "//bazel:sxt_build_system.bzl",
    "sxt_cc_component",
)

sxt_cc_component(
    name = "add",
    impl_deps = [
        ":cmov",
        "//sxt/curve_bng1/property:identity",
        "//sxt/curve_bng1/type:element_affine",
    ],
    is_cuda = True,
    test_deps = [
        ":double",
        "//sxt/base/num:fast_random_number_generator",
        "//sxt/base/test:unit_test",
        "//sxt/curve_bng1/constant:generator",
        "//sxt/curve_bng1/property:curve",
        "//sxt/curve_bng1/property:identity",
        "//sxt/curve_bng1/type:element_affine",
        "//sxt/field25/random:element",
        "//sxt/field25/type:element",
    ],
    deps = [
        ":mul_by_3b",
        "//sxt/base/macro:cuda_callable",
        "//sxt/curve_bng1/type:element_p2",
        "//sxt/field25/operation:add",
        "//sxt/field25/operation:mul",
        "//sxt/field25/operation:sub",
    ],
)

sxt_cc_component(
    name = "cmov",
    impl_deps = [
        "//sxt/curve_bng1/type:element_affine",
        "//sxt/curve_bng1/type:element_p2",
        "//sxt/field25/operation:cmov",
    ],
    is_cuda = True,
    test_deps = [
        "//sxt/base/test:unit_test",
        "//sxt/curve_bng1/constant:generator",
        "//sxt/curve_bng1/type:element_affine",
        "//sxt/curve_bng1/type:element_p2",
    ],
    deps = [
        "//sxt/base/macro:cuda_callable",
    ],
)

sxt_cc_component(
    name = "double",
    impl_deps = [
        ":cmov",
        ":mul_by_3b",
        "//sxt/curve_bng1/property:identity",
        "//sxt/curve_bng1/type:element_p2",
        "//sxt/field25/operation:add",
        "//sxt/field25/operation:mul",
        "//sxt/field25/operation:square",
        "//sxt/field25/operation:sub",
        "//sxt/field25/type:element",
    ],
    is_cuda = True,
    test_deps = [
        "//sxt/base/test:unit_test",
        "//sxt/curve_bng1/constant:generator",
        "//sxt/curve_bng1/property:curve",
        "//sxt/curve_bng1/property:identity",
        "//sxt/curve_bng1/type:element_p2",
        "//sxt/field25/constant:zero",
    ],
    deps = [
        "//sxt/base/macro:cuda_callable",
    ],
)

sxt_cc_component(
    name = "mul_by_3b",
    test_deps = [
        "//sxt/base/test:unit_test",
        "//sxt/field25/constant:one",
        "//sxt/field25/type:element",
        "//sxt/field25/type:literal",
    ],
    deps = [
        "//sxt/base/macro:cuda_callable",
        "//sxt/field25/operation:add",
        "//sxt/field25/type:element",
    ],
)

sxt_cc_component(
    name = "neg",
    impl_deps = [
        "//sxt/curve_bng1/type:element_p2",
        "//sxt/field25/operation:cmov",
        "//sxt/field25/operation:neg",
        "//sxt/field25/type:element",
    ],
    is_cuda = True,
    test_deps = [
        ":add",
        "//sxt/base/test:unit_test",
        "//sxt/curve_bng1/constant:generator",
        "//sxt/curve_bng1/type:element_p2",
    ],
    deps = [
        "//sxt/base/macro:cuda_callable",
    ],
)

sxt_cc_component(
    name = "scalar_multiply",
    impl_deps = [
        ":add",
        ":double",
        "//sxt/curve_bng1/type:element_p2",
    ],
    is_cuda = True,
    test_deps = [
        ":add",
        ":double",
        "//sxt/base/test:unit_test",
        "//sxt/curve_bng1/constant:generator",
        "//sxt/curve_bng1/type:element_p2",
    ],
    deps = [
        "//sxt/base/macro:cuda_callable",
    ],
)
