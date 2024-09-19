#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int numberOfTestCases, x, y;	
	cin >> numberOfTestCases;
	vector<pair<int,int>> cordinates(3);
	double result;
	for (int i = 0; i < numberOfTestCases; i++){
		for (int i = 0; i < 3; i++)
		{
			cin >> cordinates[i].first >> cordinates[i].second;
		}
		cout << fixed << setprecision(10);
		if(cordinates[0].second == cordinates[1].second &&
			cordinates[2].second < cordinates[0].second){
				result = abs(cordinates[0].first - cordinates[1].first);
			}
		else if (cordinates[1].second == cordinates[2].second &&
				cordinates[0].second < cordinates[1].second){
					result = abs(cordinates[1].first - cordinates[2].first);
				}
		else if (cordinates[0].second==cordinates[2].second &&
				cordinates[1].second<cordinates[0].second)
				{
					result = abs(cordinates[0].first-cordinates[2].first);
				}
				
		cout << result <<endl;
		result = 0.0;
	}
	return 0;
}