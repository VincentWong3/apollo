load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install", "install_files")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "simple_writer",
    srcs = ["simple_writer.cc"],
    deps = [
        "//cyber",
        "//modules/simple/proto:input_cc_proto",
    ],
)

cc_binary(
    name = "libsimple_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":simple_component.lib"],
)

cc_library(
    name = "simple_component.lib",
    hdrs = ["simple_component.h"],
    srcs = ["simple_component.cc"],
    deps = [
        "//cyber",
        "//modules/simple/proto:input_cc_proto",
    ],
)