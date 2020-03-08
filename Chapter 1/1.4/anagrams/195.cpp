#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//This comparator provides the desired sorting behavior
bool compareStr(char a, char b)
{
    //If they aren't the same letter, ignore case entirely
    if (tolower(a) - tolower(b) != 0) return tolower(a) < tolower(b); 

    //If they are, sort lexographically, by uppercase first
    else return a < b;
}

int main()
{
    //Initialize variables
    int n;
    string s;

    //Take in number of words
    cin >> n;

    //Iterate n times
    while (n--)
    {
        //Take in the string
        cin >> s;

        //Sort it with my custom comparator
        sort(s.begin(), s.end(), compareStr);

        //This do while goes through all permutations
        do
        {
            //Output the current string
            cout << s << endl;
        }

        //Get the next lexographical permutation ACCORDING TO my comparator
        while (next_permutation(s.begin(), s.end(), compareStr));
    }
}