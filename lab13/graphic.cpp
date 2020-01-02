#include <iostream>
using namespace std;

class CStereoShape {
private:
static int numberOfObject;
public:
CStereoShape(){
    numberOfObject++;
}

virtual double GetArea(){
    return 0;
}
virtual double GetVolume(){
    return 0;
}

virtual void Show(){
    cout << "area:" << GetArea() << endl;
    cout << "volumn:" << GetVolume() << endl;
}
static int GetNumOfObject(){
    return numberOfObject;
}

};

int CStereoShape::numberOfObject = 0;

class CCube:public CStereoShape{
double length;
double width;
double height;

public:
CCube(){
}
CCube(double length, double width, double height){
    this->length = length;
    this->width = width;
    this->height = height;
}

CCube(const CCube& cube){
    this->length = cube.height;
    this->width = cube.width;
    this->height = cube.height;
}

double GetArea(){
    return (height*width+height*length+width*length)*2;
}
double GetVolume(){
    return length*height*width;
}

void Show(){
    cout << "height:" << height << endl;
    cout << "width:" << width << endl;
    cout << "length:" << length << endl;
    CStereoShape::Show();
}

};

class CSphere:public CStereoShape{
    double redius;
public:
CSphere(){

}

CSphere(double redius){
    this->redius = redius;
}

CSphere(const CSphere& sphere){
    this->redius = sphere.redius;
}

double GetArea() override {
    return 4 * 3.14 * redius* redius;
}
double GetVolume(){
    return 4/3 * 3.14 * redius * redius * redius;
}

void Show(){
    cout << "redius:" << redius << endl;
    CStereoShape::Show();
}

};

int main(int argc, char const *argv[])
{
    CCube a_cube = CCube(4, 5, 6);
    CSphere c_sphere = CSphere(7.9);
    CStereoShape* p = &a_cube;
    p->Show();
    p = &c_sphere;
    p->Show();
    cout << "number of objects:" << CStereoShape::GetNumOfObject() << endl;;
    return 0;
}
