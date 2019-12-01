/* Author: Akshat Agarwal */

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<ctype.h>
#include <windows.h>
#include<fstream>
using namespace std;

ostream & next(ostream & output)
{
        output<<"\n";
        return output;
}

class base_cab
{
    protected:  char ride[];
    public:     virtual int login()
                {
                    cout<<""<<next;
                }
                virtual void signup()
                {
                    cout<<""<<next;
                }
                virtual void ridenow()
                {
                    cout<<" "<<next;
                }
};
class cab:public base_cab
{
    private:    char user[50],pass[50];

    public :    cab(){};
                int login();
                void signup();
                void ridenow();

                friend ostream & operator <<(ostream & output,cab &);
};

ostream & operator<<(ostream & output,cab &c)
{
    output<<"---------------------------------------------------------------";
    output<<"\n                          GO CAB                        \n";
    output<<"---------------------------------------------------------------";
    output<<"\nW";Sleep(100);output<<"E";Sleep(100);
    output<<"L";Sleep(100);output<<"C";Sleep(100);
    output<<"O";Sleep(100);output<<"M";Sleep(100);
    output<<"E";Sleep(100);output<<" ";Sleep(100);
    output<<"T";Sleep(100);output<<"O";Sleep(100);
    output<<" ";Sleep(100);output<<"G";Sleep(100);
    output<<"O";Sleep(100);output<<" ";Sleep(100);
    output<<"C";Sleep(100);output<<"A";Sleep(100);
    output<<"B";Sleep(100);output<<" ";Sleep(100);
    output<<"T";Sleep(100);output<<"A";Sleep(100);
    output<<"X";Sleep(100);output<<"I";Sleep(100);
    output<<" ";Sleep(100);output<<"S";Sleep(100);
    output<<"E";Sleep(100);output<<"R";Sleep(100);
    output<<"V";Sleep(100);output<<"I";Sleep(100);
    output<<"C";Sleep(100);output<<"E";Sleep(100);
    output<<".";Sleep(100);output<<".";Sleep(100);
    Sleep(500);
    return output;
}

int cab::login()
{
    fstream myfile;
    int found=0;
    int x=0,y,retry;
    char temp;
    char c[50],b[50];
    while(x<3)
    {
        cout<<"\n\tuser id:\t";
        cin>>user;Sleep(1000);
        cout<<"\n\tpassword:\t";
        cin>>pass;Sleep(1000);
        cout<<"\nplease wait";Sleep(250);
        cout<<".";Sleep(250);
        cout<<".";Sleep(250);
        cout<<".";Sleep(250);
        cout<<"\rplease wait   ";Sleep(250);
        cout<<"\b\b\b.";Sleep(250);
        cout<<".";Sleep(250);
        cout<<".";Sleep(250);
        myfile.open("gocab.txt",ios::app);
        myfile.close();
        myfile.open("gocab.txt",ios::in);

        while(!myfile.eof())
        {
            myfile>>c>>b;
            if((strcmp(user,c)==0)&&(strcmp(pass,b)==0))
            {
                cout<<"\ryou have successfully logged in";
                Sleep(1000);
                found=1;
                myfile.close();
                return 0;
            }
        }
        if(!found)
        {
            cout<<"\rInvalid user id or password!\n";
            x++;
            y=3-x;
            cout<<"\rDo u want to go back or retry..\n1.Go Back\n2.Retry\n";
            cin>>retry;
            if(retry==1)
            {
                myfile.close();
                return -1;
            }
            else
            {
                cout<<"\n"<<y<<" attempt left";
            }
        }
    }
    myfile.close();
    cout<<"\nThankyou for using GO CAB.......\n\n";
    exit(0);

}
void cab::signup()
{
    ofstream myfile;
    char user[50],pass1[50],pass2[50];
    Sleep(1000);
    cout<<"\nEnter details..";
    Sleep(200);
    while(1)
    {
        cout<<"\n\n\tuser id           :  ";
        cin>>user;
        Sleep(500);
        cout<<"\n\tnew password      :  ";
        cin>>pass1;
        Sleep(500);
        cout<<"\n\tretype password   :  ";
        cin>>pass2;
        if(strcmp(pass1,pass2)==0)
        {
            myfile.open("gocab.txt",ios::app);
            myfile<<"\n"<<user<<"\t"<<pass1;
            myfile.close();
            cout<<"\nThankyou for signup..... ";
            Sleep(1000);
            cout<<"\nNow login and book your ride....\n\n";
            Sleep(1000);
            login();
            break;
        }
        else
        {
            cout<<"\n\tThe password didn't match!!\n\tRetype Password";
        }
}
}

