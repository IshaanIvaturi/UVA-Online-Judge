#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize t and take in
    int t;
    cin >> t;

    //Go from case 1 to case t
    for (int c = 1; c <= t; c++)
    {
        //cards will hold the card strings, temp will be used to cin them
        vector<string> cards;
        string temp;

        //Start with y = 0
        int y = 0;

        //Take in 52 cards and push them to vector
        for (int i = 0; i < 52; i++)
        {
            cin >> temp;
            cards.push_back(temp);
        }
        
        //With 25 cards removed from the end of list, the current "top" is index 26
        int index = 26;
        int x = 0; //Initialize x

        //Procedure 3 times
        for (int i = 0; i < 3; i++)
        {
            //Extract the value from char by subtracting '0'
            int value = cards[index][0] - '0';

            //If the value was numerical, x = value, otherwise it's 10
            if (value >= 2 && value <= 9) x = value;
            else x = 10;

            //Increment y by x
            y += x;

            //Remove 10 - x cards from the "top", plus 1 for current card
            for (int j = 0; j < 10 - x + 1; j++)
            {
                cards.erase(cards.begin()+index);
                index--; //Now the top moves down
            }
        }

        //Output the card at position y, or index y-1
        cout << "Case " << c << ": " << cards[y-1] << endl;
    }
}