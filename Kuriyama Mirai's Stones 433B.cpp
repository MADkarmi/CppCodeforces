#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



long long stoneValues[100002], sortedStoneValues[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int numberOfStones, stoneValue, numberOfQueries, queryType = 1, leftBound = 0, rightBound;
    
	cin >> numberOfStones;

    for (int i = 1; i <= numberOfStones; i++)
    {   
		cin >> stoneValue;
        stoneValues[i] = sortedStoneValues[i] = stoneValue;        
    }
    sort(sortedStoneValues+1, sortedStoneValues+numberOfStones+1);
    for (int i = 1; i <= numberOfStones; i++)
    {
        stoneValues[i] += stoneValues[i-1];
        sortedStoneValues[i] += sortedStoneValues[i-1];
    }
    cin >> numberOfQueries;
    for(int i = 0; i < numberOfQueries; i++){
        cin >> queryType >> leftBound >> rightBound;
        cout<< ((queryType==1)? (stoneValues[rightBound]-stoneValues[leftBound-1]) : (sortedStoneValues[rightBound]-sortedStoneValues[leftBound-1]) )<< endl;       
    }

	return 0;
}


