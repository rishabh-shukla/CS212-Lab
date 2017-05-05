#include <iostream> // Defines istream & ostream for IO
using namespace std;
class Fraction {
    private:
    // DATA MEMBERS
    int iNumerator; // The Numerator
    unsigned int uiDenominator; // The Denominator
    protected:
    // COMPONENT FUNCTIONS
    int GetNumerator() { return iNumerator; }
    unsigned int GetDenominator() { return uiDenominator; }
    public:
    // CONSTRUCTORS
    Fraction(int = 1, int = 1); // Uses default parameters.
    Fraction(const Fraction&); // Copy Constructor
    // DESTRUCTOR
    ~Fraction(); // No virtual destructor needed
    // BASIC ASSIGNMENT OPERATOR
    Fraction& operator=(const Fraction&);
    // UNARY ARITHMETIC OPERATORS
    Fraction operator-(); // Operand 'this' implicit
    Fraction operator+();
    Fraction& operator--(); // Pre-decrement. Dividendo. p/q <-- p/q - 1
    Fraction& operator++(); // Pre-increment. Componendo. p/q <-- p/q + 1
    // BINARY ARITHMETIC OPERATORS USING FRIEND FUNCTIONS
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    // BINARY RELATIONAL OPERATORS
    bool operator==(const Fraction&);
    bool operator!=(const Fraction&);
    bool operator<(const Fraction&);
    bool operator<=(const Fraction&);
    bool operator>(const Fraction&);
    bool operator>=(const Fraction&);
    // BASIC I/O using FRIEND FUNCTIONS
    friend ostream& operator<<(ostream&, const Fraction&);
    friend istream& operator>>(istream&, Fraction&);
};
