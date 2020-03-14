#include <iostream>

using namespace std;

//Will hold whether diffs from 1 to n-1 are present
bool diffs[3005];

//Checks if diffs is all true from 1 to n-1
bool allTrue(int n)
{
    //Check from 1 to n-1
    for (int i = 1; i < n; i++)
    {
        //Return false if any are false
        if (!diffs[i]) return false;
    }

    //Then return true if it gets through
    return true;
}

int main()
{
    //n is number of #'s, x is taken in, prev is previous number
    int n, x, prev;
    
    //Keep going while n is fed
    while (cin >> n)
    {
        //Take the first number into prev
        cin >> prev;

        //Reset diffs to false
        for (int i = 0; i < 3005; i++) diffs[i] = false;

        //Iterate n-1 times
        for (int i = 1; i < n; i++)
        {
            //Take in x, update diffs for difference, set to prev
            cin >> x;
            diffs[abs(x-prev)] = true;
            prev = x;
        }

        //If all from 1 to n-1 true, output jolly
        if (allTrue(n)) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
}