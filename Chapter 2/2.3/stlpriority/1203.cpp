#include <iostream>
#include <queue>

using namespace std;

int main()
{
    //Initialize variables
    string s;
    int qnum, period, k;

    //Priority queue to hold (next time, id) and period
    priority_queue<pair<pair<int, int>, int>> argus;

    //Keep taking in register until the #
    while (cin >> s && s != "#")
    {
        //Take in the id and period
        cin >> qnum >> period;

        //Next time starts with period, id stays same, and I add period to pair
        //I multiply by -1 to get the lowest time for next remind, not highest
        //It will prioritize next remind, then lowest qnum otherwise
        argus.push({{period * -1, qnum * -1}, period});
    }

    //Take in k
    cin >> k;

    //Iterate k times
    while (k--)
    {
        //Highest priority element is next, pop it off argus
        auto next = argus.top();
        argus.pop();

        //Update its time by period, it's negative so subtract, push new to argus
        next.first.first -= next.second;
        argus.push(next);

        //Output the id number
        cout << next.first.second * -1 << endl;
    }
}