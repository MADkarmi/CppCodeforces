#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int arrayOfNumbers[200001], indexesCount[200001] = {0};	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int numberOfQueries, numberOfElements, leftIndex, rightIndex;
	long long result = 0;

	cin >> numberOfElements >> numberOfQueries;
	for (int i = 0; i < numberOfElements; i++)
	{
		cin >> arrayOfNumbers[i];
	}
	
	while(numberOfQueries > 0){
		cin >> leftIndex >> rightIndex;
		indexesCount[leftIndex - 1] ++;
		indexesCount[rightIndex] --;
		numberOfQueries--;
	}

	for (int i = 1; i < numberOfElements; i++)
	{
		indexesCount[i]+=indexesCount[i-1];
	}
	
	sort(arrayOfNumbers, arrayOfNumbers + numberOfElements);
	sort(indexesCount, indexesCount + numberOfElements);
	
	for (int i = 0; i < numberOfElements; i++)
	{
		result += static_cast<long long>(arrayOfNumbers[i]) * static_cast<long long>(indexesCount[i]);
	}
	
	cout << result;
		

	return 0;
}