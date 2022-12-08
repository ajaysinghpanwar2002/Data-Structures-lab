#include <iostream>
using namespace std;
#define nl "\n"

struct node
{
    int data;
    bool left_flag;
    bool right_flag;
    struct node *left;
    struct node *right;

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        left_flag = 0;
        right_flag = 0;
    }
};

void insert(node *root, node *&p)
{
    if (p->data == root->data)
    {
        cout << "T-BST cannot contain duplicate elements";
        return;
    }
    else if (p->data < root->data)
    {
        if (root->left_flag == 0)
        {
            p->left = root->left;
            root->left = p;
            root->left_flag = 1;
            p->right = root;
        }
        else
        {
            insert(root->left, p);
        }
    }
    else if (p->data > root->data)
    {
        if (root->right_flag == 0)
        {
            p->right = root->right; // Dangling pointer from p
            root->right = p;
            root->right_flag = 1;
            p->left = root;
        }
        else
        {
            insert(root->right, p);
        }
    }
}

class ThreadedBST
{
    node *head, *root;

public:
    ThreadedBST()
    {
        head = new node(9999);
        root = nullptr;
        head->right = head;
        head->right_flag = 1;
    }

    void insert1(int data)
    {
        node *p = new node(data);
        if (root == nullptr)
        {
            root = p;
            head->left = root;
            head->left_flag = 1;
            p->left = head;
            p->right = head;
        }
        else
        {
            insert(root, p);
        }
    }
    void inorder()
    {
        node *t = root;
        do
        {
            while (t->left_flag != 0)
            {
                t = t->left;
            }
            cout << t->data << endl;
            while (t->right_flag == 0)
            {
                t = t->right;
                if (t == head)
                {
                    return;
                }
                cout << t->data << endl;
            }
        } while (t != head);
    }
    void preorder()
    {
        node *t = root;
        do
        {
            while (t->left_flag != 0)
            {
                cout << t->data << endl;
                t = t->left;
            }
            cout << t->data;
            while (t->right_flag == 0)
            {
                t = t->right;
                if (t == head)
                {
                    return;
                }
                t = t->right;
            }
        } while (t != head);
    };
};

int main()
{
    ThreadedBST t;
    int op = 1, x = 0;
    while (op != 0)
    {
        cout << "\n************************"
             << "\n\nChoose the Traversal you want to perform : " << nl
             << "1. Insert values in tree" << nl
             << "2. Inorder Traversal" << nl
             << "3. Preorder Traversal" << nl
             << "0. Exit" << nl;

        cin >> op;
        switch (op)
        {
        case 1:
            cout << "enter the data you want to insert :";
            cin >> x;
            t.insert1(x);
            break;
        case 2:
            cout << "Inorder Traversal" << nl;
            t.inorder();
            break;
        case 3:
            cout << "preorder Traversal" << nl;
            t.preorder();
            break;
        default:
            op = 0;
            break;
        }
    }

    return 0;
}