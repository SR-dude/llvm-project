//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ios>

// class ios_base

// fmtflags setf(fmtflags fmtfl, fmtflags mask);

#include <ios>
#include <cassert>

class test
    : public std::ios
{
public:
    test()
    {
        init(0);
    }
};

int main()
{
    test t;
    assert(t.flags() == (test::skipws | test::dec));
    test::fmtflags f = t.setf(test::hex | test::right, test::dec | test::right);
    assert(f == (test::skipws | test::dec));
    assert(t.flags() == (test::skipws | test::right));
}
