#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//I use a struct to model each contestant
struct Contestant
{
    bool solved[10] = {0}; //Whether they have solved each of the 10 problems
    int tries[10] = {0}; //How many tries for each of the 10 problems
    int numSolved = 0; //How many total problems solved
    int penalty = 0; //Total penalty points
};

//I keep track of the participants by mapping them to their number
map<int, Contestant> participants;

//I compare 2 participant numbers to see who is higher ranked
bool comparator(int a, int b)
{
    //If they solved different num of probs, just take the better one
    if (participants[a].numSolved != participants[b].numSolved) 
    {
        return participants[a].numSolved > participants[b].numSolved;
    }

    //If one has less penalty points, take that one
    if (participants[a].penalty != participants[b].penalty)
    {
        return participants[a].penalty < participants[b].penalty;
    }

    //Otherwise return lower index
    return a < b;
}

int main()
{
    //t is num of test cases, s holds lines
    int t;
    string s;

    //Take in t, ignore endl of that line, and take in blank line
    cin >> t;
    cin.ignore(256, '\n');
    getline(cin, s);

    //Iterate t times
    while (t--)
    {
        //Reset the map, initialize vector for ranking
        participants.clear();
        vector<int> ranks;

        //Variables for line data
        int num, problem, time;
        char L;

        //Keep taking lines into s until blank line
        while (getline(cin, s) && s != "")
        {
            //Need a string stream to parse line (new to me)
            stringstream ss(s);
            ss >> num >> problem >> time >> L;

            //If new contestant num not in ranks, add it
            if (count(ranks.begin(), ranks.end(), num) == 0) ranks.push_back(num);

            //If problem already solved, we can ignore this line
            if (participants[num].solved[problem]) continue;

            //If correct submission
            if (L == 'C')
            {
                //Set solved for that problem to true
                participants[num].solved[problem] = true;

                //Add to penalty time to solve the problem and 20 times wrong tries for the problem
                participants[num].penalty += time + 20 * participants[num].tries[problem];
                
                //Increment number solved
                participants[num].numSolved++;
            }

            //If incorrect submission, increment problem tries
            else if (L == 'I') participants[num].tries[problem]++;
        }

        //Sort the ranks based on my comparator
        sort(ranks.begin(), ranks.end(), comparator);

        //Output information in order for each rank
        for (int rank : ranks) 
        {
            cout << rank << " " << participants[rank].numSolved << " " << participants[rank].penalty << endl;
        }

        //If not the last case, add an extra line
        if (t) cout << endl;
    }
}