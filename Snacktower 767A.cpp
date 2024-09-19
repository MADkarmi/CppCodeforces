#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool snackHasFallen[100001];

int dipslaySnackStackOrder(int snackId, int currentSnackId){
	for(int i = currentSnackId; i>0; i--){
		if(!snackHasFallen[i]){
			break;
		}
		if(snackHasFallen[i]){
			cout << i << " ";
			snackHasFallen[i]=false;
			currentSnackId = i-1;
		}
	}
	cout << "\n";
	return currentSnackId;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int numberOfSnacks, snackID, currentMaxSnackID = 0;
	cin >> numberOfSnacks;
	currentMaxSnackID = numberOfSnacks;
	for(int i = 0; i < numberOfSnacks; i++ ){
		cin >> snackID;
		snackHasFallen[snackID] = true;
		currentMaxSnackID = dipslaySnackStackOrder(snackID, currentMaxSnackID);
	}

	return 0;
}