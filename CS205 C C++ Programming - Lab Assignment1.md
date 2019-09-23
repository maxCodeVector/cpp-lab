# CS205 C/ C++ Programming - Lab Assignment1

> Name: 黄玉安(Huang Yu'an)

> SID: 11610303

### Part 1 - Analysis

Given two place's latitude and longitude: lat1, lon1, lat2, lon2.

First calculate `phi = 90 - latitude` and `theta = longitude`, pay attention to change angle angle to radian.

Then use the formula to calculate the distance between them:

 $d = R*ArcCos(c)$ 

which c is calculated by 

$c = sin(phi1)*sin(phi2)*cos(theta1-theta2) + cos(phi1)*cos(phi2)$ 

and R is the radius of earth (6371km).

### Part 2 - Code

```c++
//
// Created by hya on 19-9-23.
//
#include <iostream>
#include <cmath>
#include <climits>
#define R 6371 // the redius of earth by km
using namespace std;

double cacDistanceByPosition( double lat1, double lat2, double lon1, double lon2){
    double phi1 = (90 - lat1)*M_PI/180;
    double theta1 = lon1*M_PI/180;
    double phi2 = (90 - lat2)*M_PI/180;
    double theta2 = lon2*M_PI/180;
    if (phi1<0 || phi1 > 180 || theta1 > 180 || theta1 < -180
    || phi2<0 || phi2 > 180 || theta2 > 180 || theta2< -180){
        return -1;
    }
    double c = sin(phi1)*sin(phi2)*cos(theta1-theta2) + cos(phi1)*cos(phi2);
    return R*acos(c);
}

int main(int argv, char**args){
    char  city1[20];
    char  city2[20];
    double lat1, lat2, lon1, lon2;
    cout << "The first city: " << endl;
    cin.getline(city1, 20);
    cout << "The latitude and longitude of first city: " << endl;
    if (   !(cin >> lat1) ){
           cout << "The input data format is invalid!!" << endl;
           return 1;
    }
     if (   !(cin >> lon1) ){
           cout << "The input data format is invalid!!" << endl;
           return 1;
    }
    cout << "The second city: " << endl;
    cin.ignore(INT_MAX, '\n');
    cin.getline(city2, 20);

    cout << "The latitude and longitude of second city: " << endl;
   if (   !(cin >> lat2) ){
           cout << "The input data format is invalid!!" << endl;
           return 1;
    }
     if (   !(cin >> lon2) ){
           cout << "The input data format is invalid!!" << endl;
           return 1;
    }
    double res = cacDistanceByPosition( lat1, lat2, lon1, lon2);
    if (res < 0){
           cout << "The input data format is invalid!!" << endl;
           return 1;
    }
    cout << "The distance between " << city1 << " and "  <<  city2  <<  " is " << res << " km" << endl;
    return 0;
}
```



### Part 3 - Result & Verification

Test case #1:

>Input:
>
>Shenzhen
>22.55 114.1
>Beijing
>39.9139 116.3917
>
>Output:
>
>The distance between Shenzhen and Beijing is 1942.84  km

Test case #2:

>Input:
>
>Shenzhen
>aaa 114.1
>Beijing
>39.9139 116.3917
>
>Output:
>
>The input data format is invalid!!



### Part 4 - Difficulties & Solutions

We should notice the new line problem in cin during get string, so use `cin.ignore(INT_MAX, '\n')`, and check if it is a number: 

>   if (   !(cin >> num) ){
>
>​           cout << "The input data format is invalid!!" << endl;
>
>​           return 1;
>
>​    }

