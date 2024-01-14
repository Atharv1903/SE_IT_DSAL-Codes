// Name - Atharv Uddhav Kharmate.
// Roll NO - 23141
// Division - SE-09
// Batch - F9

//Program :-

#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *leftc,*rightc;
    node(int dataa){
        data = dataa;
        leftc = NULL;
        rightc = NULL;
    }
    node(){
        leftc = NULL;
        rightc =NULL;
    }
    node* insert(node *root,unordered_set<int>&s){
        cout << "Please enter the element you want to insert : ";
        int key; cin>>key;
        while(s.count(key)){
            cout << "Please enter an unique element : ";
            cin>>key;
        }
        s.insert(key);
        node *ptr = new node(key);
        if(root==NULL){
            root = ptr;
            return root;
        }
        node *curr = root;
        while(curr!=NULL){
            if(key>curr->data){
                if(curr->rightc ==NULL){
                    curr->rightc = ptr;
                    return root;
                }
                curr= curr->rightc;
            }
            else{
                if(curr->leftc ==NULL){
                    curr->leftc = ptr;
                    return root;
                }
                curr= curr->leftc;
            }
            
        }
        return root;
    }

    node* deletee(node *root,unordered_set<int>&s){
        if(root==NULL){
            cout << "Tree doesn't exist!" << endl;
            return root;
        }
        cout << "Please enter the data you want to delete : ";
        int key; cin>>key;
        if(s.count(key)){
            s.erase(key);
            if (root->data == key) {
                return BringCorrectNode(root);
            }
            node *dummy = root;
            while (root != NULL) {
                if (root->data > key) {
                    if (root->leftc != NULL && root->leftc->data == key) {
                        root->leftc = BringCorrectNode(root->leftc);
                        break;
                    } 
                    else {
                        root = root->leftc;
                    }
                } 
                else {
                    if (root->rightc != NULL && root->rightc->data == key) {
                        root->rightc = BringCorrectNode(root->rightc);
                        break;
                    } 
                    else{
                        root = root->rightc;
                    }
                }
            }
            return dummy;
        }
        else{
            cout << "The key is not present in the tree" << endl;
            return root;
        }
        
    } 
    
    node* BringCorrectNode(node* root) {
        if (root->leftc == NULL) 
        {
            return root->rightc;
        } 
        else if (root->rightc == NULL)
        {
            return root->leftc;
        } 
        node* rightChild = root->rightc;
        node* lastRight = findLastRight(root->leftc);
        lastRight->rightc = rightChild;
        return root->leftc;
    }

    node* findLastRight(node* root) {
        if (root->rightc == NULL) {
            return root;
        }
        return findLastRight(root->rightc);
    }
    
    int depth(node *root ){
         if(root==NULL){
            return 0;
        }
        int lheight = depth(root->leftc);
        int rheight = depth(root->rightc);
        return max(lheight,rheight) +1;
    }

    node* godeep(node *root){
        if(root->rightc==NULL) return root;
        return godeep(root->rightc);
    }

    node* mirror(node *root){
        if(root==NULL) return NULL;
        node *temp = new node(root->data);
        
        temp->leftc = mirror(root->rightc);
        temp->rightc=mirror(root->leftc);
        
        return temp;
    }

    void leafnode(node *root){
        if(root==NULL) return;
        leafnode(root->leftc);
        if(root->leftc==NULL&&root->rightc==NULL){
            cout << root->data << " ";
        }
        leafnode(root->rightc);
    }

    node *createcopy(node *root){
        if(root==NULL) return NULL;
        node *copyroot = new node;
        copyroot->data = root->data;
        copyroot->leftc = createcopy(root->leftc);
        copyroot->rightc = createcopy(root->rightc);
        return copyroot;
    }

    void parentchild(node *root){
        if(root==NULL){
            return;
        }
        parentchild(root->leftc);
        cout << "Parent : " << root->data << endl;
        int leftdata,rightdata;
        if(root->leftc==NULL){
            leftdata= -1;
        }
        else{
            leftdata=root->leftc->data;
        }
        if(root->rightc==NULL){
            rightdata = -1;
        }
        else{
            rightdata =root->rightc->data ;
        }
        cout << "Left child : " << leftdata << " " << "Right child : " << rightdata << endl;
        parentchild(root->rightc);
    }

    void levelwise(node *root){
        if(root==NULL){
            cout << "The tree is empty!" << endl;
            return;
        }
        queue<node *>q;
        q.push(root);
        cout << "Levelwise traversal :-" << endl;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                cout << q.front()->data << " ";
                if(q.front()->leftc!=NULL){
                    q.push(q.front()->leftc);
                }
                if(q.front()->rightc!=NULL){
                    q.push(q.front()->rightc);
                }
                q.pop();
            }
            cout << endl;
        }
    }

    void preorder(node *root){
        if(root==NULL) return;
        cout <<root->data << " ";
        preorder(root->leftc);
        preorder(root->rightc);
    }
    void postorder(node *root){
        if(root==NULL) return;
        postorder(root->leftc);
        postorder(root->rightc);
        cout << root->data << " ";
    }
    void inorder( node *root){
        if(root==NULL) return;
        inorder(root->leftc);
        cout << root->data << " " ;
        inorder(root->rightc);
    }
};
int main(){
    cout << "First create a tree" << endl;
    bool first = true;
    node *root=NULL;
    node call;
    unordered_set<int>s;
    while(1){
        if(first){
            cout << "Please enter root node :";
            int date; cin>>date;
            s.insert(date);
            node *ptr = new node(date);
            root = ptr;
            first =0;
        }
        else{
            cout << "You want to insert more elements ? (Y/N) : ";
            char c; cin>>c;
            if(c=='y'||c=='Y'){
                root = call.insert(root,s);
            }
            else if(c=='N'||c=='n'){
                break;
            }
            else{
                cout << "Please enter a valid choice" << endl;
            }
        }
    }
    while(1){
        cout << "MENU" << endl; 
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Display tree (Traversal)" << endl;
        cout << "5.Display - Depth of tree" << endl;
        cout << "6.Display - Mirror image" << endl;
        cout << "7.Create a copy" << endl;
        cout << "8.Display all child nodes with their parent nodes" << endl;
        cout << "9.Display all leaf nodes" << endl;
        cout << "10.Display tree levelwise" << endl;
        cout << "11.Exit" << endl;
        cout << "Please select a choice : " ;
        int ch; cin>>ch;
        cout << endl;
        if(ch==1){
            root = call.insert(root,s);
        }
        else if(ch==2){
            root = call.deletee(root,s);
        }
        else if(ch==3){
            cout << "Please enter the element you want to search : ";
            int key; cin>>key;
            if(s.count(key)){
                cout << "Element is present in the given tree" << endl;
            }
            else{
                cout << "Element is not present in the given binary tree" << endl;
            }
        }
        else if(ch==4){
            cout << "Inorder traversal : ";
            call.inorder(root);
            cout << endl;
            cout << "Preorder traversal : " ;
            call.preorder(root);
            cout << endl;
            cout << "Postorder traversal : " ;
            call.postorder(root);
            cout << endl;
        }
        else if(ch==5){
            cout << "The depth of the tree is "<<call.depth(root) << endl;
        }
        else if(ch==6){
            node *mirrorroot = new node();
            mirrorroot= call.mirror(root);
            cout << "Inorder traversal : ";
            call.inorder(mirrorroot);
            cout << endl;
            cout << "Preorder traversal : " ;
            call.preorder(mirrorroot);
            cout << endl;
            cout << "Postorder traversal : " ;
            call.postorder(mirrorroot);
            cout << endl;
            call.parentchild(mirrorroot);
        }
        else if(ch==7){
            node *copyroot = new node(root->data);
            copyroot = call.createcopy(root);
            cout << "Inorder traversal of copyroot : ";
            call.inorder(copyroot);
            cout << endl;
            cout << "Preorder traversal of copyroot : " ;
            call.preorder(copyroot);
            cout << endl;
            cout << "Postorder traversal of copyroot : " ;
            call.postorder(copyroot);
            cout << endl;
        }
        else if(ch==8){
            call.parentchild(root);
        }
        else if(ch==9){
            cout << "Leaf nodes :-" << endl;
            call.leafnode(root);
            cout << endl;
        }
        else if(ch==10){
            call.levelwise(root);
        }
        else if(ch==11){
            cout << "Exiting the code... " << endl;
            break;
        }
        else{
            cout << "Please enter correct choice " << endl;
        }
        cout << endl;
    }
}

