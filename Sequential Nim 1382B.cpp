#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int pilesElements[100001];	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int numberOfQueries, numberOfPiles, firstPlayerIsForced = 0;
	
	cin >> numberOfQueries;
	
	while(numberOfQueries > 0){
		cin >> numberOfPiles;
		for (int i = 0; i < numberOfPiles; i++)
		{
			cin>>pilesElements[i];
		}
		
		//how many times player is forced to take elements
		while(firstPlayerIsForced < numberOfPiles && pilesElements[firstPlayerIsForced] == 1){
			firstPlayerIsForced++;
		}
		cout << ((firstPlayerIsForced==numberOfPiles)^(firstPlayerIsForced%2)? "Second\n" : "First\n");
		
		firstPlayerIsForced = 0;
		numberOfQueries--;
	}

	return 0;
}