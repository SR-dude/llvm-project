//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// unique_ptr

// test reset against resetting self

#include <memory>

struct A {
  std::unique_ptr<A> ptr_;

  A() : ptr_(this) {}
  void reset() { ptr_.reset(); }
};

int main() { (new A)->reset(); }
