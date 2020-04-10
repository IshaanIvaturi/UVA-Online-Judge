#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Set precision to 4 decimals, initialize t and s
    cout << fixed << setprecision(4);
    int t;
    string s;

    //Take in the line for t, stoi t, get blank line
    getline(cin, s);
    t = stoi(s);
    getline(cin, s);

    //Iterate t times
    while (t--)
    {
        //Keeps track of occurrences
        map<string, int> counts;
        int total = 0; //Total number of trees

        //Keep taking in till blank line
        while (getline(cin, s) && s != "")
        {
            //Increment count for that string, and total
            counts[s]++;
            total++;
        }

        //Iterate through map, output string and percentage based on count and total
        for (pair<string, int> type : counts)
        {
            cout << type.first << " " << double(type.second) / total * 100 << endl;
        }

        //Output line of not the last case
        if (t) cout << endl;
    }
}