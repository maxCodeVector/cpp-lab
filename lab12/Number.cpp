#include <iostream>
using namespace std;

class Number
{
    int num;

public:
    Number()
    {
        num = 0;
    };
    Number(int num)
    {
        this->num = num;
    }

    Number operator++(int)
    {
        Number res;
        res.num = num++;
        // cout << res.num <<"ddd"<< endl;
        return res;
    }
    Number operator++()
    {
        Number res;
        res.num = ++num;
        return res;
    }

    Number operator--(int)
    {
        Number res;
        res.num = num--;
        return res;
    }
    Number operator--()
    {
        Number res;
        res.num = --num;
        return res;
    }
    friend ostream &operator<<(ostream &out, const Number &number);
};

ostream &operator<<(ostream &out, const Number &number)
{
    return out << number.num;
}

int main()
{
    Number n1(20);
    Number n2 = n1++;
    // cout << n2 << "\n";
    cout << n1 << endl;
    cout << n2 << endl;
    Number n3 = n2--;
    cout << n2 << endl;
    cout << n3 << endl;
    Number n4 = ++n3;
    cout << n3 << endl;
    cout << n4 << endl;
    Number n5 = --n4;
    cout << n4 << endl;
    cout << n5 << endl;
    return 0;
}