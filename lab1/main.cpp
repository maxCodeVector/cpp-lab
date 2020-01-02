#include <iostream>
#include <cmath>

using namespace std;

void exercise1(){
    int x = 10;
    int y = 5;
    std::cout << "Result:" << std::endl;
    std::cout << "x\tvalue\ty\tvalue\tExpressions\tResult" << std::endl;
    std::cout << x << "\t|\t\t" << y << "\t|\t\tx=y+3\t\t" << "|x=" << y+3 << std::endl;
    std::cout << x << "\t|\t\t" << y << "\t|\t\tx=y-2\t\t" << "|x=" << y-2 << std::endl;
    std::cout << x << "\t|\t\t" << y << "\t|\t\tx=y*5\t\t" << "|x=" << y*5 << std::endl;
    std::cout << x << "\t|\t\t" << y << "\t|\t\tx=x/y\t\t" << "|x=" << x/y << std::endl;
    std::cout << x << "\t|\t\t" << y << "\t|\t\tx=x%y\t\t" << "|x=" << x%y << std::endl;
}


void exercise2(){
    cout.setf(ios::fixed);
    cout.precision(0);//保留小数点后2位
    cout << "Range of char = " << -pow(2, 8*sizeof(char)-1) << " to " << pow(2, 8*sizeof(char)-1)-1 << endl;
    cout << "Range of unsigned char = " << 0 << " to " << pow(2, 8*sizeof(char))-1 << endl;
    cout << "Range of short = " << -pow(2, 8*sizeof(short)-1) << " to " << pow(2, 8*sizeof(short)-1)-1 << endl;
    cout << "Range of unsigned short = " << 0 << " to " << pow(2, 8*sizeof(unsigned short))-1 << endl;
    cout << "Range of int = " << (-pow(2, 8*sizeof(int)-1)) << " to " << pow(2, 8*sizeof(int)-1)-1 << endl;
    cout << "Range of unsigned int = " << 0 << " to " << pow(2, 8*sizeof(unsigned int))-1 << endl;
    cout << "Range of long = " << -pow(2, 8*sizeof(long)-1) << " to " << pow(2, 8*sizeof(long)-1)-1 << endl;
    cout << "Range of unsigned long = " << 0 << " to " << pow(2, 8*sizeof(unsigned long))-1 << endl;
    cout << "Range of long long = " << -pow(2, 8*sizeof(long long)-1) << " to " << pow(2, 8*sizeof(long long)-1)-1 << endl;
    cout << "Range of unsigned long long = " << 0 << " to " << pow(2, 8*sizeof(unsigned long long))-1 << endl;
}

void exercise3(){
    cout << "Enter the number of seconds:";
    long original_seconds;
    cin >> original_seconds;
    long seconds = original_seconds;
    int day = (int)(seconds / (24 * 3600));
    seconds -= day * (24*3600);
    int hour = (int)(seconds / 3600);
    seconds -= hour * 3600;
    int min = (int)(seconds/60);
    seconds -= min * 60;
    cout << original_seconds << " seconds = " << day << " days, "
        << hour << " hours, "
        << min << " minutes, "
        << seconds << " seconds" << endl;
}

int main() {
    std::cout << "\n--------Exercise 1----------------" << std::endl;
    exercise1();
    std::cout << "\n--------Exercise 2----------------" << std::endl;
    exercise2();
    std::cout << "\n--------Exercise 3----------------" << std::endl;
    exercise3();
    return 0;
}