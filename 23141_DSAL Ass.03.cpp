// Name - Atharv Uddhav Kharmate.
// Roll NO - 23141
// Division - SE-09
// Batch - F9

//Program :-

#include<iostream>
#include<cstring>
using namespace std;

class cQueue{  

    public:
        int arr[10];
        int front=-1;
        int rear=-1;
        bool is_empty();
        bool is_full();
        void enqueue(int x);
        void dequeue();
        void display();

};

//function is_empty()

bool cQueue::is_empty(){
    if(rear==-1 && front==-1)
        return true;
    else
        return false;
};

//function is_full()

bool cQueue::is_full(){
    if((front==0 && rear==sizeof(arr)-1)||(rear==(front-1)%(sizeof(arr))))
        return true;
    else
        return false;
};

//function enqueue() to insert elements

void cQueue::enqueue(int x){
    if(is_full())
        cout<<"Queue is Full!!!";
    else if(is_empty()){
        front=rear=0;
        arr[rear]=x;
    }
    else{
        rear=(rear+1)%sizeof(arr);
        arr[rear]=x;
    }
};

//function dequeue() to delete the elements

void cQueue::dequeue(){
    int data;
    if(is_empty()){
        cout<<"Queue is empty!!!";
        return;
    }
    else if(front==rear){
        data=arr[front];
        front=rear=-1;
    }
    else{
        data=arr[front];
        front=(front+1)%sizeof(arr);
    }
    cout<<"Element "<<data<<" is removed";
};

//function display() to display elements

void cQueue::display(){
    if(is_empty())
        cout<<"Queue is empty!!!";
    else{
        for(int i=front; i<=rear; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    cQueue q;
    int op,num;
    bool res,ch=true;
    while(ch){
        cout<<"\n-------------------------";
        cout<<"\n1. IsFull\n2. IsEmpty\n3. Enqueue\n4. Dequeue\n5. Display\n6. Exit\n\nEnter your choice : ";
        cin>>op;

        switch(op){ 
            case 1:
                res=q.is_full();
                if(res)
                    cout<<"Queue is full!!!";
                else
                    cout<<"Queue is not full";
                break;
            case 2:
                res=q.is_empty();
                if(res)
                    cout<<"Queue is empty!!!";
                else
                    cout<<"Queue is not empty";
                break;
            case 3:
                cout<<"Enter number to be inserted : ";
                cin>>num;
                q.enqueue(num);
                break;
            case 4:
                q.dequeue();
                break;
            case 5:
                q.display();
                break;
            case 6:
                ch=false;
                break;
        }
    }
}

//Output :-

/*

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 3
Enter number to be inserted : 1

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 3
Enter number to be inserted : 2

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 3
Enter number to be inserted : 3

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 3
Enter number to be inserted : 4

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 3
Enter number to be inserted : 5

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 5
1 2 3 4 5

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 2
Queue is not empty

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 1
Queue is not full

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 4
Element 1 is removed

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 5
2 3 4 5

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 3
Enter number to be inserted : 1

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

Enter your choice : 5
2 3 4 5 1

------------------------------------

1. IsFull
2. IsEmpty
3. Enqueue
4. Dequeue
5. Display
6. Exit

*/