#include <bits/stdc++.h>
using namespace std;

//Gives solution given the proper inputs
int solve(int len, double down, double amt, vector<pair<int, double>> dr)
{
	//Fill array of depreciation rates with 0
	double dep[110] = {0};

	//Update the rates following each record to end with a completed array
	for (auto record : dr)
	{
		for (int i = record.first; i < 110; i++)
		{
			dep[i] = record.second;
		}
	}

	double monthly = amt / len; //Monthly cost
	int month = 0;
	double owed = amt; //Amount he owes, starts at price
	double val = (amt + down) * (1 - dep[0]); //Value of car, starts with first depreciation rate

	//Keep simulating payments until he owes less than the value
	while (val <= owed)
	{
		owed -= monthly;
		val *= (1 - dep[++month]); //Increment month while using next depreciation rate
	}

	//Return solution
	return month;
}

int main()
{
	//Initialize variables and vector for input
	int len, numDr;
	double down, amt;

	vector<pair<int, double>> dr;

	//Keep going until broken
	while(true)
	{
		//Take in given amounts, break out if len invalid
		cin >> len >> down >> amt >> numDr;

		if (len < 0) break;

		//To take in depreciation rates
		pair<int, double> temp;
		int a;
		double b;

		//Fill depreciation vector with pairs
		for (int i = 0; i < numDr; i++)
		{
			cin >> a >> b;
			temp = {a, b};
			dr.push_back(temp);
		}

		//Call function
		int sol = solve(len, down, amt, dr);

		//Account for month/months
		if (sol == 1) cout << "1 month\n";
		else cout << sol << " months\n";
	}
}