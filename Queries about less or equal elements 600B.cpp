#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, tmpReader;
	vector<int> arrayA;
	vector<int> arrayB;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> tmpReader;
		arrayA.push_back(tmpReader);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> tmpReader;
		arrayB.push_back(tmpReader);
	}

	sort(arrayA.begin(), arrayA.end());

	for (int i = 0; i < m; i++)
	{
		cout << upper_bound(arrayA.begin(), arrayA.end(),arrayB[i])-arrayA.begin() << " " ;
	}

	return 0;
}