#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;
const int N = 5e5+50;

int pre[N] = {0}, result[2] = {0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string s1, s2;
    getline(cin>>ws, s1);
    getline(cin>>ws, s2);

    for (int i = 0, j = 0; i < (int)s2.length(); i++)
    {
        while (j>0 && s2[j] != s2[i])
        {
            j = pre[j];
        }
        if(s2[i]==s2[j]){
            j++;
        }
        pre[i] = j;
    }

    for (int i = 0; i < (int)s1.length(); i++)
    {
        result[s1[i]-'0']++;
    }
    for (int i = 0, j = 0; i < (int)s1.length(); i++, j++)
    {
        if(s2[j] == '0'){
            if(result[0] > 0){
                cout << "0";
                result[0]--;
            }
            else break;
        }
        else{
            if(result[1] > 0){
                cout << "1";
                result[1]--;
            }
            else break;
        }
        if(j == (int)s2.length()){
            j = pre[(int)s2.length()];
        }
    }

    while (result[1] > 0)
    {
        cout <<"1";
        result[1]--;
    }
    while (result[0] > 0)
    {
        cout <<"0";
        result[0]--;
    }

	return 0;
}
