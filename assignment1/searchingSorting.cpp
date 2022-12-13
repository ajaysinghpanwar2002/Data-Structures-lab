#include <bits/stdc++.h>
using namespace std;

// student naam ke class bna di
class student
{
    // 3 private members bhe dal diye h
    int roll;
    float sgpa;
    string name;

public:
    // jo private members theh unhe acess krne ke liye
    void getdata(int x, float y, string m)
    {
        roll = x;
        sgpa = y;
        name = m;
    }
    // private members ko print krne ke liye
    void putdata()
    {
        cout << "roll"
             << "sgpa"
             << "name" << endl;
        cout << roll << sgpa << name << endl;
    }
    // O (n)
    void linearSearch(student s1[], int n, float sg)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i].sgpa == sg)
            {
                flag = 1;
                cout << i << endl;
                s1[i].putdata();
            }
        }
        if (!flag)
        {
            cout << "NOT FOUND! \n";
        }
    }
    // best time O(n), worst O(n2)
    void bubbleSort(student s1[], int n)
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (s1[j].roll > s1[j + 1].roll)
                {
                    swap(s1[j], s1[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            s1[i].putdata();
        }
        cout << endl;
    }
    void bubbleSortName(student s1[], int k)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k - i - 1; j++)
            {
                if (s1[j].name > s1[j + 1].name)
                {
                    swap(s1[j], s1[j + 1]);
                }
            }
        }
    }
    // O(log n)
    void binarySearch(student s1[], string keys, int n)
    {
        student ss;
        ss.bubbleSortName(s1, n);
        bool flag = 0;
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (s1[mid].name < keys)
            {
                low = mid + 1;
            }
            else if (s1[mid].name > keys)
            {
                high = mid - 1;
            }
            else if (s1[mid].name > keys)
            {
                cout << "found \n";
                s1[mid].putdata();
                flag = 1;
                // break
                low++;
            }
            if (!flag)
            {
                cout << "NOT FOUND! \n";
            }
        }
    }
    void insertionSort(student s1[], int n)
    {
        int i, j;
        string key;
        for (i = 1; i < n; i++)
        {
            key = s1[i].name;
            j = i - 1;
            while (j >= 0 && s1[j].name > key)
            {
                s1[j + 1] = s1[j];
                j = j - 1;
            }
            s1[j + 1].name = key;
        }
        for (i = 0; i < n; i++)
        {
            s1[i].putdata();
        }
        cout << endl;
    }
};

int main()
{
    int n, loc, mid, choice, roll, dt = 0;
    float sgpa, key;
    string keys, name;
    student s[n], tmp;

    do
    {
        cout << "Enter the operation you want to perform \n 1: Take input \n 2: display data \n 3: linear search in sgpa \n 4: binary search in name \n 5: bubble sort in roll no \n 6: insertion sort in name \n 7: quick sort in Sgpa \n 0: end program" << endl;
        cout << "enter your choice " << endl;
        cin >> choice;

        if (dt == 0 && choice != 1)
        {
            cout << "No data availabe, To add data press 1\n";
            continue;
        }
        switch (choice)
        {
        case 1:
            dt = 1;
            cout << "enter no of students" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Roll no : ";
                cin >> roll;
                cout << "Enter Sgpa : ";
                cin >> sgpa;
                cout << "Enter Name : ";
                cin >> name;
                s[i].getdata(roll, sgpa, name);
            }
            for (int i = 0; i < n; i++)
            {
                s[i].putdata();
                cout << endl;
            }
            break;
        case 2:
        
        }
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7);
    return 0;
}