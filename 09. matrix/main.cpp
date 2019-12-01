/*
Write a C++ program to create class called MATRIX
using a two dimensional array of integers.
Implement the following operations by overloading the operator‘==’
which checks the compatibility of two matrices m1 and m2 to be added and subtracted.
Perform the addition and subtraction by overloading the operator + and – respectively.
Display the results (sum matrix m3 and difference matrix m4) by overloading the operator <<.
*/

#include<iostream>
using namespace std;

class matrix
{
            int m,n;
            int a[10][10];
    public:
            matrix()
            {
                m=0;
                n=0;
            }
            matrix(int i,int j)
            {
                m=i;
                n=j;
            }
            void setdata();
            friend matrix operator +(matrix &,matrix &);
            friend matrix operator -(matrix &,matrix &);
            friend int operator ==(matrix &,matrix &);
            friend ostream & operator<<(ostream &dout,matrix &x);
};

void matrix::setdata()
{
    cout<<"enter elements"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
}

matrix operator +(matrix &m1,matrix &m2)
{
    matrix temp(m1.m,m1.n);
    for(int i=0;i<m1.m;i++)
    {
        for(int j=0;j<m1.n;j++)
        temp.a[i][j]=m1.a[i][j]+m2.a[i][j];
    }
    return temp;
}

matrix operator -(matrix &m1,matrix &m2)
{
    matrix temp(m1.m,m1.n);
    for(int i=0;i<m1.m;i++)
    {
        for(int j=0;j<m1.n;j++)
            temp.a[i][j]=m1.a[i][j]-m2.a[i][j];
    }
    return temp;
}

int operator==(matrix &m1,matrix &m2)
{
    if((m1.m==m2.m)&&(m1.n==m2.n))
        return 1;
    else
        return 0;
}

ostream & operator<<(ostream &dout,matrix &x)
{
    for(int i=0;i<x.m;i++)
    {
        for(int j=0;j<x.n;j++)
            dout<<x.a[i][j]<<" ";
        dout<<endl;
    }
    return dout;
}

int main()
{
    int row1,row2,col1,col2;
    cout<<"enter the order of matrix1"<<endl;
    cin>>row1>>col1;
    matrix m1(row1,col1);
    cout<<"enter the order of matrix2"<<endl;
    cin>>row2>>col2;
    matrix m2(row2,col2);
    if(m1==m2)
    {
        m1.setdata();
        m2.setdata();
        cout<<"matrix 1\n";
        cout<<m1;
        cout<<"matrix 2\n";
        cout<<m2;
        matrix m3=m1+m2;
        matrix m4=m1-m2;
        cout<<"addition of matrices"<<endl;
        cout<<m3;
        cout<<"subtraction of matrices"<<endl;
        cout<<m4;
    }
    else
        cout<<"order of matrices are not equal"<<endl;
    return 0;
}
