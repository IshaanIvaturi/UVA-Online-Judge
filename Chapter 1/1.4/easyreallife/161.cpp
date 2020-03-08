#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

//Returns whether all lights are green at a particular time
//Pass inputted lights vector by reference and time to check
bool validTime(vector<int> &lights, int time)
{
    //Go through each light in vector
    for (int light : lights)
    {
        //Green if it's less than light - 5 mod light * 2
        //If any light not green, return false
        if (time % (light*2) >= light - 5) return false;
    }

    //If it reaches here, all lights were green
    return true;
}

int main()
{
    //Initialize lights vector and int variable, take in and push into lights
    vector<int> lights;
    int light;
    cin >> light;
    lights.push_back(light);

    //Keep going until an input starts with 0
    while (lights[0] != 0)
    {
        //Keep taking in lights
        while (cin >> light)
        {
            //As soon as 0 taken in, break out
            if (light == 0) break;
            lights.push_back(light); //Add to vector
        }

        //Use STL to get minimum light, as I have to check from 2 * this at least
        int minLight = *min_element(lights.begin(), lights.end());

        //noTimeFound holds whether we were able to sync up lights
        bool noTimeFound = true;

        //Go from the second time minLight turns green to 5 hours in seconds
        for (int t = minLight * 2; t <= 5 * 60 * 60; t++)
        {
            //Check for all green
            if (validTime(lights, t))
            {
                //Output in proper format, converting seconds to h:m:s
                printf("0%d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 60);
                noTimeFound = false; //Time was found
                break; //Break out, no need to keep checking
            }
        }

        //If not synchronized, output msg
        if (noTimeFound) printf("Signals fail to synchronise in 5 hours\n");

        //Reset vector, take in new light and push back
        lights.clear();
        cin >> light;
        lights.push_back(light);
    }
}