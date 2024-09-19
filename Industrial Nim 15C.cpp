#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

long long xorSum(long long x){
  switch (x % 4)
  {
  case 0:
    return 0;
  case 1:
    return x - 1;
  case 2:
    return 1;
  case 3:
    return x;
  }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    long long numberOfTestCases, xorsum = 0, amountOfStones, numberOfDumpsters;

	cin >> numberOfTestCases;
	while(numberOfTestCases > 0){
        cin >> amountOfStones >> numberOfDumpsters;
        xorsum ^= xorSum(amountOfStones)^xorSum(amountOfStones+numberOfDumpsters);

		numberOfTestCases--;
	}
    cout << (xorsum? "tolik" : "bolik") << endl;

	return 0;
}