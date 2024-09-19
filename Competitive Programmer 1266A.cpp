#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


string isThisARedCandidate(string &string){
	int sum = 0, number = 0, zerosCount = 0, evenDigitsCount = 0;
	bool isDevisableBy3;
	
	for (auto &character : string)
	{
		if(character == '0'){			
			zerosCount++;
		}

		number = int(character)-48;
		sum += number;
		
		if(number % 2 == 0){
			evenDigitsCount++;
		}
	}

	isDevisableBy3 = (sum % 3 == 0);

	return (isDevisableBy3 && (zerosCount > 0) && (evenDigitsCount>1))? "red\n" : "cyan\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int numberOfTestCases;	
	string currentCase;

	cin >> numberOfTestCases;
	getline(cin, currentCase);
	for (int i = 0; i < numberOfTestCases; i++){
		getline(cin, currentCase);		
		cout << isThisARedCandidate(currentCase);
	}

	return 0;
}