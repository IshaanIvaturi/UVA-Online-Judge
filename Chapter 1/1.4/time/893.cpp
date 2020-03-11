#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Holds the number of days per month
vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Checks if a year is leap year
bool isLeap (int y)
{
    //Divisible by 400 = leap
    if (y % 400 == 0) return true;

    //Divisible by 100 and not 400 = not leap
    if (y % 100 == 0) return false;

    //Otherwise divisible by 4 = leap
    if (y % 4 == 0) return true;

    //And if not divisible by 4 not leap
    return false;
}

int main()
{
    //Take in days, day, month, year
    int days, d, m, y;
    cin >> days >> d >> m >> y;

    //Keep going until 4 0's are taken in
    while (days != 0 && d != 0 && m != 0 && y != 0)
    {
        //TotalDays will hold the number of days from 1/1/1 to inputted date
        //I start it at days to add, since we want to get days from 1/1/1 to final date
        long totalDays = days;

        //Go through every year until current
        for (int i = 1; i < y; i++)
        {
            //Add number of days for leap year and normal
            if (isLeap(i)) totalDays += 366;
            else totalDays += 365;
        }

        //For leap year, set february to 29 days
        if (isLeap(y)) months[1] = 29;

        //Now go through the remaining full months
        for (int i = 1; i < m; i++)
        {
            //Add days in that month, -1 for 0 indexing
            totalDays += months[i-1]; 
        }

        months[1] = 28; //Set back to 28 now

        //Finally, the days get added to the total
        totalDays += d;


        //Now I have the total days from 1/1/1 to my answer date
        //I have to work back to get to the date I want

        //Start with totaldays, m=1, y=1, and transfer days surplus
        m = 1;
        y = 1;

        //Keep going if we have more than a year left
        while (totalDays >= 365)
        {
            //If leap year and we have room for another year, subtract 366
            if (isLeap(y) && totalDays > 366) totalDays -= 366;

            //If not leap year and we have room for another year, subtract 365
            else if (!isLeap(y) && totalDays > 365) totalDays -= 365;

            //Otherwise break and don't add a year
            else break;

            y++;
        }

        //Once again, set feb to 29 if we have a leap year
        if (isLeap(y)) months[1] = 29;

        //Keep going if we have room for another month
        while (totalDays > months[m-1])
        {
            //Take away the current month, and increment m
            totalDays -= months[m-1];
            m++;
        }
        months[1] = 28;

        //Output the days we have left, month, and year
        cout << totalDays << " " << m << " " << y << endl;

        //Take in data for next test case
        cin >> days >> d >> m >> y;
    }
}

