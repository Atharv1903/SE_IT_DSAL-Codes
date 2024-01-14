// Name - Atharv Uddhav Kharmate.
// Roll NO - 23141
// Division - SE-09
// Batch - F9

// Program :-

#include <iostream>
#include <cstring>
using namespace std;

struct Student{
    string name;
    int roll_no;
    float sgpa;
};

class S_details{
    private:
        struct Student s[30];   //Array of structure
        int n=0;
    public:
        int num();                      //Returns number of records
        void Insert();                  //Insert data
        void Display(int ch);                 //Display details
        void RlSearch(float key);       //Linear search
        void Rbsearch(string key);      //Binary search
        void Bsort();                   //Bubble sort
        void Isort();                   //Insertion sort
        void Qsort(int low, int high);  //Quick sort
        int Part(int low, int high);
};
//Returns number of data
int S_details::num(){
    return n;
};
//Insert Details
void S_details::Insert(){
    int num;
    if(n>30)
        cout<<"Records are full";
    else{
        cout<<"\n----------------------------------------------------------\n";
        cout<<"Enter number of students to be added : ";
        cin>>num;
        if(num>0){
            for(int i=n; i<n+num; i++){
                cout<<"\nEnter name "<<i+1<<" : ";
                cin.ignore(1,'\n');
                getline(cin,s[i].name);
                cout<<"Enter roll no : ";
                cin>>s[i].roll_no;
                if(s[i].roll_no<0){
                    cout<<"Please enter positive Roll no!!!";
                    return;
                }
                for(int j=0; j<n; j++){
                    if(s[i].roll_no==s[j].roll_no){
                        cout<<"Roll no already exists!!!";
                        return;
                    }
                }

                cout<<"Enter you SGPA : ";
                cin>>s[i].sgpa;
            }
            n=n+num;
        }   
        else{
            cout<<"Please enter a positive number";
            return;
        }
    }
};
//Display details
void S_details::Display(int ch){
    if(ch==0){
        if(n==0)
            cout<<"\nNo records\n";
        for(int i=0; i<n; i++){
            cout<<"Student "<<n+1<<"\n";
            cout<<"Name :"<<s[i].name<<"\n";
            cout<<"Roll no :"<<s[i].roll_no<<"\n";
            cout<<"SGPA :"<<s[i].sgpa<<"\n\n";
        }
    }
    else{
        if(n==0)
            cout<<"\nNo records\n";
        for(int i=n-1; i>=n-10; i--){
            cout<<"Name :"<<s[i].name<<"\n";
            cout<<"Roll no :"<<s[i].roll_no<<"\n";
            cout<<"SGPA :"<<s[i].sgpa<<"\n\n";
        }
    }
};
//Linear Search for SGPA
void S_details::RlSearch(float key){
    int flag=0;
    for(int i=0; i<n; i++){
        if(s[i].sgpa==key){
            flag=1;
            cout<<"Sudent found"<<endl;
            cout<<"Student "<<i+1<<"\n";
            cout<<"Name :"<<s[i].name<<"\n";
            cout<<"Roll no :"<<s[i].roll_no<<"\n";
            cout<<"SGPA :"<<s[i].sgpa<<"\n\n";
        }
    }
    if(!flag)
        cout<<"Student not found\n";
    
};
//Binary Search for Name
void S_details::Rbsearch(string key){
        if(n==0)
            cout<<"No data available!!!\n";
        int left = 0;
        int right = n-1;
        int middle = 0;
        int flag=0;
        while(left<=right){
            middle = (left+right)/2;
            if(s[middle].name==key){
                flag=1;
                cout<<"Student found!!!\n";
                cout<<"Student "<<middle+1<<"\n";
                cout<<"Name :"<<s[middle].name<<"\n";
                cout<<"Roll no :"<<s[middle].roll_no<<"\n";
                cout<<"SGPA :"<<s[middle].sgpa<<"\n\n";
            }
            if(s[middle].name>=s[left].name){
                if(s[left].name<=key&&key<s[middle].name){
                    right = middle-1;
                }
                else
                    left = middle+1;
            }
            else{
                if(s[middle].name<key&&key<=s[right].name){
                    left = middle+1;
                }
                else
                    right = middle-1;
            }
        }
        if(flag==0)
            cout<<"Student not found\n";
};
//Bubble sort for roll no.
void S_details::Bsort(){
    int last=n-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<last; j++){
            if(s[j].roll_no>s[j+1].roll_no){
                //swapping roll no
                int temp=s[j].roll_no;
                s[j].roll_no=s[j+1].roll_no;
                s[j+1].roll_no=temp;  
                //swapping sgpa
                float tmp1=s[j].sgpa;
                s[j].sgpa=s[j+1].sgpa;
                s[j+1].sgpa=tmp1;
                //swapping names
                string tmp2=s[j].name;
                s[j].name=s[j+1].name;
                s[j+1].name=tmp2;         
            }
        }
        last=last-1;
    }
    Display(0);
};
//Sort by name alphabetically
void S_details::Isort(){
    for(int i=1; i<n; i++){
		string key=s[i].name;
        int tmp1=s[i].roll_no;
        float tmp2=s[i].sgpa;
		int j=i-1;
		while(j>=0 && key<s[j].name){
			s[j+1].name=s[j].name;
            s[j+1].roll_no=s[j].roll_no;
            s[j+1].sgpa=s[j].sgpa;
			j=j-1;
		}
		s[j+1].name=key;
        s[j+1].roll_no=tmp1;
        s[j+1].sgpa=tmp2;	
	}
};

