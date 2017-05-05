#include <iostream>
using namespace std;
#include "Fraction.h"
#include "FractionB14CS040.cpp"
void TestFraction()
{
    cout << "\nTest Fraction Data Type" << endl;
    // CONSTRUCTORS
    // ------------
    Fraction f1(5, 3);
    Fraction f3,f2;
    cout << "Fraction f1(5, 3) = " << f1 << endl;
    cout << "Fraction f3 = " << f3 << endl;
    // BASIC ASSIGNMENT OPERATOR
    // --------------------------
    // Fraction& operator=(const Fraction&);
    cout << "Assignment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = f1;
    cout << "Assignment (After): f3 = " << f3 << ". f1 = " << f1 << endl;
    // UNARY ARITHMETIC OPERATORS
    // --------------------------
    // Fraction operator-(); // Operand 'this' implicit
    f3 = -f1;
    cout << "Unary Minus: f3 = " << f3 << ". f1 = " << f1 << endl;
    // Fraction operator+();
    // Fraction operator--(); // Pre-decrement. Dividendo
    cout << "Pre-Decrement (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = --f1;
    cout << "Pre-Decrement (After): f3 = " << f3 << ". f1 = " << f1 << endl;
    cout << "Pre-Increment (Before): f3 = " << f3 << ". f1 = " << f1 << endl;
    f3 = ++f1;
    cout << "Pre-Increment (After): f3 = " << f3 << ". f1 = " << f1 << endl;
    // BINARY ARITHMETIC OPERATORS USING FRIEND FUNCTIONS
    // --------------------------------------------------
    // friend Fraction operator+(const Fraction&, const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f1 + f2;
    cout << "Binary Plus: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;
    // friend Fraction operator/(const Fraction&, const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = f1 / f2;
    cout << "Divide: f3 = " << f3 << ". f1 = " << f1 << ". f2 = " << f2 << endl;
    // BINARY RELATIONAL OPERATORS
    // ---------------------------
    // bool operator==(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    bool bTest = f1 == f2;
    cout << "Equal: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f2 = " << f2 << endl;
    // bool operator!=(const Fraction&);
    bTest = f1 != f2;
    cout << "Not Equal: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f2 = " << f2 << endl;
    // bool operator<(const Fraction&);
    bTest = f1 < f2;
    cout << "Less: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f2 = " << f2 << endl;
    // bool operator<=(const Fraction&);
    f1 = Fraction(5, 12);
    f2 = Fraction(7, 18);
    f3 = Fraction(5, 12);
    bTest = f1 <= f2;
    cout << "Less Equal: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f2 = " << f2 << endl;
    bTest = f1 <= f3;
    cout << "Less Equal: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f3 = " << f3 << endl;
    // bool operator>(const Fraction&);
    bTest = f1 > f2;
    cout << "Greater: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f2 = " << f2 << endl;
    // bool operator>=(const Fraction&);
    bTest = f1 >= f2;
    cout << "Greater Equal: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f2 = " << f2 << endl;
    bTest = f1 >= f3;
    cout << "Greater Equal: Test = " << ((bTest)? "true": "false") <<
    ". f1 = " << f1 << ". f3 = " << f3 << endl;
    return;
}
