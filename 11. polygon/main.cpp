/*
Create a POLYGON class that has the following members
Data members : name, number of sides and area
Methods :
1)constructors and destructors
2)Display method to display details of the POLYGON object
3)Pure virtual function calcArea
4)Next Derive the following classes from POLYGON namely TRIANGLE and SQUARE with appropriate
data members and methods. Both these derived classes have to define the calcArea method to suit its
purpose.
*/

#include<iostream>
#include<string>
using namespace std;

class polygon
{
    protected: char *name;
               int num_sides;
               double area;
    public   : void show_sides_area()
               {
                   cout<<"\nname "<<name<<"\nnum of sides "<<num_sides<<"\narea "<<area<<endl<<endl;
               }
               virtual void calc_area()=0;
};

class Triangle:public polygon
{
    protected: double base,height;

    public   : Triangle(double base_var,double height_var)
               {
                   base=base_var;
                   height=height_var;
                   name="Triangle";
                   num_sides=3;
                   cout<<"Triangle constructor called"<<endl;
               }
               ~Triangle()
               {
                   cout<<"\ntriangle distructed"<<endl;
               }
               void calc_area()
               {
                   area=(base*height)/2.0;
               }
};

class square:public polygon
{
    protected: double side;

    public   : square(double side_var)
               {
                   side=side_var;
                   name="Square";
                   num_sides=4;
                   cout<<"\nSquare constructor called"<<endl;
               }
               ~square()
               {
                   cout<<"square distructed"<<endl;
               }
               void calc_area()
               {
                   area=side*side;
               }
};

int main()
{
    Triangle t(20,13);
    t.calc_area();
    t.show_sides_area();

    square s(2);
    s.calc_area();
    s.show_sides_area();

    return 0;
}
