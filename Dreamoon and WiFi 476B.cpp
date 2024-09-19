#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string sentCommands, recievedCommands;
	double ppbOfEndingInSamePlace(0);
	int position = 0, numberOfErrors = 0;
	
	getline(cin>>ws, sentCommands);
	getline(cin>>ws, recievedCommands);
	
	for (int i = 0; i < sentCommands.length(); i++)
	{
		numberOfErrors += recievedCommands[i] == '?'? 1 : 0;
		position += (sentCommands[i] == '+')? 1 : -1;

		switch (recievedCommands[i])
		{
		case '+':
			position--;
			break;
		case '-':
			position++;
			break;
		}
	}
	
	for (int posibility = 0; posibility < (1<<numberOfErrors); posibility++)
	{
		int currentPosition = position, currentPosibility = posibility;
		for (int j = 1; j <= numberOfErrors; j++)
		{
			currentPosition += (currentPosibility % 2) ? 1 : -1;
			currentPosibility /=2;
		}
		ppbOfEndingInSamePlace += (currentPosition == 0)? 1.0 : 0.0;
		
	}
	ppbOfEndingInSamePlace /= (double)(1 << numberOfErrors);
	
	cout << fixed << setprecision(12) << ppbOfEndingInSamePlace << endl;
	return 0;
}