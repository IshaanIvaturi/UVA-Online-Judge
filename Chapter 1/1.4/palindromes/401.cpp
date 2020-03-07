#include <iostream>
#include <string>
#include <map>

using namespace std;

//This map holds all characters and their reverses conveniently
//I used 0 for no reverse since it's an invalid character in the problem
map<char, char> mirror =
{
    {'A', 'A'}, {'B', '0'}, {'C', '0'}, {'D', '0'}, {'E', '3'}, {'F', '0'}, {'G', '0'},
    {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'K', '0'}, {'L', 'J'}, {'M', 'M'}, {'N', '0'},
    {'O', 'O'}, {'P', '0'}, {'Q', '0'}, {'R', '0'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, 
    {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'}, 
    {'3', 'E'}, {'4', '0'}, {'5', 'Z'}, {'6', '0'}, {'7', '0'}, {'8', '8'}, {'9', '9'}
};

//Checks if string is a palindrome
bool isPal (string s)
{
    //Only have to go up to half the length
    //Even if odd and middle truncated, it doesn't matter
    for (int i = 0; i < s.length() / 2; i++)
    {
        //Check if it's equal to the opposite side
        if (s[i] != s[s.length()-i-1]) return false;
    }

    //If it passed the test, it's true
    return true;
}

//Checks if string is mirrored
bool isMir (string s)
{
    //I have to include the middle if odd
    int lenToCheck = (s.length() - 1) / 2 + 1;

    for (int i = 0; i < lenToCheck; i++)
    {
        //I use the mirror map and check symmetry
        if (s[i] != mirror[s[s.length()-i-1]]) return false;
    }

    //Return true if passed
    return true;
}

int main()
{
    //I store input in s
    string s;

    //Keep taking in s
    while (cin >> s)
    {
        //These hold whether s is palindrome or mirror
        bool pal = isPal(s);
        bool mir = isMir(s);

        //For each case, I output the proper judgement
        //I add an extra endline after lines
        if (!pal && !mir)
        {
            cout << s << " -- is not a palindrome.\n\n";
        }
        else if (pal && !mir)
        {
            cout << s << " -- is a regular palindrome.\n\n";
        }
        else if (!pal && mir)
        {
            cout << s << " -- is a mirrored string.\n\n";
        }
        else
        {
            cout << s << " -- is a mirrored palindrome.\n\n";
        }
    }
}