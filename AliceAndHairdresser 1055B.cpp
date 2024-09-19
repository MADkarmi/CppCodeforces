#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long numberOfHairlines, numberOfRequests, maxHairLength, numberOfSwings, requestType, hairId, hairGrowth;
	cin >> numberOfHairlines >> numberOfRequests >> maxHairLength;
	vector<long long> hairLengths(numberOfHairlines);
	for(auto &hair : hairLengths){
		cin>>hair;
	}

	numberOfSwings = (hairLengths[0] > maxHairLength);//? 1 : 0;
	for (int i = 1; i < numberOfHairlines; i++)
	{
		bool a = hairLengths[i-1] <= maxHairLength;
		bool b = hairLengths[i] > maxHairLength;
		if(hairLengths[i-1] <= maxHairLength && hairLengths[i] > maxHairLength)
			numberOfSwings++;
	}

	for (int i = 0; i < numberOfRequests; i++)
	{
		cin >> requestType;
		switch (requestType)
		{
		case 1:
			cin >> hairId >> hairGrowth;
			if(hairLengths[--hairId]>maxHairLength){
				continue;
			}
			hairLengths[hairId]+= hairGrowth;
			if(hairLengths[hairId] > maxHairLength){
				bool left = hairId > 0 && hairLengths[hairId-1] > maxHairLength;
				bool right = hairId < numberOfHairlines - 1 && hairLengths[hairId+1] > maxHairLength;
				if(!left && !right)
					numberOfSwings++;
				if(left && right){
					numberOfSwings--;
				}
			}
			break;
		default:
			cout << numberOfSwings << endl;
			break;
		}
	}
	return 0;
}