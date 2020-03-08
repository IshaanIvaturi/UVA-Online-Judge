#include <iostream>

using namespace std;

int main()
{
    //n is queries, sum = sum of scores, diff = diff of scores
    int n, sum, diff;

    cin >> n; //Take in n

    //Iterate n times
    while (n--)
    {
        //Take in sum and diff
        //Do the math, solutions are (sum + diff) / 2, (sum - diff) / 2
        cin >> sum >> diff;

        //Can't have negative or non integer solution!
        if (sum < diff || (sum + diff) % 2 == 1) cout << "impossible\n";

        //Otherwise just output from formula derived
        else cout << (sum + diff) / 2 << " " << (sum - diff) / 2 << endl;
    }
}