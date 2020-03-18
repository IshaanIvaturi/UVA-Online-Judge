#include <iostream>
#include <algorithm>

using namespace std;

//Holds 3x3 grid, pad with 0's for simpler addition
int grid[5][5] = {0};

//Checks if grid is all 0's
bool allZero()
{
    //Go through the middle 3x3, if anything != 0, false
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++) if (grid[i][j] > 0) return false;
    }

    //Otherwise, return true
    return true;
}

int main()
{
    //While intimidating, this problem only wants how many steps it will take
    //to reach the zero grid minus one, where each step is just replacing each
    //square of the grid with the sum mod 2 of its adjacent squares

    //Initialize t and take it in
    int t;
    cin >> t;

    //Initialize c to take in grid values
    char c;

    //Iterate t times
    while (t--)
    {
        //Go through the middle 3x3
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                //Take in c, and set the grid to the numerical equivalent
                cin >> c;
                grid[i][j] = c - '0';
            }
        }

        //Temp will be used to store the transform
        int temp[5][5] = {0};

        //Count starts at -1, we will count steps from there
        int count = -1;
        
        //Keep going as long as it's not a zero grid
        while (!allZero())
        {
            //Go through the middle 3x3
            for (int i = 1; i < 4; i++)
            {
                for (int j = 1; j < 4; j++)
                {
                    //Since outside is 0's we can add all sides and mod by 2
                    temp[i][j] = (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1]) % 2;
                }
            }

            //Copy temp into grid
            for (int i = 1; i < 4; i++) for (int j = 1; j < 4; j++) grid[i][j] = temp[i][j];

            //Increment count
            count++;
        }

        //Our solution for the query is just count
        cout << count << endl;
    }
}