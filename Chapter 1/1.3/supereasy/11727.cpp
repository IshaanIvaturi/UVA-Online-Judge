#include <bits/stdc++.h>
using namespace std;

int main()
{
	//Initialize variables and take in t
	int t, a, b, c;

	cin >> t;

	//Iterate from 1 to t, the case numbers
	for (int i = 1; i <= t; i++)
	{
		//Take in variables, place in array and sort
		cin >> a >> b >> c;

		vector<int> arr = {a, b, c};

		sort(arr.begin(), arr.end());

		//Print case with the middle element
		printf("Case %d: %d\n", i, arr[1]);
	}
}