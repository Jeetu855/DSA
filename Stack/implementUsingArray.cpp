#include <iostream>
#include <stdlib.h>

using namespace std;
// we require an array
// its size
// and a variable on topmost(last) element

struct Stack
{
    int size;
    int top;
    int *S; // stack(array)
};

// empty if(top==-1)
// full if(top==size-1)
// *time taken by push and pop is constant

void Create(struct Stack *st)
{
    cout << "Enter size : ";
    // scanf("%d",&st->size);
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];
}

void Display(Stack st)
{
    int i{};
    for (i = st.top; i >= 0; i--) //*topmost element is first element so start printing from there
    {
        cout << st.S[i] << " ";
    }
    cout << "\n";
}

void Push(Stack *st, int x) //*check stack overflow condition for push
{
    if (st->top == st->size - 1) //*stack overflow condition
    {                            
        cout << "Stack overflow\n";
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(Stack *st)
{ //*check stack underflow condition for pop
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack underflow\n";
    }
    else
    {
        x = st->S[st->top]; //*OR st->S[st->top--] in same line
        st->top--;
    }
    return x;
}

int Peek(Stack st, int position)
{
    int x = -1;
    if (st.top - position + 1 < 0)
    {
        cout << "Invalid position\n";
    }
    else
    {
        x = st.S[st.top - position + 1];
    }
    return x;
}

bool isEmpty(Stack st)
{
    if (st.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(Stack st)
{
    if (st.top == st.size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout << boolalpha;
    Stack st;
    Create(&st);
    // Push(&st, 10);
    // Push(&st, 20);
    // Push(&st, 30);
    // Push(&st, 40);
    // Push(&st, 50);
    // Push(&st, 60);
    Display(st);
    // cout << Pop(&st) << "\n";
    // Display(st);
    // cout << Pop(&st) << "\n";
    // cout << Pop(&st) << "\n";
    // cout << Pop(&st) << "\n";
    // cout << Pop(&st) << "\n";
    // cout << Pop(&st) << "\n";
    // Display(st);
    // cout<<Peek(st,4)<<"\n";
    // cout<<isFull(st)<<"\n";
    // cout<<isEmpty(st)<<"\n";
    return 0;
}
// *Before pushing check if stack is full or not(top=size-1)
// *position of element in stack starts from 1
// *but the array inside dtack behaves normally

// *relation between stack element position and array index
// *index=top-position+1(top is the highest index and index is the one we want to peek)
