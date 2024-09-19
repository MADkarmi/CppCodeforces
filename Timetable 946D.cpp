#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;

vector<int> lessons[500];
int dp[500][501];
int transition[500][501];

void initialize(){
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 501; j++)
        {
            dp[i][j] = -1;
        }
    }
}

void calculateTransition(int day){
    int tmp[501];
    for (int i = 0; i < 501; i++)
    {
        tmp[i] = INT_MAX;
    }
    int size = lessons[day].size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            tmp[size-(j-i+1)] = min(tmp[size-(j-i+1)], lessons[day][j]-lessons[day][i]+1);
        }
    }
    for (int i = 0; i < 501; i++)
    {
        transition[day][i] = min(tmp[i], (i==0? INT_MAX : transition[day][i-1]));
        if( i >= size) transition[day][i] = 0;
    }
}

int calcResult(int day, int numberOfLessons, int numberOfDays){
    if(day >= numberOfDays) return 0;
    if(dp[day][numberOfLessons] != -1) return dp[day][numberOfLessons];
    int best = INT_MAX;
    for (int i = 0; i <= numberOfLessons; i++)
    {
        best = min(best, transition[day][i] + calcResult(day+1, numberOfLessons-i, numberOfDays));
    }
    return dp[day][numberOfLessons] = best;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int numberOfDays, numberOfWorkingHours, numberOfLessons;
    cin >> numberOfDays >> numberOfWorkingHours >> numberOfLessons;
    char c;
    for (int i = 0; i < numberOfDays; i++)
    {
        for (int j = 0; j < numberOfWorkingHours; j++)
        {
            cin >> c;
            if(c=='1'){
                lessons[i].push_back(j);
            }
        }
    }

    initialize();
    
    for (int i = 0; i < numberOfDays; i++)
    {
        calculateTransition(i);
    }


    cout << calcResult(0,numberOfLessons, numberOfDays) << endl;

	return 0;
}
