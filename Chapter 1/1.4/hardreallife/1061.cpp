#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

//Maps ABO type to the combinations of alleles
map<string, vector<pair<char, char>>> typeToCombos =
{
    {"A", {{'A', 'A'}, {'A', 'O'}}},
    {"B", {{'B', 'B'}, {'B', 'O'}}},
    {"AB", {{'A', 'B'}}},
    {"O", {{'O', 'O'}}}
};

//Maps combination of alleles to blood type
map<pair<char, char>, string> comboToType =
{
    {{'A', 'A'}, "A"},
    {{'A', 'O'}, "A"},
    {{'O', 'A'}, "A"},
    {{'A', 'B'}, "AB"},
    {{'B', 'A'}, "AB"},
    {{'B', 'B'}, "B"},
    {{'B', 'O'}, "B"},
    {{'O', 'B'}, "B"},
    {{'O', 'O'}, "O"}
};

//Maps allele to all possible blood types it can come from
map<char, vector<string>> alleleToTypes =
{
    {{'A'}, {"A", "AB"}},
    {{'B'}, {"B", "AB"}},
    {{'O'}, {"O", "A", "B"}}
};

int main()
{
    //Take in blood type of par1, par2, child
    string par1, par2, child;
    cin >> par1 >> par2 >> child;

    //Will be incremented for cases
    int testCase = 1;

    //Keep going until E N D signal
    while (par1 != "E")
    {
        //If parent is unknown
        if (par1 == "?" || par2 == "?")
        {
            string par; //ABO of known parent
            char parRh; //Rh of known parent
            char childRh; //Rh of child

            //If par2 is the mystery
            if (par2 == "?")
            {
                //Use par1 as the known parent
                parRh = par1[par1.length()-1]; //Last char of blood type
                par1.pop_back(); //Now par is just ABO
                childRh = child[child.length()-1]; //Same for child
                child.pop_back();
                par = par1; //Set par to known
            }

            //If par1 is the mystery
            else
            {
                //Same but for par2 as known
                parRh = par2[par2.length()-1];
                par2.pop_back();
                childRh = child[child.length()-1];
                child.pop_back();
                par = par2;
            }

            //Holds the possible ABO blood types of mystery parent
            set<string> parTypes;

            //Go through combos needed to produce child ABO
            for (pair<char, char> childCombo : typeToCombos[child])
            {
                //And combos parent could have
                for (pair<char, char> parCombo : typeToCombos[par])
                {
                    //If parent allele matches first child allele
                    if (parCombo.first == childCombo.first || parCombo.second == childCombo.first) 
                    {
                        //Insert all the types which can create the other allele to mystery parent
                        for (string type : alleleToTypes[childCombo.second]) parTypes.insert(type);
                    }

                    //Same for second
                    if (parCombo.first == childCombo.second || parCombo.second == childCombo.second)
                    {
                        for (string type : alleleToTypes[childCombo.first]) parTypes.insert(type);
                    }
                }
            }

            //Holds the possible Rh blood types of mystery parent
            set<char> parRhs;

            if (childRh == '+')
            {
                //If child and parent are +, mystery could be either
                if (parRh == '+')
                {
                    parRhs.insert('+');
                    parRhs.insert('-');
                }

                //If child + and parent -, other parent can't be -
                else
                {
                    parRhs.insert('+');
                }
            }

            //If child -, parents could be anything
            else
            {
                parRhs.insert('+');
                parRhs.insert('-');
            }
            
            //Holds all final blood types of parent
            vector<string> allTypes;

            //Push back all combinations of parTypes and parRhs
            for (string type : parTypes)
            {
                for (char rH : parRhs)
                {
                    //Add them to combine into final blood type
                    allTypes.push_back(type + rH);
                }
            }
            
            //If multiple solutions
            if (allTypes.size() > 1)
            {
                //If par2 was the mystery
                if (par2 == "?")
                {
                    //Output parent 1 blood, brackets notation, child
                    cout << "Case " << testCase << ": " << par1 + parRh << " {";

                    for (int i = 0; i < allTypes.size(); i++)
                    {
                        if (i != 0) cout << ", ";

                        cout << allTypes[i];
                    }

                    cout << "} " << child + childRh << endl;
                }

                //If par1 was the mystery, same thing but different order of output
                else
                {
                    cout << "Case " << testCase << ": {";

                    for (int i = 0; i < allTypes.size(); i++)
                    {
                        if (i != 0) cout << ", ";

                        cout << allTypes[i];
                    }

                    cout << "} " << par2 + parRh << " " << child + childRh << endl;
                }
                
            }

            //If only one solution, no brackets needed
            else if (allTypes.size() == 1)
            {
                if (par2 == "?") cout << "Case " << testCase << ": " << par1 + parRh << " " << allTypes[0] << " " << child + childRh << endl;
                else cout << "Case " << testCase << ": " << allTypes[0] << " " << par2 + parRh << " " << child + childRh << endl;
            }

            //If none, output impossible
            else
            {
                if (par2 == "?")
                {
                    cout << "Case " << testCase << ": " << par1 + parRh << " IMPOSSIBLE " << child + childRh << endl;
                }
                else
                {
                    cout << "Case " << testCase << ": IMPOSSIBLE " << par2 + parRh << " " << child + childRh << endl;
                }
            }
        }

        //If child unknown
        else
        {
            //Same procedure to store Rh and ABO of parents separately
            char par1Rh = par1[par1.length()-1];
            par1.pop_back();
            char par2Rh = par2[par2.length()-1];
            par2.pop_back();

            //Holds possible ABOs of child
            set<string> childTypes;

            //Go through all allele combos from parent 1
            for (pair<char, char> par1Combo : typeToCombos[par1])
            {
                //And parent 2
                for (pair<char, char> par2Combo : typeToCombos[par2])
                {
                    //Insert the type formed in all allele permutations
                    childTypes.insert(comboToType[{par1Combo.first, par2Combo.first}]);
                    childTypes.insert(comboToType[{par1Combo.first, par2Combo.second}]);
                    childTypes.insert(comboToType[{par1Combo.second, par2Combo.first}]);
                    childTypes.insert(comboToType[{par1Combo.second, par2Combo.second}]);
                }
            }

            //Holds possible Rhs of child
            set<char> childRhs;

            //If parent 1 is +, parent 2 doesn't matter, child can be either
            if (par1Rh == '+')
            {
                childRhs.insert('+');
                childRhs.insert('-');
            }

            //If parent 1 is -
            else
            {
                //If parent 2 is +, child is either
                if (par2Rh == '+')
                {
                    childRhs.insert('+');
                    childRhs.insert('-');
                }

                //Both - makes -
                else childRhs.insert('-');
            }

            //Same allTypes and procedure
            vector<string> allTypes;

            for (string type : childTypes)
            {
                for (char rH : childRhs)
                {
                    allTypes.push_back(type + rH);
                }
            }

            //Bracket notation
            if (allTypes.size() > 1)
            {
                cout << "Case " << testCase << ": " << par1 + par1Rh << " " << par2 + par2Rh << " " << "{";

                for (int i = 0; i < allTypes.size(); i++)
                {
                    if (i != 0) cout << ", ";

                    cout << allTypes[i];
                }

                cout << "}\n";
            }

            //Single notation
            else
            {
                cout << "Case " << testCase << ": " << par1 + par1Rh << " " << par2 + par2Rh << " " << allTypes[0] << endl;
            }
        }
        
        //Take in the next parents and child
        cin >> par1 >> par2 >> child; 

        //Increment the test case
        testCase++;
    }
}