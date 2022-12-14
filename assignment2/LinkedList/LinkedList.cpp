#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node *head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAtHead(node *head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deleteAtHead(node *head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}
void deletion(node *head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    display(head);
    cout << search(head, 5);
    deletion(head, 3);
    return 0;
}

/**
 * @brief Value, Address, Reference 
 * Variable, Pointer, Reference Variable
 * "0xff", 0xff, 0xff * 
 */
// .h
// extern int i;
// int i;
// int i = 10;
// HLL, Assembly Code, Machine Code, Executable Binary
// Compilation, Assemble, Linking
// .o, 
// Table (Symbol Table)

// Example 1
// int i = 1; // Value Variable
// int& j = i; // Reference Variable
// int* k = &i; // Pointer Variable

// Symbol Table
/**
 * j, i: 0xff
 * k: 0xf2
 */

// Pointer Arithematic
// ++

