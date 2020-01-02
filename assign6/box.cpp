#include "box.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Box box1;
    Box box2(3, 4, 5);
    Box large(100000, 100000, 100000);

    cout << bool(box1 < box2) << endl;
    cout << (large < box1) << endl;
    cout << large << endl;
    cout << large.CalculateVolume() << endl;
    cout << box2.getLength() << " " << box2.getBreadth() << " " << box2.getHeight() << endl;
    return 0;
}