//Quick sort for top 10 toppers
void S_details::Qsort(int low, int high){
    if (low < high) {
        int pi = Part(low, high);
        Qsort(low, pi - 1);
        Qsort(pi + 1, high);
    }
};
int S_details::Part(int low, int high) {
    float pivot = s[high].sgpa;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (s[j].sgpa <= pivot) {
            i++;
            //swapping SGPA
            float temp = s[i].sgpa;
            s[i].sgpa = s[j].sgpa;
            s[j].sgpa = temp;
            //swapping roll no
            int temp1 = s[i].roll_no;
            s[i].roll_no = s[j].roll_no;
            s[j].roll_no = temp1;
            //swapping name
            string temp2 = s[i].name;
            s[i].name = s[j].name;
            s[j].name = temp2;
        }
    }
    //swapping SGPA
    float temp = s[i+1].sgpa;
    s[i+1].sgpa = s[high].sgpa;
    s[high].sgpa = temp;
    //swapping roll no
    int temp1 = s[i+1].roll_no;
    s[i+1].roll_no = s[high].roll_no;
    s[high].roll_no = temp1;
    //swapping name
    string temp2 = s[i+1].name;
    s[i+1].name = s[high].name;
    s[high].name = temp2;
    return i+1;
};


int main(){
    S_details det;
    string s_name;
    int op,rno;
    float sgpa;
    det.Insert();
    
    int ch=1;
    while(ch){
        cout<<"\n\n----------------------------------------------------------\n";
        cout<<"Enter the operation\n\n1. Insert data\n2. Display data\n3. Search record by SGPA\n4. Search record by Name\n5. Sort data by Roll no.\n6. Sort data by Name\n7. Display first 10 toppers\n8. Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>op;
        switch(op){
            case 1:
                det.Insert();
                break;
            case 2:
                det.Display(0);
                break;
            case 3:
                cout<<"Enter the SGPA : ";
                cin>>sgpa;
                det.RlSearch(sgpa);
                break;
            case 4:
                det.Isort();
                cout<<"Enter Name to be searched : ";
                cin.ignore(1,'\n');
                getline(cin,s_name);
                det.Rbsearch(s_name);
                break;
            case 5:
                det.Bsort();
                break;
            case 6:
                det.Isort();
                det.Display(0);
                break;
            case 7:
                cout<<"\nPrinting details of first ten toppers\n";
                det.Qsort(0,det.num());
                det.Display(1);
                break;
            case 8:
                ch=0;
                break;
        }
    }
    return 0; 
}


