// Name - Atharv Uddhav Kharmate.
// Roll NO - 23141
// Division - SE-09
// Batch - F9

//Program :-

#include<iostream>
using namespace std;
const int v=4;
string city[4]={"Pune","Nagpur","Mumbai","Satara"}; 
int min_Key(int key[], bool visited[])  
{ 
    int min = 999, min_index;  // 999 represents an Infinite value
 
    for (int m = 0; m < v; m++) { 
        if (visited[m] == false && key[m] < min) { 
        	// vertex should not be visited
            min = key[m];
min_index = m;  
        }
    }    
    return min_index;  
}  
int print_MST(int parent[], int cost[v][v])  
{  
    int minCost=0;
cout<<"Edge \tWeight\n";  
    for (int i = 1; i< v; i++) {
cout<<city[parent[i]]<<" - "<<city[i]<<" \t"<<cost[i][parent[i]]<<" \n";  
minCost+=cost[i][parent[i]];
    }
cout<<"Total cost is : "<<minCost;
    return 0;
}  
// Function to find the MST using adjacency cost matrix representation  
void find_MST(int cost[v][v])  
{  
    int parent[v], key[v];
    bool visited[v];
    // Initialize all the arrays 
    for (int i = 0; i< v; i++) { 
        key[i] = 999;    // 99 represents an Infinite value
        visited[i] = false;
        parent[i]=-1;
    }    
    key[0] = 0;  // Include first vertex in MST by setting its key vaue to 0.  
    parent[0] = -1; // First node is always root of MST  
 
    // The MST will have maximum V-1 vertices  
    for (int x = 0; x < v - 1; x++) 
    {  
        // Finding the minimum key vertex from the 
        //set of vertices not yet included in MST  
        int u = min_Key(key, visited);  
         visited[u] = true;  // Add the minimum key vertex to the MST  
        // Update key and parent arrays
        for (int m = 0; m< v; m++)  
        {
            // cost[u][v] is non zero only for adjacent vertices of u  
            // visited[v] is false for vertices not yet included in MST  
            // key[] gets updated only if cost[u][v] is smaller than key[v]  
            if (cost[u][m]!=0 && visited[m] == false && cost[u][m] < key[m])
            {  
                parent[m] = u;
                key[m] = cost[u][m];  
            }        
        }
    }
    // print the final MST  
print_MST(parent, cost);  
}  
int main()
{
    int cost[v][v];
    int ch;
    int lp=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0; j<i;j++)
        {
            if(i!=j)
            {
                cout<<"\nEnter the distance between "<<city[j]<<" and "<< city[i]<<":";
                cin>>cost[i][j];
                cost[j][i]=cost[i][j];
            }
            else{
                cost[i][j]=0;
            }
        }
    }
    find_MST(cost);    
}

//Output :-

/*

Enter the distance between Pune and Nagpur:231
Enter the distance between Pune and Mumbai:200
Enter the distance between Nagpur and Mumbai:343
Enter the distance between Pune and Satara:125
Enter the distance between Nagpur and Satara:454
Enter the distance between Mumbai and Satara:256
Edge    Weight
Pune - Nagpur   231
Pune - Mumbai   200
Pune - Satara   125
Total cost is : 556
--------------------------------
*/
