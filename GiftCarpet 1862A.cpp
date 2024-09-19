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

	int numberOfTestCases, n, m, progressPointer;

	string vika = "vika";

	cin >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; i++){
		cin >> n >> m;
		vector<string> carpet(n);
		for (int i = 0; i < n; i++)
		{
			cin >> carpet[i];
		}

		progressPointer = 0;
		for (int column = 0; column < m; column++)
		{
			for (int row = 0; row < n; row++)
			{
				if(carpet[row][column] == vika[progressPointer]){
					progressPointer++;
					break;
				}
			}
		}

		cout << (progressPointer==4? "YES\n" : "NO\n");
	}

	return 0;
}