Pointers are variables that store address of other variables

int a{4};
int *p;  //pointer to integer
p=&a;  //putting & in front of a variable gives us the address of that variable
print *p = 4 // derefrencing a pointer
*p = 8
print a = 8

Pointer Arithematic

print p  // value/address stored in pointer variable p
print p+1 // answer will be value stored in p + storage required to store int pointer in memory i.e 4 bytes
so final answer will be value+4

**p+1 takes us to address of next integer**

**Why do we need to specify data type for pointers, since they are just address why do they need data type?**

***Answer : We need to specify the data type because it is needed when derefrencing the pointer***
***Lets say pointer 'p' holds address of integer variable. Integer in mordern system take up 4 bytes***
***The address stored in pointer 'p' is the address of first byte.*** 
***But it needs to know how many bytes to read after knowing the base address, for that we need to specify the data type of pointers*** 

Example code

```c
int a = 1025;
int *p=&a;
cout<<"size of interger is "<<sizeof(int)<<"bytes\n";
cout<<"Address = "<<p<<" value ="<<*p<<"\n";
cout<<"Address = "<<(p+1)<<" value ="<<*(p+1)<<"\n";
char *p0;
p0=(char *)p;//typecasting
cout<<"size of char is "<<sizeof(char)<<" bytes\n";
cout<<"Address = "<<p<<" value="<<*p<<"\n";
cout<<"Address = "<<(p0+1)<<" value ="<<*(p0+1)<<"\n";
```
Output 

After typecasting the pointer to char pointer, it will only ready 1 byte of data
1025 in binary, the last byte is : 00000000 00000000 00000100 00000001
So the output will be '1' and not 1025 since it wont ready 4 bytes but only the first byte
*(p0+1) this will print the value 4 as the second byte value is 4

#### Void pointer

```c
int a = 1025;
int *p=&a;
void *p0;
p0=p; // dont need typecasting here
```

Since this type of pointer is not mapped to particular data type, we cannot derefrence it
Also pointer arithematic on it will give compilation error

#### Pointer to pointer

```c
int x=5;
int *p=&a;
*p=6;
int **q=&p;
```

When declaring pointer read them from right to left, example

```c
int **q; // this will be read as pointer to pointer to integer
int ***p; // this will be read as pointer to pointer to pointer to integer

//p can store value of ** (pointer to pointer)
//q can store value of *  (pointer)  
```

#### Pointers as Function Arguments(Call by reference)

```c
void Increment(int a){
    a=a+1;
    cout<<"Address of variable in Increment function is "<<&a;
}

int main(){
    int a{10};
    Increment(a);
    cout<<"Address of variable in main is "<<&a;
    return 0;
}
```

Both the adddress are different so the variable in both the methods are different
When program is executed, some amount of memory is set aside for the program
This memory is divided into 4 parts
- Stack (Stores all the local variables)(Fixed is size)
- Heap 
- Static/Global (For static and global variables)(Fixed is size)
- Code(Text) (Instruction in the program)(Fixed is size)


Each function has a stack frame
When increment function called, a new stack frame created for it
The local variables are in the stack frame of respective function
When we increment the value of the varible 'a', the variable inside the Increment function is incremented
and the variable inside the main function is untouched

In the calling function(Here the main funciton), the argument is called actual argument 
In the called funcion (here the Increment function), the argument is called formal argument

Actual argument is mapped to formal 
Here we have 1 variable mapped to another variable and the value of actual argument is copied into formal argument
This is what we term as Call by Value


To actually increment original variables value, we need call by reference

```c
void Increment(int p){
    *p=*p+1;
    cout<<"Address of variable in Increment function is "<<&a;
}

int main(){
    int a{10};
    Increment(&a);
    cout<<"Address of variable in main is "<<&a;
    return 0;
}
```

This will increment the value of original variable


#### Pointer and Arrays

```c
int A[5];
int *p=A;
A[0]=1,A[1]=2,A[2]=3,A[3]=4,A[4]=5;
print *p   = 1
print *(p+1)   = 2
print *(p+2)   = 3
print *(p+3)   = 4
//pointer arithematic useful with arrays
```

***Name of array is address of first element of array***


#### Array as function Arguments

```c
int sumOfElements(int A[]){
    int sum{0};
    int size=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<size;i++){
        sum+=A[x];
    }
    return z;
}
// 
int main(){
    int A[]{1,2,3,4,5};
    int total = sumOfElements(A);
    cout<<"Sum of elements is"<< total<<"\n";
}
```
Running the above program, the output is 1, i.e sum of elements of array comes out as 1
This happens because

***When we pass array as a parameter to a function, the compiler instead of copying the entire array in the called function,***
***just copies the address of first element of the array passed as argument. Compiler implicitly converts 'int A[]' to 'int *A'***
***Arrays always passed by call by refrence. This makes lot of sense cause array can be really large in size. Dosent make sense to copy the entire array each time it is passed to a . So for array there is no call by value there is always call by reference***

So the output of above program will be 1 since 'sizeof(A) = 4' and 'sizeof(A[0])=4' so final value of size variable is 1 so only first element of array is added to total and its value is 1

We should calculate the size of array in main function and pass it as a parameter to the function that requires the size of an array
The solution would be to calculate the size of array in main function and pass it as an argument to the sumOfElements function

#### Character Arrays

**How to store stings?**
size of array >= number of characters in string + 1
extra 1 space for null terminator
null character/null terminator = \0 has ascii value 0
these are c-style strings
'printf' and 'cout' only print until they reach the null character

