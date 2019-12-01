#include <iostream>
#include<math.h>
using namespace std;

class circletype
{
    private: int radius,x,y;
    public: circletype()
            {
                    radius=0;
                    x=0;
                    y=0;
            }
            circletype(int a,int b,int c)
            {
                radius=a;
                    x=b;
                    y=c;
            }
            void display()
            {
                cout<<"radius"<<radius<<endl;
                cout<<"xcenter:"<<x<<endl;
                cout<<"ycenter:"<<y<<endl;
            }
            friend void checkcircle(circletype c1,circletype c2)
            {
                int d;
                d=sqrt(((c1.x-c2.x)*(c1.x-c2.x))+((c1.y-c2.y)*(c1.y-c2.y)));
                if((c1.radius+c2.radius) == d)
                {
                    cout<<"circle touches each other"<<endl;
                }
                if((c1.radius+c2.radius) < d)
                {
                    cout<<"circles are disjoint"<<endl;
                }
                if((c1.radius+c2.radius) > d)
                {
                    cout<<"circle intersect each other"<<endl;
                }
            }
};

int main()
{
    circletype c1(10,5,5),c2(2,2,0),c3(2,-2,0);
    checkcircle(c1,c2);
    checkcircle(c1,c3);
    c1.display();
}
