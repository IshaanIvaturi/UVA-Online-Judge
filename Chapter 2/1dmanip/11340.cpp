#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    //Initialize variables and take in n
    int n, k, p, m;
    char c;
    string s;
    cin >> n;

    //Iterate n times
    while (n--)
    {
        //Set up a map for prices of each char
        //Unentered prices are automatically 0
        map<char, int> prices;

        //Take in k and iterate k times
        cin >> k;
        while (k--)
        {
            //Take in c and p, set price of c to p
            cin >> c >> p;
            prices[c] = p;
        }

        //Take in m, and get rid of \n left by cin
        cin >> m;
        cin.ignore(256, '\n');

        //Initialize var to hold cost in cents
        int cost = 0;

        //Iterate m times
        while (m--)
        {
            //Take in a line, add cost per character
            getline(cin, s);
            for (char ch : s) cost += prices[ch];
        }

        //Output in proper format, dividing cost by 100 for $ and mod for cents
        printf("%d.%02d$\n", cost / 100, cost % 100);
    }
}