#include <iostream>
#include <set>

using namespace std;

int main()
{
    //Initialize variables and take in n
    int n, b, sg, sb, temp;
    cin >> n;

    //Iterate n times
    while (n--)
    {
        //Use multisets, greatest value first, for green and blue soldiers
        //Also keep track of the weakened soldiers to add at end of round
        multiset<int, greater<int>> green, blue, newGreen, newBlue;

        //Take in b, sg, sb
        cin >> b >> sg >> sb;

        //Insert all green soldiers
        while (sg--)
        {
            cin >> temp;
            green.insert(temp);
        }

        //Insert all blue
        while (sb--)
        {
            cin >> temp;
            blue.insert(temp);
        }
        
        //Keep going while both can fight
        while (green.size() > 0 && blue.size() > 0)
        {
            //Clear new sets, set iterators to beginning
            newGreen.clear();
            newBlue.clear();
            auto git = green.begin();
            auto bit = blue.begin();

            //Iterate for each battlefield
            for (int i = 0; i < b; i++)
            {
                //If iterator has reached end, one is done
                if (git == green.end() || bit == blue.end()) break;

                //Depending on whose solder is stronger, I insert to newgreen/newblue
                if (*git > *bit) newGreen.insert(*git - *bit);
                else if (*git < *bit) newBlue.insert(*bit - *git);

                //Increment iterators
                git++;
                bit++;
            }

            //Remove the used soldiers, and insert the weakened
            green.erase(green.begin(), git);
            blue.erase(blue.begin(), bit);
            green.insert(newGreen.begin(), newGreen.end());
            blue.insert(newBlue.begin(), newBlue.end());
        }
        
        //If both empty, both died, otherwise output soldiers
        if (green.size() == blue.size()) cout << "green and blue died\n";
        else if (green.size() > blue.size())
        {
            cout << "green wins\n";
            for (int soldier : green) cout << soldier << endl;
        }
        else
        {
            cout << "blue wins\n";
            for (int soldier : blue) cout << soldier << endl;
        }

        //For all cases except last, add an endl
        if (n) cout << endl;
    }
}