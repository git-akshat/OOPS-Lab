/*
Create a RainGauge class that store rainfallincm information and city name.
Include a zero parameter constructor. Write methods for the following
a) fnReadMeasurement that generates a random decimal value in the range of 0
   20cms and reads the name of the city
b) fnDispReading that display city name and rainfall received.
c) Write a friend function that takes an array of RainGauge objects and the
   number of cities as parameters and calculates the average rainfall received.
d) Create an array of RainGauge objects in main and display the results.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class RainGauge
{
            double dRainInCm;
            char cLocation[20];
    public:
            RainGauge()
            {
                dRainInCm = 0.0;
                strcpy(cLocation, "\0");
            }

            void fnReadMeasurement()
            {
                cout << "\nEnter Location of the RainGauge\n";
                cin >> cLocation;
                srand(time(NULL));
                dRainInCm = ((rand()%20+1000)/1000.0);
            }

            void fnDispReading()
            {
                cout << cLocation << " : " << dRainInCm << " cms\n";
            }

            friend double fnCalcAvg(RainGauge r[], int iNum)
            {
                int i;
                double dAvgRain = 0.0;
                for(i=0; i<iNum;i++)
                {
                    dAvgRain += r[i].dRainInCm;
                }
                dAvgRain /= iNum;
                return dAvgRain;
            }
};


int main()
{
    RainGauge rainSensorArray[10];
    double dAvgRainFall;
    int i, iNum;
    cout << "\nEnter the number of cities\n";
    cin >> iNum;
    for(i=0;i<iNum;i++)
    {
        rainSensorArray[i].fnReadMeasurement();
    }
    cout << "\nRainfall Information\n";
    cout << "========================\n";
    for(i=0;i<iNum;i++)
    {
        rainSensorArray[i].fnDispReading();
    }
    dAvgRainFall = fnCalcAvg(rainSensorArray, iNum);
    cout << "\nAverage RainFall recieved is " << dAvgRainFall << " cms\n";
    return 0;
}
