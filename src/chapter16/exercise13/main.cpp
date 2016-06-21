//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>

using namespace std;

namespace exercise16_13 {

    class Point {
        double x;
        double y;
    public:

        Point(double x, double y) : x(x), y(y) {

        }

        friend class Square;
        friend class Line;
    };

    class Square {
    private:
        Point lowerRight;
        Point topLeft;
    public:
        Square(const Point &lowerRight, const Point &topLeft) : lowerRight(lowerRight), topLeft(topLeft) {
        }

        Point getCenter() {
            return Point((lowerRight.x + topLeft.x) / 2, (lowerRight.y + topLeft.y) / 2);
        }
    };

    class Line {
    private:
        Line(double a, double b, double c) :
                a(a), b(b), c(c) { };

    public:

        double a;
        double b;
        double c;


        static Line create(Point pa, Point pb) {
            if (pa.x != pb.x || pa.y != pb.y) {
                return Line(
                        pa.y - pb.y,
                        pb.x - pa.x,
                        pa.x * pb.y - pb.x * pa.y
                );
            } else {
                throw std::invalid_argument("Both points are the same");
            }
        }
        friend ostream &operator<<(ostream &ost, const Line &line) {
            ost << showpos << line.a << "x " << line.b << "y " << line.c;
            return ost;
        }
    };

    void main() {
        Square sq1 = Square({20,20}, {50, 50});
        Square sq2 = Square({2000,10}, {2030,900});

        cout << Line::create(sq1.getCenter(), sq2.getCenter()) << endl;

    }

}
