#include <iostream>
 
 using namespace std;

class CandyBar{
    static const int Len = 40;
    char brand[Len];
    double weight;
    int calorie;
public:
    void setCandyBar();
    void showCandyBar();

};


using namespace std;

void CandyBar::setCandyBar(){
    cout << "Enter brand name of the candy bar:";
    cin.getline(this->brand, 40);
    cout << "Enter weight of the candy bar:";
    cin >> this->weight;

    cout << "Enter calories (an integer value) in the candy bar:";
    cin >> this->calorie;
}


void CandyBar::showCandyBar(){
    cout << "name:" << this->brand << endl;
    cout << "calories:" << this->calorie << endl;
    cout << "weight:" << this->weight << endl;
}

void exercise1(){
    CandyBar candy;
    candy.setCandyBar();
    candy.showCandyBar();
}

class Rectangle{
float width;
float height;
public:
    Rectangle(){
        width = 1;
        height = 1;
    }
    Rectangle(float width, float height);
    float getArea();
    float getPerimeter();
    void display();
};
Rectangle::Rectangle(float width, float height){
    this->width = width;
    this->height = height;
}

float Rectangle::getArea(){
    return width*height;
}

float Rectangle::getPerimeter(){
    return (width+height)*2;
}

void Rectangle::display(){
    cout << "Width:" << width << endl;
    cout << "Height:" << height << endl;
    cout << "Area:" << getArea() << endl;
    cout << "Perimeter:" << getPerimeter() << endl;
}

void exercise2(){
    Rectangle rec1(4, 40), rec2(3.5, 35.9);
    cout << "Rectangle 1\n---------------" << endl;
    rec1.display();
    cout << "Rectangle 2\n---------------" << endl;
    rec2.display();
}



int main(){
    exercise1();
    exercise2();
    return 0;
}