```c
char C[5]="John"
cout<<strlen(C)<<"\n"; // length is 4
cout<<sizeof(C);  // = 5 bytes, since we also count sizeof null terminator

//another declaration
char Z[5]={'J','o','h','n','\0'}// in this type of declration we have to specify null termination explicitly
```

**Arrays and pointers are different types used in similar manner**

```c
char c1[6]="Hello";
// another way to do this
char *c3 = "Hello";
char *c2;
c2=c1; //this is valid
// c1=c2 //this is not valid, this will give compilation error
```

If we just want to pass array to function and not change its contents do it like this

```c
void print(const char *C){
    while(*C!='\0'){
        cout<<*C;
        C++;
    }
}
// pass it as const so that its content cannot be modified by the function its being passed to
```

#### Pointes and MultiDimensional Arrays

```c
int B[2][3];
// 2 1-Dimensional Array of 3 elements each
// B[0] and B[1] are 2 1-Dimensional Arrays of size 3, lets say B[0] is at address 400-411(assuming integer takes 4 bytes)
// then array B[1] will be from 412-423 address, in memory they are like 2 contiguous arrays
// As we know, name of array is address of first element, but in this case each element is not an integer
// B[0] and B[1] are 1-dimensional array
// something like int *p=B;  this is wrong since B will return a pointer to 1-Dimensional array of integers and not just pointer to int
int (*p)[3] = B; //  this is ok since B return address of B[0] array
//  doing something like print *B, which is same as printing B[0], B[0] is variable name for 1-Dimensional array of 3 integers
// so &B[0] returns pointer to first integer in B[0]  
```

What will print(B+1) print?
***B returns us pointer to first 1-D array of 3 integers,so if we do B+1 pointer arithematic, we are moving to next 1-D array of 3 integers***
B+1 == &B[1]
\*(B+1) == B[1] == &B[1][0]
\*(B+1) is pointer to integer B[1][0]

(\*(B+1)+2) : Divide the problem, \*(B+1) returns pointer to element B[1][0] or just base address of B[1]
Adding +2 to it is adding 2*sizeof(int) so overall (\*(B+1)+2) gives pointer to B[1][2]

\*(\*B+1): \*B returns base address of first integer array, +1 to it will return the address of second integer in that array so B[0][1]
now we need to derefrence pointer pointing to B[0][1] so it returns the value of second element in first array


```c
    int B[2][3]{{1,2,3,},{4,5,6}};
    cout<<B<<"\n";  // base address of first array, prints pointer to 1-D array of integers
    cout<<*B<<"\n"; // base address of first array, prints pointer to an intger
    cout<<&B[0]<<"\n"; // base address of first array
    cout<<*(B+1)<<"\n"; // base address of first array
    cout<<&B[1]<<"\n"; // base address of second array
// Output:
// 0x61fef8
// 0x61fef8
// 0x61fef8
// 0x61ff04
// 0x61ff04
```
B :  base address of first array, prints pointer to 1-D array of integers
\*B : base address of first array, prints pointer to an integer
Multidimesional array can be thought of as array of arrays

3-D array is collection of 2-D arrays

```c
int C[3][2][2];
// 3 arrays of size 4 integers
// array name C : this will give us pointer to a 2-D array of size [2][2]
// *C : this will give us pointer to a 1-D array of size [2]
```

#### Pointers and Dynamic Memory

Heap size is not fixed
Heap is free pool of memory
Using heap refered to as dynammic meory allocation
**This is not the heap data structure, unlike stack memory that is actually an implementaion of stack data structure**

```c
int a;
int *p;
p = (int *)malloc(sizeof(int));
// we are doing typecasting here as p is a pointer to integer and malloc returns a pointer to void
*p=10;
p = (int *)malloc(sizeof(int));
// free(p); // this clears the pointer to previous block
// one more block of 4 bytes allocated on the heap, p now points to new block, the previous block still sits in memory
// it is no cleared automatically
*p=20;
```

**malloc function requires a parameter that is the size of memory we require on heap and malloc returns a pointer**
**malloc returns a void pointer**
**In the above code we are doing typecasting as p is a pointer to integer and malloc returns pointer to void**
Only way to access heap is by using pointers

```c++
int *p;
p = new int;
*p=10;
delete p;
p = new int[20];
delete [] p;
```
**new and delete are type safe and return pointer to data type that we requested**

##### Functions to allocate memory on the heap

- malloc : void * malloc(size_t size)   : the data passed to it must be unsigned, it does not initilize the values
- calloc : void * calloc(size_t num, size_t size) : again it also requires unsigned data for size and also another unsigned data for number of elements, calloc sets all the values wiht '0'
example : int *p = (int *)calloc(20,sizeof(int))
- realloc : void * realloc(void * ptr, size_t size)  : if we have a dynamically allocated block of memory and we want to change size of it, it requires the pointer to base address of the dynamically allocated memory block

#### Function Pointers

These are used to store address of functions
**Address of a function is the address of the first instruction in that function**

```c++

int add(int a,int b){
    return a+b;
}
int main(){
   int (*p)(int, int); // first type the return type of function, then name of variable then type argument type of this function
   p=&add;  // above line, if we dont put variable name inside parenthesis that means we are declaring a function that returns a
   return 0;  // pointer to an integer like this : int * a(int , int)
   int c = (*p)(2,3); // to execute the function, derefrence the pointer, make sure to write the variable inside parenthesis
}
```

Also we can just use the function name when assigning the pointer a value, the '&' is not necessary, like this
And to derefrence, we can just use the name of variable, no need to derefrence
```c
p=add;
int c = p(2,3);
```