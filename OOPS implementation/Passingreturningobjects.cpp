#include<iostream>
using namespace std;

class Point {
    int x, y;
public:

    Point(int a, int b) {
        x = a; y = b;
    }

    static Point addpoint(Point p1, Point p2) {
        Point temp;
        temp.x = p1.x + p2.x;
        temp.y = p1.y + p2.y;
        return temp;
    }

    void showPoint() {
        cout << "X=" << x << endl;
        cout << "Y=" << y << endl;
    }
};

int main() {
    Point p1(2, 3);
    Point p2(3, 4);
    
    Point p3 = Point::addpoint(p1, p2);
    
    p3.showPoint();

    return 0;
}
