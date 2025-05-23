#include "pch.h"
#include "ReactNativeWindowsHello.h"

#include <winrt/Microsoft.ReactNative.h>
#include <winrt/Windows.Security.Credentials.UI.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/base.h>

using namespace winrt;
using namespace Windows::Security::Credentials::UI;
using namespace Windows::Foundation;
using namespace Microsoft::ReactNative;

namespace winrt::ReactNativeWindowsHello {

void ReactNativeWindowsHello::Initialize(ReactContext const& reactContext) noexcept {
    m_context = reactContext;
}

// Map availability result to the JS-expected struct
ReactNativeWindowsHelloCodegen::WindowsHelloSpec_availabilityStatus ToAvailabilityStatus(UserConsentVerifierAvailability availability) {
    switch (availability) {
        case UserConsentVerifierAvailability::Available:
            return { 0.0, "A biometric verifier device is available." };
        case UserConsentVerifierAvailability::DeviceNotPresent:
            return { 1.0, "There is no biometric verifier device available." };
        case UserConsentVerifierAvailability::NotConfiguredForUser:
            return { 2.0, "A biometric verifier device is not configured for this user." };
        case UserConsentVerifierAvailability::DisabledByPolicy:
            return { 3.0, "Group policy has disabled the biometric verifier device." };
        case UserConsentVerifierAvailability::DeviceBusy:
            return { 4.0, "The biometric verifier device is performing an operation and is unavailable." };
        default:
            return { 1.0, "Unknown error" };
    }
}

// Map verification result to the JS-expected struct
ReactNativeWindowsHelloCodegen::WindowsHelloSpec_verificationResult ToVerificationResult(UserConsentVerificationResult result) {
    switch (result) {
        case UserConsentVerificationResult::Verified:
            return { 0.0, "User consent verified" };
        case UserConsentVerificationResult::DeviceNotPresent:
            return { 1.0, "There is no biometric verifier device available." };
        case UserConsentVerificationResult::NotConfiguredForUser:
            return { 2.0, "A biometric verifier device is not configured for this user." };
        case UserConsentVerificationResult::DisabledByPolicy:
            return { 3.0, "Group policy has disabled the biometric verifier device." };
        case UserConsentVerificationResult::DeviceBusy:
            return { 4.0, "The biometric verifier device is performing an operation and is unavailable." };
        case UserConsentVerificationResult::RetriesExhausted:
            return { 5.0, "After 10 attempts, verification failed." };
        case UserConsentVerificationResult::Canceled:
            return { 6.0, "The verification operation was canceled." };
        default:
            return { 6.0, "Unknown error" };
    }
}

void ReactNativeWindowsHello::getDeviceStatus(ReactPromise<ReactNativeWindowsHelloCodegen::WindowsHelloSpec_availabilityStatus>&& result) noexcept {
    try {
        UserConsentVerifier::CheckAvailabilityAsync().Completed(
            [result = std::move(result)](IAsyncOperation<UserConsentVerifierAvailability> const& op, AsyncStatus const status) mutable {
                if (status == AsyncStatus::Completed) {
                    auto availability = op.GetResults();
                    result.Resolve(ToAvailabilityStatus(availability));
                } else {
                    result.Reject("Failed to retrieve biometric availability.");
                }
            });
    } catch (...) {
        result.Reject("Exception occurred while checking device status.");
    }
}

void ReactNativeWindowsHello::requestConsentVerification(std::string promptMessage, ReactPromise<ReactNativeWindowsHelloCodegen::WindowsHelloSpec_verificationResult>&& result) noexcept {
    try {
        hstring hPrompt = to_hstring(promptMessage);
        UserConsentVerifier::RequestVerificationAsync(hPrompt).Completed(
            [result = std::move(result)](IAsyncOperation<UserConsentVerificationResult> const& op, AsyncStatus const status) mutable {
                if (status == AsyncStatus::Completed) {
                    auto verificationResult = op.GetResults();
                    result.Resolve(ToVerificationResult(verificationResult));
                } else {
                    result.Reject("Failed to complete consent verification.");
                }
            });
    } catch (...) {
        result.Reject("Exception occurred during consent verification.");
    }
}

} // namespace winrt::ReactNativeWindowsHello