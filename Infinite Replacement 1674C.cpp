#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// t = a____ => -1
// t = 1 => 1
// t = 2^s.len


bool tCotainsA(string &s){
	for (char &c : s){
		if(c == 'a'){
			return true;
		}
	}
	return false;
}

long long int powerOf2(int factor){
	long long int pow = 1;
	for (int  i = 0; i < factor; i++)
	{
		pow *= 2;
	}

	return pow;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int numberOfTestCases, numberOfPossibleStrings = 0;	
	string sString, tString;

	cin >> numberOfTestCases;
	getline(cin, sString);
	for (int i = 0; i < numberOfTestCases; i++)
	{			
		getline(cin, sString);
		getline(cin, tString);
		
		if(tCotainsA(tString)){
			if(tString.size() == 1){
				cout << 1 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			
		}else{
			cout <<  powerOf2(sString.size()) << endl;
		}
	}	
	
	return 0;
}
