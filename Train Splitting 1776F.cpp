#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;
const int N = 52;
vector<pair<int, int>> edges[N];
int cityConnections[N], result[N*N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numberOfTestCases, numberOfCities, numberOfTrainRoutes, cityU, cityV;
	cin >> numberOfTestCases;
	while(numberOfTestCases > 0){
        cin >> numberOfCities >> numberOfTrainRoutes;

        for (int i = 1; i <= numberOfTrainRoutes; i++)
        {
            cin >> cityU >> cityV;
            edges[cityU].emplace_back(cityV, i);
            edges[cityV].emplace_back(cityU, i);
            cityConnections[cityU]++;
            cityConnections[cityV]++;
        }

        if(*min_element(cityConnections+1, cityConnections+1+numberOfCities) < numberOfCities-1){
            int city = min_element(cityConnections+1, cityConnections+1+numberOfCities) - cityConnections;
            cout << "2\n";
            for (int i = 0; i < cityConnections[city]; i++)
            {
                result[edges[city][i].second] = 1;
            }
            for (int i = 1; i <= numberOfTrainRoutes; i++)
            {
                if(!result[i]){
                    result[i]=2;
                }
            }
        }
        else{
            cout << "3\n";

            result[edges[1][0].second] = 1;
            for (int i = 1; i < cityConnections[1]; i++)
            {
                result[edges[1][i].second] = 2;
            }
            for (int i = 1; i <= numberOfTrainRoutes; i++)
            {
                if(!result[i]){
                    result[i]=3;
                }
            }
        }
        for (int i = 1; i <= numberOfTrainRoutes; i++)
        {
            cout << result[i] << " ";
            result[i] = 0;
        }
        for (int i = 1; i < numberOfCities; i++)
        {
            edges[i].clear();
            cityConnections[i] = 0;
        }
		numberOfTestCases--;
	}
	return 0;
}
