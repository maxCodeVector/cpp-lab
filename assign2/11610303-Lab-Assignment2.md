# CS205 C/ C++ Programming Lab Assignment2

>Name: 黄玉安 (Huang Yu'an)
>
>SID: 11610303

### Part1 - Analysis

I use some metric to calculate the given command's hash value and compare with predfined command, if it is found, return the predefined index, else return INVALID.

Also, due to my implemetaion of calculating hash value, I check the imput length and delete whitespace in both side.  After that, we can use the index along with switch statement to output what we want.

### Part2 -Code

```c
#include <string.h>
#include <iostream>

#define START 0
#define STOP 1
#define RESTART 2
#define STATUS 3
#define EXIT 4
#define INVALID 5
#define MAX_LEN 2000
#define MAX_COMM_LEN 8

using namespace std;

char* commands[] = {
    "start",
    "stop",
    "restart",
    "status",
    "exit"
};

void valid(char* comm){
    cout << "command " << comm << " recognized" << endl;
}

void invalid(){
    cout << "Invalid command" << endl;
}

long cac_hash(char* s){
    /* none empty string has zero hash value, null or invalid string return -1  */
    if(s==NULL){
        return -1;
    }
    int len = strlen(s);
    // delete first space
    int head = 0;
    while (head < len && s[head]==' ')
    {
        head ++;
    }
    long hash = 0;
    int comm_len = 0;
    while (head < len && s[head]!=' ')
    {
        hash = 255 * hash + s[head] + 128;
        head ++;
        comm_len ++;
        if(comm_len >= MAX_COMM_LEN)
            return -1;
    }
    while (head < len)
    {
        if(s[head]!=' '){
            return -1;
        }
        head ++;
    }
    return hash;
}

long comm_dict[5];

int get_comm_index(long hash){
    if(hash == 0){
        return -1;
    }else if (hash == -1)
    {
        return INVALID;
    }
    
    for(int i=0;i<5;i++){
        if(hash == comm_dict[i])
            return i;
    }
    return INVALID;
}

int main(){
    comm_dict[START] = cac_hash("start");
    comm_dict[STOP] = cac_hash("stop");
    comm_dict[RESTART] = cac_hash("restart");
    comm_dict[STATUS] = cac_hash("status");
    comm_dict[EXIT]  = cac_hash("exit");
   
    char comm[MAX_LEN];
    while (1)
    {
        cout << "> ";
        // cin.ignore(INT_MAX, '\n');
        cin.getline(comm, MAX_LEN);
        int index = get_comm_index(cac_hash(comm));
        switch (index)
        {
        case START:
        case STOP:
        case RESTART:
        case STATUS:
            valid(commands[index]);
            break;
        case EXIT:
            return 0;
        case INVALID:
            invalid();
            break;
        default:
            break;
        }
        /* code */
    }
    

    return 0;
}
```





### Part 3 - Result & Verification

>
>➜  assigment2 ./shell                    
>
>\> jjj
>\> Invalid command
>\> sss
>\> Invalid command
>\> 11111111111111111111111111111111111111
>\> Invalid command
>\> stip    
>\> Invalid command
>\> stop                                                                                           1
>\> Invalid command
>\> stop                                 
>\> command stop recognized
>\>
>\> 
>\>
>\> e  
>\> Invalid command
>\>                
>\> exit

The reslut is the same as what we want.

### Part 4 - Difficulties & Solutions

I found it is difficult that can not use string with switch statement. However, we can treat it in another way. In my case, I use similar "hash" value, and compare hash value of them. Use the index to adapte to switch.

