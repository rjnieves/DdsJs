/**
 * @brief Contains the definition of the `counterpartType()` function.
 * @author Rolando J. Nieves
 * @date 2024-03-12 14:27:32
 */

import { BaseCodecProxy, CppInstanceWrapper } from "../model";
import { coreDxProxyCounterpartType } from "./coredx";
import { coreDxWrapperCounterpartClass } from "./coredx/counterpart-type";


export class CounterpartTypeGen {
  public constructor(public readonly providerName: string) {}

  public forProxy(codecProxy: BaseCodecProxy): string {
    if (this.providerName === "CoreDX") {
      return coreDxProxyCounterpartType(codecProxy);
    } else {
      let msg = `Unsupported DDS provider "${this.providerName}".`;
      throw new Error(msg);
    }
  }

  public forWrapper(wrapper: CppInstanceWrapper): string {
    if (this.providerName === "CoreDX") {
      return coreDxWrapperCounterpartClass(wrapper);
    } else {
      let msg = `Unsupported DDS provider "${this.providerName}".`;
      throw new Error(msg);
    }
  }
}

// vim: set ts=2 sw=2 expandtab:
