#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize variables and take in t
    int t, n, m;
    char c;
    cin >> t;

    //Iterate t times
    while (t--)
    {
        //Take in piece and board dimensions
        cin >> c >> n >> m;

        //For a rook, it will fill in all of the smaller between rows and cols
        if (c == 'r')
        {
            //All I need is the min function
            cout << min(n, m) << endl;
            continue;
        }

        //For knight, every black/white square will do
        if (c == 'k')
        {
            //If n*m is even, I need half, so +1 is truncated
            //If n*m is odd, I want the larger half, so +1
            cout << (n * m + 1) / 2 << endl;
            continue;
        }

        //Queen is same deal as rook for n, m >= 4, diagonals are avoidable
        if (c == 'Q')
        {
            cout << min(n, m) << endl;
            continue;
        }

        //King is every other square in both rows and cols
        if (c == 'K')
        {
            //Once again, +1 for odd cases, but half of n * half of m
            cout << ((n + 1) / 2) * ((m + 1) / 2) << endl;
            continue;
        }
    }
}