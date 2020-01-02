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