#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

//Initial, target, i's and o's, current string from stack
string s1, s2, io, s; 

//Size of strings, index to push, number of i's already
int n, ind, iCount;

//Stack of char to simulate the stack operations
stack<char> simul;

//Uses a DFS and quickly prunes incorrect solution paths
void solve()
{
    //If current string is target, I can output the operations
    if (s == s2)
    {
        //Output i's and o's properly spaced, it's of length 2*n
        cout << io[0];
        for (int i = 1; i < 2*n; i++) cout << " " << io[i];
        cout << endl;
        return; //This branch is complete, I return back
    }

    //If I haven't used up all my inputs
    if (iCount < n)
    {
        simul.push(s1[ind]); //push the current index to the stack
        ind++; //Increment ind for next time
        io += 'i'; //Add an i to the io string
        iCount++; //Increment my number of inputs

        solve(); //Recursively call solve from this new state

        //Reverse all these actions and move on
        simul.pop();
        ind--;
        io.pop_back();
        iCount--;
    }

    //If it's possible to output
    if (!simul.empty())
    {
        //I add the top of stack to my current string
        s += simul.top();

        //If s is not on the right path to s2, I reverse and move on
        if (s != s2.substr(0, s.size())) s.pop_back();

        //Otherwise...
        else
        {
            simul.pop(); //Remove the top of the stack
            io += 'o'; //Add o to io sequence

            solve(); //Call solve from this state

            //Reverse what I've done and move on
            simul.push(s[s.size()-1]);
            s.pop_back();
            io.pop_back();
        }
    }
}

//Checks if 2 strings are anagrams by sorting comparing
bool anagrams(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main()
{
    //Keep taking in initial and target
    while (cin >> s1 >> s2)
    {
        cout << "[\n"; //Output first bracket

        //Only need to test if anagrams, otherwise useless
        if (anagrams(s1, s2))
        {
            io = "i"; //Always start with 1 inputted
            s = ""; //s starts empty
            n = s1.size(); //n is size of one string
            ind = 1; //Index 0 is already inputted
            iCount = 1; //1 i so far
            simul.push(s1[0]); //Push the first element

            solve(); //Solve the entire tree

            simul.pop(); //Pop the initial first element 
        }

        cout << "]\n"; //Closing bracket
    }
}