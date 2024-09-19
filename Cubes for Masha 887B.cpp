#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int faces[3][6];
	int numberOfCubes, maxNumberCreatedByNumbersOnCubes;
	map<int, int> numbersCreated;
	cin >> numberOfCubes;

	for(int i = 0; i<numberOfCubes; i++){
		for(int j = 0; j<6; j++){
			cin >> faces[i][j];
			numbersCreated[faces[i][j]] = 1;
		}
	}

	for (int i = 0; i < numberOfCubes; i++)
	{
		for (int j = i+1; j < numberOfCubes; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				for (int l = 0; l < 6; l++)
				{
					maxNumberCreatedByNumbersOnCubes = faces[i][l]*10 + faces[j][k];
					numbersCreated[maxNumberCreatedByNumbersOnCubes] = 1;
					maxNumberCreatedByNumbersOnCubes = faces[j][l]*10 + faces[i][k];
					numbersCreated[maxNumberCreatedByNumbersOnCubes] = 1;
				}

			}

		}

	}

	for(int i = 1; i<=99; i++){
		if(!numbersCreated[i]){
			cout << i - 1;
			break;
		}
	}

	return 0;
}