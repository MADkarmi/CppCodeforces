#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <deque>
using namespace std;

int treeRoot = 0, numberOfElementsToChange = 0;
vector<int> parent(200002);
vector<int> treeData[200001];
vector<int> color(200002);


void dfs(int sourceIndex){
    color[sourceIndex] = 1;

    int dataSize = treeData[sourceIndex].size();
    for (int i = 0; i < dataSize; i++)
    {
        if(sourceIndex == treeData[sourceIndex][i]){
            if(treeRoot == 0){
                treeRoot = sourceIndex;
            }
            else if (treeRoot != sourceIndex)
            {
                parent[sourceIndex] = treeRoot;
                numberOfElementsToChange++;
            }

        }
        else if (color[treeData[sourceIndex][i]] == 0)
        {
            dfs(treeData[sourceIndex][i]);
        }
        else if (color[treeData[sourceIndex][i]] == 1)
        {
            if(treeRoot == 0){
                treeRoot = sourceIndex;
            }
            parent[sourceIndex] = treeRoot;
            numberOfElementsToChange++;
        }
    }

    color[sourceIndex] = 2;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int numberOfNodes, nodeParent;
    cin >> numberOfNodes;
    for (int i = 1; i <= numberOfNodes; i++)
    {
        cin >> nodeParent;
        parent[i] = nodeParent;
        treeData[i].push_back(nodeParent);
        if(treeRoot == 0 && i == parent[i]){
            treeRoot = i;
        }
    }

    for (int i = 1; i <= numberOfNodes; i++)
    {
        if(color[i] == 0){
            dfs(i);
        }
    }

    cout << numberOfElementsToChange << "\n";
    for (int i = 1; i <= numberOfNodes; i++)
    {
        cout << parent[i]<< " ";
    }

	return 0;
}
