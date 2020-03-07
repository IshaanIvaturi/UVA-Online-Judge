#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    //Initialize t and string to hold sentence
    int t;
    string s;

    cin >> t; //Take in t

    cin.ignore(256, '\n'); //Get rid of \n left by cin to getline

    //Iterate t times, from 1 to t
    for (int i = 1; i <= t; i++)
    {
        //Store line in s
        getline(cin, s);

        //Go through all ignorable chars
        for (char c : {'.', ',', '!', '?', ' ', '(', ')'})
        {
            //Use STL to remove all occurrences
            s.erase(remove(s.begin(), s.end(), c), s.end());
        }

        //Checks if length of string is perfect square
        double sqrtLen = sqrt(s.length());

        //If it's not
        if (sqrtLen != floor(sqrtLen))
        {
            //Output fail and continue to next input
            cout << "Case #" << i << ":\nNo magic :(\n";
            continue;
        }

        //Will hold the K*K grid
        vector<string> grid;

        //Keeps track of index in s
        int index = 0;

        //Iterate K times
        for (int j = 0; j < int(sqrtLen); j++)
        {
            //Temp will be added to grid
            string temp = "";

            //Iterate K times again
            for (int k = 0; k < int(sqrtLen); k++)
            {
                //Add to temp string, increment index
                temp += s[index];
                index++;
            }

            //Push back into grid
            grid.push_back(temp);
        }

        //TestString will be built up from all directions
        //Will check if it == s which means valid palindrome
        string testString = "";

        //Already built with horizontal from (0, 0)
        //Now vertical from (0, 0)
        //Go through all squares in this order
        for (int col = 0; col < int(sqrtLen); col++)
        {
            for (int row = 0; row < int(sqrtLen); row++)
            {
                //Add to testString 
                testString += grid[row][col];
            }
        }

        //Check if it's equal to s, if not output fail and continue
        if (testString != s) 
        {
            cout << "Case #" << i << ":\nNo magic :(\n";
            continue;
        }

        //Always reset to ""
        testString = "";

        //Now horizontal from (K-1, K-1)
        for (int row = int(sqrtLen) - 1; row >= 0; row--)
        {
            for (int col = int(sqrtLen) - 1; col >= 0; col--)
            {
                testString += grid[row][col];
            }
        }

        if (testString != s) 
        {
            cout << "Case #" << i << ":\nNo magic :(\n";
            continue;
        }

        testString = "";

        //Now vertical from (k-1, k-1)
        for (int col = int(sqrtLen) - 1; col >= 0; col--)
        {
            for (int row = int(sqrtLen) - 1; row >= 0; row--)
            {
                testString += grid[row][col];
            }
        }

        if (testString != s) 
        {
            cout << "Case #" << i << ":\nNo magic :(\n";
            continue;
        }

        //If it got through, output K
        cout << "Case #" << i << ":\n" << int(sqrtLen) << endl;        
    }
}