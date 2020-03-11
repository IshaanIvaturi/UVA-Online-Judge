#include <iostream>
#include <string>
#include <vector>

using namespace std;

//THIS CODE IS ALMOST IDENTICAL TO 893.cpp!!
//I will be highlighting the parts which are different, but please refer to that for more info

vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap (int y)
{
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int main()
{
    //Initialize variables, take in n
    int n, d, m, y;
    string date;
    cin >> n;

    //Go from 1 to n for test cases
    for (int t = 1; t <= n; t++)
    {
        //Take in the date as a string
        cin >> date;

        //Use substrings to store in proper variables
        d = stoi(date.substr(2, 2));
        m = stoi(date.substr(0, 2));
        y = stoi(date.substr(4, 4));

        //This time I am always adding 40 weeks, not days variable
        long totalDays = 40 * 7;

        for (int i = 1; i < y; i++)
        {
            if (isLeap(i)) totalDays += 366;
            else totalDays += 365;
        }

        if (isLeap(y)) months[1] = 29;

        for (int i = 1; i < m; i++)
        {
            totalDays += months[i-1]; 
        }
        months[1] = 28;

        totalDays += d;

        m = 1;
        y = 1;

        while (totalDays >= 365)
        {
            if (isLeap(y) && totalDays > 366) totalDays -= 366;
            else if (!isLeap(y) && totalDays > 365) totalDays -= 365;
            else break;
            y++;
        }

        if (isLeap(y)) months[1] = 29;

        while (totalDays > months[m-1])
        {
            totalDays -= months[m-1];
            m++;
        }
        months[1] = 28;

        //Now I have the final date stored in totaldays, m, y

        string sign; //Will hold the sign

        //Use month and day info to get sign
        if (m == 1 && totalDays > 20 || m == 2 && totalDays < 20) sign = "aquarius";
        else if (m == 2 && totalDays > 19 || m == 3 && totalDays < 21) sign = "pisces";
        else if (m == 3 && totalDays > 20 || m == 4 && totalDays < 21) sign = "aries";
        else if (m == 4 && totalDays > 20 || m == 5 && totalDays < 22) sign = "taurus";
        else if (m == 5 && totalDays > 21 || m == 6 && totalDays < 22) sign = "gemini";
        else if (m == 6 && totalDays > 21 || m == 7 && totalDays < 23) sign = "cancer";
        else if (m == 7 && totalDays > 22 || m == 8 && totalDays < 22) sign = "leo";
        else if (m == 8 && totalDays > 21 || m == 9 && totalDays < 24) sign = "virgo";
        else if (m == 9 && totalDays > 23 || m == 10 && totalDays < 24) sign = "libra";
        else if (m == 10 && totalDays > 23 || m == 11 && totalDays < 23) sign = "scorpio";
        else if (m == 11 && totalDays > 22 || m == 12 && totalDays < 23) sign = "sagittarius";
        else sign = "capricorn";

        //Will properly format output
        string outputString;

        //I make sure to add leading 0's where needed
        if (m <= 9) outputString += '0' + to_string(m);
        else outputString += to_string(m);

        outputString += '/';

        if (totalDays <= 9) outputString += '0' + to_string(totalDays);
        else outputString += to_string(totalDays);

        outputString += '/' + to_string(y) + ' ' + sign + '\n';

        //Output the test case and output string for each test case
        cout << t << " " << outputString;
    }
}