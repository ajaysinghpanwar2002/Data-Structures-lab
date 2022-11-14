#include <iostream>
using namespace std;
#define nl "\n"

// node structure
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// insertion
Node *insertBst(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBst(root->left, val);
    }
    else
    {
        // val > root->data
        root->right = insertBst(root->right, val);
    }
    return root;
}
// searching
Node *searchBst(Node *root, int key)

{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    // data > key
    if (root->data > key)
    {
        return searchBst(root->left, key);
    }
    // data < key
    return searchBst(root->right, key);
}
// inordersuccessor
Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
// deletion
Node *deleteBst(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteBst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteBst(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBst(root->right, temp->data);
    }
    return root;
}
// display of tree using Inorder Traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Display - Depth of tree
int depth(Node *root)
{
    if(root == NULL) return 0;
    int lh = depth(root->left);

}
int main()
{   
    // Node *root = NULL;
    // root = insertBst(root, 5);
    // insertBst(root, 1);
    // insertBst(root, 3);
    // insertBst(root, 4);
    // insertBst(root, 7);
    // if (searchBst(root, 5) == NULL)
    // {
    //     cout << "key does not exist";
    // }
    // else
    // {
    //     cout << "key exists";
    // }
    // // print inorder
    // inorder(root);
    // cout << endl;

    // root = deleteBst(root, 5);
    // inorder(root);

    int op = 1;
    Node *root = NULL;
    int n, arr[n];
    switch (op)
        while (op =! 0)
        {
            cout << "\nChoose the operation you want to perform: " << nl;
            cout << "1. Insertion " << nl;
            cout << "2. Delete " << nl;
            cout << "3. Search " << nl;
            cout << "4. Display tree (Traversal) " << nl;
            cout << "5. Display - Depth of tree " << nl;
            cout << "6. Display - Mirror image " << nl;
            cout << "7. Create a copy " << nl;
            cout << "8. Display all parent nodes with their child nodes " << nl;
            cout << "9. Display leaf nodes " << nl;
            cout << "10. Display tree level wise " << nl;
            cout << "*. Press any other numeric key to exit" << nl;
            cin >> op;
            {
            case 1:
                cout << "enter the elements you want to insert in a tree" << endl;
                cin >> n;
                for (int i = 0; i < n; i++)
                {   
                    cin >> arr[i];
                }
                root = insertBst(root, arr[n]);
                break;
            case 2:
                /* code */
                break;
            default:
                op = 0;
                break;
            }
        }
    return 0;
}
