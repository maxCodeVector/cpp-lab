#include <exception>
#include "stdio.h"
#include <string>
#include <iostream>
#include <list>
using namespace std;

struct OutOfRangeException : public exception
{
    int num;
    int order;
    static list <int> int_list;
    OutOfRangeException(int num, int order)
    {
        this->num = num;
        this -> order = order;
    }
    const char *what() const throw()
    {
        cerr << "out of range of parameter" << order << ":" << num << endl;
        ;
        return "out of range";
    }
    /* data */
};

list<int> OutOfRangeException:: int_list = {1,2};

float calculateAverage(int score[], int num)
{
    // try
    {
        float res = 0;
        for (int i = 0; i < num; i++)
        {
            if (score[i] < 0 || score[i] > 100)
            {
                throw OutOfRangeException(score[i], i+1);
            }
            res += score[i];
        }
        return res / num;
    }
    // catch (OutOfRangeException &o)
    // {
    //     cout << o.what() << endl;
    // }
    return -1;
}

int main(int argc, char const *argv[])
{
    /* code */

    int score[] = {3, -40, 5, 6};
    float avg = calculateAverage(score, 4);
    cout << "average is:" << avg << endl;

    return 0;
}
