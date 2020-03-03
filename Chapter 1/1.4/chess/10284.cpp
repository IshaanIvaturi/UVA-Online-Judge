#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Initialize FEN, and keep taking it in
    string FEN;

    while(cin >> FEN)
    {
        //Initialize an 8x8 char array for board
        char board[8][8];

        //Keeps track of the current row and col
        int i = 0;
        int j = 0;

        //Go through each character in string
        for (char c : FEN)
        {
            //If it's a number
            if (c >= '1' && c <= '8')
            {
                //Set that many spaces to -, which means empty
                for (int n = 0; n < c - '0'; n++)
                {
                    board[i][j] = '-';
                    j++; //Increment col
                }
            }

            //If /, increment row and set col back to 0
            else if (c == '/')
            {
                i++;
                j = 0;
            }

            //Otherwise, just fill with c
            else
            {
                board[i][j] = c;
                j++;
            }
        }

        //Now, iterate through all squares
        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                //If not a piece, continue
                if (board[r][c] == '-' || board[r][c] == 'A') continue;

                //Black pawn
                if (board[r][c] == 'p')
                {
                    //Set empty squares diagonally down by 1 to attacked
                    //Need to check if within bounds
                    if (r <= 6 && c <= 6)
                    {
                        if (board[r+1][c+1] == '-') board[r+1][c+1] = 'A';
                    }
                    if (r <= 6 && c >= 1)
                    {
                        if (board[r+1][c-1] == '-') board[r+1][c-1] = 'A';
                    }
                }
                
                //White pawn
                if (board[r][c] == 'P')
                {
                    //Same thing, opposite direction
                    if (r >= 1 && c <= 6)
                    {
                        if (board[r-1][c+1] == '-') board[r-1][c+1] = 'A';
                    }
                    if (r >= 1 && c >= 1)
                    {
                        if (board[r-1][c-1] == '-') board[r-1][c-1] = 'A';
                    }
                }

                //Knight
                if (board[r][c] == 'N' || board[r][c] == 'n')
                {
                    //Vector contains possible moves
                    vector<pair<int, int>> combos = 
                    {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};

                    //For each one, test if move is possible, update squares with A
                    for (pair<int, int> com : combos)
                    {
                        if (r + com.first >= 0 && r + com.first <= 7 && c + com.second >= 0 && c + com.second <= 7)
                        {
                            if (board[r + com.first][c + com.second] == '-') board[r + com.first][c + com.second] = 'A';
                        }
                    }
                }

                //Bishop
                if (board[r][c] == 'B' || board[r][c] == 'b')
                {
                    //This one is a little harder
                    //Go in each of the 4 diagonals until end of board or another piece

                    int n = 1; //I will increment this to move in one diagonal

                    //Down and right diagonal, until I reach edge
                    while (r + n <= 7 && c + n <= 7)
                    {
                        //If empty, continue
                        if (board[r+n][c+n] == '-' || board[r+n][c+n] == 'A') 
                        {
                            board[r+n][c+n] = 'A';
                            n++;
                        }
                        //Otherwise I'm blocked and must stop
                        else break;
                    }

                    //Reset n to 1 and repeat for other 3 directions
                    n = 1;

                    while (r - n >= 0 && c - n >= 0)
                    {
                        if (board[r-n][c-n] == '-' || board[r-n][c-n] == 'A') 
                        {
                            board[r-n][c-n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r + n <= 7 && c - n >= 0)
                    {
                        if (board[r+n][c-n] == '-' || board[r+n][c-n] == 'A') 
                        {
                            board[r+n][c-n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r - n >= 0 && c + n <= 7)
                    {
                        if (board[r-n][c+n] == '-' || board[r-n][c+n] == 'A') 
                        {
                            board[r-n][c+n] = 'A';
                            n++;
                        }
                        else break;
                    }
                }

                //Rook
                if (board[r][c] == 'R' || board[r][c] == 'r')
                {
                    //Same procedure as bishop, but the 4 directions are straight now
                    int n = 1;

                    while (r + n <= 7)
                    {
                        if (board[r+n][c] == '-' || board[r+n][c] == 'A') 
                        {
                            board[r+n][c] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r - n >= 0)
                    {
                        if (board[r-n][c] == '-' || board[r-n][c] == 'A') 
                        {
                            board[r-n][c] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (c - n >= 0)
                    {
                        if (board[r][c-n] == '-' || board[r][c-n] == 'A') 
                        {
                            board[r][c-n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (c + n <= 7)
                    {
                        if (board[r][c+n] == '-' || board[r][c+n] == 'A') 
                        {
                            board[r][c+n] = 'A';
                            n++;
                        }
                        else break;
                    }
                }

                //Queen
                if (board[r][c] == 'Q' || board[r][c] == 'q')
                {
                    //Literally just bishop + rook
                    int n = 1;

                    while (r + n <= 7 && c + n <= 7)
                    {
                        if (board[r+n][c+n] == '-' || board[r+n][c+n] == 'A') 
                        {
                            board[r+n][c+n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r - n >= 0 && c - n >= 0)
                    {
                        if (board[r-n][c-n] == '-' || board[r-n][c-n] == 'A') 
                        {
                            board[r-n][c-n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r + n <= 7 && c - n >= 0)
                    {
                        if (board[r+n][c-n] == '-' || board[r+n][c-n] == 'A') 
                        {
                            board[r+n][c-n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r - n >= 0 && c + n <= 7)
                    {
                        if (board[r-n][c+n] == '-' || board[r-n][c+n] == 'A') 
                        {
                            board[r-n][c+n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r + n <= 7)
                    {
                        if (board[r+n][c] == '-' || board[r+n][c] == 'A') 
                        {
                            board[r+n][c] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (r - n >= 0)
                    {
                        if (board[r-n][c] == '-' || board[r-n][c] == 'A') 
                        {
                            board[r-n][c] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (c - n >= 0)
                    {
                        if (board[r][c-n] == '-' || board[r][c-n] == 'A') 
                        {
                            board[r][c-n] = 'A';
                            n++;
                        }
                        else break;
                    }

                    n = 1;

                    while (c + n <= 7)
                    {
                        if (board[r][c+n] == '-' || board[r][c+n] == 'A') 
                        {
                            board[r][c+n] = 'A';
                            n++;
                        }
                        else break;
                    }
                }

                //King
                if (board[r][c] == 'K' || board[r][c] == 'k')
                {
                    //Same procedure as knight, can move by 1 around itself
                    vector<pair<int, int>> combos =
                    {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

                    //Check within range, and update to A
                    for (pair<int, int> com : combos)
                    {
                        if (r + com.first >= 0 && r + com.first <= 7 && c + com.second >= 0 && c + com.second <= 7)
                        {
                            if (board[r + com.first][c + com.second] == '-') board[r + com.first][c + com.second] = 'A';
                        }
                    }
                }
            }
        }

        //Sol holds solution, increment for each non attacked empty square
        int sol = 0;

        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                if (board[r][c] == '-') sol++;
            }
        }

        //Output solution
        cout << sol << endl;
    }
}