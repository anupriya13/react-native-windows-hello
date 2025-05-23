#pragma once

#include "pch.h"
#include "resource.h"

#if __has_include("codegen/NativeWindowsHelloDataTypes.g.h")
  #include "codegen/NativeWindowsHelloDataTypes.g.h"
#endif
#include "codegen/NativeWindowsHelloSpec.g.h"

#include "NativeModules.h"

namespace winrt::ReactNativeWindowsHello
{

REACT_MODULE(ReactNativeWindowsHello)
struct ReactNativeWindowsHello
{
  using ModuleSpec = ReactNativeWindowsHelloCodegen::WindowsHelloSpec;

  REACT_INIT(Initialize)
  void Initialize(React::ReactContext const &reactContext) noexcept;

  REACT_METHOD(getDeviceStatus) 
  void getDeviceStatus(::React::ReactPromise<ReactNativeWindowsHelloCodegen::WindowsHelloSpec_availabilityStatus> &&result) noexcept;

  REACT_METHOD(requestConsentVerification) 
  void requestConsentVerification(std::string promptMessage, ::React::ReactPromise<ReactNativeWindowsHelloCodegen::WindowsHelloSpec_verificationResult> &&result) noexcept;

private:
  React::ReactContext m_context;
};

} // namespace winrt::ReactNativeWindowsHello