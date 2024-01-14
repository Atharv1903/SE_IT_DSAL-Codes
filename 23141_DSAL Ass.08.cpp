Name - Atharv Uddhav Kharmate.
Roll NO - 23141
Division - SE-09
Batch - F9

Program :-
 
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    bool lthread; // false if for child and true is thread
    bool rthread;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        lthread = true;
        rthread = true;
    }
};
class TBT // Threaded binary tree
{
public:
    node *root;
    TBT()
    {
        root = NULL;
    }
    node *insert(node *root, int val) // Function to insert elements in tree
    {
        node *curr = root;
        node *parent = NULL;
        while (curr != NULL)
        {
            if (curr->data == val)
            {
                return root;
            }
            parent = curr;
            if (val < curr->data)
            {
                if (curr->lthread == false)
                {
                    curr = curr->left;
                }
                else
                {
                    break;
                }
            }
            else if (val > curr->data)
            {
                if (curr->rthread == false)
                {
                    curr = curr->right;
                }
                else
                {
                    break;
                }
            }
        }
        node *newnode = new node(val);
        if (parent == NULL)
        {
            root = newnode;
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        else if (val > parent->data)
        {
            newnode->right = parent->right;
            newnode->left = parent;
            parent->rthread = false;
            parent->right = newnode;
        }
        else if (val < parent->data)
        {
            newnode->left = parent->left;
            newnode->right = parent;
            parent->lthread = false;
            parent->left = newnode;
        }
        return root;
    }
    node *inorderSuccessor(node *temp) // Function to find InorderSuccessor
    {
        if (temp->rthread == true)
        {
            return temp->right;
        } 
        temp = temp->right;
        while (temp->lthread == false)
        {
            temp = temp->left;
        }
        return temp;
    }
    void inorder(node *root) // Function for inorder traversal
    {
        if (root == NULL)
        {
            cout << "\nEmpty tree.";
        }
        else
        {
            node *temp = root;
            while (temp->lthread == false)
            {
                temp = temp->left;
            }
 
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = inorderSuccessor(temp);
            }
        }
    }
    void preorder(node *root) // Function for preorder traversal with recursion
    {
        if (root == NULL)
        {
            cout << "\nEmpty tree.";
        }
        cout << root->data << " ";
        if (root->lthread == false)
        {
            preorder(root->left);
        }
        if (root->rthread == false)
        {
            preorder(root->right);
        }
    }
 
    void preordernonrecursive(node *root) // Function for preorder traversal without recursion
    {
        if (root == NULL)
        {
            cout << "\nEmpty tree.";
        }
        while (root != NULL)
        {
            cout << root->data << " ";
            if (root->lthread == false)
            {
                root = root->left;
            }
            else if (root->rthread == false)
            {
                root = root->right;
            }
            else
            {
                while (root != NULL && root->rthread == true)
                {
                    root = inorderSuccessor(root);
                }
                if (root != NULL)
                {
                    root = root->right;
                }
            }
        }
    }
    void postorder(node *root) // Function for postorder traversal with recursion
    {
        if (root == NULL)
        {
            cout << "\nEmpty tree.";
        }
        if (root->lthread == false)
        {
            preorder(root->left);
        }
        if (root->rthread == false)
        {
            preorder(root->right);
        }
        cout << root->data << " ";
    }
};
int main()
{
    TBT obj; // Instance of class TBT
    int choice, n, val;
    do
    {
        cout << "\n1.Insert elements in tree";
        cout << "\n2.Display inorder";
        cout << "\n3.Display preorder";
        cout << "\n4.Display postorder";
        cout << "\n5.Diplay preorder with recursion";
        cout << "\n6.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
 
        switch (choice)
        {
        case 1:
            obj.root = (obj.insert(obj.root, 50));
            cout << "\nRoot of Threaded Binary Tree: 50";
            cout << "\nEnter no of elements you want: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter values: ";
                cin >> val;
                obj.insert(obj.root, val);
            }
            break;
        case 2:
            cout << "\nThreaded Binary tree using inorder: ";
            obj.inorder(obj.root);
            cout << endl;
            break;
        case 3:
            cout << "\nThreaded Binary tree using preorder:  ";
            obj.preordernonrecursive(obj.root);
            cout << endl;
            break;
        case 4:
            cout << "\nThreaded Binary tree using postorder: ";
            obj.postorder(obj.root);
            cout << endl;
            break;
        case 5:
            cout << "\nThreaded Binary tree using preorder: ";
            obj.preorder(obj.root);
            cout << endl;
            break;
        default:
            break;
        }
    } while (choice < 6);
    return 0;
}

Output :-

1.Insert elements in tree
2.Display inorder
3.Display preorder
4.Display postorder
5.Diplay preorder with recursion
6.Exit
Enter your choice: 1
Root of Threaded Binary Tree: 50
Enter no of elements you want: 4
Enter values: 34
Enter values: 65
Enter values: 2
Enter values: 13 
1.Insert elements in tree
2.Display inorder
3.Display preorder
4.Display postorder
5.Diplay preorder with recursion
6.Exit
Enter your choice: 2
Threaded Binary tree using inorder: 2 13 34 50 65
1.Insert elements in tree
2.Display inorder
3.Display preorder
4.Display postorder
5.Diplay preorder with recursion
6.Exit
Enter your choice: 3
Threaded Binary tree using preorder:  50 34 2 13 65
1.Insert elements in tree
2.Display inorder
3.Display preorder
4.Display postorder
5.Diplay preorder with recursion
6.Exit
Enter your choice: 4
Threaded Binary tree using postorder: 34 2 13 65 50
1.Insert elements in tree
2.Display inorder
3.Display preorder
4.Display postorder
5.Diplay preorder with recursion
6.Exit
Enter your choice: 6

