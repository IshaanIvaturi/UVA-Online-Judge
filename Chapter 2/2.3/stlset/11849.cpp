#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    //Initialize variables, unordered set because don't need sorting
    int n, m, cd;
    unordered_set<int> cds;

    //Take in n and m until they're both 0
    while (cin >> n >> m && n + m != 0)
    {
        //Clear my set, elems is number of cds to take in
        cds.clear();
        int elems = n + m;

        //I take in all the cds
        while (elems--)
        {
            //Take in the cd
            cin >> cd;

            //If it's already there, erase it, otherwise insert it
            if (cds.find(cd) != cds.end()) cds.erase(cd);
            else cds.insert(cd);
        }

        //The size is cds that were unique
        //Subtracting it from total gets duplicated elements
        //Have to divide by 2 to not double count them
        cout << (n + m - cds.size()) / 2 << endl;
    }
}