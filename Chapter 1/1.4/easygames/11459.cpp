#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //Initialize variables and take in t
    int t, a, b, c, roll;

    cin >> t;

    //Iterates t times
    while (t--)
    {
        //Take in players, snakes/ladders, rolls
        cin >> a >> b >> c;

        //Destination array, will be used for snakes/ladders
        int dest[100];

        //Set each index to its own value
        for (int i = 0; i < 100; i++) dest[i] = i;

        //Iterates for number of snakes/ladders
        while (b--)
        {
            //Start, end of snake/ladder
            int start, end;

            //Take in and subtract 1 to account for 0 indexing
            cin >> start >> end;
            start--;
            end--;

            //The destination from the start should map to the end
            //Those without a portal origin map to themselves, for no change
            dest[start] = end;
        }

        //This holds the locations of a players, all start at 0
        vector<int> pos(a);

        //This will be modded around to increment the right player
        int currentPlayer = 0;

        //Tells the program that there's no winner yet
        bool noWinner = true;

        //Iterates for each roll
        while (c--)
        {
            //Take in the roll
            cin >> roll;

            //If winner found, it just takes in rolls and ignores
            //Otherwise, it runs the code for each roll
            if (noWinner)
            {
                //Mod by a to get the right player, add to their position
                pos[currentPlayer % a] += roll;

                //If they've passed 99, set them back to stay in bounds of dest array
                if (pos[currentPlayer % a] >= 99)
                {
                    pos[currentPlayer % a] = 99;
                }

                //This will perform the snake/ladder function, mapping to the right square
                pos[currentPlayer % a] = dest[pos[currentPlayer % a]];

                //If a player has won
                if (pos[currentPlayer % a] >= 99)
                {
                    //Output current info of all players
                    for (int i = 0; i < a; i++)
                    {
                        cout << "Position of player " << i+1 << " is " << pos[i]+1 << ".\n";
                    }

                    //Now it will take in rest of values but ignore them
                    noWinner = false;
                }
            }

            //Increment player each roll
            currentPlayer++;
        }
        
        //If all rolls complete and still no winner
        if (noWinner)
        {
            //Simply display all the current positions
            for (int i = 0; i < a; i++)
            {
                cout << "Position of player " << i+1 << " is " << pos[i]+1 << ".\n";
            }
        }
    }
}