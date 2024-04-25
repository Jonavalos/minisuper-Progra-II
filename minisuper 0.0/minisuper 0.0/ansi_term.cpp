//#include "ansi_term.h"
//
//using namespace std;
//
//namespace ansi_term {
//
//    void init(int cp) {
//#if defined(__MINGW32__) || defined(__CYGWIN__)
//        stringstream cmd;
//        cmd << "chcp " << cp;
//        system(cmd.str().c_str());
//        system("cls");
//#else
//        // system("clear");
//#endif
//
//        background(BLACK);
//        color(WHITE);
//    }
//
//    string reset() {
//        stringstream r;
//        r << "\e[0m";
//        return r.str();
//    }
//
//    string clear() {
//        stringstream r;
//        r << "\e[2J";
//        return r.str();
//    }
//
//    string clear_eol() {
//        stringstream r;
//        r << "\e[0J";
//        return r.str();
//    }
//
//    string home() {
//        stringstream r;
//        r << "\e[H";
//        return r.str();
//    }
//
//    string gotoxy(int x, int y) {
//        stringstream r;
//        r << "\e[" << y << ";" << x << "H";
//        return r.str();
//    }
//
//    string color(int c) {
//        stringstream r;
//        r << "\e[38;5;" << c << "m";
//        return r.str();
//    }
//
//    string background(int c, bool bright) {
//        stringstream r;
//        r << "\e[" << (c + 40);
//        if (bright) {
//            r << ";1";
//        }
//        r << "m";
//        return r.str();
//    }
//
//    int utf8_strlen(const string& str) {
//        // http://www.zedwood.com/article/cpp-utf8-strlen-function
//        int c, i, ix, q;
//        for (q = 0, i = 0, ix = str.length(); i < ix; i++, q++) {
//            c = (unsigned char)str[i];
//            if (c >= 0 && c <= 127) i += 0;
//            else if ((c & 0xE0) == 0xC0) i += 1;
//            else if ((c & 0xF0) == 0xE0) i += 2;
//            else if ((c & 0xF8) == 0xF0) i += 3;
//            //else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
//            //else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
//            else return 0; //invalid utf8
//        }
//        return q;
//    }
//
//}