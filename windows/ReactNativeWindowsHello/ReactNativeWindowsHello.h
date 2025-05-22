#pragma once

#include "pch.h"
#include "resource.h"

#if __has_include("codegen/NativeReactNativeWindowsHelloDataTypes.g.h")
  #include "codegen/NativeReactNativeWindowsHelloDataTypes.g.h"
#endif
#include "codegen/NativeReactNativeWindowsHelloSpec.g.h"

#include "NativeModules.h"

namespace winrt::ReactNativeWindowsHello
{

REACT_MODULE(ReactNativeWindowsHello)
struct ReactNativeWindowsHello
{
  using ModuleSpec = ReactNativeWindowsHelloCodegen::ReactNativeWindowsHelloSpec;

  REACT_INIT(Initialize)
  void Initialize(React::ReactContext const &reactContext) noexcept;

  REACT_SYNC_METHOD(multiply)
  double multiply(double a, double b) noexcept;

private:
  React::ReactContext m_context;
};

} // namespace winrt::ReactNativeWindowsHello