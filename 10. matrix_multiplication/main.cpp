/*
Write a C++ program to create class called MATRIX. Overload the operator
‘==’which checks the compatibility of two matrices m1 and m2 to be multiplied.
Perform the multiplication of matrices by overloading the operator *. Display
the results (product matrix m3) by overloading the operator <<.
*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class matrix
{
            int r,c;
            int a[10][10];
    public: matrix()
            {}
            matrix(int m,int n)
            {
                r=m;
                c=n;
            }
            void read()
            {
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        cin>>a[i][j];
            }
            friend ostream & operator <<(ostream &dout,matrix &m);
            friend int operator == (matrix &m1,matrix &m2);
            friend matrix operator * (matrix &m1, matrix &m2);
};

ostream & operator << (ostream & dout,matrix &m)
{
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
        {
            dout<<m.a[i][j];
            dout<<setw(6);
        }
        dout<<"\n";
    }
    return dout;
}

int operator == (matrix &m1,matrix &m2)
{
    int flag;
    try
    {
        flag=1;
        if(m1.c==m2.r)
        {
            if((m1.r==m2.r)&&(m1.c==m2.c))
            {
                for(int i=0;i<m1.r;i++)
                    for(int j=0;j<m1.c;j++)
                        if(m1.a[i][j]!=m2.a[i][j])
                            flag=0;
            }
            cout<<"2 matricies are equal\n";
        }
        else
            throw(m1.r);
    }
    catch(...)
    {
        cout<<"multiplication not possivli\n";
        exit(0);
    }
    if(flag)
        return 1;
    else
        return 0;
}

matrix operator * (matrix &m1,matrix &m2)
{
    matrix m3(m1.r,m1.c);
    for(int i=0;i<m1.r;i++)
    {
        for(int j=0;j<m2.c;j++)
        {
            m3.a[i][j]=0;
            for(int k=0;k<m1.c;k++)
            {
                 m3.a[i][j]=m3.a[i][j]+m1.a[i][k]*m2.a[k][j];
            }
        }
    }
        return m3;
}
int main()
{
    int r1,r2,c1,c2;
    cout<<"enter the num of rows n col of 1st matrix\n";
    cin>>r1>>c1;
    matrix m1(r1,c1);
    cout<<"enter the num of rows n col of 2nd matrix\n";
    cin>>r2>>c2;
    matrix m2(r2,c2);
    cout<<"enter the "<<r1*c1<<"elments of matrix1\n";
    m1.read();
    cout<<"enter the "<<r2*c2<<"elements of matrix2\n";
    m2.read();
    matrix m3;
    cout<<"1st matrix:\n";
    cout<<m1;
    cout<<"2nd matrix:\n";
    cout<<m2;
    int f=m1==m2;
    if(f==0)
    {
        cout<<"matrices are not equal\n";
    }
    else
    {
        cout<<"matrices are equal\n";
    }
    m3=m1*m2;
    cout<<"resultant matrix:\n";
    cout<<m3;
    return 0;
}
