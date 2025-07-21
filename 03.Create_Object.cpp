#include <bits/stdc++.h>
#define int long long
using namespace std;
class Shape {
private:
    int a, b;
public:
    Shape() {}                              // default constructor
    Shape(int _a, int _b) : a(_a), b(_b) {} // constructor
    double area() {}
    double perimeter() {}
    ~Shape() = default; // destructor
};
signed main() {
    Shape circle(1, 2);
    return 0;
}