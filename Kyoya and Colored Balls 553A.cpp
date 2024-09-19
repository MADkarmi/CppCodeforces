#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int dpSize = 1005;
const long long int mod = 1000000007;
long long dp[dpSize][dpSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    for (long long int i = 0; i < dpSize; i++)
    {
        for (long long int j = 0; j <= i; j++)
        {
            if(j==0){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
            }
        }
    }

    int numberOfColors, numberOfBalls;
    cin >> numberOfColors;
    long long int total = 0, result = 1ll;
    for (int i = 0; i < numberOfColors; i++)
    {
        cin >> numberOfBalls;
        result = (result * dp[total + numberOfBalls - 1][numberOfBalls - 1])% mod;
        total += numberOfBalls;
    }
    cout << result << endl;
	return 0;
}