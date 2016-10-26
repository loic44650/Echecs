#pragma once

#include <ostream>

namespace Color {
    enum Code {
        FG_BLACK     = 30,
        FG_WHITE     = 97,
        FG_DEFAULT   = 39,
        BG_LIGHTBLUE = 104,
        BG_LIGHTGREY = 47,
        BG_DARKGRAY  = 100,
        BG_DEFAULT   = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
