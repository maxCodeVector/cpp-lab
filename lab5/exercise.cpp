#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

void exersice1(){
    int sum = 0;
    int inum;
    do
    {
        cout << "Enter integer number: ";
        cin >> inum;
        sum += inum;
        cout << "The cumulative number is: " << sum << endl;
        /* code */
    }while (inum != 0);
}

void exersice2(){
    char word[100];
    int num_words = 0;
    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> word;
    while (strcmp(word, "done")!=0) // means not equal, this function will return 0 when equaling.
    {
        num_words ++;
        cin >> word;
    }
    cout << "You entered a total of " << num_words << " words" << endl;
}

void exersice3while(){
    int first = 0;
    int sencond = 1;
    int max_num;
    cout << "Enter a positive number: ";
    cin >> max_num;
    int next = first + sencond;
    cout << "Fibonacci Series: 0 1";
    while (next <= max_num)
    {
        cout << " " << next;
        first = next;
        next = sencond + next;
        sencond = first;
        /* code */
    }
    cout << endl;
}

void exersice3dowhile(){
    int first = 0;
    int sencond = 1;
    int max_num;
    cout << "Enter a positive number: ";
    cin >> max_num;
    int next = first + sencond;
    cout << "Fibonacci Series: 0 1";
    do
    {
        cout << " " << next;
        first = next;
        next = sencond + next;
        sencond = first;
        /* code */
    }while (next <= max_num);
    
    cout << endl;
}

void exersice3for(){
    int first = 0;
    int sencond = 1;
    int max_num;
    cout << "Enter a positive number: ";
    cin >> max_num;
    int next = first + sencond;
    cout << "Fibonacci Series: 0 1";
   for(;;)
    {
        cout << " " << next;
        first = next;
        next = sencond + next;
        sencond = first;
        if (next > max_num){
            break;
        }
        /* code */
    }
    cout << endl;
}

void exercise4(){
    int max_num = 7;
    for(int i=1;i<=max_num;i++){
        for(int j=1;j<=max_num;j++){
            if(j<=i){
                cout << j;
            }else{
                cout << '*';
            }
        }
        cout << endl;
    }
}

int main(){
    exersice1();
    exersice2();
    exersice3while();
    exersice3dowhile();
    exersice3for();
    exercise4();
    return 0;
}