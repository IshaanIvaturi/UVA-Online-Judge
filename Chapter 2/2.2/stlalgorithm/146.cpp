#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //Initialize s, take it in
    string s;
    cin >> s;

    //Keep going until s is #
    while (s != "#")
    {
        //If there's another permutation, output that permutation
        if (next_permutation(s.begin(), s.end())) cout << s << endl;

        //Otherwise output no successor
        else cout << "No Successor\n";

        //Take in the next s
        cin >> s;
    }
}