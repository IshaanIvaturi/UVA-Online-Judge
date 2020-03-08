#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //N holds the number of pages
    int n;
    cin >> n; //Take in for the first time

    //Keep going until I take in n = 0
    while (n != 0)
    {
        //Output intitial line for printing order
        cout << "Printing order for " << n << " pages:\n";

        //1 is special case without a back, code in its output
        if (n == 1)
        {
            cout << "Sheet 1, front: Blank, 1\n";
            cin >> n; //Have to take in the next n
            continue; //Ignore rest
        }

        //Will hold pages in order they should be read
        vector<int> pageNums;

        //NumBlank is distance to nearest multiple of 4
        //I have to pad by this amount to have front and back for each sheet
        int numBlank = (4 - (n % 4)) % 4;

        //Add all page numbers from 1 to n
        for (int i = 1; i <= n; i++) pageNums.push_back(i);

        //For blanks, I add 0 to the end
        for (int i = 0; i < numBlank; i++) pageNums.push_back(0);

        //Go from sheet 1 to 1 more than pageNums / 4
        for (int sheet = 1; sheet <= (pageNums.size() - 1) / 4 + 1; sheet++)
        {
            //Take the page the right distance from the end for the first front
            //Then convert to string, blank in the case of 0
            int front1 = pageNums[pageNums.size()-(sheet*2)+1];
            string f1 = front1 == 0 ? "Blank" : to_string(front1);

            //Second front is a distance from beginning instead
            int front2 = pageNums[sheet * 2 - 2];
            string f2 = front2 == 0 ? "Blank" : to_string(front2);

            //First back is 1 page after second front
            int back1 = pageNums[sheet * 2 - 1];
            string b1 = back1 == 0 ? "Blank" : to_string(back1);

            //Second back is 1 page before first front
            int back2 = pageNums[pageNums.size()-(sheet*2)];
            string b2 = back2 == 0 ? "Blank" : to_string(back2);

            //Output the sheet in the right format
            cout << "Sheet " << sheet << ", front: " << f1 << ", " << f2 << endl;
            cout << "Sheet " << sheet << ", back : " << b1 << ", " << b2 << endl;
        }
        
        //Take in next n
        cin >> n;
    }
}