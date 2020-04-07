#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    //Initialize variables, take in cases
    int c, n, t, m, arrived;
    string dir;
    cin >> c;

    //Iterate c times
    while (c--)
    {
        //Take in n, t, m
        cin >> n >> t >> m;

        //Initialize a queue for left side and right side
        queue<pair<int, int>> left, right;

        //Iterate m times
        for (int i = 0; i < m; i++)
        {
            //Take in time and direction
            cin >> arrived >> dir;

            //Push the pair to the appropriate queue
            if (dir == "left") left.push({arrived, i});
            else right.push({arrived, i});
        }

        //Sol holds solution at right index, is m length
        vector<int> sol(m);
        bool isLeft = true; //Left bank or right bank currently
        int currentTime = 0; //Time at the moment

        //Keep going while there are cars
        while (!left.empty() || !right.empty())
        {
            int count = 0; //How many cars from one bank have been taken
            int first = INT_MAX; //Time next car arrives, take into account left and right
            if (!left.empty()) first = min(first, left.front().first);
            if (!right.empty()) first = min(first, right.front().first);

            currentTime = max(currentTime, first); //If I can skip to next car, I should

            //If we're on left bank
            if (isLeft)
            {
                //Keep going while left has cars, they arrived in time, and less than n
                while (!left.empty() && left.front().first <= currentTime && count < n)
                {
                    //It'll take t from now to get it to other bank
                    sol[left.front().second] = currentTime + t;

                    //Remove it, increment count
                    left.pop();
                    count++;
                }
            }

            //Same thing, but for right bank
            else
            {
                while (!right.empty() && right.front().first <= currentTime && count < n)
                {
                    sol[right.front().second] = currentTime + t;
                    right.pop();
                    count++;
                }
            }
            
            //Switch bank, I have to transport current cars
            isLeft = !isLeft;

            //Time to cross the bank
            currentTime += t;
        }

        //Output in the proper order and format
        for (int time : sol) cout << time << endl;
        if (c) cout << endl;
    }
}