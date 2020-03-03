#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Initialize and take in dimensions
    int n, m;
    
    cin >> n >> m;

    //Keep going until n is taken in as 0
    while(n != 0)
    {
        int sol; //Holds solution
        
        //Keeps track of smaller dimension and larger
        int small = n;
        int large = m;

        //I make sure small holds small and large holds large
        if (n > m) swap(small, large);

        //In the case that a dimension is 1, knight can be placed in all
        if (small == 1)
        {
            sol = large;
        }

        //If small is 2, it's a little more complicated
        else if (small == 2)
        {
            //X X _ _ X X _ _ ...
            //X X _ _ X X _ _ ...

            //This can be worked out to a formula based on 
            //a cycle of 4 as follows
            int div = (large - 1) / 4;
            int rem = (large - 1) % 4;

            if (rem == 0) sol = 2 * div + 1;
            else sol = 2 * div + 2;

            //That was for one line, so I just double it
            sol *= 2;
        }
        else
        {
            //In all other cases, same solution as 278.cpp
            sol = (n * m + 1) / 2;
        }
        
        //Output solution and take in next dimensions
        printf("%d knights may be placed on a %d row %d column board.\n", sol, n, m);

        cin >> n >> m;
    }
}