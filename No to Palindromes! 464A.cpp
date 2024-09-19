#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> adjacent[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string stringS;
    int n, p, index = -1;
    bool result = false;
    cin >> n >> p;
    getline(cin>>ws, stringS);

    for (int i = n-1; i >=0; i--)
    {
        int s = stringS[i]-'a'+1;
        for (int j = s; j < p; j++)
        {
            if( (i >= 1 && j == stringS[i-1] -'a') || (i >=2 && j == stringS[i-2] -'a')){
                continue;
            }
            stringS[i] = char(j+'a');
            index = i+1;
            result = true;
            break;
        }
        if(result){
            break;
        }
    }

    if(!result){
        cout << "NO\n";
    } else{
        for (int i = index; i < n; i++)
        {
            for (int j = 0; j < p; j++)
            {
                if( (i >= 1 && j == stringS[i-1] -'a') || (i >=2 && j == stringS[i-2] -'a')){
                    continue;
                }
                stringS[i] = char(j + 'a');
                break;
            }

        }
        for (int i = 0; i < n; i++)
        {
            cout << stringS[i];
        }
    }
	return 0;
}
