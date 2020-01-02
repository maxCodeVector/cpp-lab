#ifndef __UTF8STRING__ASSIGN5
#define __UTF8STRING__ASSIGN5

#include <string>
#include <iostream>
using namespace std;

class UTF8string{
    string ori;

public:
    UTF8string(const char* str);
    int length();
    int bytes();
    int find(string substr);
    void replace(UTF8string to_remove, UTF8string replacement);

    friend ostream& operator<<(ostream&os, const UTF8string&other);
    UTF8string operator+(UTF8string& another) const;
    void operator+=(UTF8string another);
    UTF8string operator*(int times);
    friend UTF8string operator*(int times, UTF8string& ori);
    UTF8string operator!();

};


#endif