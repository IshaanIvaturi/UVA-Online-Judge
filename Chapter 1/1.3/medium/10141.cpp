#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize variables and take in n and p
    int n, p, r;
    double d;
    string temp, name;

    //I use getline to clear the \n left by scanf
    scanf("%d %d", &n, &p);
    getline(cin, temp);

    //Case 1
    int RFP = 1;

    //Keep going till n is input to 0
    while (n != 0)
    {
        //Extra endl when it's not first case
        if(RFP > 1) cout << endl;
        for (int i = 0; i < n; i++) getline(cin, temp); //These lines are all useless to me

        //Keep track of the best offer with these variables
        string bestName;
        int bestR;
        double bestPrice;

        //Fill with the first offer
        getline(cin, bestName);
        scanf("%f %d", &bestPrice, &bestR);
        getline(cin, temp);

        //Useless strings
        for (int j = 0; j < bestR; j++) getline(cin, temp);

        //Continue for rest of offers
        for (int i = 1; i < p; i++)
        {
            getline(cin, name);
            scanf("%f %d", &d, &r);
            getline(cin, temp);

            //If r is better, update all variables
            if (r > bestR)
            {
                bestName = name;
                bestR = r;
                bestPrice = d;
            }
            //If r is the same and cost is less, update all variables
            else if (r == bestR && d < bestPrice)
            {
                bestName = name;
                bestR = r;
                bestPrice = d;
            }

            //Useless lines
            for (int j = 0; j < r; j++) getline(cin, temp);
        }

        //Output best offer, scan new variables, and increment case number
        cout << "RFP #" << RFP << endl;
        cout << bestName << endl;

        scanf("%d %d", &n, &p);
        getline(cin, temp);
        RFP++;
    }

    return 0;
}