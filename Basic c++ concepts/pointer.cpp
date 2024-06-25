#include<iostream>

using namespace std;

int Add(int a,int b){
    return a+b;
}

int main(){
    int c;
   int (*p)(int, int); // first type the return type of function, then name of variable then type argument type of this function
   p=&Add;
   c = (*p)(2,3); // to execute the function, derefrence the pointer 
   cout<<c;
   return 0;

}