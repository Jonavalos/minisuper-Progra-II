//#ifndef CONSOLE_H
//#define CONSOLE_H
//
//#include <iostream>
//#include <cstdlib>
//#include <exception>
//#include <sstream>
//
///* -----------------------------------------------------
// *
// * (c) 2019-2023
// * Georges Alfaro S.
// * version 2.2.1 2023-04-25
// *
// * https://invisible-island.net/xterm/ctlseqs/ctlseqs.html
// * https://www.ecma-international.org/publications-and-standards/standards/ecma-48/
// * https://www.ecma-international.org/wp-content/uploads/ECMA-48_5th_edition_june_1991.pdf
// * http://www.zedwood.com/article/cpp-utf8-strlen-function
// *
// * -----------------------------------------------------
// */
//
//namespace ansi_term {
//
//    enum color {
//        BLACK = 0,
//        RED,
//        GREEN,
//        YELLOW,
//        BLUE,
//        MAGENTA,
//        CYAN,
//        WHITE,
//
//        BRIGHT_BLACK,
//        BRIGHT_RED,
//        BRIGHT_GREEN,
//        BRIGHT_YELLOW,
//        BRIGHT_BLUE,
//        BRIGHT_MAGENTA,
//        BRIGHT_CYAN,
//        BRIGHT_WHITE
//    };
//
//    enum code_page {
//        IBMPC_OEM = 437,
//        UNICODE = 65001
//    };
//
//    void init(int = UNICODE);
//    std::string reset();
//
//    std::string clear();
//    std::string clear_eol();
//    std::string home();
//    std::string gotoxy(int, int);
//
//    std::string color(int);
//    std::string background(int, bool = false);
//
//    int utf8_strlen(const std::string&);
//
//};
//
//#endif /* CONSOLE_H */