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
	
	int numberOfQueries, numberOfButtonsA, numberOfButtonsB, numberOfButtonsC;
	string first = "First\n", second = "Second\n";

	cin >> numberOfQueries;
	while(numberOfQueries > 0){
		cin >> numberOfButtonsA >> numberOfButtonsB >> numberOfButtonsC; 
		if(numberOfButtonsA + numberOfButtonsC > numberOfButtonsB + numberOfButtonsC)
		{
			cout<< first;
		} else if (numberOfButtonsA + numberOfButtonsC < numberOfButtonsB + numberOfButtonsC)
		{
			cout<< second;
		} else if ((numberOfButtonsA + numberOfButtonsB + numberOfButtonsC) % 2 == 0){
				cout << second;
		} else {
				cout << first;
		}
	
		numberOfQueries--;
	}


	return 0;
}