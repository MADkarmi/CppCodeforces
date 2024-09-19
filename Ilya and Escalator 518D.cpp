#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

double dp[2001][2001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,t;
	double p;
	cin >> n >> p >> t;
	for (int i = 1; i <=t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = (1-p)*dp[i-1][j] + p*(1+dp[i-1][j-1]);
		}
	}
	cout << fixed << setprecision(10) << dp[t][n];
	return 0;
}