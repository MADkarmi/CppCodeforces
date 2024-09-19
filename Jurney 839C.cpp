#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> adjacent[100001];

long double dfs(int cityU=0, int cityV= -1){
    long double sum = 0;
    for (auto city : adjacent[cityU])
    {
        if(city != cityV){
            sum += dfs(city, cityU) + 1;
        }
    }

    return sum ? sum/(adjacent[cityU].size() - (cityV != -1)) : 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numberOfCities, cityUId, cityVId;

	cin >> numberOfCities;
	while(numberOfCities > 1){
		cin >> cityUId >> cityVId;
        cityUId --;
        cityVId --;
        adjacent[cityUId].push_back(cityVId);
        adjacent[cityVId].push_back(cityUId);
		numberOfCities--;
	}

    cout << fixed << setprecision(20) << dfs() << endl;
	return 0;
}
