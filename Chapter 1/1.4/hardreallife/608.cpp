#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//Takes in balance conditions and weights of each char
//Returns whether the current weights satisfy all conditions
bool satisfiesBal (vector<vector<string>> &balances, map<char, int> &weights)
{
    //Go through each set of balance conditions
    //Each one is {string 1, string 2, even/down/up}
    for (vector<string> balance : balances)
    {
        //These will hold the final weights of each side of the balance
        int score1 = 0;
        int score2 = 0;

        //Go through the strings and add the weight of each char to score
        for (char c : balance[0]) score1 += weights[c];
        for (char c : balance[1]) score2 += weights[c];

        //If the score comparisons don't match up with the even/down/up, false
        if (score1 == score2 && balance[2] != "even") return false;
        if (score1 < score2 && balance[2] != "down") return false;
        if (score1 > score2 && balance[2] != "up") return false;
    }

    //If it gets here, it satisifed all conditions
    return true;
}

int main()
{
    //Initialize variables, take in n
    string s1, s2, bal;
    int n;
    cin >> n;

    //Iterate n times
    while (n--)
    {
        //This will hold the input strings and verdict
        vector<vector<string>> balances;

        //Go through the 3 balances
        for (int i = 0; i < 3; i++)
        {
            //Take in strings and balance, push into balances
            cin >> s1 >> s2 >> bal;
            vector<string> temp = {s1, s2, bal};
            balances.push_back(temp);
        }

        //This holds the "weight" of each character for simulation
        map<char, int> weights;

        //For each character, set weight to 0
        for (char c : "ABCDEFGHIJKL") weights[c] = 0;

        //Go through each character
        for (char c : "ABCDEFGHIJKL")
        {
            //Simulate that char being lighter
            weights[c] = -1;

            //If this satisfies all conditions, output and break out
            if (satisfiesBal(balances, weights))
            {
                cout << c << " is the counterfeit coin and it is light.\n";
                break;
            }

            //Simulate that char being heavier
            weights[c] = 1;

            if (satisfiesBal(balances, weights))
            {
                cout << c << " is the counterfeit coin and it is heavy.\n";
                break;
            }

            //Set the weight back to 0 and continue
            weights[c] = 0;
        }
    }
}