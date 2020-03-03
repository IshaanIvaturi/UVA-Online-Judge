#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize and take in variables
    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    //Keep going till a gets input as 0
    while (a != 0)
    {
        int sol; //Will hold the answer

        //There's only 6 combinations for a, b, c to be compared to x, y, sol; so I programmed them in
        vector<vector<int>> orders = {{a, b, c}, {a, c, b}, {b, a, c}, {b, c, a}, {c, a, b}, {c, b, a}};

        //I go through each possibility and see what sol needs to be at least
        for (vector<int> order : orders)
        {
            int score = 0; //Holds how many out of 3 prince wins

            //X is compared to first num and Y is compared to second num
            if (x > order[0]) score++;
            if (y > order[1]) score++;

            if (score == 0) sol = 100; //If he has won 0 of the 2, it's impossible to win, so sol is set to large num
            if (score == 2)
            {
                //If he has won 2 of 2, he will win no matter what
                int card = 1;

                //I iterate through all the cards from the lowest 
                while(card <= 52)
                {
                    //If the card is already in play, I can't use it so I increment
                    if (a == card || b == card || c == card || x == card || y == card)
                    {
                        card++;
                    }
                    //Otherwise I just set sol to the max of the current sol and this low value since sol is worst case
                    else
                    {
                        sol = max(sol, card);
                        break;
                    } 
                }
            }
            if (score == 1)
            {
                //If he has won 1, it's possible to win since he needs to win last round

                //I start card at smallest value, 1 above his sister
                int card = order[2] + 1;
                bool flag = true; //This keeps track of if a card is found

                //Keep going till card 52, where no card is found
                while(card <= 52)
                {
                    //Can't use card in play
                    if (a == card || b == card || c == card || x == card || y == card)
                    {
                        card++;
                    }

                    //Card was found, set sol to max of current and this, set off flag
                    else
                    {
                        sol = max(sol, card);
                        flag = false;
                        break;
                    } 
                }

                //If flag wasn't set off set sol to large number, can't win
                if (flag) sol = 100;
            }
        }
        
        //If sol is 100, output -1, otherwise output sol
        if (sol != 100) cout << sol << endl;
        else cout << -1 << endl;

        //Take in variables for next test case
        cin >> a >> b >> c >> x >> y;
    }
}