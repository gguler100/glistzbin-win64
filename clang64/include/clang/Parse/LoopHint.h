//===--- LoopHint.h - Types for LoopHint ------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_PARSE_LOOPHINT_H
#define LLVM_CLANG_PARSE_LOOPHINT_H

#include "clang/Basic/IdentifierTable.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Sema/Ownership.h"
#include "clang/Sema/ParsedAttr.h"

namespace clang {

/// Loop optimization hint for loop and unroll pragmas.
struct LoopHint {
  // Source range of the directive.
  SourceRange Range;
  // Identifier corresponding to the name of the pragma.  "loop" for
  // "#pragma clang loop" directives and "unroll" for "#pragma unroll"
  // hints.
  IdentifierLoc *PragmaNameLoc;
  // Name of the loop hint.  Examples: "unroll", "vectorize".  In the
  // "#pragma unroll" and "#pragma nounroll" cases, this is identical to
  // PragmaNameLoc.
  IdentifierLoc *OptionLoc;
  // Identifier for the hint state argument.  If null, then the state is
  // default value such as for "#pragma unroll".
  IdentifierLoc *StateLoc;
  // Expression for the hint argument if it exists, null otherwise.
  Expr *ValueExpr;

  LoopHint()
      : PragmaNameLoc(nullptr), OptionLoc(nullptr), StateLoc(nullptr),
        ValueExpr(nullptr) {}
};

} // end namespace clang

#endif // LLVM_CLANG_PARSE_LOOPHINT_H