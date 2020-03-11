#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    //Time holds the string input, take it in
    string time;
    cin >> time;

    //Keep going until time is 0:00
    while (time != "0:00")
    {
        //Cast last 2 characters to int for minutes
        int minutes = stoi(time.substr(time.length()-2));

        //Remove these characters and the :
        for (int i = 0; i < 3; i++) time.pop_back();

        //Hours is what's left
        int hours = stoi(time);

        //Get the degrees from 12:00
        //For hours, add the hour to the fractional hour from minutes, and multiply by 30
        double hourDegrees = (hours % 12 + (double)minutes/60) * 30;

        //For minutes, each minute is 6 degrees
        double minuteDegrees = minutes * 6;
        
        //Take the absolute difference between the hours and minutes
        double degreeDiff = abs(hourDegrees - minuteDegrees);

        //Get smaller angle by taking other angle if it's reflex angle
        if (degreeDiff > 180) degreeDiff = 360 - degreeDiff;

        //Set precision to 3 and print difference
        cout << fixed << setprecision(3) << degreeDiff << endl;

        //Take in next time
        cin >> time;
    }
}