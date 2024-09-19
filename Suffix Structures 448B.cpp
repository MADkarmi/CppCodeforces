#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkArray(string t, string s){
	sort(t.begin(), t.end());
	sort(s.begin(), s.end());
	return t == s;
}

bool checkAutomation(string t, string s){
	int j = 0;
	for (int i = 0; i < t.length() && j < s.length(); i++)
	{
		j += (t[i] == s[j]);
	}
	return j == s.length();
}

bool checkBoth(string t, string s){
	for (int i = 0; i < s.length(); i++)
	{
		int index = t.find(s[i]);
		if(index == -1)
			return false;
		t[index] = '0';
	}
	return true;
}

void solve(string t, string s){
	if(checkArray(t, s)){
		cout << "array\n";
	} else if(checkAutomation(t, s)){
		cout << "automaton\n";
	} else if(checkBoth(t, s)){
		cout << "both\n";
	}else{
		cout << "need tree\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string stringT, stringS;
	getline(cin>>ws, stringT);
	getline(cin>>ws, stringS);
	solve(stringT, stringS);

	return 0;
}