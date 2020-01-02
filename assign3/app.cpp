#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory.h>
#include <string.h>


#define NAME_LEN 35
#define ARR_SIZE 1000
#define RES_INC_STEP 10
#define MIN(a, b) a<b?a:b
#define R 6371 // the redius of earth by km
#define PI 3.14159
using namespace std;

struct City{
    char name[NAME_LEN];
    char country[NAME_LEN];
    double latitude;
    double longitude;
};

double cac_distance_by_position(double lat1, double lat2, double lon1, double lon2){
    double phi1= (90-lat1)*PI/180;
    double theta1=lon1*PI/180;
    double phi2= (90-lat2)*PI/180;
    double theta2=lon2*PI/180;
    if (phi1<0||phi1>180||theta1>180||theta1<-180
        ||phi2<0||phi2>180||theta2>180||theta2<-180){
        return-1;    
    }
    double c=sin(phi1)*sin(phi2)*cos(theta1-theta2) +cos(phi1)*cos(phi2);
    return R*acos(c);
}

int parse_line(string& line, City& city){
    int trancated_falg = 0;
    stringstream input_s(line);
    string temp;

    getline(input_s, temp, ',');
    memcpy(city.name, temp.c_str(), NAME_LEN);
    if(temp.length() > NAME_LEN){
        trancated_falg = 1;
    }

    getline(input_s, temp, ',');
    getline(input_s, temp, ',');
    memcpy(city.country, temp.c_str(), NAME_LEN);
    if(temp.length() > NAME_LEN){
        trancated_falg = 1;
    }

    getline(input_s, temp, ',');
    city.latitude = atof(temp.c_str());

    getline(input_s, temp, ',');
    city.longitude = atof(temp.c_str());

    return trancated_falg;
}

static struct City citys[ARR_SIZE];
static int city_len = 0;
/**
 * return -1 file do not exist, 1 is success, 0 means data truncated 
 */
int read_city_from_csv_file(string file_path){
    string line;
    ifstream city_file(file_path);
    if(!city_file.is_open()){
        return -1;
    }
    int truncated = 1;
    while(getline(city_file, line)){
        if(city_len > ARR_SIZE){
            return 0;
        }
        if(parse_line(line, citys[city_len])!=0){
            truncated = 0;
        }
        city_len ++;
    }
    return truncated;
}

/**
 * index 0 use to store res array length, at the end of res_cap will be -1
 */ 
int search_city(int res[], string name){
    int res_len = 0;
    for(int i=0;i<city_len;i++){ 
        int min = MIN(name.length(), strlen(citys[i].name));
        int eq_flag = 1;
        for(int k=0;k<min;k++){
            if(citys[i].name[k] != name[k]){
                eq_flag = 0;
                break;
            } 
        }
        if(eq_flag){
            res_len++;
            if(res_len +1 >= res[0]){
                realloc(res, (res[0] + RES_INC_STEP)*sizeof(int));
                res[0] += RES_INC_STEP;
            }
            res[res_len] = i;
        }
    }
    return res_len;
}

void display_res(int res[], int res_len){
    for(int i=1;i<=res_len;i++){
        cout << i << "th city name:" << citys[res[i]].name << endl;
    }

}

void trim(string &s)
{
    int index = 0;
    if( !s.empty())
    {
        while( (index = s.find(' ',index)) != string::npos)
        {
            s.erase(index,1);
        }
    }
}

double inline cac_city_distance(City &city1, City &city2){
    return cac_distance_by_position(city1.latitude, city2.latitude, city1.longitude, city2.longitude);
}

int get_city_choice(string & comm){
    if(comm.length() < 3){
        cout << "two short name, re input" << endl;
        return -1;
    }
    int res_len;
    int* res = (int*)malloc(RES_INC_STEP*sizeof(int));
    res[0] = RES_INC_STEP;
    res_len = search_city(res, comm);
    int city_index;
    if(res_len >= 1){
        display_res(res, res_len);
        cout << "choose the city by the inedx:";
        int choice;
        cin >> choice;
        cin.get();
        if(choice <= 0 || choice > res_len){
            cout << "not have this index" << endl;
            city_index = -1;
        }else
            city_index = res[choice];
    }else if(res_len < 1){
        cout << "not found this file" << endl;
        city_index = -1;
    }else{
        city_index = res[1];
    }
    free(res);
    return city_index;
}


int main(){
    int ret = read_city_from_csv_file("world_cities.csv");
    switch (ret)
    {
    case -1:
        cout << "read file failed, file not exist" << endl;
        return 1;
    case 0:
        cout << "warning:some data have been truncated" << endl;
        return 1;
    case 1:
        cout << "load data success!" << endl;
    }
    cout << "city number:" << city_len << endl;
    string comm;
    int city_index1, city_index2;
    while (1)
    {
        do{
            cout << "\nchoose the first city by input prefix of its name, \ninput bye to exit:";
            getline(cin, comm);
            trim(comm);
            if(comm == "bye"){
                return 0;
            }
            city_index1 = get_city_choice(comm);
        }while (city_index1 <= 0);
        cout << "***choose first city:" << citys[city_index1].name << endl;

        do{
            cout << "\nchoose the second city by input prefix of its name, \ninput bye to exit:";
            getline(cin, comm);
            trim(comm);
            if(comm == "bye"){
                return 0;
            }
            city_index2 = get_city_choice(comm);
        }while(city_index2 <= 0);
        cout << "***choose second city:" << citys[city_index2].name << endl;

        double dis = cac_city_distance(citys[city_index1], citys[city_index2]);
        cout << "=====> the distance between " << citys[city_index1].name 
            << " and " << citys[city_index2].name << " is:" << dis << endl;
    }
    return 0;
}