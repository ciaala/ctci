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

        Point operator%(Line &line) {
            // double YY = thils
            // double XX =
            double denominator = (a * line.b - b * line.a);
            if (denominator != 0) {
                double x;
                if (line.b != 0) {
                    x = -(c - (b * line.c) / line.b) * (line.b / denominator);
                } else if (b != 0) {
                    x = -(line.c - (line.b * c) / b) * (b / denominator);
                } else {
                    throw std::invalid_argument("algorithm cannot proceed");
                }
                double y = -(a * x + c) / b;
                return Point(x, y);
            } else if (c == line.c) {
                throw std::invalid_argument("The lines are parallel and adjacent");
            }
            throw std::invalid_argument("The lines don't intersect");
        }

        friend ostream &operator<<(ostream &ost, const Line &line) {
            ost << showpos << line.a << "x " << line.b << "y " << line.c;
            return ost;
        }
    };

    void main() {
        Square sq1 = Square({20, 20}, {50, 50});
        Square sq2 = Square({2000, 10}, {2030, 900});
        Line diag = Line::create(sq1.getCenter(), sq2.getCenter());
        // TODO intersect with the perimeter of the square
        // TODO check condition to find the side of the sq1 and sq2 which are not facing
        // TODO compare the slope of the diagonals vs slope of the center-line
        // TODO to be discussed ...
        cout << diag << endl;

    }

}