//Output :-

/*

First create a tree
Please enter root node :25
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 30
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 50
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 40
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 10
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 60
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 7
You want to insert more elements ? (Y/N) : y
Please enter the element you want to insert : 26
You want to insert more elements ? (Y/N) : n
MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 3
Please enter the element you want to search : 60
Element is present in the given tree

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 4
Inorder traversal : 7 10 25 26 30 40 50 60 
Preorder traversal : 25 10 7 30 26 50 40 60 
Postorder traversal : 7 10 26 40 60 50 30 25 

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 1
Please enter the element you want to insert : 45
MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 4
Inorder traversal : 7 10 25 26 30 40 45 50 60 
Preorder traversal : 25 10 7 30 26 50 40 45 60 
Postorder traversal : 7 10 26 45 40 60 50 30 25 

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 2
Please enter the data you want to delete : 60
MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 4
Inorder traversal : 7 10 25 26 30 40 45 50 
Preorder traversal : 25 10 7 30 26 50 40 45 
Postorder traversal : 7 10 26 45 40 50 30 25 

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 5
The depth of the tree is 5

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 6
Inorder traversal : 50 45 40 30 26 25 10 7 
Preorder traversal : 25 30 50 40 45 26 10 7 
Postorder traversal : 45 40 50 26 30 7 10 25 
Parent : 50
Left child : -1 Right child : 40
Parent : 45
Left child : -1 Right child : -1
Parent : 40
Left child : 45 Right child : -1
Parent : 30
Left child : 50 Right child : 26
Parent : 26
Left child : -1 Right child : -1
Parent : 25
Left child : 30 Right child : 10
Parent : 10
Left child : -1 Right child : 7
Parent : 7
Left child : -1 Right child : -1

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 7
Inorder traversal of copyroot : 7 10 25 26 30 40 45 50 
Preorder traversal of copyroot : 25 10 7 30 26 50 40 45 
Postorder traversal of copyroot : 7 10 26 45 40 50 30 25 

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 8
Parent : 7
Left child : -1 Right child : -1
Parent : 10
Left child : 7 Right child : -1
Parent : 25
Left child : 10 Right child : 30
Parent : 26
Left child : -1 Right child : -1
Parent : 30
Left child : 26 Right child : 50
Parent : 40
Left child : -1 Right child : 45
Parent : 45
Left child : -1 Right child : -1
Parent : 50
Left child : 40 Right child : -1

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 9
Leaf nodes :-
7 26 45 

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 10
Levelwise traversal :-
25 
10 30 
7 26 50 
40 
45 

MENU
1.Insert
2.Delete
3.Search
4.Display tree (Traversal)
5.Display - Depth of tree
6.Display - Mirror image
7.Create a copy
8.Display all child nodes with their parent nodes
9.Display all leaf nodes
10.Display tree levelwise
11.Exit
Please select a choice : 11
Exiting the code... 

*/