// Output :-
/*
Enter number of students to be added : 15

Enter name 1 : Atharv Kharmate   
Enter roll no : 14
Enter you SGPA : 9

Enter name 2 : Suyash Mali
Enter roll no : 2
Enter you SGPA : 9.35

Enter name 3 : Sahil Pawar
Enter roll no : 5
Enter you SGPA : 9.55

Enter name 4 : Omkar Patil
Enter roll no : 11
Enter you SGPA : 8.99

Enter name 5 : Aditya Bandgar
Enter roll no : 15
Enter you SGPA : 9

Enter name 6 : Ashish Kharade
Enter roll no : 7
Enter you SGPA : 8.57

Enter name 7 : Anup Kesarwani
Enter roll no : 8
Enter you SGPA : 8.66

Enter name 8 : Atharv Khade
Enter roll no : 6   
Enter you SGPA : 6.67

Enter name 9 : Pranav Dangare
Enter roll no : 12
Enter you SGPA : 8.34

Enter name 10 : Prajwal Wajire
Enter roll no : 13
Enter you SGPA : 7.54

Enter name 11 : Yogesh Sagare
Enter roll no : 1
Enter you SGPA : 10

Enter name 12 : Anish Ghatage
Enter roll no : 3
Enter you SGPA : 8

Enter name 13 : Om Sonavle
Enter roll no : 4
Enter you SGPA : 7.78

Enter name 14 : Rohit Bagal
Enter roll no : 10
Enter you SGPA : 8.43

Enter name 15 : Vikram Bhosale
Enter roll no : 9
Enter you SGPA : 8


----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 1

----------------------------------------------------------
Enter number of students to be added : 1

Enter name 16 : Devashish Patil
Enter roll no : 16
Enter you SGPA : 7.99


----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 2
Student 17
Name :Atharv Kharmate
Roll no :14
SGPA :9

Student 17
Name :Suyash Mali
Roll no :2
SGPA :9.35

Student 17
Name :Sahil Pawar
Roll no :5
SGPA :9.55

Student 17
Name :Omkar Patil
Roll no :11
SGPA :8.99

Student 17
Name :Aditya Bandgar
Roll no :15
SGPA :9

Student 17
Name :Ashish Kharade
Roll no :7
SGPA :8.57

Student 17
Name :Anup Kesarwani
Roll no :8
SGPA :8.66

Student 17
Name :Atharv Khade
Roll no :6
SGPA :6.67

Student 17
Name :Pranav Dangare
Roll no :12
SGPA :8.34

Student 17
Name :Prajwal Wajire
Roll no :13
SGPA :7.54

Student 17
Name :Yogesh Sagare
Roll no :1
SGPA :10

Student 17
Name :Anish Ghatage
Roll no :3
SGPA :8

Student 17
Name :Om Sonavle
Roll no :4
SGPA :7.78

Student 17
Name :Rohit Bagal
Roll no :10
SGPA :8.43

Student 17
Name :Vikram Bhosale
Roll no :9
SGPA :8

Student 17
Name :Devashish Patil
Roll no :16
SGPA :7.99



----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 3
Enter the SGPA : 9
Sudent found
Student 1
Name :Atharv Kharmate
Roll no :14
SGPA :9

Sudent found
Student 5
Name :Aditya Bandgar
Roll no :15
SGPA :9



----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 4
Enter Name to be searched : Suyash Mali
Student found!!!
Student 14
Name :Suyash Mali
Roll no :2
SGPA :9.35



----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 4
Enter Name to be searched : Swarup Mane
Student not found


----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 5
Student 17
Name :Yogesh Sagare
Roll no :1
SGPA :10

Student 17
Name :Suyash Mali
Roll no :2
SGPA :9.35

Student 17
Name :Anish Ghatage
Roll no :3
SGPA :8

Student 17
Name :Om Sonavle
Roll no :4
SGPA :7.78

Student 17
Name :Sahil Pawar
Roll no :5
SGPA :9.55

Student 17
Name :Atharv Khade
Roll no :6
SGPA :6.67

Student 17
Name :Ashish Kharade
Roll no :7
SGPA :8.57

Student 17
Name :Anup Kesarwani
Roll no :8
SGPA :8.66

Student 17
Name :Vikram Bhosale
Roll no :9
SGPA :8

Student 17
Name :Rohit Bagal
Roll no :10
SGPA :8.43

Student 17
Name :Omkar Patil
Roll no :11
SGPA :8.99

Student 17
Name :Pranav Dangare
Roll no :12
SGPA :8.34

Student 17
Name :Prajwal Wajire
Roll no :13
SGPA :7.54

Student 17
Name :Atharv Kharmate
Roll no :14
SGPA :9

Student 17
Name :Aditya Bandgar
Roll no :15
SGPA :9

Student 17
Name :Devashish Patil
Roll no :16
SGPA :7.99



----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 6
Student 17
Name :Aditya Bandgar
Roll no :15
SGPA :9

Student 17
Name :Anish Ghatage
Roll no :3
SGPA :8

Student 17
Name :Anup Kesarwani
Roll no :8
SGPA :8.66

Student 17
Name :Ashish Kharade
Roll no :7
SGPA :8.57

Student 17
Name :Atharv Khade
Roll no :6
SGPA :6.67

Student 17
Name :Atharv Kharmate
Roll no :14
SGPA :9

Student 17
Name :Devashish Patil
Roll no :16
SGPA :7.99

Student 17
Name :Om Sonavle
Roll no :4
SGPA :7.78

Student 17
Name :Omkar Patil
Roll no :11
SGPA :8.99

Student 17
Name :Prajwal Wajire
Roll no :13
SGPA :7.54

Student 17
Name :Pranav Dangare
Roll no :12
SGPA :8.34

Student 17
Name :Rohit Bagal
Roll no :10
SGPA :8.43

Student 17
Name :Sahil Pawar
Roll no :5
SGPA :9.55

Student 17
Name :Suyash Mali
Roll no :2
SGPA :9.35

Student 17
Name :Vikram Bhosale
Roll no :9
SGPA :8

Student 17
Name :Yogesh Sagare
Roll no :1
SGPA :10



----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit

Enter your choice : 7

Printing details of first ten toppers
Name :Sahil Pawar
Roll no :5
SGPA :9.55

Name :Suyash Mali
Roll no :2
SGPA :9.35

Name :Aditya Bandgar
Roll no :15
SGPA :9

Name :Atharv Kharmate
Roll no :14
SGPA :9

Name :Omkar Patil
Roll no :11
SGPA :8.99

Name :Anup Kesarwani
Roll no :8
SGPA :8.66

Name :Ashish Kharade
Roll no :7
SGPA :8.57

Name :Rohit Bagal
Roll no :10
SGPA :8.43

Name :Pranav Dangare
Roll no :12
SGPA :8.34

Name :Vikram Bhosale
Roll no :9
SGPA :8



----------------------------------------------------------
Enter the operation

1. Insert data
2. Display data
3. Search record by SGPA
4. Search record by Name
5. Sort data by Roll no.
6. Sort data by Name
7. Display first 10 toppers
8. Exit
*/