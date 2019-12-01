/*
Write a C++ program to create a template functions for Insertion sort and
Selection Sort. Demonstrate sorting of integers and double data types for both
sorting algorithms.
*/


#include<iostream>
#include<cstdlib>
//#include<conio.h>
using namespace std;

template<class T>

void s_sort(T a[],int n)
{
    T t;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i]) //for descending order use if(a[j]>a[i])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}

template<class T>

void i_sort(T a[],int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        T t=a[i];
        int j;
        for(j=i-1;j>=0&&t<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }
}

int main()
{
    int a[100],i,n;
    double s[100];
    int choice;
    while(1)
    {
        cout<<"\n1.Selection Sort\n2.Insertion Sort\n3.exit\n";
        cout<<"Enter choice";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter The number of Element:\n";
            cin>>n;
            cout<<"\nEnter Elements:\n";
            for(i=0;i<n;i++)
            {
                cin>>a[i];
            }
            s_sort(a,n);
            cout<<"\nSorting using Selection Sort\n";
            for(i=0;i<n;i++)
            {
                cout<<a[i]<<"\t";
            }
            break;

            case 2: cout<<"Enter The number of Element:\n";
                    cin>>n;
                    cout<<"\nEnter Elements:\n";
                    for(i=0;i<n;i++)
                    {
                        cin>>s[i];
                    }
                    i_sort(s,n);
                    cout<<"\nSorting using Insertion Sort\n";
                    for(i=0;i<n;i++)
                    {
                        cout<<s[i]<<"\t";
                    }
                    break;

            case 3: exit(0);

            default: cout<<"invalid choice"<<endl;
        }
    }
    return 0;
}
