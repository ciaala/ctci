//
// Created by crypt on 5/25/2016.
//
#include <iostream>
#include <exception>

using namespace std;

int main_chapter1(const int, const char **);

int main_chapter2(const int, const char **);

int main_chapter3(const int, const char **);

int main_chapter4(const int, const char **);


int main_chapter5(const int, const char **);

int main_chapter_08(const int, const char **);

int main_chapter10(const int, const char **);

int main_chapter15(const int, const char **);

int main_chapter16(const int, const char **);

int main_chapter17(const int, const char **);

int main(const int argc, const char **argv) {
    try {
        main_chapter1(argc, argv);
        main_chapter2(argc, argv);
        main_chapter3(argc, argv);
        main_chapter4(argc, argv);
        //main_chapter5(argc, argv);

        main_chapter_08(argc, argv);
        // main_chapter10(argc, argv);
        //main_chapter15(argc, argv);
        //main_chapter16(argc, argv);
        //main_chapter17(argc, argv);
    } catch (exception &e) {
        cout << "Exception catched. " << e.what() << endl;
    }
    cout << "Exiting" << endl;
    return 0;
}
