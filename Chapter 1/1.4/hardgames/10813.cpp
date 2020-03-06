#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Initialize n, var to hold each num draw, and card array
    int n, draw, card[5][5];

    cin >> n; //Take in n

    //Iterate n times
    while (n--)
    {
        //Fill in the first half of the card
        for (int i = 0; i < 12; i++)
        {
            //This evaluates the proper row and column
            //Truncated division finds which fifth i is in
            //Mod specifies the actual column in that fifth
            cin >> card[i/5][i%5];
        }

        //Middle is free space, 0 means square is completed
        card[2][2] = 0;

        //Fill in the last half of the card
        for (int i = 13; i < 25; i++)
        {
            cin >> card[i/5][i%5];
        }
        
        //Will be updated when player wins
        bool notWon = true;

        //To evaluate the 75 draws
        for (int i = 1; i <= 75; i++)
        {
            //Take in the number drawn
            cin >> draw;

            //If won, just take in but ignore
            if (notWon)
            {
                //These hold coordinates of draw on card if found
                int drawRow = -1;
                int drawCol = -1;

                //Iterate through board
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        //Check if draw is on card
                        if (card[j][k] == draw)
                        {
                            //Update coordinates
                            drawRow = j;
                            drawCol = k;

                            //Set to 0, square completed
                            card[j][k] = 0;
                        }
                    }
                }
                
                //Continue here if the draw was found on board
                if (drawRow != -1 && drawCol != -1)
                {
                    //Keep track of the score in the draw's row and col
                    //Score of 5 means game has been won
                    int rowScore = 0;
                    int colScore = 0;

                    //Check the whole row and col, keep track of score
                    for (int x = 0; x < 5; x++)
                    {
                        if (card[drawRow][x] == 0) rowScore++;
                        if (card[x][drawCol] == 0) colScore++;
                    }

                    //If either reached 5, print the result
                    if (rowScore == 5 || colScore == 5)
                    {
                        cout << "BINGO after " << i << " numbers announced\n";
                        notWon = false; //Now rest of inputs will be taken in and ignored
                        continue; //Don't want to duplicate if multiple bingoes!!
                    }

                    //Checks diagonal in direction of backslash ("\")
                    //Only evaluate if row = col, which means it's on diagonal
                    if (drawRow == drawCol)
                    {
                        //Diagscore holds the score of the diagonal
                        int diagScore = 0;

                        //Check each square on the diagonal
                        for (int x = 0; x < 5; x++)
                        {
                            if (card[x][x] == 0) diagScore++;
                        }

                        //Same procedure if player has won
                        if (diagScore == 5)
                        {
                            cout << "BINGO after " << i+1 << " numbers announced\n";
                            notWon = false;
                            continue;
                        }
                    }

                    //Checks diagonal in direction of slash ("/")
                    //Only evaluate if row + col = 4, on diagonal
                    if (drawRow + drawCol == 4)
                    {
                        int diagScore = 0;

                        for (int x = 0; x < 5; x++)
                        {
                            if (card[x][4-x] == 0) diagScore++;
                        }

                        if (diagScore == 5)
                        {
                            cout << "BINGO after " << i+1 << " numbers announced\n";
                            notWon = false;
                            continue;
                        }
                    }
                }
            }
        }
    }
}