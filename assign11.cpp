
#include <iostream>
#include <fstream>
using namespace std;


class student
{
public:
    char name[10];
    int roll;
    void getdata()
    {
        cout << "\n Enter roll no:-  ";
        cin >> roll;
        cout<<"Enter name:- ";
        cin>>name;
    }

    void putdata()
    {
        cout << "\nRoll No:-  "<< roll <<" ----- Name:- ";
        cout<< name<<endl;
    }
};


class file
{
    fstream fp;

public:
    void create()
    {
        char ans;
        student s;
        fp.open("stu.txt", ios::out);
        do
        {
            s.getdata();
            fp.write((char *)&s, sizeof(s));
            cout << "\n Want to add more?(Press Y||y)";
            cin >> ans;
        } while (ans == 'Y' || ans == 'y');
        fp.close();
    }
    void append()
    {
        char ans;
        student s;
        fp.open("stu.txt", ios::app);
        do
        {
            s.getdata();
            fp.write((char *)&s, sizeof(s));
            cout << "\n Want to add more?(Press Enter Y/y)";
            cin >> ans;
        } while (ans == 'Y' || ans == 'y');
        fp.close();
}
    void display()
    {
        student s;
        fp.open("stu.txt", ios::in);
        while (!fp.eof())
        {
            fp.read((char *)&s, sizeof(s));
            //if (!fp.eof())
                s.putdata();
        }
        fp.close();
    }
    void search()
    {
        student s;
        int flag = 0;
        cout << "\n Enter roll to be searched:";
        int r;
        cin >> r;  
        fp.open("stu.txt", ios::in);
        while (!fp.eof())
        {
            fp.read((char *)&s, sizeof(s));
            if (!fp.eof() && s.roll == r)
            {
                flag = 1;
                s.putdata();
                break;
            }
        }
        if (flag == 0)
            cout << "\n Not found";
        fp.close();
    }
    void update()
    {
        student s;
        int flag = 0;
        cout << "\n Enter roll to be updated:";
        int r;
        cin >> r;
        fp.open("stu.txt", ios::in | ios::out);
        while (!fp.eof())
        {
            fp.read((char *)&s, sizeof(s));
            if (!fp.eof() && s.roll == r)
            {
                flag = 1;
                cout << "\n Enter new data\n";
                s.getdata();
                fp.seekp(-1 * sizeof(s), ios::cur);
                fp.write((char *)&s, sizeof(s));
                break;
            }
        }

        if (flag == 0)
            cout << "\n Not found";
        fp.close();
    }
    void delete1()
    {
        student s;
        int flag = 0;
        fstream fp1;
        cout << "\n Enter roll to be deleted:";
        int r;
        cin >> r;
        fp.open("stu.txt", ios::in);
        fp1.open("temp.txt", ios::out);
        while (fp.read((char *)&s, sizeof(s)))
        {

            if (s.roll != r)
            {
                flag = 1;
                fp1.write((char *)&s, sizeof(s));
            }
        }
        if (flag == 0)
            cout << "\n Not found";
        fp.close();
        fp1.close();
        remove("stu.txt");
        rename("temp.txt", "stu.txt");
    }
};

int main()
{
    file f;
    int choice;
    do
    {
        cout << "\n 1.Creation \n 2.Display \n 3.Searching \n 4.Append";
        cout << " \n 5.Deletion \n 6.Update";
        cout << "\n Enter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            f.create();
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.search();
            break;
        case 4:
            f.append();
            break;
        case 5:
            f.delete1();
            break;
        case 6:
            f.update();
            break;
        }
    } while (choice < 7);
}