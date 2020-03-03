#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize variables and take in L
    long L;
    string s, current;

    cin >> L;

    //Keep going until L is input as 0
    while (L != 0)
    {
        //Initially set to +x
        current = "+x";

        //Iterate L-1 times
        for (long i = 0; i < L-1; i++)
        {
            //Take in operation
            cin >> s;

            if (s == "No") continue;

            //Case work with if statements, tested all combinations and incremented current
            if (current == "+x") current = s;
            if (current == "-x")
            {
                if (s == "+y") current = "-y";
                if (s == "-y") current = "+y";
                if (s == "+z") current = "-z";
                if (s == "-z") current = "+z";
            }
            if (current == "+y")
            {
                if (s == "+y") current = "-x";
                if (s == "-y") current = "+x";
            }
            if (current == "-y")
            {
                if (s == "+y") current = "+x";
                if (s == "-y") current = "-x";
            }
            if (current == "+z")
            {
                if (s == "+z") current = "-x";
                if (s == "-z") current = "+x";
            }
            if (current == "-z")
            {
                if (s == "+z") current = "+x";
                if (s == "-z") current = "-x";
            }
        }

        //Output current and take in next L
        cout << current << endl;
        cin >> L;
    }
}