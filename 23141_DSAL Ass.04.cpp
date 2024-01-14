// Name - Atharv Uddhav Kharmate.
// Roll No. - 23141
// Division - SE-09
// Batch - F9

//Program :-

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};

class Expression
{
    char prefix[20], postfix[20], infix[20];
    Node *root;
    int top;

public:
    void input(int);
    Node *getroot()
    {
        return root;
    }
    Node *create_Post();
    void inorder_withRec(Node *);
    void preorder_withRec(Node *);
    void postorder_withRec(Node *);
    void inorder_withoutRec(Node *);
    void preorder_withoutRec(Node *);
    void postorder_withoutRec(Node *);
};

void Expression::input(int x)
{
    if (x == 0)
    {
        cout << "\nEnter prefix Expression: ";
        cin >> prefix;
    }
    else
    {
        cout << "\nEnter postfix Expression: ";
        cin >> postfix;
    }
}

Node *Expression::create_Post()
{
    int i = 0;
    Node *temp, *t1, *t2;
    stack<Node *> s;

    for (; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            temp = new Node;
            temp->data = postfix[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();
            temp = new Node;
            temp->data = postfix[i];
            temp->left = t1;
            temp->right = t2;
            s.push(temp);
        }
    }
    temp = s.top();
    s.pop();
    return temp;
}

void Expression::inorder_withRec(Node *t)
{
    if (t != NULL)
    {
        inorder_withRec(t->left);
        cout << " " << t->data;
        inorder_withRec(t->right);
    }
}

void Expression::preorder_withRec(Node *t)
{
    if (t != NULL)
    {
        cout << " " << t->data;
        preorder_withRec(t->left);
        preorder_withRec(t->right);
    }
}

void Expression::postorder_withRec(Node *t)
{
    if (t != NULL)
    {
        postorder_withRec(t->left);
        postorder_withRec(t->right);
        cout << " " << t->data;
    }
}

void Expression::inorder_withoutRec(Node *t)
{
    Node *temp = t;
    stack<Node *> s;

    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
    }

    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        cout << " " << temp->data;
        temp = temp->right;
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}

void Expression::preorder_withoutRec(Node *t)
{
    Node *temp = t;
    stack<Node *> s;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        s.push(temp);
        temp = temp->left;
    }

    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        temp = temp->right;
        while (temp != NULL)
        {
            cout << " " << temp->data;
            s.push(temp);
            temp = temp->left;
        }
    }
}

void Expression::postorder_withoutRec(Node *t)
{
    Node *t1, *temp = t;
    stack<Node *> s, s1;

    while (temp != NULL)
    {
        s.push(temp);
        s1.push(NULL);
        temp = temp->left;
    }

    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        t1 = s1.top();
        s1.pop();
        if (t1 == NULL)
        {
            s.push(temp);
            s1.push((Node *)1);
            temp = temp->right;
            while (temp != NULL)
            {
                s.push(temp);
                s1.push(NULL);
                temp = temp->left;
            }
        }
        else
            cout << " " << temp->data;
    }
}
int main()
{
    int choice;
    Expression et;
    Node *t;
    et.input(1);
    t = et.create_Post();

    while (1)
    {
        // For Recursive Traversals
        cout << "\n1. Inorder traversal with recursion";
        cout << "\n2. Preorder traversal with recursion";
        cout << "\n3. Postorder traversal with recursion";
        // For Non-Recursive Traversals
        cout << "\n4. Inorder traversal without recursion";
        cout << "\n5. Preorder traversal without recursion";
        cout << "\n6. Postorder traversal without recursion";
        cout << "\n7. Exit the program";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nInorder traversal with recursion: ";
            et.inorder_withRec(t);
            cout << "\n";
            break;
        case 2:
            cout << "\nPreorder traversal with recursion: ";
            et.preorder_withRec(t);
            cout << "\n";
            break;
        case 3:
            cout << "\nPostorder traversal with recursion: ";
            et.postorder_withRec(t);
            cout << "\n";
            break;
        case 4:
            cout << "\nInorder traversal without recursion: ";
            et.inorder_withoutRec(t);
            cout << "\n";
            break;
        case 5:
            cout << "\nPreorder traversal without recursion: ";
            et.preorder_withoutRec(t);
            cout << "\n";
            break;
        case 6:
            cout << "\nPostorder traversal without recursion: ";
            et.postorder_withoutRec(t);
            cout << "\n";
            break;
        case 7:
            return 0;
        default:
            cout << "\nWrong choice. Please enter again.";
        }
    }
    return 0;
}

//Output:-

/*

Enter postfix Expression: ab+

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

Enter your choice: 1

Inorder traversal with recursion:  a + b

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

Enter your choice: 2

Preorder traversal with recursion:  + a b

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

Enter your choice: 3

Postorder traversal with recursion:  a b +

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

Enter your choice: 4

Inorder traversal without recursion:  a + b

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

Enter your choice: 5

Preorder traversal without recursion:  + a b

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

Enter your choice: 6

Postorder traversal without recursion:  a b +

1. Inorder traversal with recursion
2. Preorder traversal with recursion
3. Postorder traversal with recursion
4. Inorder traversal without recursion
5. Preorder traversal without recursion
6. Postorder traversal without recursion
7. Exit the program

*/