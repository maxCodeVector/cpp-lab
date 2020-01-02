#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int vn = 5;
const char vowel[vn] = {'a', 'e', 'i', 'o', 'u'};

void exercise1(){
    char ch;
    cout << "Enter any alphabet:";
    cin >> ch;
    while (ch!='0')
    {
        switch (ch)
        {
        case 'A':
        case 'a':
        case 'E': 
        case 'e': 
        case 'I':
        case 'i': 
        case 'O':
        case 'o':
        case 'U': 
        case 'u':
            cout << "Vowel" << endl;
            break;
        
        default:
            cout << "Consonant" << endl;
        }

    cout << "Enter any alphabet:";
    cin >> ch;
        /* code */
    }
}

void exercise2(){
    cout << "Enter words (q to quit):" << endl;
    int nVowel = 0;
    int nConsonant =0;
    int nOther=0;
    char word[30];
    while(cin>>word)
    {
        if(isalpha(word[0]))
        {
            if(strlen(word)==1&&word[0]=='q')
            {
                break;
            }
            char x=tolower(word[0]);
                //completecodehere
        }
    }
        cout<<nVowel<<"words begining with vowels"<<endl
        <<nConsonant<<"words begining with consonants"<<endl
        <<nOther<<"others"<<endl;
    
}



int main(){
    exercise1();
    return 0;
}