int main()
{
    base_cab bc;
    base_cab *p;
    p=&bc;
    cab c;
    p=&c;
    cout<<c;
    int ch,choice2,choice,ilogin;
    while(1)
    {
        cout<<"\n\n\nPlease select your choice\n\t1.LOG IN\n\t2.SIGN UP\n\t3.EXIT\n";
        cin>>ch;
        switch(ch)
        {

            case 1: ilogin=p->login();
                    if(ilogin==-1)
                    {
                        continue;
                    }
                    break;

            case 2: p->signup();
                    break;

            case 3: cout<<"\nThank you for using GO CAB";
                    exit(0);

            default: cout<<"\nInvalid choice!";
                     break;
        }

        while(1)
        {
            cout<<"\nEnter your choice\n";
            cout<<"1.RIDE NOW\n2.LOGOUT\n";
            cin>>choice2;
            switch(choice2)
            {
                case 1: p->ridenow();
                        break;

                case 2: cout<<"\nThank you for riding with GO CAB   :]\n\n\n\n";
                        exit(0);

                default:cout<<"\nINVALID CHOICE";
                        break;
            }
        }
    }
}


void cab::ridenow()
{
    char pick[50],drop[50],z[5],con[5],y[5];
    int i,choice,no,k=1,r;

    cout<<"\nEnter pickup location:\t";
    cin>>pick;
    Sleep(1000);
    cout<<"\nEnter drop location  :\t";
    cin>>drop;
    while(k!=2)
    {
        cout<<"\nselect your ride\n";
        Sleep(400);
        cout<<"1. Mini\n";
        Sleep(250);
        cout<<"2. Micro\n";
        Sleep(250);
        cout<<"3. ultra\n";
        Sleep(250);
        cout<<"4. prime\n";
        Sleep(500);
        cout<<"\nEnter choice: ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"\nEnter number of passengers(1/2): ";
            cin>>no;
            if(no<=2&&no>0)
            {
                k=2;
            }
            else
            {
                cout<<"\ninvalid input";
                cout<<"(max 2 passengers allowed)\n";
                Sleep(1000);
            }
        }
        else if(choice==2||choice==3||choice==4)
        {
            cout<<"\nEnter number of passengers(max.4): ";
            cin>>no;
            if(no<=4&&no>0)
            {
                k=2;
            }
            else
            {
                cout<<"\ninvalid input";
                cout<<"(max 4 passengers allowed)\n";
                Sleep(1000);
            }
        }
        else
        {
            cout<<"\nInvalid choice!";
        }
    }
    getchar();
    cout<<"\n           press enter to continue\r";
    gets(y);
    cout<<"\rcreating itinerary";
    Sleep(250);
    cout<<".";
    Sleep(250);
    cout<<".";
    Sleep(250);
    cout<<".";
    Sleep(250);
    cout<<"\rcreating itinerary   ";
    Sleep(250);
    cout<<"\b\b\b.";
    Sleep(250);
    cout<<".";
    Sleep(250);
    cout<<".";
    Sleep(250);
    cout<<"\r---------------------------------------------------------------";
    cout<<"\n                          GO CAB                        \n";
    cout<<"---------------------------------------------------------------";
    cout<<"\n\n Pickup location:\t";
    puts(pick);
    cout<<"\n\n Drop location  :\t";
    puts(drop);
    cout<<"\n\n Ride           :\t";
    if(choice==1)
    {
        cout<<"Mini";
    }
    if(choice==2)
    {
        cout<<"Micro";
    }
    if(choice==3)
    {
        cout<<"Ultra";
    }
    if(choice==4)
    {
        cout<<"Prime";
    }
    cout<<"\n\n\n No of passengers :\t"<<no;
    cout<<"\n---------------------------------------------------------------\n";
    Sleep(1000);
    cout<<"\n\n        press enter for confirm booking";
    gets(z);
    cout<<"\r\rplease wait";
        Sleep(250);
        cout<<".";
        Sleep(250);
        cout<<".";
        Sleep(250);
        cout<<".";
        Sleep(250);
        cout<<"\rplease wait   ";
        Sleep(250);
        cout<<"\b\b\b.";
        Sleep(250);
        cout<<".";
        Sleep(250);
        cout<<".";
        Sleep(250);
    cout<<" ";
    cout<<"\ryour booking has been confirmed.\n";
    Sleep(1000);
    cout<<"\nyour driver ";
    srand(time(NULL));
    r=rand()%10;
    switch(r)
    {
        case 1: cout<<"Ashish";
        break;
        case 2: cout<<"Channaswami";
        break;
        case 3: cout<<"Akarsh";
        break;
        case 4: cout<<"Abhishek";
        break;
        case 5: cout<<"Durgesh";
        break;
        case 6: cout<<"Manoj";
        break;
        case 7: cout<<"Amar";
        break;
        case 8: cout<<"Akshay";
        break;
        case 9: cout<<"Narasimha";
        break;
        case 10: cout<<"Kundan";
        break;
    }
    cout<<" will pick you up in "<<rand()%10+1<<" minutes."<<next;
    Sleep(1000);
    cout<<"\n\n";
    }

