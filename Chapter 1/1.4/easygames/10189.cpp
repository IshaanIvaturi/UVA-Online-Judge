#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Initialize n and m, and take them in
    int n, m;
    char c; //c is a temp char for input

    cin >> n >> m;

    //Field number starts at 1, increments, ends when n gets input as 0
    for (int field = 1; n != 0; field++)
    {
        //To add spaces between fields, but not at very end
        if (field > 1) cout << endl;

        //I use a vector<vector<char>> to hold the grid of . and *
        vector<vector<char>> grid;

        //Go through rows and cols, input to temp vector, and push to grid
        for (int i = 0; i < n; i++)
        {
            vector<char> temp;

            for (int j = 0; j < m; j++)
            {
                cin >> c;
                temp.push_back(c);
            }

            grid.push_back(temp);
        }

        //Go through every square
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //I don't care if it's a mine
                if (grid[i][j] == '*') continue;

                //Store all adjacent squares with vector<pair<int, int>>
                vector<pair<int, int>> adj = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
                int bombCount = 0; //Will count mines around

                //Iterate through adjacent coords
                for (pair<int, int> coord : adj)
                {
                    //Check if it's in bounds
                    if (i + coord.first >= 0 && i + coord.first < n && j + coord.second >= 0 && j + coord.second < m)
                    {
                        //If it's a bomb, add to the count
                        if (grid[i+coord.first][j+coord.second] == '*') bombCount++;
                    }
                }
                //Convert int to char and replace square
                grid[i][j] = bombCount + '0';
            }
        }

        //Output field number and grid
        cout << "Field #" << field << ":\n";

        for (vector<char> row : grid)
        {
            for (char col : row) cout << col;
            cout << endl;
        }

        //Take in n and m again
        cin >> n >> m;
    }
}