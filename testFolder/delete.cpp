#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SelectionSort(int A[],int n){
    int i{},j{},k{};

    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[i]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}


int main()
{
    int A[] = {2,3,1,8,7,9,4,6,5,0}, n = 10;
    int B[] = {0,1,2,3,4,5,6,7,8,9};

    SelectionSort(A, n);
    SelectionSort(B, n);

    for (auto x : A)
    {
        cout << x << " ";
    }
    cout<<"\n";
     for (auto x : B)
    {
        cout << x << " ";
    }
    return 0;
}