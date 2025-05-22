
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off

#include <string>
#include <optional>
#include <functional>
#include <vector>

namespace ReactNativeWindowsHelloCodegen {

struct WindowsHelloSpec_availabilityStatus {
    double value;
    std::string message;
};

struct WindowsHelloSpec_verificationResult {
    double value;
    std::string message;
};

} // namespace ReactNativeWindowsHelloCodegen
