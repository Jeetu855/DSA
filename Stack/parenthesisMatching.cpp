#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    char data;
    Node *next;
};
Node *top{nullptr};

void Push(char x)
{
    Node *t = new Node;
    if (t)
    {
        t->data = x;
        t->next = top;
        top = t;
    }
    else
    {
        cout << "Heap memory full\n";
    }
}

char Pop()
{
    Node *t;
    char x = '-';
    if (top)
    {
        t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int isBalance(char *exp)
{
    int i{};
    for (i; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')')
        {   //*case when more number of closing brackets
            //    *than opening so stack becomes 0 and still we have ) brackets left
            if (top == nullptr)
            {
                return false;
            }
            else
            {
                Pop();
            }
        }
    }
    if (top == nullptr)
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
    // cout<<boolalpha;
    // char expr[]="((a+b)*(c-d))";
    char *exp = "((a+b)*(c-d))";
    char *expr = "(((a+b)*(c-d))";

    char *exprsn = "((a+b)*(c-d)";
    char *exprsnn = "(a+b)*(c-d))";
    cout << isBalance(exp) << "\n";
    cout << isBalance(expr) << "\n";

    cout << isBalance(exprsn) << "\n";
    cout << isBalance(exprsnn) << "\n";

    // cout<<(expr[1])<<"\n";
    // cout<<(exp[1])<<"\n";
    return 0;
}