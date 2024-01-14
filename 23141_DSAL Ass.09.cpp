Name - Atharv Uddhav Kharmate.
Roll NO - 23141
Division - SE-09
Batch - F9

Program :-

#include <iostream>
using namespace std;

void heapify1(int arr[], int N, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify1(arr, N, largest);
    }
}
void heapify2(int arr[], int N, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] < arr[smallest])
        smallest = l;

    if (r < N && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify2(arr, N, smallest);
    }
}
void heapSort1(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify1(arr, N, i);

    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify1(arr, i, 0);
    }
}
void heapSort2(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify2(arr, N, i);

    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify2(arr, i, 0);
    }
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int N;
    cout << "\nEnter the Size of Array:";
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        int x;
        cout << "\nEnter Element: ";
        cin >> x;
        arr[i] = x;
    }
    int ch = 1;
    while (ch)
    {
        int op;
        cout << "\n\n----------------------------------------------------------\n";
        cout << "Enter the operation\n\n1.Maximum Heap\n2.Minimum Heap\n3. Exit\n";
        cout << "\nEnter your choice : ";
        cin >> op;
        switch (op)
        {
        case 1:
            heapSort1(arr, N);
            cout << "Sorted array is \n";
            printArray(arr, N);
            break;

        case 2:
            
            heapSort2(arr, N);
            cout << "\nSorted array is: \n";
            printArray(arr, N);
            break;

        case 3:
            ch = 0;
            break;
        }
    }
}

Output :-

Enter the Size of Array:5
Enter Element: 40
Enter Element: 12
Enter Element: 5
Enter Element: 32
Enter Element: 24
----------------------------------------------------------
Enter the operation

1.Maximum Heap
2.Minimum Heap
3. Exit

Enter your choice : 1
Sorted array is 
5 12 24 32 40 


----------------------------------------------------------
Enter the operation

1.Maximum Heap
2.Minimum Heap
3. Exit

Enter your choice : 2
Sorted array is: 
40 32 24 12 5 


----------------------------------------------------------
Enter the operation

1.Maximum Heap
2.Minimum Heap
3. Exit

Enter your choice : 3
