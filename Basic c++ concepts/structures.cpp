#include<iostream>

using namespace std;

struct Rectangle //this is declaration and dosent occupy memory
{
    int length; //4bytes
    int breadth; //4bytes
    char x; //**for character also 4 bytes allocated but only 2 bytes used
//this adjustment is called padding of memory
// but if we have a float it will take 8bytes not 4
};

struct Rectangle r2;
int main(){
    struct Rectangle r1; //this occupies memory
    r1.length=10;
    r1.breadth=20;
    cout<<"Area is: "<<(r1.breadth)*(r1.length)<<endl;//200
    struct Rectangle r3{10,5};
    cout<<sizeof(r3)<<endl;
    // * Pointer to structure
    struct Rectangle *p=&r1;
    (*p).length=20;//need () coz . has higher precedence
    cout<<"Area is: "<<(r1.breadth)*(r1.length)<<endl;//400
    p->breadth=10;
    cout<<"Area is: "<<(r1.breadth)*(r1.length)<<endl;//200
    
    //create struc dynamically
    struct Rectangle *p1{nullptr};
    p1=new struct Rectangle;
    p1->length=10;
    p1->breadth=10;
    cout<<"-------------------"<<endl;
    cout<<"Area is: "<<((*p1).breadth)*((*p1).length)<<endl;
    delete p1;

    
    // **Reference
    int a=10;
    int &r=a;
    cout<<a<<endl;
    cout<<r<<endl;
    r++;
    cout<<a<<endl;
    cout<<r<<endl;

    // * r and a have same address
    return 0;
}

