#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
using namespace std;

const int MAXROWS = 2;
const int MAXCOLS = 3;

template<class T1>
class Matrix{

T1 maxtrix[MAXROWS][MAXCOLS];

public:
void addMatrix(T1 array1[][MAXCOLS]){
    for(int i=0;i<MAXROWS;i++){
        for(int j=0;j<MAXCOLS;j++){
            this->maxtrix[i][j] += array1[i][j];
        }
    }
}
void setMatrix(T1 array1[][MAXCOLS]){
    for(int i=0;i<MAXROWS;i++){
        for(int j=0;j<MAXCOLS;j++){
            this->maxtrix[i][j] = array1[i][j];
        }
    }

}
void printMatrix(){
    for(int i=0;i<MAXROWS;i++){
        for(int j=0;j<MAXCOLS;j++){
            cout << this->maxtrix[i][j] << " ";
        }
        cout << endl;
    }

}


};



#endif