// Name - Atharv Uddhav Kharmate.
// Roll NO - 23141
// Division - SE-09
// Batch - F9

//Program :-

#include <iostream>
#include <fstream>
#include <climits>
#include <sstream>
using namespace std;

struct Student
{
    int roll_no;
    string name;
    int division;
    string address;
};
class StudentD
{
public:
    Student record;
    int num_student = 1;

public:
    void newFile();
    void clearFile();
    void add();
    void display();
    void search();
    void delete_record();
    void modify();

    StudentD()
    {
        clearFile();
        newFile();
    }
};
void StudentD::newFile()
{
    ofstream obj("Student_Database.txt");
    obj << "Roll No\t\tName\t\tDivision\tAddress" << endl;
    obj.close();
    cout << "\n\nNew File Created Succesfully!!!" << endl;
    return;
}
void StudentD::clearFile()
{
    ofstream obj("Student_Database.txt", ios::trunc);
    cout << "\n\nFile Cleared SuccessFully!!!";
    obj.close();
}
void StudentD::add()
{
    cout << "\nEnter Record " << num_student << endl;
    ofstream obj;
    obj.open("Student_Database.txt", ios::app);
    cout << "\nEnter Roll No : ";
    cin >> record.roll_no;
    cout << "Enter Name : ";
    cin >> record.name;
    cout << "Enter Division : ";
    cin >> record.division;
    cout << "Enter Address : ";
    cin >> record.address;

    num_student++;
    obj << record.roll_no << "\t\t" << record.name << "\t\t" << record.division << "\t\t" << record.address << endl;
    obj.close();
}
void StudentD::display()
{
    ifstream obj;
    obj.open("Student_Database.txt");
    if (obj.is_open())
    {
        string line;
        while (getline(obj, line))
        {
            cout << line << endl;
        }
        obj.close();
    }
    else
    {
        cout << "File not Found";
    }
    cout << endl;
}
void StudentD::search()
{
    int rn;
    cout << "\nEnter Roll No to Be Found : ";
    cin >> rn;
    ifstream obj;
    obj.open("Student_Database.txt");
    if (obj.is_open())
    {
        int j = 0;
        string line;
        while (getline(obj, line))
        {
            string arr[4];
            int i = 0;
            stringstream input(line);
            while (input.good() && i < 4)
            {
                input >> arr[i];
                i++;
            }
            if (to_string(rn) == arr[0])
            {
                cout << "\n\nSearch Succesful!!! \n\nRecord Found at Position " << j << "\n\nRecord : ";
                for (int i = 0; i < 4; i++)
                {
                    cout << arr[i] << " ";
                }
                return;
            }
            j++;
        }
        cout << "\nRecord Not Found";
        obj.close();
    }
    else
    {
        cout << "File not Found";
    }
    cout << endl;
}
void StudentD::delete_record()
{
    int rn;
    cout << "\nEnter Roll No to Be Deleted : ";
    cin >> rn;
    ifstream obj;
    ofstream temp("temp_samp.txt");
    obj.open("Student_Database.txt");
    if (obj.is_open())
    {
        string line;
        while (getline(obj, line))
        {
            string arr[4];
            int i = 0;
            stringstream input(line);
            while (input.good() && i < 4)
            {
                input >> arr[i];
                i++;
            }
            if (to_string(rn) != arr[0])
            {
                temp << line << endl;
            }
        }
        cout << "\nData Deleted Successfully!!!";
        obj.close();
        temp.close();
        remove("Student_Database.txt");
        rename("temp_samp.txt", "Student_Database.txt");
    }
    else
    {
        cout << "File not Found";
    }
    cout << endl;
}
void StudentD::modify()
{
    int rn;
    cout << "\nEnter Roll No of data to be Modified : ";
    cin >> rn;
    ifstream obj;
    ofstream temp("temp_samp.txt");
    obj.open("Student_Database.txt");
    if (obj.is_open())
    {
        string line;
        while (getline(obj, line))
        {
            string arr[4];
            int i = 0;
            stringstream input(line);
            while (input.good() && i < 4)
            {
                input >> arr[i];
                i++;
            }
            if (to_string(rn) != arr[0])
            {
                temp << line << endl;
            }
            else
            {
                cout << "\n\nEnter Modified Data : ";
                cout << "\nEnter Roll No : ";
                cin >> record.roll_no;
                cout << "Enter Name : ";
                cin >> record.name;
                cout << "Enter Division : ";
                cin >> record.division;
                cout << "Enter Address : ";
                cin >> record.address;

                temp << record.roll_no << "\t\t" << record.name << "\t\t" << record.division << "\t\t" << record.address << endl;
            }
        }
        cout << "\nData Modified Successfully!!!";
        obj.close();
        temp.close();
        remove("Student_Database.txt");
        rename("temp_samp.txt", "Student_Database.txt");
    }
    else
    {
        cout << "File not Found";
    }
    cout << endl;
}
int main()
{
    StudentD s;
    bool go = true;
    while (go)
    {
        cout << "\n------------Menu--------------";
        cout << "\n\n1.Create New File";
        cout << "\n2.Add Record";
        cout << "\n3.Display Record";
        cout << "\n4.Delete Record";
        cout << "\n5.Search Record";
        cout << "\n6.Modify Record";
        cout << "\n7.Clear File";
        cout << "\n8.Exit";
        cout << "\n\nChoose an Option : ";
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
            s.newFile();
            break;
        case 2:
            s.add();
            break;
        case 3:
            s.display();
            break;
        case 4:
            s.delete_record();
            break;
        case 5:
            s.search();
            break;
        case 6:
            s.modify();
            break;
        case 7:
            s.clearFile();
            break;
        case 8:
            go = false;
            cout << "\n-----------------Thank You-------------------";
            break;
        default:
            cout << "\n\nInvalid Input";
        }
    }
    return 0;
}

