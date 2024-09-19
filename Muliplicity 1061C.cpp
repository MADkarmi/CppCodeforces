#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;

const int maxN = 1e6+2;
const int mod = 1e9+7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<int> arrayA(maxN), counter(maxN);
    int lengthOfArray, result = 0;

    cin >> lengthOfArray;
    counter[0] = 1;
    for (int i = 0; i < lengthOfArray; i++)
    {
        cin >> arrayA[i];
        vector<int> current;
        for (int j = 1; j*j <= arrayA[i]; j++)
        {
            if(arrayA[i]%j==0){
                current.push_back(j);
                if(j != arrayA[i]/j){
                    current.push_back(arrayA[i]/j);
                }
            }
        }
        sort(current.begin(), current.end());
        reverse(current.begin(), current.end());

        for(auto &iter : current){
            counter[iter]+=counter[iter-1];
            counter[iter]%=mod;
        }
    }

    for (int i = 1; i <= lengthOfArray; i++)
    {
        result+=counter[i];
        result %= mod;
    }


    cout << result << endl;

	return 0;
}
