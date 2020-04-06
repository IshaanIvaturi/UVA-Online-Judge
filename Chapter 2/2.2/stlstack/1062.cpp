#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    //String to hold input and current case
    string s;
    int caseNum = 1;

    //Take in s until you hit end
    while (cin >> s && s != "end")
    {
        //Max number of stacks is 26, store in vector
        vector<stack<char>> stacks(26);
        int used = 0; //Keeps track of how many stacks used

        //Go through each character
        for (char c : s)
        {
            //Go through each stack
            for (int i = 0; i < 26; i++)
            {
                //If new stack or the top loads after c, c can be pushed
                if (stacks[i].empty() || stacks[i].top() >= c) 
                {
                    //Reached new stack means we used 1 more
                    if (stacks[i].empty()) used++;
                    stacks[i].push(c); //Push c to the stack it landed on
                    break; //break out
                }
            }
        }
        
        //Output case number and number of stacks used, increment case
        cout << "Case " << caseNum << ": " << used << endl;
        caseNum++;
    }
}