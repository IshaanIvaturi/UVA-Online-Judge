#include <iostream>
#include <queue>

using namespace std;

int main()
{
    //Initialize variables, take in number of cases
    int c, l, m, length;
    string dir;
    cin >> c;

    //Iterate c times
    while (c--)
    {
        //Take in l and m, multiply l by 100 to get in cm
        cin >> l >> m;
        l *= 100;

        //Queues for both banks
        queue<int> left, right;

        //Based on direction, for each car put in right queue
        while (m--)
        {
            cin >> length >> dir;

            if (dir == "left") left.push(length);
            else right.push(length);
        }

        //Crosses keeps track of sol, isLeft keeps track of side
        int crosses = 0;
        bool isLeft = true;

        //Go till both are empty
        while (!left.empty() || !right.empty())
        {
            //How much length in the ferry is taken up
            int currentLen = 0;

            //If left bank
            if (isLeft)
            {
                //Keep going while there's space
                while (!left.empty() && currentLen + left.front() <= l) 
                {
                    //Add to the space, pop off left side
                    currentLen += left.front();
                    left.pop();
                }
            }

            //Same for right bank
            else
            {
                while (!right.empty() && currentLen + right.front() <= l) 
                {
                    currentLen += right.front();
                    right.pop();
                }
            }
            
            //Increment crosses, change side of bank
            crosses++;
            isLeft = !isLeft;
        }

        //Output crosses
        cout << crosses << endl;
    }
}