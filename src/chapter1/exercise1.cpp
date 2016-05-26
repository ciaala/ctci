#include <iostream>
#include <stack>

using namespace std;


void sortStack(stack<int> &s) {
    stack<int> aux;
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (aux.empty() || v < aux.top()) {
            aux.push(v);

        } else {
            int c;
            do {
                c = aux.top();
                aux.pop();
                s.push(c);
            } while (c < v && !aux.empty());
            s.push(v);
        }
    }
    while (!aux.empty()) {
        s.push(aux.top());
        aux.pop();
    }
}

void
test_sorting() {
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(3);
    s.push(2);
    s.push(7);
    s.push(1);
    sortStack(s);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}

template<size_t rows, size_t cols>
void rotate90degree(int32_t (&image)[rows][cols]) {
    cout << cols << "x" << rows << endl;
}

void
test_rotate90degree() {
    int32_t image[20][20];
    int32_t image2[40][40];

    rotate90degree(image);
    rotate90degree(image2);
}

int main_EX11(const int argc, const char **argv) {
    cout << "Hello, World!" << endl;
    test_sorting();
    return 0;
}
