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
	
	int numberOfNodes, numberOfEdges, pc1, pc2, numberOfPcWithNoConnection = 0, numberOfPcWith1Connection = 0, numberOfPcWith2Connections = 0, numberOfPcWithMoreConnections = 0;
    cin >> numberOfNodes >> numberOfEdges;
	int numberOfConnections[100001];
    for (int i = 0; i < 100001; i++)
    {
        numberOfConnections[i] = 0;
    }
    

	for (int i = 1; i < numberOfEdges + 1; i++){
		cin >> pc1 >> pc2;
        numberOfConnections[pc1] ++;
        numberOfConnections[pc2] ++;
	}

    for (int i = 1; i < numberOfNodes + 1; i++){
        switch (numberOfConnections[i])
        {
        case 0:
            numberOfPcWithNoConnection++;
            break;
        case 1:
            numberOfPcWith1Connection++;
            break;
        case 2:
            numberOfPcWith2Connections++;
            break;
        default:
            numberOfPcWithMoreConnections++;
            break;
        }
    }

    if(numberOfPcWith1Connection == 2 && numberOfPcWith2Connections == (numberOfNodes - 2)){
        cout << "bus topology\n";
    } else if(numberOfPcWith2Connections == numberOfNodes){
        cout << "ring topology\n";
    } else if(numberOfPcWith1Connection == (numberOfNodes-1) && numberOfPcWithMoreConnections == 1){
        cout << "star topology\n";
    } else {
        cout << "unknown topology\n";
    }

	return 0;
}