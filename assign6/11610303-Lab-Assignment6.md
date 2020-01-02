# CS205 C/ C++ Programming Lab Assignment6

>Name: 黄玉安 (Huang Yu'an)
>
>SID: 11610303

### Part1 - Analysis

Just need to implement function `long long CalculateVolum()` and override some operator (<, <<).



### Part2 -Code

The code in box.hpp

```c++
#ifndef BOX_HPP
#define BOX_HPP
#include <ostream>
using namespace std;

class Box{
private:
    int l;
    int b;
    int h;
public:
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }
    Box(int length, int breadth, int height){
        l = length;
        b = breadth;
        h = height;
    }
    Box(const Box& box){
        l = box.b;
        b = box.b;
        h = box.h;
    }
    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume(){
        long long res;
        res = (long long)l * (long long)h * (long long)b;
    }
    bool operator<(Box& box){
        return l < box.l 
        || l == box.l && b < box.b
        || l == box.l && b == box.b && h < box.h;
    }
    friend ostream& operator<<(ostream& os, Box& box);

  
};

ostream& operator<<(ostream& os, Box& box){
    os << box.l << " " << box.b << " "<< box.h;
}

#endif
```

Test: box.cpp

```c++
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

```



You can find more details in my submited code file.

### Part 3 - Result & Verification

compile and run it.

>➜  assign6 ./boxTest             
>1
>0
>100000 100000 100000
>1000000000000000
>3 4 5

The reslut is the same as what we want.

### Part 4 - Difficulties & Solutions

Pay attension the type range of int and long long when implement ` long long CalculateVolume()`.

