#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int numberOfTestCases;	
	long long number, result = -LLONG_MIN;

	cin >> numberOfTestCases;
	for (int i = 0; i < numberOfTestCases; i++){
		cin >> number;
		for(long long j = 0; j*j <=number; j++){
			if(j*j == number){
				number = LLONG_MIN;
			}
		}
		result = max(result, number);
	}

	cout << result;

	return 0;
}