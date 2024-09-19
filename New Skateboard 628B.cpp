#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

bool lastTwoDevisibleBy4(char &firstNumber, char &seconfNumber){
	int number = ((firstNumber - '0') * 10 + (seconfNumber - '0'));
	return (number % 4 == 0) ? true : false;
}

int main()
{
	char input[300020];
				
	long long int sumOfNumbers = 0;
	scanf("%s", &input);
	int n = strlen(input);

	if((input[0]-'0') % 4 == 0){
			sumOfNumbers++;
	}

	for(int j = n-1; j>0; j--){
		if((input[j]-'0') % 4 == 0){
			sumOfNumbers++;
		}
		if(lastTwoDevisibleBy4(input[j-1], input[j])){
			sumOfNumbers += j;
		}
	}

	printf("%lld\n", sumOfNumbers);

	return 0;
}
