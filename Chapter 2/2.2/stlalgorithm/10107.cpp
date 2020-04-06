#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //v will hold all nums, x will hold each num
    vector<int> v;
    int x;

    //Keep taking in x
    while (cin >> x)
    {
        //Push into vector
        v.push_back(x);

        //Put the middle element for odd size in right place
        nth_element(v.begin(), v.begin() + v.size() / 2, v.end());

        //If odd size
        if (v.size() % 2 == 1)
        {
            //Output the middle element
            cout << v[v.size()/2] << endl;
        }

        //If even size
        else
        {
            //Put the other middle element in right place
            nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());

            //Output the truncated average, not just middle element
            cout << (v[v.size()/2-1] + v[v.size()/2]) / 2 << endl;
        }
    }
}