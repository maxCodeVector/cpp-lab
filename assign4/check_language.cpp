/*
 *   This program demonstrates how to use utf8_to_codepoint().
 *   To compile it:
 *     gcc -o demo using_utf8_to_codepoint.c utf8.c
 *
 *   Type UTF-8 characters or words on the command line, it will
 *   tell you what are the equivalent code points.
 */
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "utf8.h"

using namespace std;

struct code_point
{
    unsigned int start;
    unsigned int end;
    int chars_num;
    string name;
};

static const int MAX_CHARS = 300;
struct code_point chars[MAX_CHARS];
static int curr = 0;


void read_blockfile(){
    ifstream ifile("Blocks.txt");

    string line;
    int start, end;
    char name[100];
    while (!ifile.eof())
    {
        getline(ifile, line);
        if(line[0]=='#' || line[0]==' ')
            continue;
        int res = sscanf(line.c_str(), "%x..%x; %[^\n]", &start, &end, name);
        if(res!=3)
            continue;
        else{
            chars[curr].start = start;
            chars[curr].end = end;
            chars[curr].chars_num = 0;
            chars[curr].name = name;
            curr++;
        }
        // cout << name << endl;
    }
    ifile.close();
}

void find_code_point(unsigned int codepoint){
    for(int i=0;i<curr;i++){
        if(chars[i].start < codepoint && chars[i].end > codepoint){
            chars[i].chars_num ++;
        }
    }
}

int found(){
    int max = 0;
    int res = 0;
    for(int i=0;i<curr;i++){
        if(chars[i].chars_num > max){
            max = chars[i].chars_num;
            res = i;
        }
    }
    return res;
}


void check(string &line){

    unsigned char *p;
    int            bytes_in_char;
    int            i;
    unsigned int   codepoint;
    
    char* myc_string = new char[line.size()+1];
    line.copy(myc_string, line.size()+1);
    p = (unsigned char*)myc_string;
    while (*p) {
        codepoint = utf8_to_codepoint(p, &bytes_in_char);
        if (codepoint) {
            // printf("%c %u (%X) %d byte character\n", *p,
                    // codepoint, codepoint, bytes_in_char);
            // p += bytes_in_char;  // Same as the line that follows
            _utf8_incr(p);
            find_code_point(codepoint);
        } else {
            printf("%c Invalid UTF-8\n", *p);
            p++;  // Try the next character
        }
    }
    delete[] myc_string;
}


int main(int argc, char **argv) {

    read_blockfile();

    
    // while (!cin.eof())
    // {
    //     /* code */
    // }
    string line;
    while (cin >> line)
    {
        // cout << line << endl;
        check(line);
    }
    int res = found();
    cout << "there comes the result, file is:" << chars[res].name << endl;
}