//Output :-

/*

File Cleared SuccessFully!!!

New File Created Succesfully!!!

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 1


New File Created Succesfully!!!

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 1


New File Created Succesfully!!!

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 2

Enter Record 1

Enter Roll No : 23141
Enter Name : Atharv
Enter Division : 9
Enter Address : abc

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 2

Enter Record 2

Enter Roll No : 2342
Enter Name : Parth
Enter Division : 9
Enter Address : def

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 2

Enter Record 3

Enter Roll No : 23158
Enter Name : Sanika
Enter Division : 9
Enter Address : xyz

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 3

Roll No         Name            Division        Address
23141           Atharv          9               abc
2342            Parth           9               def
23158           Sanika          9               xyz


------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 6

Enter Roll No of data to be Modified : 2342


Enter Modified Data :
Enter Roll No : 23142
Enter Name : Parth
Enter Division : 9
Enter Address : def

Data Modified Successfully!!!

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 3

Roll No         Name            Division        Address
23141           Atharv          9               abc
23142           Parth           9               def
23158           Sanika          9               xyz


------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 4

Enter Roll No to Be Deleted : 23142

Data Deleted Successfully!!!

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 3

Roll No         Name            Division        Address
23141           Atharv          9               abc
23158           Sanika          9               xyz


------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 5

Enter Roll No to Be Found : 23158

Search Succesful!!!

Record Found at Position 2

Record : 23158 Sanika 9 xyz

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 3

Roll No         Name            Division        Address
23141           Atharv          9               abc
23158           Sanika          9               xyz

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit

Choose an Option : 7


File Cleared SuccessFully!!!

------------Menu--------------

1.Create New File
2.Add Record
3.Display Record
4.Delete Record
5.Search Record
6.Modify Record
7.Clear File
8.Exit
7.Clear File
8.Exit

Choose an Option : 8

-----------------Thank You-------------------

*/