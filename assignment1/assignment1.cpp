#include <bits/stdc++.h>
using namespace std;

class student
{
    int roll;
    float sgpa;
    string name;

public:
    void getdata(int x, float y, string m)
    {
        roll = x;
        sgpa = y;
        name = m;
    }
    void putdata()
    {
        cout << "roll"
             << "\t"
             << "sgpa"
             << "\t"
             << "name" << endl;
        cout << roll << "\t"
             << "\t" << sgpa << "\t"
             << "\t" << name << endl;
    }
    // time complexity O(logn)
    void linearSearch(student s1[], int n, float sg)
    {
        int i = 0, flag = 0;
        for (i = 0; i < n; i++)
        {
            if (s1[i].sgpa == sg)
            {
                flag = 1;
                cout << i << endl;
                s1[i].putdata();
            }
        }
        if (!flag)
            cout << "NOT FOUND!\n";
    }
    // time complexity O(n)
    void binarySearch(student s1[], string keys, int n)
    {
        student ss;
        ss.bubbleSortName(s1, n);
        int f = 0;
        int low = 0;
        int high = n - 1;

        int mid;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (s1[mid].name < keys)
            {
                low = mid + 1;
            }
            else if (s1[mid].name > keys)
            {
                high = mid - 1;
            }
            else if (s1[mid].name == keys)
            {
                cout << "found \n";
                s1[mid].putdata();
                f = 1;
                // break;
                low++;
            }
        }
        if (!f)
        {
            cout << "NOT FOUND!\n";
        }
    }
    // best time O(n), worst O(n2)
    void bubbleSort(student s1[], int n)
    {
        int i, j;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (s1[j].roll > s1[j + 1].roll)
                {
                    swap(s1[j], s1[j + 1]);
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            s1[i].putdata();
        }
        cout << endl;
    }
    void bubbleSortName(student s1[], int n)
    {
        int i, j;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (s1[j].name > s1[j + 1].name)
                {
                    swap(s1[j], s1[j + 1]);
                }
            }
        }
        // void printArray(student s1[], int n);
        // {
        //     int i;
        //     for (i = 0; i < n; i++)
        //     {
        //         s1[i].putdata();
        //     }
        //     cout << endl;
        // }
    }
    // best time O(n), worst O(n2)
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
    // for doing quick sort we have to make partion first
    // best time nlogn, worst time O(n2)
    int partition(student s1[], int start, int end)
    {
        int pivot = s1[start].sgpa;
        int count = 0;
        for (int i = start + 1; i <= end; i++)
        {
            if (s1[i].sgpa <= pivot)
                count++;
        }
        // giving pivot element its correct position
        int pivotIndex = start + count;
        swap(s1[pivotIndex], s1[start]);
        // sorting left and right parts
        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex)
        {
            while (s1[i].sgpa <= pivot)
            {
                i++;
            }
            while (s1[j].sgpa > pivot)
            {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex)
            {
                swap(s1[i++], s1[j--]);
            }
        }
        return pivotIndex;
    }
    void quickSort(student s1[], int start, int end)
    {
        // base case
        if (start >= end)
            return;
        // partioning the array
        int p = partition(s1, start, end);
        // sorting the left part
        quickSort(s1, start, p - 1);
        // sorting the right part
        quickSort(s1, p + 1, end);
    }
    void printArrays(student s1[], int n)
    {
        int i;
        cout << "enter the no of toppers you want to see " << endl;
        cin >> n;
        for (i = n - 1; i >= 0; i--)
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
            // Take input
            dt = 1;
            cout << "Enter no of student" << endl;
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
            // Display data
            for (int i = 0; i < n; i++)
            {
                cout << i << endl;
                s[i].putdata();
                cout << endl;
            }
            break;
        case 3:
            // linear search
            cout << "enter sgpa to be searched using linear search" << endl;
            cin >> key;
            tmp.linearSearch(s, n, key);
            break;
        case 4:
            // binary search
            cout << "enter name to searched using binary search" << endl;
            cin >> keys;
            tmp.binarySearch(s, keys, n);
            cout << endl;
            break;
        case 5:
            // bubble sort
            cout << "we have sorted the elements with roll no using bubble sort" << endl;
            tmp.bubbleSort(s, n);
            break;
        case 6:
            // insertion sort
            cout << "we have sorted the elements with name using insertion sort " << endl;
            tmp.insertionSort(s, n);
            break;
        case 7:
            // quick sort in sgpa
            cout << "we have sorted the elements with sgpa using quick sort " << endl;
            tmp.quickSort(s, 0, n - 1);
            tmp.printArrays(s, n);
            break;
        }
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7);
}
