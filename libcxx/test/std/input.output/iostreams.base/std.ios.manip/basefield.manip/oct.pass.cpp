//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ios>

// class ios_base

// ios_base& oct(ios_base& str);

#include <ios>
#include <streambuf>
#include <cassert>

struct testbuf : public std::streambuf {};

int main()
{
    testbuf sb;
    std::ios ios(&sb);
    std::ios_base& r = std::oct(ios);
    assert(&r == &ios);
    assert(ios.flags() & std::ios::oct);
}
