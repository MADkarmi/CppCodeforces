#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;


const int mod = 998244353;
const int N=5002;

long long  p[N],inv[N];

long long calculate(int n, int m) {
    return (((p[n]*inv[m])%mod)*inv[n-m])%mod;
}

long long dp(long long x,long long k) {
    long long  ret=1;
    while (k>0) {
        if (k&1) ret=(ret*x)%mod;
        k>>=1;
        x=(x*x)%mod;
    }
    return ret;
}

int a[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    p[0]=1;inv[0]=1;
    for (int i=1;i<=5000;i++) {
        p[i]=(p[i-1]*i)%mod;
        inv[i]=dp(p[i],mod-2);
    }

    cin >> a[0] >> a[1] >> a[2];

    long long result[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        int x = i, y = (i+1)%3;
        int limit = min(a[x],a[y]);
        for (int j = 0; j <= limit; j++)
        {
            long long tmp = (((calculate(a[x],j)*calculate(a[y],j))%mod) * p[j])%mod;
            result[i] = (result[i]+tmp)%mod;
        }
    }

    cout << (((result[0]*result[1])%mod)*result[2])%mod;


	return 0;
}
