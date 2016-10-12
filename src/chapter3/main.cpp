#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;


namespace exercise3_1 { void main_03_1(); }
namespace exercise3_2 { void main_03_2(); }
namespace exercise3_3 { void main_03_3(); }
namespace exercise3_4 { void main_03_4(); }
namespace exercise3_5 { void main_03_5(); }
namespace exercise3_6 { void main_03_6(); }

#include <iostream>

using namespace std;

int main_chapter3(const int argc, const char **argv) {
    cout << endl << "CHAPTER 3 ==============================" << endl;
    exercise3_1::main_03_1();
    /*
     exercise3_2::main_03_2();
     exercise3_3::main_03_3();
     exercise3_4::main_03_4();
     exercise3_5::main_03_5();
     exercise3_6::main_03_6();
    */
    return 0;
}