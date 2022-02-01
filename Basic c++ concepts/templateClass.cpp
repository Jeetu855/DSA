#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Arithematic
{
private:
    T a;
    T b;

public:
    Arithematic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithematic<T>::Arithematic(T a, T b) : a{a}, b{b} {};
// Arithematic::Arithematic(T a,T b){
//    this->a=a;
//    this->b=b;
// }
template <class T>
T Arithematic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithematic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{

    Arithematic<int> ar1{10, 5};
    cout << "Addition: " << ar1.add() << endl;
    cout << "Subtraction: " << ar1.sub() << endl;

    Arithematic<double> ar2{10.2, 5.7};
    cout << "Addition: " << ar2.add() << endl;
    cout << "Subtraction: " << ar2.sub() << endl;

    // *debugging test
    int arr[]{1, 2, 3, 4, 5};
    int sum{};
    for (int x : arr)
    {
        sum = sum + x;
    }
    cout << sum << endl;
    return 0;
}