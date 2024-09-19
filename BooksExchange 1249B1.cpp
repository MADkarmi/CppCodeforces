#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numberOfTestCases, numberOfKids, count;

	cin >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; i++){
		cin >> numberOfKids;

		vector<int> permutation(numberOfKids);

		for(auto &pi: permutation){
			cin >> pi;
		}

		for (int i = 0; i < numberOfKids; i++)
		{
			count = 1;
			int current = permutation[i];
			while (current != i+1)
			{
				count++;
				current = permutation[current-1];
			}
			cout << count << " ";
		}
		cout << endl;
	}

	return 0;
}