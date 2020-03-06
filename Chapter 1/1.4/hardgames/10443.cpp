#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Initialize variables I will use
    int t, r, c, n;
    string s;

    //This will be used later, it holds the adjacent squares
    vector<vector<int>> adj = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    //Take in t
    cin >> t;

    //Iterate t times
    while (t--)
    {
        //Take in rows, cols, and number of iterations
        cin >> r >> c >> n;
        vector<string> grid; //This holds the current grid
        vector<string> next; //Will be updated to hold the next day

        //Take in all the rows
        for (int i = 0; i < r; i++)
        {
            cin >> s;

            //Update both the grid and the next at first
            grid.push_back(s);
            next.push_back(s);
        }

        //Iterate the number of days
        while (n--)
        {
            //Go through every square
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    //This will hold what it loses to
                    char enemy;

                    //I set enemy to the proper character
                    if (grid[i][j] == 'R') enemy = 'P';
                    if (grid[i][j] == 'P') enemy = 'S';
                    if (grid[i][j] == 'S') enemy = 'R';

                    //I go through adjacent squares
                    for (vector<int> pair : adj)
                    {
                        //The actual coords require adding adj to square
                        int I = i + pair[0];
                        int J = j + pair[1];

                        //If the adj is within bounds and is the enemy, set next to the enemy
                        if (I >= 0 && I < r && J >= 0 && J < c && grid[I][J] == enemy) next[i][j] = enemy;
                    }
                }
            }

            //Set grid to next for next iteration
            grid = next;
        }

        //Output the grid
        for (int i = 0; i < r; i++) cout << grid[i] << endl;

        //Add a line if it isn't the last iteration
        if (t) cout << endl;
    }
}