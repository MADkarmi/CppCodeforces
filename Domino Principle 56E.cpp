#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include <stack>

using namespace std;

const int N = 1e8+10;
const int N1 = 1e5+1;
struct domino{
    int positionX;
    int height;
    int index;
};

bool compare(domino d1, domino d2){
    return d1.positionX<d2.positionX;
}

domino dominos[N1];
stack<int> stac;
int result[N1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numberOfDominoes, positionX, height;


	cin >> numberOfDominoes;
    for (int i = 0; i < numberOfDominoes; i++)
    {
        cin >> positionX >> height;
        dominos[i] = {positionX, height, i};
    }

    sort(dominos, dominos+numberOfDominoes, compare);
    for (int i = numberOfDominoes-1; i >= 0; i--)
    {
        result[dominos[i].index] = 1;
        while (!stac.empty() && dominos[i].positionX+dominos[i].height > dominos[stac.top()].positionX)
        {
            result[dominos[i].index]+=result[dominos[stac.top()].index];
            stac.pop();
        }
        stac.push(i);
    }

    for (int i = 0; i < numberOfDominoes; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
	return 0;
}
