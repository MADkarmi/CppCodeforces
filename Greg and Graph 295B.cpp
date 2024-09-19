#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>

using namespace std;

int deleted[502];
deque<long long> result;
int matrix [2][502][502];

void solve(int numberOfVertices){
    for (int k = 1; k <= numberOfVertices; k++)
    {
        long long sum = 0;
        for (int i = 0; i < numberOfVertices; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
            {
                int indexI = deleted[i], indexJ = deleted[j], indexK = deleted[k-1];
                matrix[k&1][indexI][indexJ] = min( matrix[(k+1)&1][indexI][indexJ],
                                                    matrix[(k+1)&1][indexI][indexK] + matrix[(k+1)&1][indexK][indexJ]);
                if(i<k && j<k){
                    sum += matrix[k&1][indexI][indexJ];
                }
            }
        }
        result.push_front(sum);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int numberOfVertices;
    cin >> numberOfVertices;
    result.clear();
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            cin >> matrix[0][i][j];
        }
    }

    for (int i = numberOfVertices-1; i >= 0; i--)
    {
        cin >> deleted[i], --deleted[i];
    }

    solve(numberOfVertices);

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i] << " \n"[i+1 == (int)result.size()];
    }

	return 0;
}
