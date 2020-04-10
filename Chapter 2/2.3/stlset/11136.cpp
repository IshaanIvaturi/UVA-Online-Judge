#include <iostream>
#include <set>

using namespace std;

int main()
{
    //Initialize variables, and multiset to simulate
    long long n, k, a, cost;
    multiset<int> bills;
    
    //Keep taking in n until it's 0
    while (cin >> n && n != 0)
    {
        //clear my multiset, and set cost back to 0
        bills.clear();
        cost = 0;

        //For each day
        while (n--)
        {
            //Take in number of new entries
            cin >> k;
            
            //Insert to bills
            while (k--)
            {
                cin >> a;
                bills.insert(a);
            }

            //Add end - begin to cost
            cost += *bills.rbegin() - *bills.begin();

            //Remove begin and end
            bills.erase(bills.begin());
            bills.erase(prev(bills.end()));
        }

        //Output the cost
        cout << cost << endl;
    }
}