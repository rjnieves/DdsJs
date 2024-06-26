/**
 * @brief Contains the definition of the `OwnedCodecProxy` class.
 * @author Rolando J. Nieves
 * @date 2024-02-16 12:04:11
 */

import { DestinationFolder, HeaderFileBase, ImplementationFileBase } from "../codegen";
import { BaseCodecProxy } from "./codec-proxy";
import { ScopeContainer } from "./scope-container";
import { ScopeMember } from "./scope-member";


export abstract class OwnedCodecProxy extends BaseCodecProxy implements ScopeMember {
  public headerFile: HeaderFileBase< any > | null;
  public implementationFile: ImplementationFileBase< any > | null;
  public providerHeader: string | null;
  
  public constructor(idlName: string, napiContainerName: string, public readonly owner: ScopeContainer, jsTypeName?: string) {
    super(idlName, napiContainerName, jsTypeName || idlName);
    this.headerFile = null;
    this.implementationFile = null;
    this.providerHeader = null;
  }

  public abstract emit(destination: DestinationFolder, providerHeader: string): void;
}

// vim: set ts=2 sw=2 expandtab:
