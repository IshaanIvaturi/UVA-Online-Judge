#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int main()
{
    //Initialize number of test cases and string to hold lines
    int t;
    string s;

    //Take in t, and ignore the trailing \n to prepare for getline
    cin >> t;
    cin.ignore(256, '\n');

    //Take in blank line after t
    getline(cin, s);

    //Iterate t times
    while (t--)
    {
        vector<string> phrases; //Holds all the phrases
        vector<string> compare; //Holds with spaces omitted and sorted to compare
        getline(cin, s); //Take in the first phrase

        //Keep going until we get an empty line
        while (s != "")
        {
            //Add to phrases
            phrases.push_back(s);

            //Remove spaces and sort with STL
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
            sort(s.begin(), s.end());

            //Add to compare
            compare.push_back(s);

            //Get the next line
            getline(cin, s);
        }

        //This will hold the pairs of anagrams
        //Set ensures lexographical order between pairs
        set<vector<string>> pairs;

        //Iterate through every pair exactly once
        for (int i = 0; i < phrases.size(); i++)
        {
            for (int j = i+1; j < phrases.size(); j++)
            {
                //If the compares are equal, they're anagrams
                if (compare[i] == compare[j])
                {
                    //Set up the pair with the phrases
                    vector<string> pair = {phrases[i], phrases[j]};

                    //Make sure they're ordered lexographically within
                    if (phrases[j] < phrases[i]) swap(pair[0], pair[1]);

                    //Add to the set
                    pairs.insert(pair);
                }
            }
        }

        //Go through the set outputting the equivalences
        for (vector<string> pair : pairs)
        {
            cout << pair[0] << " = " << pair[1] << endl;
        }

        //Extra line between if t > 0 (not at last case)
        if (t) cout << endl;
    }


}