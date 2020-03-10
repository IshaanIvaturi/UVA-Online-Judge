#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//Grid holds the current page array of chars
char grid[60][60];

//Maps each char to a vector<string> of its large counterpart
//This part was so tedious xd
map<char, vector<string>> bigChar =
{
    {'A', {".***..", "*...*.", "*****.", "*...*.", "*...*."}},
    {'B', {"****..", "*...*.", "****..", "*...*.", "****.."}},
    {'C', {".****.", "*...*.", "*.....", "*.....", ".****."}},
    {'D', {"****..", "*...*.", "*...*.", "*...*.", "****.."}},
    {'E', {"*****.", "*.....", "***...", "*.....", "*****."}},
    {'F', {"*****.", "*.....", "***...", "*.....", "*....."}},
    {'G', {".****.", "*.....", "*..**.", "*...*.", ".***.."}},
    {'H', {"*...*.", "*...*.", "*****.", "*...*.", "*...*."}},
    {'I', {"*****.", "..*...", "..*...", "..*...", "*****."}},
    {'J', {"..***.", "...*..", "...*..", "*..*..", ".**..."}},
    {'K', {"*...*.", "*..*..", "***...", "*..*..", "*...*."}},
    {'L', {"*.....", "*.....", "*.....", "*.....", "*****."}},
    {'M', {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."}},
    {'N', {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."}},
    {'O', {".***..", "*...*.", "*...*.", "*...*.", ".***.."}},
    {'P', {"****..", "*...*.", "****..", "*.....", "*....."}},
    {'Q', {".***..", "*...*.", "*...*.", "*..**.", ".****."}},
    {'R', {"****..", "*...*.", "****..", "*..*..", "*...*."}},
    {'S', {".****.", "*.....", ".***..", "....*.", "****.."}},
    {'T', {"*****.", "*.*.*.", "..*...", "..*...", ".***.."}},
    {'U', {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."}},
    {'V', {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."}},
    {'W', {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."}},
    {'X', {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."}},
    {'Y', {"*...*.", ".*.*..", "..*...", "..*...", "..*..."}},
    {'Z', {"*****.", "...*..", "..*...", ".*....", "*****."}},
    {' ', {"......", "......", "......", "......", "......"}}
};

//Types the sentence in C5 with top left at coords row, col
void typeBig(string sentence, int row, int col)
{
    //Go through each character in the sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        //The tlCol holds the current col of the top left of character
        //Increments by 6 per character, since they're 6 wide
        int tlCol = col + i*6;

        //Go through the 5 rows and 6 cols of each character
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                //If it's within bounds and asterisk, update the grid. Otherwise, do nothing
                if (row+j < 60 && tlCol+k >= 0 && tlCol+k < 60 && bigChar[sentence[i]][j][k] == '*') grid[row+j][tlCol+k] = '*';
            }
        }
    }
}

//Types the sentence in C1 with top left at coords row, col
void typeSmall(string sentence, int row, int col)
{
    //Go through each character
    for (int i = 0; i < sentence.length(); i++)
    {
        //Do nothing for spaces
        if (sentence[i] == ' ') continue;

        //If within grid, update with the proper character
        if (col+i < 60) grid[row][col+i] = sentence[i];
    }
}

int main()
{
    //Fill grid with periods initially
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++) grid[i][j] = '.';
    }

    //Initialize variables
    string format, font, sentence;
    int row, col;
    char c;

    //Keep taking in the command for format
    while (cin >> format)
    {
        //End of page signal
        if (format == ".EOP")
        {
            //Go through whole grid
            for (int i = 0; i < 60; i++)
            {
                for (int j = 0; j < 60; j++) 
                {
                    //Print the character and reset to blank
                    cout << grid[i][j]; 
                    grid[i][j] = '.';
                }
                cout << endl;
            }
            
            //Need an extra blank line after grid
            cout << endl;

            //And a line of dashes
            for (int i = 0; i < 60; i++) cout << '-';

            //And another 2 blank lines
            cout << endl << endl;

            //Go right to the next command
            continue;
        }

        //Set sentence to blank for now
        sentence = "";

        //Take in the font number and row number
        cin >> font >> row;
        row--; //Subtract by 1 to account for indexing by 1

        //.P is the only one that gives col directly, so take it in
        if (format == ".P") cin >> col; col--;

        //Read but ignore the space before sentence and the |
        cin.get(c);
        cin.get(c);

        //Keep reading characters...
        while (cin.get(c))
        {
            //Until the 2nd |
            if (c == '|') break;

            //Add to the sentence
            sentence += c;
        }

        //For left justified, col is just 0
        if (format == ".L") col = 0;

        //For right justified...
        if (format == ".R")
        {
            //Small font means just subtract from 60
            //It's ok if it's negative, because my method just doesn't do anything there
            if (font == "C1") col = 60 - sentence.length();

            //Big font means we have to scale up sentence by 6
            else col = 60 - (sentence.length() * 6);
        }

        //For centered...
        if (format == ".C")
        {
            //For small font, start from half the grid size - half the sentence length
            if (font == "C1") col = 30 - sentence.length()/2;

            //Once again scale up by 6 for large
            else col = 30 - (sentence.length()*6)/2;
        }

        //Call my type methods accordingly
        if (font == "C1") typeSmall(sentence, row, col);
        else typeBig(sentence, row, col);
    }
}