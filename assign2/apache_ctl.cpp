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