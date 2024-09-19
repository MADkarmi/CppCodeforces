#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int numberOfPlanes;
    cin >> numberOfPlanes;
	int fi[5001];
    bool loveTriangleExists = false;

	for (int i = 1; i < numberOfPlanes + 1; i++){
		cin >> fi[i];
	}

    for (int i = 1; i < numberOfPlanes + 1; i++)
    {
        if(fi[fi[fi[i]]] == i){
            loveTriangleExists = true;
        }
    }
    loveTriangleExists? cout << "YES" : cout << "NO";
	return 0;
}