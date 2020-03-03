#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Initialize required variables
    int n, b, h, w, p, sol, beds;

    //Keep going while it's possible to take in 4 ints
    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        //Sol starts at very large value, to be reduced with min function
        sol = INT_MAX;

        //Go through all the hotels
        for (int i = 0; i < h; i++)
        {
            //Take in the hotel price
            scanf("%d", &p);

            //Go through the weeks
            for (int j = 0; j < w; j++)
            {
                //Take in beds for the week
                scanf("%d", &beds);

                //If there's space, and price less than sol, update
                if (beds >= n) sol = min(sol, p * n);
            }
        }

        //Display either stay home or price
        if (sol > b) printf("stay home\n");
        else printf("%d\n", sol);
    }  

    return 0;      
}