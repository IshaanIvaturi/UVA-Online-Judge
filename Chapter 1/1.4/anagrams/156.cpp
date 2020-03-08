#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    string s; //Holds inputted word
    vector<string> words; //Holds all words in dictionary
    vector<string> compare; //Will sort chars and convert to upper to test for anagram
    vector<string> ananagrams; //Will store solution

    cin >> s; //Take in s

    //Keep going until I take in a hashtag
    while (s != "#")
    {
        //Add s to words
        words.push_back(s);

        //Use transform to convert to upper, sort to sort chars, then add to compare
        transform(s.begin(), s.end(), s.begin(), ::toupper);

        sort(s.begin(), s.end());

        compare.push_back(s);

        //Take in next string
        cin >> s;
    }

    //Go through all elements in compare
    for (int i = 0; i < compare.size(); i++)
    {
        //Use count to test if it appears only once, if so, add the word, not compare, to ananagrams
        if (count(compare.begin(), compare.end(), compare[i]) == 1) ananagrams.push_back(words[i]);
    }

    //Sort ananagrams in lexographical order
    sort(ananagrams.begin(), ananagrams.end());

    //Output each one on a separate line
    for (string ananagram : ananagrams)
    {
        cout << ananagram << endl;
    }
}