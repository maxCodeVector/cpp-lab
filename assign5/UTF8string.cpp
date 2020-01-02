#include "UTF8string.hpp"
#include "utf8.h"

UTF8string::UTF8string(const char* str){
    this->ori = string(str);
}
int UTF8string::length(){
    return utf8_charlen((unsigned char*)ori.c_str());
}
int UTF8string::bytes(){
    return ori.size();
}
int UTF8string::find(string substr){
    unsigned char* res = utf8_search((unsigned char *)ori.c_str(), 
                                  (unsigned char *)substr.c_str());
    return length()- utf8_charlen(res);
}
void UTF8string::replace(UTF8string to_remove, UTF8string replacement){
    int position = find(to_remove.ori);
    position = utf8_charpos_to_bytes((unsigned char*)this->ori.c_str(), position);
    ori.replace(position, to_remove.bytes(), replacement.ori);
}

ostream& operator<<(ostream&os, const UTF8string&other){
    return os << other.ori;
}
UTF8string UTF8string::operator+(UTF8string& another) const{
    string str = this->ori;
    str.append(another.ori);
    UTF8string res(str.c_str());
    return res;
}
void UTF8string::operator+=(UTF8string another){
    this->ori.append(another.ori);
}
UTF8string UTF8string::operator*(int times){
    string str;
    while (times > 0)
    {
        str.append(this->ori);
        times --;
    }
    UTF8string res(str.c_str());
    return res;
}

UTF8string operator*(int times, UTF8string& ori){
    return ori.operator*(times);
}

UTF8string UTF8string::operator!(){
    int len = length();
    unsigned char* cstr = (unsigned char*)ori.c_str();
    int pos = bytes();
    string res = "";
    for(int i=len-1;i>=0;i--){
        int start = utf8_charpos_to_bytes(cstr, i);
        res.append(this->ori.substr(start, pos-start));
        pos = start;
    }
    UTF8string sres(res.c_str());
    return sres;
}
