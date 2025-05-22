
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off

// #include "NativeWindowsHelloDataTypes.g.h" before this file to use the generated type definition
#include <NativeModules.h>
#include <tuple>

namespace ReactNativeWindowsHelloCodegen {

inline winrt::Microsoft::ReactNative::FieldMap GetStructInfo(WindowsHelloSpec_availabilityStatus*) noexcept {
    winrt::Microsoft::ReactNative::FieldMap fieldMap {
        {L"value", &WindowsHelloSpec_availabilityStatus::value},
        {L"message", &WindowsHelloSpec_availabilityStatus::message},
    };
    return fieldMap;
}

inline winrt::Microsoft::ReactNative::FieldMap GetStructInfo(WindowsHelloSpec_verificationResult*) noexcept {
    winrt::Microsoft::ReactNative::FieldMap fieldMap {
        {L"value", &WindowsHelloSpec_verificationResult::value},
        {L"message", &WindowsHelloSpec_verificationResult::message},
    };
    return fieldMap;
}

struct WindowsHelloSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      Method<void(Promise<WindowsHelloSpec_availabilityStatus>) noexcept>{0, L"getDeviceStatus"},
      Method<void(std::string, Promise<WindowsHelloSpec_verificationResult>) noexcept>{1, L"requestConsentVerification"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, WindowsHelloSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "getDeviceStatus",
          "    REACT_METHOD(getDeviceStatus) void getDeviceStatus(::React::ReactPromise<WindowsHelloSpec_availabilityStatus> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(getDeviceStatus) static void getDeviceStatus(::React::ReactPromise<WindowsHelloSpec_availabilityStatus> &&result) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          1,
          "requestConsentVerification",
          "    REACT_METHOD(requestConsentVerification) void requestConsentVerification(std::string promptMessage, ::React::ReactPromise<WindowsHelloSpec_verificationResult> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(requestConsentVerification) static void requestConsentVerification(std::string promptMessage, ::React::ReactPromise<WindowsHelloSpec_verificationResult> &&result) noexcept { /* implementation */ }\n");
  }
};

} // namespace ReactNativeWindowsHelloCodegen
