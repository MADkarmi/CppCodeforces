#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
long long calculateDistance( pair<long long, long long> pointA, pair<long long, long long> pointB){
	long long x = 1ll* (pointA.first - pointB.first) * (pointA.first - pointB.first);
	long long y = 1ll* (pointA.second - pointB.second) * (pointA.second - pointB.second);
	return (x+y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	vector<pair<long long ,long long >> cordinates(3);
	
	for (int i = 0; i < 3; i++)
	{
		cin >> cordinates[i].first >> cordinates[i].second;
	}
	long long distAB = calculateDistance(cordinates[0], cordinates[1]);
	long long distAC = calculateDistance(cordinates[0], cordinates[2]);
	long long distBC = calculateDistance(cordinates[1], cordinates[2]);
	if((1ll*(1ll*cordinates[0].first*(cordinates[1].second - cordinates[2].second))+
			(1ll*cordinates[1].first*(cordinates[2].second-cordinates[0].second))+
			(1ll*cordinates[2].first*(cordinates[0].second-cordinates[1].second)))!= 0 &&
			(distAB==distAC || distAB==distBC)){
				cout << "Yes\n";
			}
	else{
		cout << "No\n";
	}

	return 0;
}