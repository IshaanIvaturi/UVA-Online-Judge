#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Initialize variables and take in first num of nums
    int n, num;
    cin >> n;

    //Will increment c for cases
    int c = 1;

    //Keep going until I take in a 0
    while (n != 0)
    {
        //Output the case #
        cout << "Case " << c << ":\n";

        //Groups holds chains of consecutive numbers in separate vectors
        //I start with the value 0 so it has something to compare to, will ignore later
        vector<vector<int>> groups = {{0}};

        //Iterate n times
        for (int i = 0; i < n; i++)
        {
            //Take in the current number
            cin >> num;

            //If it's consecutive with the end of last group, add it there
            if (num == groups.back().back() + 1) groups.back().push_back(num);

            //Otherwise, create new group
            else groups.push_back({num});
        }

        //Go through groups, but ignore the 0 at beginning
        for (int i = 1; i < groups.size(); i++)
        {
            //If single num, just put that number on its own line
            if (groups[i].size() == 1) cout << 0 << groups[i][0] << endl;

            //Otherwise, find where the begin and end of group differ
            else
            {
                //Store the beginning of group and end as strings
                string frontStr = "0" + to_string(groups[i].front());
                string backStr = "0" + to_string(groups[i].back());

                //Keep track of index where they differ
                int ind = 0;
                
                //Keep going through and incrementing index until difference
                while (frontStr[ind] == backStr[ind]) ind++;

                //Output the - and the differing characters from the end of sequence
                cout << frontStr << "-";
                for (int j = ind; j < backStr.size(); j++) cout << backStr[j];
                cout << endl;
            }
        }

        //Add a newline, take in next n, and increment case
        cout << endl;
        cin >> n;
        c++;
    }
}