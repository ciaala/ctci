//
// Created by crypt on 5/25/2016.
//
#include <iostream>

int main_chapter1(const int, const char **);

int main_chapter2(const int, const char **);

int main_chapter3(const int, const char **);

int main_chapter5(const int, const char **);

int main_chapter10(const int, const char **);

int main_chapter15(const int, const char **);

int main_chapter16(const int, const char **);

int main_chapter17(const int, const char **);

int main(const int argc, const char **argv) {
    try {
        main_chapter1(argc, argv);
        main_chapter2(argc, argv);
        main_chapter3(argc, argv);
        //main_chapter5(argc, argv);

        // main_chapter10(argc, argv);
        //main_chapter15(argc, argv);
        //main_chapter16(argc, argv);
        //main_chapter17(argc, argv);
    } catch (...) {
        std::cout << "Exception catched" << std::endl;
    }
    std::cout << "Exiting" << std::endl;
    return 0;
}
