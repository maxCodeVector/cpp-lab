#include <iostream>
using namespace std;

class Complex{
    float real;
    float vir;

public:
    Complex(float real, float vir){
        this->real = real;
        this->vir = vir;
    }
    Complex(){
        this->real = 0;
        this->vir = 0;
    }
    friend ostream& operator<<(ostream& out, const Complex& complex);
    friend istream& operator>>(istream& out, Complex& complex);
    friend Complex operator*(int multier, Complex& complex);
    Complex operator~();
    Complex operator+(Complex& b);
    Complex operator-(Complex& b);
    Complex operator*(Complex& b);
    bool operator==(Complex& b);
    bool operator!=(Complex& b);
};

