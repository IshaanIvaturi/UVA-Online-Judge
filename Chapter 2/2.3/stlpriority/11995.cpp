#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    //Initialize variables
    int n, type, x;

    //Keep taking in n
    while (cin >> n)
    {
        //Initialize data structures
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        //And vectors to hold them, as well as actual order
        vector<int> sv, qv, pqv, actual;
        
        //Whether there was an invalid operation
        bool possible = true;

        //Iterate n times
        while (n--)
        {
            //Take in type and value
            cin >> type >> x;

            //If already invalid operation, skip
            if (!possible) continue;

            //If 1, push x to all 
            if (type == 1)
            {
                s.push(x);
                q.push(x);
                pq.push(x);
            }

            //If 2, check for invalid, or push to corresponding vector
            else if (type == 2)
            {
                if (s.empty())
                {
                    cout << "impossible\n";
                    possible = false;
                    continue;
                }
                sv.push_back(s.top());
                qv.push_back(q.front());
                pqv.push_back(pq.top());
                s.pop();
                q.pop();
                pq.pop();
                actual.push_back(x);
            }
        }
        
        //If it was impossible, ignore this
        if (!possible) continue;

        //Check how many vectors matched the actual
        int matches = 0;
        if (sv == actual) matches++;
        if (qv == actual) matches++;
        if (pqv == actual) matches++;

        //If none matched, impossible, if more matched, not sure
        if (matches == 0) cout << "impossible\n";
        else if (matches > 1) cout << "not sure\n";

        //Otherwise, print the one which matched
        else
        {
            if (sv == actual) cout << "stack\n";
            if (qv == actual) cout << "queue\n";
            if (pqv == actual) cout << "priority queue\n";
        }
    }
}