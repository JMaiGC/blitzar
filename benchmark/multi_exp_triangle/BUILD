load("//bazel:sxt_benchmark.bzl", "sxt_cc_benchmark")

sxt_cc_benchmark(
    name = "benchmark",
    srcs = [
        "benchmark.m.cc",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//sxt/base/curve:element",
        "//sxt/base/num:fast_random_number_generator",
        "//sxt/curve21/operation:add",
        "//sxt/curve21/operation:double",
        "//sxt/curve21/operation:neg",
        "//sxt/curve21/type:element_p3",
        "//sxt/curve_bng1/operation:add",
        "//sxt/curve_bng1/operation:double",
        "//sxt/curve_bng1/operation:neg",
        "//sxt/curve_bng1/random:element_p2",
        "//sxt/curve_bng1/type:conversion_utility",
        "//sxt/curve_bng1/type:element_affine",
        "//sxt/curve_bng1/type:element_p2",
        "//sxt/curve_g1/operation:add",
        "//sxt/curve_g1/operation:compression",
        "//sxt/curve_g1/operation:double",
        "//sxt/curve_g1/operation:neg",
        "//sxt/curve_g1/random:element_p2",
        "//sxt/curve_g1/type:compressed_element",
        "//sxt/curve_g1/type:conversion_utility",
        "//sxt/curve_g1/type:element_p2",
        "//sxt/curve_gk/operation:add",
        "//sxt/curve_gk/operation:double",
        "//sxt/curve_gk/operation:neg",
        "//sxt/curve_gk/random:element_p2",
        "//sxt/curve_gk/type:conversion_utility",
        "//sxt/curve_gk/type:element_affine",
        "//sxt/curve_gk/type:element_p2",
        "//sxt/execution/schedule:scheduler",
        "//sxt/memory/resource:pinned_resource",
        "//sxt/multiexp/pippenger2:in_memory_partition_table_accessor_utility",
        "//sxt/multiexp/pippenger2:variable_length_multiexponentiation",
        "//sxt/ristretto/operation:compression",
        "//sxt/ristretto/type:compressed_element",
        "//sxt/seqcommit/generator:base_element",
    ],
)
