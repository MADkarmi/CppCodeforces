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

    string publicKey;
    long long intA, intB;
	getline(cin>>ws, publicKey);
    cin >> intA >> intB;
    long long n = publicKey.length(), pow = 1;
    vector<long long> prefix(n+1, 0), suffix(n+1, 0);

    for (int i = n-1; i >= 0; i--)
    {
        suffix[i]=suffix[i+1]+(publicKey[i]-'0')*pow;
        suffix[i]%=intB;
        pow = (pow*10)%intB;
    }
    prefix[0]=(publicKey[0]-'0')%intA;
    pow = 10;
    for (int i = 1; i < n; i++)
    {
        prefix[i]=(publicKey[i]-'0')+10*prefix[i-1];
        prefix[i]%=intA;
    }

    bool coutNo = true;
    for (int i = 0; i < n-1; i++)
    {
        if(publicKey[i+1]!='0' && prefix[i]==0 && suffix[i+1]==0){
            cout << "YES\n" << publicKey.substr(0, i+1) << "\n" << publicKey.substr(i+1);
            coutNo = false;
            break;
        }
    }
    if(coutNo){
        cout << "NO";
    }

	return 0;
}
