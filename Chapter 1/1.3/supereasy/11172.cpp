#include <bits/stdc++.h>
using namespace std;

int main()
{
	//Initialize variables and input # of tests
	int t, a, b;

	cin >> t;

	//Iterate t times
	for (int i = 0; i < t; i++)
	{
		//Take in a and b
		cin >> a >> b;

		//Simple if else logic for output
		if (a < b) cout << "<" << endl;
		else if (a > b) cout << ">" << endl;
		else cout << "=" << endl;
	}
}