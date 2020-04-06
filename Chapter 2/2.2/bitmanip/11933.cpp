#include <iostream>

using namespace std;

int main()
{
    //N is the given number
    int n;

    //Keep taking n as long as n is not 0
    while (cin >> n, n)
    {
        //To hold a and b, start all bits at 0
        int a = 0, b = 0;

        bool inA = true; //If current bit is in A or not
        int index = 0; //Current index of a and b

        //Keep going while n > 0
        while (n)
        {
            //If the last bit is 1
            if (n & 1)
            {
                //Turn on the bit at index for a or b based on inA
                if (inA) a |= (1 << index);
                else b |= (1 << index);

                //Toggle inA so the next 1 goes to B
                inA = !inA;
            }

            //Shift n to the right so the last bit is deleted, and increment index
            n >>= 1;
            index++;
        }

        //Output a and b
        cout << a << " " << b << endl;
    }
}