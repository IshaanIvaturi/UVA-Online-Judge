#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    //Set up variables, and take in # of test cases
    int set, n, s, q, qi, temp;
    cin >> set;

    //Iterate for test cases
    while (set--)
    {
        //Take in n, s, q
        cin >> n >> s >> q;

        //platB for n stations is a queue, carrier is a stack
        vector<queue<int>> platB(n);
        stack<int> carrier;

        //Go through all n stations
        for (int i = 0; i < n; i++)
        {
            //Take in number of cargos
            cin >> qi;

            while (qi--)
            {
                //Push 1 less to proper queue for 0 indexing
                cin >> temp;
                platB[i].push(temp-1);
            }
        }
        
        //Current station, current time
        int station = 0, time = 0;

        //Keep going till done
        while (true)
        {
            //If next in carrier is correct station, we won't add to queue anyway
            while (!carrier.empty() && (platB[station].size() < q || carrier.top() == station))
            {
                //If it goes to platform b, push it accordingly, pop, increment time
                if (carrier.top() != station) platB[station].push(carrier.top());
                carrier.pop();
                time++;
            }

            //Load from platform as long as you can
            while (!platB[station].empty() && carrier.size() < s)
            {
                //Push from station, pop from station, increment time
                carrier.push(platB[station].front());
                platB[station].pop();
                time++;
            }

            //Simply check whether the carrier and all queues are empty
            bool allEmpty = carrier.empty();

            for (int i = 0; i < n; i++)
            {
                if (!platB[i].empty())
                {
                    allEmpty = false;
                    break;
                }
            }
            
            //If so, break out
            if (allEmpty) break;

            //Otherwise, move to next station with modulo
            time += 2;
            station = (station + 1) % n;
        }

        //Output total time
        cout << time << endl;
    }
}