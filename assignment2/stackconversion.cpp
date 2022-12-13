#include <bits/stdc++.h>
using namespace std;

int evaluate(char x)
{
    if (x == '*')
    {
        return 4;
    }
    else if (x == '/')
    {
        return 3;
    }
    else if (x == '+')
    {
        return 2;
    }
    else if (x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node
{
    char data;
    struct node *next;
};
class stack
{
public:
    node *top;
    stack()
    {
        top = NULL;
    }
    node create(int x)
    {
        node *p;
        p = new node;
        p->data = x;
        p->next = NULL;
        return *p;
    }
    void push(char x)
    {
        node *newnode;
        newnode = new node;
        *newnode = create(x);
        if (top == NULL)
        {
            top = newnode;
            return;
        }
        newnode->next = top;
        top = newnode;
        return;
    }
    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return 1;
        }
        node *temp;
        temp = top;
        top = top->next;
        return temp->data;
    }
    void display()
    {
        node *temp;
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool empty()
    {
        return top == NULL;
    }
    char topElement()
    {
        return top->data;
    }
};
int evalution(int a, int b, char x)
{
    if (x == '*')
    {
        return b * a;
    }
    else if (x == '/')
    {
        return b / a;
    }
    else if (x == '+')
    {
        return b + a;
    }
    else
    {
        return b - a;
    }
}

int main()
{

    return 0;
}