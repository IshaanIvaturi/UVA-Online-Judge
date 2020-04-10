#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    //Initialize variables, take in t
    int t, n, s; 
    cin >> t;

    //Order doesn't matter, keeps track of last index element was seen
    unordered_map<int, int> prev;

    //Iterate t times
    while (t--)
    {
        //Clear my map, take in n
        prev.clear();
        cin >> n;
        
        //Holds answer, index of most recent repetition, current unique segment len
        int sol = 0, lastRep = 0, segLen = 0;

        //Index by 1, since map initializes to zero, we can use as easy check
        for (int i = 1; i <= n; i++)
        {
            //Take in the next element
            cin >> s;

            //If we've seen it before
            if (prev[s] != 0)
            {
                //Update to most recent repetition
                lastRep = max(lastRep, prev[s]);
                //length of segment is distance from index to last rep
                segLen = i - lastRep;
            }

            //Otherwise, the segment just increments
            else segLen++;
            
            //Update our map, and our solution which is the longest segment
            prev[s] = i;
            sol = max(sol, segLen);
        }

        //Output solution
        cout << sol << endl;
    }
}