/*
Write a class called ResistancePair that represents a pair of resistance
connected either in series or parallel.
Implement a method too read the resistance values of the resistance pair.
Provide a pure virtual function that calculates the combined resistance of the resistance pair
which will be implemented in its child classes namely SeriesResistancePair and ParallelResistancePair.
Now calculate the combined resistance of 4 ResistancePair objects connected in parallel.

Note :
1)The combined resistance for two resistors connected in series is the sum of its individual resistances.
2)The combined resistance for two resistors connected in parallel
is the reciprocal of the sum of the individual reciprocal of the resistances.
*/

#include<iostream>
using namespace std;

class ResistancePair
{
    protected: double r1,r2;
    public   : void read_data()
               {
                   cout<<"enter two resistances"<<endl;
                   cin>>r1>>r2;
               };
               virtual double calc_resistance()=0;
};

class series_resistance_pair: public ResistancePair
{
    public: double calc_resistance()
            {
                return (r1+r2);
            }
};

class parallel_resistance_pair: public ResistancePair
{
    public: double calc_resistance()
            {
                return ((1/r1)+(1/r2));
            }
};

int main()
{
    ResistancePair *ptr[4];
    int i;
    char ch;
    double denominator=0,total_resistance;
    for(i=0;i<4;i++)
    {
        cout<<"Enter type (s or p)"<<endl;
        cin>>ch;
        if(ch=='s')
        {
            ptr[i]=new series_resistance_pair;
        }
        else if(ch=='p')
        {
            ptr[i]=new parallel_resistance_pair;
        }
        else
        {
            cout<<"invalid type"<<endl;
            return 0;
        }
        ptr[i]->read_data();
    }
    for(i=0;i<4;i++)
    {
        denominator= denominator + (1/ptr[i]->calc_resistance());
    }
    total_resistance= 1/denominator;
    cout<<"total resistance= "<<total_resistance<<endl;
    return 0;
}
