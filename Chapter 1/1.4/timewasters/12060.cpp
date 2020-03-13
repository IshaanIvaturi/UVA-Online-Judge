#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Finds the gcf of 2 numbers
int gcf(int a, int b)
{
    //If the numbers divided evenly, return that divisor
    if (b == 0) return a;

    //Otherwise mod a by b and then run it again, till you reach even division
    a %= b;

    //Reverse the order since now b is bigger than a, keep reducing till solution
    return gcf(b, a);
}

int main()
{
    //Initialize parts of fraction, take in n as denomenator
    int denom, numer, whole, temp;
    cin >> denom;

    //Will increment caseNum for output
    int caseNum = 1;

    //Keep going until it feeds a 0 for denom
    while (denom != 0)
    {
        //Numerator starts at 0
        numer = 0;

        //Go denom number of times
        for (int i = 0; i < denom; i++)
        {
            //Take in next number, add it to numerator
            cin >> temp;
            numer += temp;
        }

        //Now find gcf of my improper fraction
        int div = abs(gcf(denom, numer));

        //Get fraction into lowest terms
        numer /= div;
        denom /= div;

        //Whole number part is trucated division, mod numerator
        whole = numer / denom;
        numer %= denom;

        //Will use lengths of numerator and denomenator later
        int denomLen = to_string(denom).length();
        int numerLen = to_string(abs(numer)).length(); //Need abs in case negative

        //Output the case number
        cout << "Case " << caseNum << ":\n";

        //If a whole number
        if (numer == 0)
        {
            //Output dash if negative, then abs of whole number
            if (whole < 0) cout << "- ";
            cout << abs(whole) << endl;
        }

        //If just a fraction
        else if (whole == 0)
        {
            //Make space if negative
            if (numer < 0) cout << "  ";
            //Add extra spaces for numerator if denom longer
            for (int i = 0; i < denomLen-numerLen; i++) cout << " ";
            //Output numerator now
            cout << abs(numer) << endl;
            
            //Output - sign for negative
            if (numer < 0) cout << "- ";
            //Output dashes for length of denomenator
            for (int i = 0; i < denomLen; i++) cout << "-";
            cout << endl;

            //Output extra spaces if negative, then denomenator
            if (numer < 0) cout << "  ";
            cout << denom << endl;
        }

        //If number and fraction
        else
        {
            
            if (whole < 0) cout << "  ";
            //Add spaces for length of whole number
            for (int i = 0; i < to_string(abs(whole)).length(); i++) cout << " ";
            for (int i = 0; i < denomLen-numerLen; i++) cout << " ";
            cout << abs(numer) << endl;

            if (whole < 0) cout << "- ";
            //Output whole numbeer
            cout << abs(whole);
            for (int i = 0; i < denomLen; i++) cout << "-";
            cout << endl;

            if (whole < 0) cout << "  ";
            //Add spaces for length of whole number
            for (int i = 0; i < to_string(abs(whole)).length(); i++) cout << " ";
            cout << denom << endl;
        }
        
        //Take in next denomenator and increment caseNum
        cin >> denom;
        caseNum++;
    }
}