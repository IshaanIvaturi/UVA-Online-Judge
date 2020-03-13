#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//I store direction as change in row, change in col
//This maps a direction to its right side, which is useful later
map<pair<int, int>, pair<int, int>> rightSide =
{
    {{0, 1}, {1, 0}}, {{-1, 0}, {0, 1}}, {{0, -1}, {-1, 0}}, {{1, 0}, {0, -1}}
};

int main()
{
    //Initialize variables, take in b and w for dimensions of grid
    int b, w;
    char c;
    cin >> b >> w;

    //Keep going until it feeds in 0
    while (b != 0)
    {
        //I add 2 to each dimension to have a wall border and don't deal with out of bounds
        //I set everything to -1, which means wall in my program
        vector<vector<int>> maze(b+2, vector<int>(w+2, -1));

        //I go through the maze, but ignore the border leaving as -1
        for (int i = 1; i <= b; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                //I take in character, and if it's 0, I reset that spot to 0, no wall
                //I use my maze not only to keep track of walls, but to count visits
                cin >> c;
                if (c == '0') maze[i][j] = 0;
            }
        }

        //Set up starting coords at bottom left ignoring border
        int row = b;
        int col = 1;

        //dr is change in row, dc is change in col, represents direction
        //Starts facing right
        int dr = 0;
        int dc = 1;

        //If still on starting square, haven't moved yet
        bool first = true;

        //Keep going while you're not on start, or it's still first move
        while (row != b || col != 1 || first)
        {
            //Store the direction to your right for later
            pair<int, int> right = rightSide[{dr, dc}];

            //If there's no wall to the right of you
            //To stick to the right wall, you have to go right here
            if (maze[row+right.first][col+right.second] != -1)
            {
                //Set your direction to right of current
                dr = right.first;
                dc = right.second;

                //Move to the new direction
                row += dr;
                col += dc;

                //Increment your new maze square
                maze[row][col]++;
                first = false; //No longer at starting square
            }

            //If there is a wall to the right of you
            else
            {
                //If there's no wall in front, you might as well go forward
                if (maze[row+dr][col+dc] != -1)
                {
                    //Go forward
                    row += dr;
                    col += dc;

                    maze[row][col]++;
                    first = false;
                }

                //If your right side and forward side are blocked, turn left
                //Don't go yet, since you may not be able to
                else
                {
                    //Setting dr and dc to negative right is equivalent to left
                    dr = right.first * -1;
                    dc = right.second * -1;
                }
            }
        }
        
        //Sol holds counts of squares that were visited 0, 1, 2, 3, 4 times
        vector<int> sol = {0, 0, 0, 0, 0};

        //Go through rows of maze
        for (vector<int> r : maze)
        {
            //Go through cols of row
            for (int c : r)
            {
                //If not a wall, increment the proper spot in sol
                if (c != -1) sol[c]++;
            }
        }

        //Use printf to right justify
        printf("%3d%3d%3d%3d%3d\n", sol[0], sol[1], sol[2], sol[3], sol[4]);

        //Take in b and w
        cin >> b >> w;
    }
}