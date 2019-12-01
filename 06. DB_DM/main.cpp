/*
Create two classes DB & DM which store the value of distances. DM stores
distances in metres & centimeters and DB in feet & inches. Write a program that
can read values for the class objects and add one object of DM with another
object of DB. Use friend function to carry out the addition. The object that stores
the result should be a DB object.
*/

#include<iostream>
using namespace std;

class DB;
class DM
{
    private:
            float metres;
            float centimetres;
    public:
            DM()
            {
                metres=0;
                centimetres=0;
            }
            DM(float a,float b)
            {
                metres=a;
                centimetres=b;
            }
            friend void add(DM,DB);
};

class DB
{
        float feet;
        float inches;
    public:
        DB()
        {
            feet=0;
            inches=0;
        }
        DB(float a,float b)
        {
            feet=a;
            inches=b;
        }
        friend void add(DM,DB);
};

void add(DM d1,DB d2)
{

    float f,i;
    i=(d1.metres+(d1.centimetres/100))*39.37;
    f=int(i)/12;
    i=int(i)%12;
    f=f+d2.feet;
    i=i+d2.inches;
    if(i>12)
    {
        f=f+int(i)/12;
        i=int(i)%12;
    }
    cout<<"feet="<<f<<endl;
    cout<<"inches="<<i<<endl;
}

int main()
{
    float x,y;
    cout<<"enterthe distance in metres and cms"<<endl;
    cin>>x>>y;
    DM d1(x,y);
    cout<<"enter the distance in feet and inches"<<endl;
    cin>>x>>y;
    DB d2(x,y);
    add(d1,d2);
}
