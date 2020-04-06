#include <iostream>
#include <list>

using namespace std;

int main()
{
    //This holds each line
    string s;

    //Keep taking in lines
    while (cin >> s)
    {
        //Initialize a linked list for solution
        list<char> beiju;

        //This iterator will be the "cursor", starts at beginning
        auto it = beiju.begin();

        //Go through string char by char
        for (char c : s)
        {
            //If [, jump to beginning
            if (c == '[') it = beiju.begin();

            //If ], jump to end
            else if (c == ']') it = beiju.end();

            //Otherwise, insert the character at cursor
            else beiju.insert(it, c);
        }

        //Output the whole list
        for (char c : beiju) cout << c;
        cout << endl;
    }
}