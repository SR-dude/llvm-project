//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iomanip>

// template<charT> T4 setfill(charT c);

#include <iomanip>
#include <ostream>
#include <cassert>

template <class CharT>
struct testbuf
    : public std::basic_streambuf<CharT>
{
    testbuf() {}
};

int main()
{
    {
        testbuf<char> sb;
        std::ostream os(&sb);
        os << std::setfill('*');
        assert(os.fill() == '*');
    }
    {
        testbuf<wchar_t> sb;
        std::wostream os(&sb);
        os << std::setfill(L'*');
        assert(os.fill() == L'*');
    }
}
