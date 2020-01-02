#include <iostream>
#include <string>
using namespace std; 

//Make a template out of the prototype
template<typename T>
T Max(T one, T two);

int main()
{
    int i_one = 3, i_two = 5;
    float f_one = 5.6, f_two=7.3;
    string d = "doukey", a = "apple";
    cout << "The max of " << i_one << " and " << i_two << " is " << Max(i_one, i_two) << endl;
    cout << "The max of " << f_one << " and " << f_two << " is " << Max(f_one, f_two) << endl;
    cout << "The max of " << d << " and " << a << " is " << Max(d, a) << endl;
    //Test your template on float and string types
    return 0;
}
//Make a template out of this function.Don't forget the return type.
template<typename T>
T Max(T one, T two)
{
    T biggest;
    if (one < two)
    {
        biggest = two;
    }
    else
    {
        biggest = one;
    }
    return biggest;
}