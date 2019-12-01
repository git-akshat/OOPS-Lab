/*
Define a ITEM class with item_name, item_code, item_prize, number_of_items
(item_count) as data members. Demonstrate the followings concepts by suitable
behaviors:
Working with Files: demonstrate the following file operations:
a. Writing an object at the end of file
b. Reading all objects from a file and display on console.
c. Update a given object information on the file.
*/


#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class item
{
            char name[20];
            int code;
            int price;
            int no_of_objects;
    public:
            void getdata()
            {
            cout<<"\nenter name,code,price,no of objects\n";
            cin>>name>>code>>price>>no_of_objects;
            }
            void display()
            {
                cout<<endl;
                cout<<"name:"<<name<<" code:"<<code<<" price:"<<price<<" no of items:"<<no_of_objects<<endl;
            }
};

int main()
{
    int n;
    cout<<"enter the no of objects: ";
    cin>>n;
    fstream file;
    item it;
    file.open("item",ios::out);
    file.close();
    file.open("item",ios::app|ios::in);
    if(file)
    {
        cout<<"file opened successfully\n";
        for(int i=0;i<n;i++)
        {
            cout<<"\nenter the details of the item "<<i+1;
            it.getdata();
            file.write((char*)&it,sizeof(it));
        }
        file.seekg(0);
        for(int i=0;i<n;i++)
        {
            cout<<"item"<<i+1;
            file.read((char*)&it,sizeof(it));
            it.display();
        }
        cout<<"\nenter another object to add\n";
        it.getdata();
        file.write((char*)&it,sizeof(it));
        file.seekg(0);
        cout<<"\nafter adding an item";
        for(int i=0;i<=n;i++)
        {
            file.read((char*)&it,sizeof(it));
            it.display();
        }
        cout<<"\nenter the object no to be modified :";
        int n1;
        cin>>n1;
        int loc=(n1-1)*sizeof(it);
        file.seekp(loc);
        cout<<"\nenter the new values for the item ";
        it.getdata();
        file.write((char*)&it,sizeof(it));
        cout<<"\nfile after modification";
        file.seekg(0);
        for(int i=0;i<=n;i++)
        {
            file.read((char*)&it,sizeof(it));
            it.display();
        }
        file.close();
    }
    else
    {
        cout<<"error in opening the file";
    }
}
