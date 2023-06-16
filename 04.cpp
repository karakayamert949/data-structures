#include <iostream>
#include <cmath>
using namespace std;

// reference ampersand operatorda kullanımı

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

ostream & operator<<(ostream &s, ComplexNumber &cn)
{
    s <<cn.real();
    if(cn.imag()<0)
        s <<cn.imag() <<"i";
    else 
        s <<"+"<<cn.imag() <<"i";
    return s;
};

ComplexNumber operator+(ComplexNumber &cn1, ComplexNumber &cn2)
{
    float x = cn1.real() + cn2.real();
    float y = cn1.imag() + cn2.imag();
    return ComplexNumber(x,y);
}

ComplexNumber operator-(ComplexNumber &cn1, ComplexNumber &cn2)
{
    float x= cn1.real()-cn2.real();
    float y= cn1.imag()-cn2.imag();
    return ComplexNumber(x,y);
}

int main()
{
    ComplexNumber z1=ComplexNumber(2,-16);  // invokes default constructor
    ComplexNumber z2=ComplexNumber(3,4);  // invokes the other constructor
    
    int n = 2;
    char c ='t';
    cout <<n <<endl <<c <<endl <<z2 <<endl;
    ComplexNumber z3 = z1+z2;
    ComplexNumber z4=z1-z2;
    cout <<z3 <<endl <<z4;

    
    return 0;
};
