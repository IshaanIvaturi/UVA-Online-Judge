#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //Dimensions, weights of each corner, potencies of each corner
    //17000 is bigger than 2^14, so it's a safe value to initialize
    int n, w[17000], p[17000];

    //Keep taking in n
    while (cin >> n)
    {
        //Iterate 2^n times, 1 << n equals 2^n, take in corner weight
        for (int i = 0; i < 1 << n; i++) cin >> w[i];

        //Iterate 2^n times, for each corner
        for (int i = 0; i < 1 << n; i++)
        {
            //Set potency of corner to 0
            p[i] = 0;

            //Iterate through dimensions, all bits of corner
            //Toggle the bit, and add that weight to potency
            //Adjacent corners are simply 1 bit toggled
            for (int j = 0; j < n; j++) p[i] += w[i ^ (1 << j)]; //i^(1<<j) toggles bit at j
        }

        //Sol will hold max potency
        int sol = 0;

        //Go through all corners
        for (int i = 0; i < 1 << n; i++)
        {
            //For each adjacent corner, max sol with corner plus adjacent for all pairs
            for (int j = 0; j < n; j++) sol = max(sol, p[i] + p[i ^ (1 << j)]);
        }

        //Output sol
        cout << sol << endl;
    }
}