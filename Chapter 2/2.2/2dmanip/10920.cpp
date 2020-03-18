#include <iostream>
#include <map>
#include <math.h>

using namespace std;

//Maps a direction in the "cartesian coords" to the next counterclockwise dir
map<pair<int, int>, pair<int, int>> nextDir =
{
    {{1, 0}, {0, -1}}, {{0, -1}, {-1, 0}}, {{-1, 0}, {0, 1}}, {{0, 1}, {1, 0}}
};

int main()
{
    //Initialize and take in sz and p
    int sz;
    long long p; //p can get really big, especially in max grid size
    cin >> sz >> p;

    while (sz != 0)
    {
        //The upper right diagonal is all the odd squares
        //I'm finding the nearest one to reduce runtime
        int closestOddRoot = sqrt(p);
        if (closestOddRoot % 2 == 0) closestOddRoot--;

        //I start just above this odd perfect square
        long long current = pow(closestOddRoot, 2) + 1;
        int segment = closestOddRoot; //Starting length of 1 spiral arm

        //Coord 1 is size / 2 + 1, then add root / 2 to both, and an extra for row above
        int row = sz / 2 + 1 + closestOddRoot / 2 + 1;
        int col = sz / 2 + 1 + closestOddRoot / 2;

        //Starting direction left
        int dr = 0;
        int dc = -1;

        //If p actually is this odd root, we're done
        if (p == pow(closestOddRoot, 2)) 
        {
            printf("Line = %d, column = %d.\n", row-1, col);
            cin >> sz >> p;
            continue;
        }

        //Keep going until current reaches p
        while (current != p)
        {
            //If p isn't in the segment
            if (current + segment < p)
            {
                //Add segment to current
                current += segment;

                //Increment row and col in right direction
                row += segment * dr;
                col += segment * dc;
            }

            //If it is
            else
            {
                //Keep going until current is segment
                for (int i = 0; i < segment; i++)
                {
                    if (current == p) break;
                    row += dr;
                    col += dc;
                    current++;
                }

            }
            
            //Set direction to next 
            pair<int, int> next = nextDir[{dr, dc}];
            dr = next.first;
            dc = next.second;

            //Segment length increases when you go up or down
            if (dr == 1 || dr == -1) segment++;
        }

        //Output where the number was found, take in sz and p again
        printf("Line = %d, column = %d.\n", row, col);
        cin >> sz >> p;
    }
}