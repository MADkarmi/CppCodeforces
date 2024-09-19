#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;
const int N = 1e5+1;
long long mark[N];
set<long long> marks;

long long solve(long long numberOfMarks, long long lengthOfRuler, long long jumpNormsForBoiz, long long jumpNormsForGirls){
    for (int i = 0; i < numberOfMarks; i++)
    {
        if(mark[i] + jumpNormsForGirls <= lengthOfRuler &&
            (marks.count(mark[i] + jumpNormsForGirls + jumpNormsForBoiz) || marks.count(mark[i] + jumpNormsForGirls - jumpNormsForBoiz))){
                return mark[i] + jumpNormsForGirls;
            }
        if(mark[i] - jumpNormsForGirls >= 0 &&
            (marks.count(mark[i] - jumpNormsForGirls + jumpNormsForBoiz) || marks.count(mark[i] - jumpNormsForGirls - jumpNormsForBoiz))){
                return mark[i] - jumpNormsForGirls;
            }
    }
    return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    bool normsForGirls = false, normsForBoiz = false;
    long long numberOfMarks, lengthOfRuler, jumpNormsForBoiz, jumpNormsForGirls;
    cin >> numberOfMarks >> lengthOfRuler >> jumpNormsForGirls >> jumpNormsForBoiz;

    for (int i = 0; i < numberOfMarks; i++)
    {
        cin >> mark[i];
        marks.insert(mark[i]);
        if(mark[i] == jumpNormsForBoiz){
            normsForBoiz = true;
        }
        if(mark[i] == jumpNormsForGirls){
            normsForGirls = true;
        }
    }

    for (int i = 0; i < numberOfMarks; i++)
    {
        if(marks.count(mark[i] + jumpNormsForBoiz)){
            normsForBoiz = true;
        }
    }

    for (int i = 0; i < numberOfMarks; i++)
    {
        if(marks.count(mark[i]+jumpNormsForGirls)){
            normsForGirls = true;
        }
    }

    if(normsForBoiz && normsForGirls){
        cout << "0\n";
    }
    else if (!normsForBoiz && normsForGirls)
    {
        cout << "1\n" << jumpNormsForBoiz << endl;
    }
    else if (normsForBoiz && !normsForGirls)
    {
        cout << "1\n" << jumpNormsForGirls << endl;
    }
    else{
        long long result = solve(numberOfMarks, lengthOfRuler, jumpNormsForBoiz, jumpNormsForGirls);
        if(result==-1){
            cout << "2\n" << jumpNormsForGirls << " " << jumpNormsForBoiz << endl;
        }
        else{
            cout << "1\n" << result << endl;
        }
    }

	return 0;
}
