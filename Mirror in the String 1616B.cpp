#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string &s, int stringLength){
	int k = 0;
	for (int i = 0; i < stringLength-1; i++)
	{
		if(s[i]<s[i+1]){
			break;
		}

		k++;
	}
	
	if(stringLength == 1 || s[0]==s[1]){
		cout << s[0] << s[0] << endl;
		return;
	}

	string resusltString = s.substr(0, k + 1);
	cout << resusltString;
	reverse(resusltString.begin(), resusltString.end());
	cout << resusltString  << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int numberOfTestCases, stringLength;
	string str;

	cin >> numberOfTestCases;
	while(numberOfTestCases > 0){
		cin >> stringLength;
		getline(cin>>ws, str);
		solve(str, stringLength);
		numberOfTestCases--;
	}
		

	return 0;
}