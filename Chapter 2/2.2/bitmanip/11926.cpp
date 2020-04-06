#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//So I don't need to keep typing size of calendar
//Number of minutes I need to track
#define M 1000001

int main()
{
    //one time, repeating, start, end, repeat
    int n, m, s, e, r;

    //Keep taking in n and m, and both can't be 0
    while (cin >> n >> m && (n || m))
    {
        //I use a bitset to hold whether each minute is free or not
        //0 is free, 1 is not free
        bitset<M> calendar;

        //This holds whether a conflict was found
        bool conflict = false;

        //Iterate for each one time range
        while (n--)
        {
            //Take in start and end
            cin >> s >> e;

            //If there has been a conflict, skip this
            if (conflict) continue;

            //Go from start up to but not including end
            for (int i = s; i < e; i++)
            {
                //If already on, then there's conflict
                if (calendar[i]) conflict = true;

                //Otherwise, set it to true
                else calendar[i] = true;
            }
        }

        //For each repeating range
        while (m--)
        {
            //Take in start, end, repeat interval
            cin >> s >> e >> r;

            //Keep going while start is below max and no conflict
            while (s < M && !conflict)
            {
                //Go from start to end, same procedure
                for (int i = s; i < e; i++)
                {
                    if (calendar[i]) conflict = true;
                    else calendar[i] = true;
                }

                //Increment start by repeat
                s += r;

                //Increment end by repeat, or max size, whichever comes first
                e = min(e + r, M);
            }
        }

        //Output conflict if conflict, no conflict otherwise
        cout << (conflict ? "CONFLICT" : "NO CONFLICT") << endl;
    }
}