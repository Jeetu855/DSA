#include <iostream>
#include <string>
#include <vector>

using namespace std;
// * append means adding element at the end
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << endl;
};

void Append(struct Array *arr, int x)
{ // x is the value we are gonna append
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
};

void Insert(struct Array *arr, int index, int x)
{ // index is at which index we wanna put x
    int i;
    if (index >= 0 && index < arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
};

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // Append(&arr, 10);
    // Display(arr);
    Insert(&arr, 0, 10);
    Display(arr);
    return 0;
}
// * c++ code
// #include <iostream>
// using namespace std;

// class Array{
// private:
//     int *A;
//     int size;
//     int length;
// public:
//     Array(int sz);
//     void create();
//     void display();
//     void append(int x);
//     void insert(int index, int x);
//     ~Array();
// };

// Array::Array(int sz){
//     sz = size;
//     A = new int [sz];
// }

// void Array::create(){
//     cout<<"enter length for array: ";
//     cin>>length;
//     cout<<"enter elements for array: "<<endl;
//     for(int i{0}; i<length; i++){
//         cout<<"array at "<<i<<" : ";
//         cin>>A[i];
//     }
// }
// void Array::display(){
//     for(int i{0}; i<length; i++){
//         cout<<A[i]<<" ";
//     }
//     cout<<endl;
// }

// void Array::append(int x){
//     if(length < size){
//         A[length] = x;
//         length++;
//     }
// }

// void Array::insert(int index, int x){
//     if(length < size){
//         for(int i{length}; i>index; i--){
//             A[i] = A[i-1];
//         }
//         A[index] = x;
//         length++;
//     }
// }

// Array::~Array(){
//     delete [] A;
// }

// int main(){
//     Array arr(10);
//     arr.create();
//     arr.display();
//     arr.append(69);
//     arr.display();
//     arr.insert(2, 66);
//     arr.display();
//     return 0;
// }