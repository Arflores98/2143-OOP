/*****************************************************************************
*Description: 
*This program is a calculator that can add, subtract, multiply, and divide 
*fraction numbers. I created a proper fraction class that will overload the 
*plus, minus, multiply, divide, and == operators. I determined that my 
*additional method should be a private method that will be called by the public 
*methods. I also created a method that will reduce the fraction to its lowest.
*
*
*****************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;
/*****************************************************************************
*Class Nmae: Fraction
*
*Description: In this class, I created a fraction class that will overload the
*    +, -, *, /, and == operators. I also created a method that will reduce 
*    the fraction to its lowest comon denominator.
*
*
*****************************************************************************/
class Fraction 
{
private:
    int num;
    int den;

public:
    Fraction() { num = den = 1; } // Default constructor
    Fraction(int n, int d)        // Constructor
    {
        num = n; // Assigns the value of n to num
        den = d; // Assigns the value of d to den
    }
    Fraction(string frac)
    {
        num = frac[0] - 48; // Subtracts 48 from the ASCII value of the first character to get the numerator
                            // ex. (51 being 3) 51-48 = 3
        den = frac[2] - 48; // Subtracts 48 from the ASCII value of the third character to get the denominator
    }

    void print() // Prints the fraction
    {
        cout << num << "/" << den;
    }

    friend ostream& operator<<(ostream& os, const Fraction& rhs) // Overloads the << operator
    {
        return os << rhs.num << "/" << rhs.den; // Returns the numerator and denominator
    }

    int gcd(int a, int b) 
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void simplifyFraction() 
    {
    int gcdValue = gcd(num, den);
    num /= gcdValue;
    den /= gcdValue;
    }          

    // Overloaded addition operator
    Fraction operator+(const Fraction& rhs)// or "other"
    {
        Fraction temp = rhs;   // created temp

        temp.den = temp.den * this->den; // changed denominator of temp bc now there is 3 fractions with temp
        temp.num = temp.num * this->den; // changed numerator of temp
        this->den = this->den * rhs.den;  // changed the denominator of this
        this->num = this->num * rhs.den;  // changed the numerator of this
        temp.num = temp.num + this->num; // added the numerators of temp and this
        temp.simplifyFraction();
        return temp;
    }

    // Overloaded subtraction operator
    Fraction operator-(const Fraction& rhs)
    {
        Fraction temp = rhs;   // created temp
        temp.den = temp.den * this->den; // changed denominator of temp bc now there is 3           fractions with temp
        temp.num = temp.num *  this->den; // changed numerator of temp
        this->den = this-> den * rhs.den;  // changed the denominator of this
        this->num = this->num * rhs.den;  // changed the numerator of this
        temp.num = this->num - temp.num; // subtracted the numerators of temp and this
        temp.simplifyFraction();
        return temp;
    }
    // Overloaded multiplication operator
    Fraction operator*(const Fraction& rhs)
    {
        Fraction result; // or "temp"
        result.num = this->num * rhs.num;
        result.den = this->den * rhs.den;
        result.simplifyFraction();
        return result;
        // TODO: Implement the multiplication logic
    }

    // Overloaded division operator
    Fraction operator/(const Fraction& rhs)
    {
        Fraction result; // or "temp"
        result.num = this->num / rhs.num;
        result.den = this->den / rhs.den;
        result.simplifyFraction();
        return result;
        // TODO: Implement the division logic
    }

    // Overloaded equality operator (==)
    bool operator==(const Fraction& rhs) const
    {
        return (this->num == rhs.num && this->den == rhs.den);
    }
    // TODO: Check if two fractions are equal by comparing numerators and denominators
  // TODO: Implement methods to read input from stdin (lecture topic)
};

int main() {
    ifstream infile("input.txt");
    //ofstream outfile("output.txt");

    string f1, op, f2;


    while (infile >> f1 >> op >> f2)
    {
        auto i = f1[0] - '0';
        auto j = f1[2] - '0';
        auto x = f2[0] - '0';
        auto y = f2[2] - '0';

        Fraction f1(i, j);
        Fraction f2(x, y);

        if (op == "+")
            cout << f1 + f2 << endl;
        else if (op == "-")
            cout << f1 - f2 << endl;
        else if (op == "*")
            cout << f1 * f2 << endl;
        else if (op == "/")
            cout << f1 / f2 << endl;
    }

    infile.close();
    return 0;
}