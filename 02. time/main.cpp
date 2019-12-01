/*
Write a C++ program that stores the time duration in hh:mm:ss format in a
class called Duaration having the members hh, mm and ss.
Include the following constructors:
a) zero parameter constructor that sets all data members to zero.
b) three parameter constructor that sets values of hh, mm and ss respectively if
the values are valid.
c)Implement the following methods
 1. getDuration method that reads and validates a time duration
 2. showDuration method that displays the time duration
 3. addDuration method that adds two durations
 Illustrate the addition of two time durations.
 */


#include <iostream>
using namespace std;

class DurationType
{
            int iHr, iMn, iSc;
    public:
            DurationType()
            {
                iHr = iMn = iSc = 0;
            }
            DurationType(int h, int m, int s)
            {
                iHr = h;
                iMn = m;
                iSc = s;
            }
            void fnSetDuration()
            {
                int h,m,s;
                cout << "\nEnter the duration : \n";
                cin >> h >> m >> s;
                if(m<60 && s<60)
                {
                    iHr = h;
                    iMn = m;
                    iSc = s;
                }
                else
                    cout << "\nInvalid Input\n";
            }

                void fnShowDuration()
                {
                    cout << iHr << ":"<< iMn << ":"<< iSc << endl;
                }
                DurationType fnAddDuration(DurationType d2)
                {
                    DurationType d3;
                    int hh, mm, ss;
                    ss = iSc + d2.iSc;
                    mm = iMn + d2.iMn + (ss/60);
                    hh = iHr + d2.iHr + (mm/60);
                    d3.iSc = ss % 60;
                    d3.iMn = mm % 60;
                    d3.iHr = hh;
                    return d3;
                }
};



int main()
{
    DurationType d1, d2, d3;
    d1.fnSetDuration();
    d2.fnSetDuration();
    d3 = d1.fnAddDuration(d2); // d3 = fnAddDuration(d1,d2);
    cout << "\nDuration1 ";
    d1.fnShowDuration();
    cout << "\nDuration2 ";
    d2.fnShowDuration();
    cout << "\nTotal Duration ";
    d3.fnShowDuration();
    return 0;
}
