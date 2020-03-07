#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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

int main()
{
    //I have to read by line due to spaces in input
    string s;

    //I take the line from cin into s
    getline(cin, s);

    //Keep going until I take in "DONE"
    while (s != "DONE")
    {
        //I iterate through characters to ignore
        for (char c : {'.', ',', '!', '?', ' '})
        {
            //I use STL to remove them from the string
            s.erase(remove(s.begin(), s.end(), c), s.end());
        }

        //Then, I use STL to convert all to same case
        transform(s.begin(), s.end(), s.begin(), ::toupper);

        //Test whether the remaining string is a palindrome
        //Output accordingly
        if (isPal(s)) cout << "You won't be eaten!\n";
        else cout << "Uh oh..\n";

        //Take in the next line
        getline(cin, s);
    }
}