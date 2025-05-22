// @flow
import type { TurboModule } from 'react-native/Libraries/TurboModule/RCTExport';
import { TurboModuleRegistry } from 'react-native';

type availabilityStatus = {
    +value: number,
    +message: string,
}

type verificationResult = {
    +value: number,
    +message: string,
}

export interface Spec extends TurboModule {
    +getDeviceStatus: () => Promise<availabilityStatus>;
    +requestConsentVerification: (promptMessage : string) => Promise<verificationResult>;
}

export default (TurboModuleRegistry.get<Spec>('ReactNativeWindowsHello'): ?Spec);