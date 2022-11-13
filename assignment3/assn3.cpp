#include <bits/stdc++.h>

using namespace std;
void insertElement(int arr[], int n, int &f, int &r, int data)
{
    // queue full condition
    if ((r + 1) % n == f)
    {
        cout << "Circular Queue is full!\n";
    }
    // queue is empty we'll add 1 element and make it f=0, r=0;
    else if (f == -1 and r == -1)
    {
        f++;
        r++;
        arr[r] = data;
    }
    // default case you can insert element
    else
    {
        r = (r + 1) % n;
        arr[r] = data;
    }
}
void deleteElement(int arr[], int n, int &f, int &r)
{
    // queue is empty
    if ((f == -1 and r == -1))
    {
        cout << "queue is empty" << endl;
    }
    // 1 element is there and we can delete that and setting f=-1 and r=-1
    else if (f == r)
    {
        cout << "the deleted element is " << arr[f] << endl;
        f = -1;
        r = -1;
    }
    // default case for deleting element
    else
    {
        cout << "the deleted element is "  << arr[f]<< endl;
        f = (f + 1) % n;
    }
}

void display(int arr[], int n, int f, int r)
{
    // queue empty condition
    if (f == -1 and r == -1)
    {
        cout << "Circular Queue is empty\n";
    }
    // default case
    else
    {
        cout << "The elements of Circular queue are : ";
        while (f != r)
        {
            cout << arr[f] << " ";

            f = (f + 1) % n;
        }
        cout << arr[f] << endl;
    }
}
int main()
{
    int n;
    cout << "\nEnter the size of circular queue : ";
    cin >> n;

    int arr[n];
    int f = -1, r = -1, data = 0;

    bool value = 1;
    int op = 0;
    while (value)
    {
        cout << "** CIRCULAR QUEUE **\n\n"
             << "Choose the operation you want to perform : \n"
             << "1. Insertion \n"
             << "2. Deletion \n"
             << "3. Display the Queue\n";

        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter the data you want to insert : ";
            cin >> data;
            insertElement(arr, n, f, r, data);
            break;
        case 2:
            deleteElement(arr, n, f, r);
            break;
        case 3:
            display(arr, n, f, r);
            break;
        default:
            value = 0;
        }
    }
}