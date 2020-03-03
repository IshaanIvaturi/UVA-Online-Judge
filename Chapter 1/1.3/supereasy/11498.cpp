#include <bits/stdc++.h>
using namespace std;

int main()
{
	//Initialize variables and take in k
	int k, n, m, x, y;

	cin >> k;

	//Keep going till 0 gets input
	while (k != 0)
	{
		//Take in division point
		cin >> n >> m;

		//Iterate for # of queries
		for (int i = 0; i < k; i++)
		{
			//Take in query point
			cin >> x >> y;

			//First check for borderline
			if (x == n || y == m)
			{
				cout << "divisa" << endl;
			}
			//Break up cases north of division
			else if (y > m)
			{
				if (x < n) cout << "NO" << endl;
				else cout << "NE" << endl;
			}
			//Break up cases south of division
			else
			{
				if (x < n) cout << "SO" << endl;
				else cout << "SE" << endl;
			}
		}

		//Take in next k
		cin >> k;
	}	
}