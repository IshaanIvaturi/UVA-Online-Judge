#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    while (line != "Game Over")
    {
        vector<int> pins;

        for (char c : line)
        {
            if (c == ' ') continue;

            if (c == 'X') pins.push_back(10);
            else if (c == '/') pins.push_back(10 - pins.back());
            else pins.push_back(c - '0');
        }

        int i = 0;
        int f = 1;
        int score = 0;

        while (f <= 10)
        {
            if (pins[i] == 10)
            {
                score += pins[i] + pins[i+1] + pins[i+2];
                i++;
            }

            else if (pins[i] + pins[i+1] == 10)
            {
                score += pins[i] + pins[i+1] + pins[i+2];
                i += 2;
            }

            else
            {
                score += pins[i] + pins[i+1];
                i += 2;
            }

            f++; 
        }

        cout << score << endl;

        getline(cin, line);
    }
}