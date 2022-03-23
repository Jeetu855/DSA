#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Node
{
    char data;
    Node *next;
};

Node *top = nullptr;

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
    char x = '-';
    Node *t = nullptr;
    if (top)
    {
        t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    else
    {
        cout << "Stack is empty\n";
    }
    return x;
}

int isEmpty()
{
    if (top != nullptr)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int isBalance(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            Push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                Pop();
            }
        }
    }
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;

    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char *toPostfix(char *infix)
{
    char *postfix = new char[strlen(infix) + 2]; //*+2, 1  for \0 and 1 for initial stack value
    int i{}, j{};
    while (infix[i])
    {
        if (isOperand(infix[i]))
        {
            postfix[j] = infix[i];
            i++, j++;
        }
        else if (precedence(infix[i]) > precedence(top->data))//*if checking for first time when stack is empty will give error 
        {//*so push some random value at beginning
            Push(infix[i]);
            i++;
        }
        else
        {
            postfix[j] = Pop();
            j++;
        }
    }
    while (top != nullptr)
    {
        postfix[j] = Pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char a[] = "((a+b)*(c-d)";
    char b[] = "((a*b)-(c*d))";
    char c[] = "(a+b)-(d-e))";
    // cout<<isBalance(a)<<"\n";
    // cout << isBalance(b) << "\n";
    // cout<<isBalance(c)<<"\n";
    char infix[]= "a+b*c-d/e";
    Push('#');//*need some random val coz initially stack maybe empty and precedence finding may give error when checking it for first time

    char *postfix = toPostfix(infix);

    printf("%s ", postfix);
    return 0;
}