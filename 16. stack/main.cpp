/*
Write a C++ program to create a template class STACK, with push and pop and
display member functions. Write a menu based program to illustrate the
working for stack of floating point values and stack of integers. Use exception
handling to handle the special conditions underflow and overflow of the stack.
*/


#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class stack
{
            T *st;
            int top;
            int max;
    public:
            stack(int size)
            {
                top=-1;
                max=size;
                st=new T[size];
            }

            ~stack()
            {
                delete st;
            }

            void operator+(T );
            void operator-(int);
            void display();
};

template<class T>

void stack<T>::operator+(T item)
{
    if(top==max-1)
        throw ('o');
    else
        st[++top]=item;
    return;
}

template<class T>

void stack<T>::operator-(int a)
{
    if(top==-1)
        throw ('u');
    else
    {
        T ele=st[top--];
        cout<<"item deleted= "<<ele<<endl;
    }
}

template<class T>

void stack<T>::display()
{
    if(top==-1)
        cout<<"stack is empty"<<endl;
    else
    {
        cout<<"bottom"<<" ";
        for(int i=0;i<=top;i++)
        {
            cout<<st[i]<<" ";
        }
        cout<<"top";
    }
    return;
}

int main()
{
    int count;
    cout<<"Enter max size of stack"<<endl;
    cin>>count;
    stack<int> si(count);
    stack<float> sf(count);
    int ch,item,dd;
    float itemf;
    cout<<"\nEnter choice\n1.for integer\n2.for float\n";
    cin>>dd;

    while(1)
    {
        cout<<"\n1-Push\n2-Pop\n3-Display\n4-Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1 :cout<<"\nEnter the item to be inserted"<<endl;
                    if(dd==1)
                    {
                        try
                        {
                            cin>>item;
                            si+item;
                        }
                        catch(char s)
                        {
                            cout<<"stack overflow"<<endl;
                        }
                    }
                    else if(dd==2)
                    {
                        try
                        {
                            cin>>itemf;
                            sf+itemf;
                        }
                        catch(char s)
                        {
                            cout<<"stack overflow"<<endl;
                        }
                    }
                    break;

            case 2 :if(dd==1)
                    {
                        try
                        {
                            si-0;
                        }
                        catch(char s)
                        {
                            cout<<"stack underflow"<<endl;
                        }
                    }
                    else if(dd==2)
                    {
                        try
                        {
                            sf-0;
                        }
                        catch(char s)
                        {
                            cout<<"stack underflow"<<endl;
                        }
                    }
                    break;

            case 3 :cout<<"elements of stack"<<endl;
                    if(dd==1)
                        si.display();
                    else if(dd==2)
                        sf.display();
                    break;

            case 4 :exit(0);

            default: cout<<"invalid choice"<<endl;
                     break;
        }
    }
    return 0;
}
