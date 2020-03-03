#include <bits/stdc++.h>

using namespace std;

//This will hold the 13 cards as strings
string cards[13];

int main()
{
    //Keep going while you can take in a card
    while (cin >> cards[0])
    {
        //Take in the rest of the cards to array
        for (int i = 1; i < 13; i++) cin >> cards[i];

        int total = 0;
        map<char, bool> stopped; //Suit is stopped
        map<char, int> numCards; //Number of cards in suit
        map<char, bool> hasAce;  //Ace in suit?
        map<char, bool> hasKing; //King in suit?
        map<char, bool> hasQueen; //Queen in suit?
        map<char, bool> hasJack; //Jack in suit?

        //Go through all cards
        for (int i = 0; i < 13; i++)
        {
            //Unpack string to value and suit
            char value = cards[i][0];
            char suit = cards[i][1];

            //Add 4, hasAce true, suit automatically stopped
            if (value == 'A')
            {
                total += 4;
                hasAce[suit] = true;
                stopped[suit] = true;
            }

            //Add 3, hasKing true, suit stopped if already a card
            if (value == 'K')
            {
                total += 3;
                hasKing[suit] = true;
                if (numCards[suit] > 0) stopped[suit] = true;
            }

            //Add 2, hasQueen true, suit stopped if already 2 cards
            if (value == 'Q')
            {
                total += 2;
                hasQueen[suit] = true;
                if (numCards[suit] > 1) stopped[suit] = true;
            }

            //Add 1, hasJack true
            if (value == 'J')
            {
                total += 1;
                hasJack[suit] = true;
            }

            //No matter what the card is, there's one more card in the suit
            numCards[suit]++;

            //If already a king, stopped
            if (hasKing[suit] && numCards[suit] == 2) stopped[suit] = true;

            //If already a queen and another card, stopped
            if (hasQueen[suit] && numCards[suit] == 3) stopped[suit] = true;
        }

        //Go through suits and subtract based on K, Q, J and numbers of cards
        for (pair<char, int> suitNum : numCards)
        {
            if (hasKing[suitNum.first] && suitNum.second < 2) total--;
            if (hasQueen[suitNum.first] && suitNum.second < 3) total--;
            if (hasJack[suitNum.first] && suitNum.second < 4) total--;
        }

        //At this point, the total is the no trump total, so check no trump conditions
        if (total >= 16 && stopped['S'] && stopped['H'] && stopped['D'] && stopped['C'])
        {
            //If satisfied, bid no trump and continue
            cout << "BID NO-TRUMP\n";
            continue;
        }

        //Keeps track of suit to bid on
        pair<char, int> bestSuit = {'S', 0};

        //Goes through in proper order
        for (char suit : {'S', 'H', 'D', 'C'})
        {
            //Add to the total for number of cards per suit
            if (numCards[suit] == 2) total++;
            if (numCards[suit] == 1 || numCards[suit] == 0) total += 2;

            //If the suit has more cards than the best, update the best
            if (numCards[suit] > bestSuit.second)
            {
                bestSuit = {suit, numCards[suit]};
            }
        }

        //Pass for total less than 14
        if (total < 14)
        {
            cout << "PASS\n";
            continue;
        }

        //Bid the best suit
        cout << "BID " << bestSuit.first << endl;
    }
}