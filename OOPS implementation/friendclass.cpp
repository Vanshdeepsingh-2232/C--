#include<iostream>
using namespace std;

class calculator;  // Forward declaration

class Abc {
    int a = 10, b = 10, c = 10, d = 10;

    friend class calculator;
};

class calculator {
public:
    void sum(Abc obj) {
        cout << obj.a + obj.b + obj.c + obj.d << endl;
    }
};

int main() {
    Abc a1;
    calculator calc;  // Create an instance of the calculator class
    calc.sum(a1);     // Call the sum function on the calculator instance
    return 0;
}
