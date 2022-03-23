#include <iostream>

#include <cstring>

using namespace std;

class Stack

{

private:
    char *S;

    int top;

    int Size;

public:
    Stack(int n);

    void push(char ch);

    int pop();

    int IsEmpty();

    int IsFull();

    int StackTop();
};

Stack::Stack(int n)

{

    Size = n;

    top = -1;

    S = new char[Size];
}

void Stack::push(char ch)

{

    if (IsFull())

        cout << "Stack overflow";

    else

    {

        top++;

        S[top] = ch;
    }
}

int Stack::pop()

{

    char ch;

    if (IsEmpty())

        return -1;

    else

    {

        ch = S[top];

        top--;
    }

    return ch;
}

int Stack::IsEmpty()

{

    if (top == -1)

        return 1;

    return 0;
}

int Stack::IsFull()

{

    if (top == Size - 1)

        return 1;

    return 0;
}

int Stack::StackTop()

{

    if (top == -1)

        return -1;

    else

        return S[top];
}

bool isBalanced(char exp[])

{

    Stack st(strlen(exp));

    for (int i = 0; exp[i] != '\0'; i++)

    {

        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')

            st.push(exp[i]);

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {

            if (st.IsEmpty())

                return false;

            else if ((exp[i] == st.StackTop() + 1) || (exp[i] == st.StackTop() + 2))
            {
                //* +1 and +2 coz ascii values of '(' and  ')' differ by 1 and of other brackets differ by 2
                cout << static_cast<char>(st.StackTop() ) << "\n";
                cout << static_cast<char>(st.StackTop() +1) << "\n";
                st.pop();
            }

            else
                return false;
        }
    }

    if (st.IsEmpty())

        return true;

    else

        return false;
}

int main()

{

    char A[10];

    cout << "Enter the expression ";

    cin >> A;

    int temp = isBalanced(A);

    if (temp == true)

        cout << "Matched";

    else

        cout << "Not matched";

    return 0;
}
