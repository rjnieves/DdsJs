/**
 * @brief Contains the definition of the `CppInstanceWrapper` class.
 * @author Rolando J. Nieves
 * @date 2024-02-15 18:28:03
 */

import { CppNameGen, DestinationFolder, HeaderFileBase, ImplementationFileBase } from "../codegen";
import { OwnedCodecProxy } from "./owned-codec-proxy";


export abstract class CppInstanceWrapper {
  public headerFile: HeaderFileBase< any > | null;
  public implementationFile: ImplementationFileBase< any > | null;
  public providerHeader: string | null;
  public readonly name: string;
  public readonly baseWrapperName: string;
  public readonly cppCounterpartName: string;
  public constructor(public readonly supportedProxy: OwnedCodecProxy, nameGen: CppNameGen) {
    this.name = nameGen.wrapperNameFor(this);
    this.baseWrapperName = nameGen.baseWrapperNameFor(this);
    this.cppCounterpartName = nameGen.typeGen.forWrapper(this);
    this.headerFile = null;
    this.implementationFile = null;
    this.providerHeader = null;
  }

  public abstract emit(destination: DestinationFolder, providerHeader: string): void;
}

// vim: set ts=2 sw=2 expandtab:
