#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxSize = 1e6+10;
bool isPrime[maxSize+1];

void sieve(){
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i*i <= maxSize; i++)
    {
        if(isPrime[i] == true){
            for (int j = i*i; j <= maxSize; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    isPrime[2] = true;
}

bool isSquare(long long int number){
    long long int squareRoot = sqrt(number);
    return (squareRoot*squareRoot == number);
}

int main()
{
    sieve();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;

    long long int number, primePtr;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        primePtr = sqrt(number);

        if(isSquare(number) && isPrime[(int)primePtr] && number != 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
	return 0;
}