#include "Complex.h"

ostream& operator<<(ostream& out, const Complex& complex){
    return out << complex.real << "+" << complex.vir << "i";
}

istream& operator>>(istream& out, Complex& complex){
    cout << "real:";
    out >> complex.real;
    cout << "imaginary:";
    out >> complex.vir;
}

Complex operator*(int multier, Complex& complex){
    Complex c;
    c.real = complex.real * multier;
    c.vir = complex.vir * multier;
    return c;
}
Complex Complex::operator~(){
    Complex c;
    c.real = this->real;
    c.vir = this->vir * -1;
    return c;
}
Complex Complex::operator+(Complex& b){
    Complex c;
    c.real = this->real + b.real;
    c.vir = this->vir + b.vir;
    return c;
}
Complex Complex::operator-(Complex& b){
    Complex c;
    c.real = this->real - b.real;
    c.vir = this->vir -b.vir;
    return c;
}
Complex Complex::operator*(Complex& b){
    Complex c;
    c.real = this->real * b.real - this->vir * b.vir;
    c.vir = this->vir * b.real + this->real * b.vir;
    return c;
}
bool Complex::operator==(Complex& b){
    return this->real == b.real && this->vir == b.vir;
}
bool Complex::operator!=(Complex& b){
    return !(*this==b);
}

int main()
{
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a is " << a << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * b is " << 2 * b << endl;
    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is" << (b != c) << endl;
    cout << "a==c is" << (a == c) << endl << endl;
    Complex d;
    cout << "Enter a complex number : " << endl;
    cin >> d;
    cout << "d is " << d << endl;
    return 0;
}
