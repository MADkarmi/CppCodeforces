#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> dp(4002, -1);
vector<int> pieceLength(3);

int dynam(int ribbonLength){
	if(ribbonLength == 0){
		return 1;
	}

	if(ribbonLength < *min_element(begin(pieceLength), end(pieceLength))){
		return 0;
	}

	int &cuts = dp[ribbonLength];
	if(cuts != -1) {
		return cuts;
	}

	for(auto &piece : pieceLength){
		int currentCut = dynam(ribbonLength - piece);
		cuts = max(cuts, currentCut + (currentCut > 0? 1 : 0));
	}

	return cuts;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ribbonLength;
	cin >> ribbonLength;

	for(auto &element : pieceLength){
		cin >> element;
	}

	int result = dynam(ribbonLength)-1;
	cout << result << endl;

	return 0;
}