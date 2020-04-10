#include <iostream>
#include <queue>

using namespace std;

int main()
{
    //Initialize variables
    int n, x, a, b;

    //Set up a priority queue to keep smallest element at top
    priority_queue<int, vector<int>, greater<int>> smallest;
    
    //Keep taking in n until it's 0
    while (cin >> n && n != 0)
    {
        //Take in all the values and push them to pq
        while (n--)
        {
            cin >> x;
            smallest.push(x);
        }

        //Cost holds the solution
        int cost = 0;

        //Keep going as long as the priority queue has 2 elements to add
        while (smallest.size() >= 2)
        {
            //Replace the 2 smallest with their sum in priority queue
            //It's optimal to add the smallest values possible
            a = smallest.top();
            smallest.pop();
            b = smallest.top();
            smallest.pop();
            smallest.push(a+b);

            //Add their sum to cost
            cost += a+b;
        }

        //Pop off the final sum, don't need it
        smallest.pop();

        //Output the cost
        cout << cost << endl;
    }
}