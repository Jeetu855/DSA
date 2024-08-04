#include<iostream>


void Insert(int A[],int insert_index){
    int i{insert_index},temp{0};
    temp=A[insert_index];

    while(i>1 && temp>A[i/2]){//comparing with parent
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}


int Delete(int A[],int n){ // Is also heap sort
    int i{0},j{0},x{0},temp{0},del_val{0};
    del_val=A[1];
    x=A[n];// n is the index of last element
    A[1]=A[n];
    A[n]=del_val;
    i=1;j=2*i; // j is left child of i

    while(j<n-1){ // < n-1 coz we have reduced the size of the array by 1
        if(A[j+1]>A[j]){
            j=j+1;  
        }
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*i;
        }
        else{
            break;
        }
    }
    return del_val;
}

int main(){

    int H[]{0,10,20,30,25,5,40,35};// 0 is ignored, we wont be using that location
    // Insert(H,2);//assume first element already in heap
    // Insert(H,3);
    // Insert(H,4);
    // Insert(H,5);

    for(size_t i=2;i<=7;i++){
        Insert(H,i);
    }
    for(size_t i=1;i<=7;i++){
        std::cout<<H[i]<<" ";
    }
    std::cout<<"\n";

    // std::cout<<"Deleted value is :"<<Delete(H,7)<<"\n";
    // for(size_t i=1;i<=7;i++){
    //     std::cout<<H[i]<<" ";
    // }
    std::cout<<"\n";
    for(size_t i=7;i>=1;i--){
        std::cout<<"Deleted value is "<<Delete(H,i)<<"\n";
    }

    for(size_t i=1;i<=7;i++){
        std::cout<<H[i]<<" ";
    }
    return 0;
}