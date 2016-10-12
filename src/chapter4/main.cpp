#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;


namespace exercise_04_1 { void main_04_1(); }
namespace exercise_04_2 { void main_04_2(); }
namespace exercise_04_3 { void main_04_3(); }
namespace exercise_04_4 { void main_04_4(); }
namespace exercise_04_5 { void main_04_5(); }
namespace exercise_04_6 { void main_04_6(); }

#include <iostream>

using namespace std;

int main_chapter4(const int argc, const char **argv) {
    cout << endl << "CHAPTER 4 ==============================" << endl;
    exercise_04_1::main_04_1();
    /*
     exercise_04_2::main_04_2();
     exercise_04_3::main_04_3();
     exercise_04_4::main_04_4();
     exercise_04_5::main_04_5();
     exercise_04_6::main_04_6();
    */
    return 0;
}