#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize variables and take in # of tests
    int t, n, c;

    cin >> t;

    //Iterate through test cases
    for (int i = 0; i < t; i++)
    {
        //Sol starts at very small value, will be increased by max
        int sol = INT_MIN;
        cin >> n;   //Take in # of students

        //Iterate through students
        for (int j = 0; j < n; j++)
        {
            //Take in speed, and update sol if it's greater than currently
            cin >> c;
            sol = max(sol, c);
        }

        //Print the case # and the max speed taken in
        printf("Case %d: %d\n", i + 1, sol);
    }
}