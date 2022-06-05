#include <iostream>

using namespace std;

class Stack

{

private:
    int *S;

    int Size;

    int top;

public:
    Stack(int Size);

    void push(int ele);

    int pop();

    void Display();

    bool IsEmpty();

    bool IsFull();
};

Stack::Stack(int Size)

{

    this->Size = Size;

    top = -1;

    S = new int[this->Size];
}

void Stack::push(int ele)

{

    if (IsFull())

        cout << "Stack overflow";

    else

    {

        top++;

        S[top] = ele;
    }
}

int Stack::pop()

{

    int ele;

    if (IsEmpty())

        return -1;

    else

    {

        ele = S[top];

        top--;
    }

    return ele;
}

void Stack::Display()

{

    for (int i = top; i >= 0; i--)

    {

        cout << S[i] << " ";
    }
}

bool Stack::IsEmpty()

{

    if (top == -1)

        return true;

    else

        return false;
}

bool Stack::IsFull()

{

    if (top == Size - 1)

        return true;

    else

        return false;
}

Stack s1(10);

Stack s2(10);

void enqueue(int ele)

{

    if (s1.IsFull())

        cout << "Stack Overflow";

    else

        s1.push(ele);
}

void dequeue()

{

    if (s2.IsEmpty())

    {

        if (s1.IsEmpty())

            cout << "Stack underflow";

        else

        {

            while (!s1.IsEmpty())

            {

                s2.push(s1.pop());
            }
        }
    }

    cout << "Deleted element is " << s2.pop();
}

int main()

{

    int element, choice;

    do

    {

        cout << endl
             << endl
             << "********************MENU OPTIONS***********************" << endl;

        cout << "1.Enqueue" << endl;

        cout << "2.Dequeue" << endl;

        cout << "3.Display Stack 1" << endl;

        cout << "4.Display Stack 2" << endl;

        cout << "5.Exit" << endl;

        cout << endl
             << "Enter your choice ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            cout << "Enter element you want to insert ";

            cin >> element;

            enqueue(element);

            break;

        case 2:
            dequeue();

            break;

        case 3:
            cout << "Stack 1 is : ";

            s1.Display();

            break;

        case 4:
            cout << "Stack 2 is : ";

            s2.Display();

            break;
        }

    } while (choice < 5);

    return 0;
}