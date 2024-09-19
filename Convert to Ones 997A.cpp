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

	int stringLength, firstOpCost, secondOpCost, numberOfZeroChunks=0;

	cin >> stringLength >> firstOpCost >> secondOpCost;
	string str;
	getline(cin>>ws, str);

	for (int i = 0, j = 0; i < stringLength; i=j)
	{
		while(j<stringLength && str[i]==str[j]){
			j++;
		}
		if(str[i]=='0'){
			numberOfZeroChunks++;
		}
	}


	if(!numberOfZeroChunks)
	{
		cout << 0;
	}
	else if (firstOpCost < secondOpCost)
	{
		cout << firstOpCost * (numberOfZeroChunks - 1ll) + secondOpCost;
	}
	else
	{
		cout << 1ll * secondOpCost * numberOfZeroChunks;
	}

	return 0;
}