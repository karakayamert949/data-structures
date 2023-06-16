#include <iostream>
#include <cmath>
using namespace std;

// Complex Numbers z=x+yi

class ComplexNumber
{ // Class members:
  // private by default; "encapsulation"; in struct public by default
  // Attributes:
    float x;
    float y;
  public:
  // Methods:
    ComplexNumber();  // default constructor
    ComplexNumber(float a, float b);  // another constructor
    float real(void);
    float imag(void);
    float magnitude(void);
};

ComplexNumber::ComplexNumber()
{
    x=0;
    y=0;
    cout <<"Default constructor" <<endl;
};

ComplexNumber::ComplexNumber(float a, float b)
{
    x=a;
    y=b;
    cout <<"The other constructor" <<endl;
};

float ComplexNumber::real(void)
{
    return x;
};

float ComplexNumber::imag(void)
{
    return y;
};

float ComplexNumber::magnitude(void)
{
    return sqrt(x*x+y*y);
};

int main()
{
    ComplexNumber z1;  // invokes default constructor
    ComplexNumber z2=ComplexNumber(3,4);  // invokes the other constructor
    
    cout <<z1.real() <<"+" <<z1.imag() <<"i" <<endl;
    cout <<"|" <<z2.real() <<"+" <<z2.imag() <<"i|=" <<z2.magnitude() <<endl;
    
    cout <<endl; // enter
    return 0;
};
