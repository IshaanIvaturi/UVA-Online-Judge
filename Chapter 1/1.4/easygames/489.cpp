#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    //Initialize round #, solution string, and guess string
    int round;
    string solution, guesses;

    //Take in round #
    cin >> round;

    //Keep going till -1 is taken in
    while(round != -1)
    {
        //Take in solution and guesses
        cin >> solution >> guesses;

        //Blanks starts as spaces, but gets filled with correct guesses
        string blanks(solution.length(), ' ');
        
        //Keep track of guesses to avoid double penalties for same character
        set<char> guessed;

        int wrong = 0; //Count wrong guesses

        bool incomplete = true; //This holds whether something was printed or not yet

        //Go through guesses char by char
        for (char c : guesses)
        {
            //If already guessed, skip it
            if (guessed.find(c) != guessed.end()) continue;

            guessed.insert(c); //Otherwise insert to set

            //If blanks is solution, they guessed the word, so I output they won
            if (blanks == solution)
            {
                cout << "Round " << round << endl << "You win.\n";
                incomplete = false; //Something was printed
                break; //Break out, we're done
            }

            //If they reach 7 wrongs, they lose
            if (wrong == 7)
            {
                cout << "Round " << round << endl << "You lose.\n";
                incomplete = false;
                break;
            }

            //If guessed char isn't in solution, increment wrong
            if (solution.find(c) == string::npos)
            {
                wrong++;
                continue;
            }

            //If it's a correct guess, update blanks in right places
            for (int i = 0; i < solution.length(); i++)
            {
                if (solution[i] == c)
                {
                    blanks[i] = c;
                }
            }
        }

        //Now, at the end, simply evaluate the final results
        if (incomplete)
        {
            if (wrong >= 7) cout << "Round " << round << endl << "You lose.\n";
            else if (blanks == solution) cout << "Round " << round << endl << "You win.\n";
            else cout << "Round " << round << endl << "You chickened out.\n";
        }

        //Take in next round
        cin >> round;
    }
}