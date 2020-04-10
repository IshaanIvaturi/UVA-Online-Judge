#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //Initialize n
    int n;
    
    //Keep taking in n until it's 0
    while (cin >> n && n != 0)
    {
        //Keeps track of selection counts
        map<vector<int>, int> counts;

        //Iterate n times
        while (n--)
        {
            //Schedule contains 5 courses, take them in
            vector<int> courses(5);
            for (int i = 0; i < 5; i++) cin >> courses[i];

            //Sort so that course order doesn't matter, and increment counts
            sort(courses.begin(), courses.end());
            counts[courses]++;
        }

        //Find the most popular by keeping a max variable and iterating
        int maxCount = 0;
        for (pair<vector<int>, int> combo : counts) maxCount = max(maxCount, combo.second);

        //Find the number at max popularity by adding max count for each schedule at max count
        int sol = 0;
        for (pair<vector<int>, int> combo : counts) if (combo.second == maxCount) sol += combo.second;

        //Output sol
        cout << sol << endl;
    }
}