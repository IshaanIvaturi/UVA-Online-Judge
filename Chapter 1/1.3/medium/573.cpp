#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Initialize and take in variables
    int h, u, d, f;

    scanf("%d %d %d %d", &h, &u, &d, &f);

    //Keep going when h value is valid
    while (h != 0)
    {
        int day = 1; //Starts on day 1
        double height = 0; //Starts at height 0
        double climb = u; //Amt climbed starts at u
        double fatigue = climb * f / 100; //Amt lost to fatigue predetermined

        //Keep going through until success or fail
        while (true)
        {
            //Increment height by climb
            height += climb;

            //Possible success, account for it
            if (height > h)
            {
                printf("success on day %d\n", day);
                break;
            }

            //Decrease height by sliding distance
            height -= d;

            //Possible failure, account for it
            if (height < 0)
            {
                printf("failure on day %d\n", day);
                break;
            }

            //Climb can be at least 0, so decrement by fatigue or 0
            climb = max(climb - fatigue, 0.0);

            //Increment day
            day++;
        }
        
        //Scan next test case
        scanf("%d %d %d %d", &h, &u, &d, &f);
    }
}