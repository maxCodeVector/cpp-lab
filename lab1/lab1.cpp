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