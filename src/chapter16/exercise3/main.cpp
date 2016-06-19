//
// Created by crypt on 6/19/16.
//

#include <stdexcept>
#include <iostream>

using namespace std;
namespace exercise16_3 {

    class Point {

    public:
        double x;
        double y;

        Point(double x, double y) : x(x), y(y) { }

        friend ostream &operator<<(ostream &ost, Point &p) {
            ost << "(" << p.x << "," << p.y << ")";
            return ost;
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
                }
                double y = -(a * x + c) / b;
                return Point(x, y);
            } else if ( c == line.c ){
                throw std::invalid_argument("The lines are parallel and adjacent");
            }
            throw std::invalid_argument("The lines don't intersect");
        }

        friend ostream &operator<<(ostream &ost, Line &line) {
            ost << showpos << line.a << "x " << line.b << "y " << line.c;
            return ost;
        }
    };

    void main() {

        Line l1 = Line::create(Point(3, 3), Point(2, 2));
        Line l2 = Line::create(Point(1, 1), Point(2, 2));
        cout << "line1: " << l1 << endl;
        cout << "line2: " << l2 << endl;
        Point p1 = (l1 % l2);
        cout << "Found intersection point: " << p1 << endl;
    }
}