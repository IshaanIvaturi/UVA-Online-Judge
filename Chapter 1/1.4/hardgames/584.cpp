#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //I have to go line by line since there are different numbers of inputs
    string line;
    getline(cin, line); //Take in a line of input to line variable

    //Keep going when line isn't game over
    while (line != "Game Over")
    {
        //This will hold the scores taken in
        vector<int> pins;

        //I go through line char by char
        for (char c : line)
        {
            //I don't care about spaces
            if (c == ' ') continue;

            if (c == 'X') pins.push_back(10); //A strike is a score of 10 initially
            else if (c == '/') pins.push_back(10 - pins.back()); //Spare fills in from prev number
            else pins.push_back(c - '0'); //Otherwise, score is just score
        }

        int i = 0; //i is used to index through the scores
        int f = 1; //f holds number of frames completed
        int score = 0; //This holds the current score

        //Keep going as long as you're under 10 frames
        while (f <= 10)
        {
            //If strike
            if (pins[i] == 10)
            {
                //Add 10 + the next 2 scores
                score += pins[i] + pins[i+1] + pins[i+2];
                i++; //Go to the next bowl
            }

            //If spare
            else if (pins[i] + pins[i+1] == 10)
            {
                //Add 10 (current 2 bowls) + next bowl
                score += pins[i] + pins[i+1] + pins[i+2];
                i += 2; //Go forward by 2 bowls
            }

            //Normal frame
            else
            {
                //Add the 2 scores for the frame
                score += pins[i] + pins[i+1];
                i += 2; //Go forward by 2 bowls
            }

            f++; //Increment frames 
        }

        //Output the score, and take in the next line
        cout << score << endl;

        getline(cin, line);
    }
}