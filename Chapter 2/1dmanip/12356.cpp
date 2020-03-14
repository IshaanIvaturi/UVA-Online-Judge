#include <iostream>

using namespace std;

int main()
{
    //It could be simulated with vectors and erase, but too slow
    //Arrays and changing indices is more efficient

    //Initialize vars, take in s and b
    int s, b, l, r;
    cin >> s >> b;

    //Keep going until I take in s as 0
    while (s != 0)
    {
        //Holds left and right side for each soldier index
        //Larger than maximum size
        int leftSide[100005];
        int rightSide[100005];

        //Go through all soldier nums
        for (int i = 1; i <= s; i++)
        {
            //Start with left as i-1, right as i+1
            leftSide[i] = i-1;
            rightSide[i] = i+1;
        }

        //Iterate b times
        while (b--)
        {
            //Take in left and right
            cin >> l >> r;

            //Check if no soldier, output *, otherwise output left side
            if (leftSide[l] < 1) cout << "* ";
            else cout << leftSide[l] << " ";

            //Same for right
            if (rightSide[r] > s) cout << "*\n";
            else cout << rightSide[r] << endl;

            //Update the left array for right side to new left
            leftSide[rightSide[r]] = leftSide[l];

            //Same for right
            rightSide[leftSide[l]] = rightSide[r];
        }

        //Output hyphen and take in s and b
        cout << "-\n";
        cin >> s >> b;
    }
}