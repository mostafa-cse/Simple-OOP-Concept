#include <bits/stdc++.h>
#define int long long
using namespace std;
class Shape {
public:    // current class can use only
protected: // onherited & own class can use on only
    int a, b;

public:
    Shape() {}                              // default constructor
    Shape(int _a, int _b) : a(_a), b(_b) {} // constructor
    virtual double area() {}
    virtual double perimeter() {}
    ~Shape() = default; // destructor
};
class Circle : Shape { // Circle inherits Shape
private:

public:
    double area() override{
        return M_PI * a * a;
    }
    
    double perimeter() override {
        return 2 * M_PI * a;
    }
};
class Tropozium : Shape { // Tropozium inherits Shape
private:
    int h;
public:
    Tropozium() {}
    Tropozium(int _h) : h(_h) {}
    double area() override {
        return 0.5 * (a + b) * h; 
    }
    double perimeter() override {
        return a + b + 2 * h;
    }
};
signed main() {
    
    return 0;
}