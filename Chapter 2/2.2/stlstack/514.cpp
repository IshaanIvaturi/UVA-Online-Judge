#include <iostream>
#include <stack>

using namespace std;

int main()
{
    //initialize n, and an array larger than max goal size
    int n, wanted[1005];

    //Take in n, and use n not 0 as condition for loop
    while (cin >> n, n != 0)
    {
        //Take in first wanted, use not 0 as condition
        while (cin >> wanted[0], wanted[0] != 0)
        {
            //Take in the rest of the goal
            for (int i = 1; i < n; i++) cin >> wanted[i];

            //Use stack to simulate
            stack<int> track;

            //Current is current starting car, index is where we are in result train
            int current = 1, index = 0;

            //Keep going until current hits n
            while (current <= n)
            {
                //Add the car to the stack
                track.push(current);

                //Keep going while there are cars and right order
                while (!track.empty() && track.top() == wanted[index] && index < n)
                {
                    //Remove the car, increment index
                    track.pop();
                    index++;
                }

                //Increment current now, to add next starting car
                current++;
            }

            //If the stack is empty, all cars were placed, so yes
            if (track.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

        //Extra line after each set
        cout << endl;
    }
}