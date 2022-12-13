#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

class Node
{
public:
    Node *left;
    char data;
    Node *right;

    Node(char x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class ExpressionTree
{
    Node *root;

public:
    ExpressionTree()
    {
        root = nullptr;
    }

    stack<Node *> s; // for non-recursive traversals (backtracking)
    void inorderTraversalRecursive(Node *root)
    {
        if (root != nullptr)
        {
            inorderTraversalRecursive(root->left);
            cout << root->data;
            inorderTraversalRecursive(root->right);
        }
        else
        {
            return;
        }
    }
    void inorderTraversalNonRecursive(Node *root)
    {
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            cout << root->data;
            root = root->right;
            while (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
        }
    }
    void PreOrderTraversalRecursive(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << endl;
            PreOrderTraversalRecursive(root->left);
            PreOrderTraversalRecursive(root->right);
        }
        else
            return;
    }
    void preOrderTraversalNonRecursive(Node *root)
    {
        while (root != nullptr)
        {
            cout << root->data;
            s.push(root);
            root = root->left;
        }
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            root = root->right;
            while (root != nullptr)
            {
                cout << root->data;
                s.push(root);
                root = root->left;
            }
        }
    }
    void postOrderRecursive(Node *root)
    {
        if (root != nullptr)
        {
            postOrderRecursive(root->left);
            postOrderRecursive(root->right);
            cout << root->data;
        }
        else
            return;
    }
};

int main()
{
    int op = 1, op1 = 1;
    string postfix, prefix;

    ExpressionTree t;
    Node *root;

    stack<Node *> st;
    while (op != 0)
    {
        cout << "\nChoose the operation you want to perform: " << nl;
        cout << "1. Postfix Expression Tree" << nl;
        cout << "2. Prefix Expression Tree" << nl;
        cout << "3. Traversal" << nl;
        cout << "*. Press any other numeric key to exit" << nl;
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Enter the Postfix Expression : " << nl;
            cin >> postfix;
            for (auto it : postfix)
            {
                Node *newNode = new Node(it);
                if ((it >= 'a' and it <= 'z') or (it >= 'A' and it <= 'Z') or (it >= '0' and it <= '9'))
                {
                    st.push(newNode);
                }
                else
                {
                    Node *t2 = st.top();
                    st.pop();
                    Node *t1 = st.top();
                    st.pop();
                    newNode->left = t1;
                    newNode->right = t2;
                    st.push(newNode);
                }
            }
            root = st.top();
            st.pop();
            break;
        case 2:
            cout << "Enter the Prefix Expression : " << nl;
            cin >> prefix;
            for (auto it = prefix.rbegin(); it < prefix.rend(); it++)
            {
                Node *newNode = new Node(*it);
                if ((*it >= 'a' and *it <= 'z') or (*it >= 'A' and *it <= 'Z') or (*it >= '0' and *it <= '9'))
                {
                    st.push(newNode);
                }
                else
                {
                    Node *t1 = st.top();
                    st.pop();
                    Node *t2 = st.top();
                    st.pop();
                    newNode->left = t1;
                    newNode->right = t2;
                    st.push(newNode);
                }
            }
            root = st.top();
            st.pop();
            break;
        }
    }

    return 0;
}