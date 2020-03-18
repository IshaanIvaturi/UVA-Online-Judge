#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Initialize vars here to use in methods
int N, n;
string s;

//Initialize vector strings to hold characters
vector<string> small;
vector<string> large;

//Rotates small array clockwise 90 degrees in place
void rotateClockwise()
{
    //Go through each loop starting from outside
    for (int i = 0; i < n/2; i++)
    {
        //Go through elements on one of the sides
        for (int j = i; j < n-i-1; j++)
        {
            //Save the top square for later
            char temp = small[i][j];

            //Set top to corresponding left
            small[i][j] = small[n-j-1][i];

            //Set left to corresponding bottom
            small[n-j-1][i] = small[n-i-1][n-j-1];

            //Set bottom to corresponding right
            small[n-i-1][n-j-1] = small[j][n-i-1];

            //Set right back to top
            small[j][n-i-1] = temp;
        }
    }
}

//Counts the occurrences of small square in large square
int smallInLarge()
{
    //Count will hold returned value
    int count = 0;

    //Go through top left squares of large to check if it results in small
    for (int i = 0; i <= N-n; i++)
    {
        for (int j = 0; j <= N-n; j++)
        {
            //Match holds how many squares are the same
            int match = 0;

            //Go through each square of small
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    //Check if corresponding large square == small, increment match
                    if (large[i+k][j+l] == small[k][l]) match++;
                }
            }

            //If n^2 matched, then it's an occurrence, increment count
            if (match == n*n) count++;
        }
    }

    //Finally return count
    return count;
}

int main()
{
    //Take in N and n
    cin >> N >> n;

    //Keep going until N is taken in as 0
    while (N != 0)
    {
        //Reset vectors
        large.clear();
        small.clear();

        //Take in large vector
        for (int i = 0; i < N; i++)
        {
            cin >> s;
            large.push_back(s);
        }

        //Take in small vector
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            small.push_back(s);
        }

        //Check and rotate 4 times
        for (int i = 0; i < 4; i++)
        {
            //Output number of occurrences
            cout << smallInLarge();
            //Add space except for end of line
            if (i != 3) cout << " ";
            //Rotate afterwards and check again
            rotateClockwise();
        }

        //Output newline and take in N and n again
        cout << endl;
        cin >> N >> n;
    }
}