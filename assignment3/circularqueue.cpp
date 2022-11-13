// implement circular queue using array and perform following operatins on it
// 1) insertion
// 2) delete element
// 3) display
//  handle queue full conditon by considering fixed size of queue

#include <bits/stdc++.h>

using namespace std;
void insertElement(int arr[], int n, int &f, int &r, int data)
{
    if ((r + 1) % n == f)
    {
        cout << "Circular Queue is full!\n";
    }
    else if (f == -1 and r == -1)
    {
        f++;
        r++;
        arr[r] = data;
    }

    else
    {
        r = (r + 1) % n;
        arr[r] = data;
    }
}

void deleteElement(int arr[], int n, int &f, int &r)
{
    if (f == -1 and r == -1)
    {
        cout << "Circular queue is already empty\n";
    }
    else if (f == r)
    {
        cout << "The deleted data is " << arr[f] << endl;
        f = -1;
        r = -1;
    }
    else
    {
        cout << "The deleted data is " << arr[f] << endl;
        f = (f + 1) % n;
    }
}

void display(int arr[], int n, int f, int r)
{
    if (f == -1 and r == -1)
    {
        cout << "Circular Queue is empty\n";
    }
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
    cout << "\nEnter the size of the Circular queue : ";
    cin >> n;

    int arr[n];
    int f = -1, r = -1, data = 0;

    bool run = 1;
    int op = 0;
    while (run)
    {
        cout << "** CIRCULAR QUEUE **\n\n"
             << "Choose the desired option : \n"
             << "1. Insertion (Enqueue)\n"
             << "2. Deletion (Dequeue)\n"
             << "3. Display the Circular Queue\n"
             << "4. Enter any other numeric key to exit\n\n";

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
            run = 0;
        }
    }
}