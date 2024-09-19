#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define topLeft(x,y)  ((--x >= 0) && (--y >= 0))
#define topRight(x,y, col) ((--x >= 0) && (++y < col))
#define bottomLeft(x,y, row, col) ((++x < row) && (--y >= 0))
#define bottomRight(x,y, row, col) ((++x < row) && (++y < col))

enum Direction{
	topLeft,
	topRight,
	bottomLeft,
	bottomRight,
};

int cell[200][200] = {0};


int calculateDiagonalSum(Direction direction, int x, int y, int row, int col, int sum = 0){
	bool shiftUntil;
	switch (direction)
	{
		case topLeft:
			while(topLeft(x, y)){
					sum+=cell[x][y];
			}
			break;
		case topRight:
			while(topRight(x, y, col)){
					sum+=cell[x][y];
			}
			break;
		case bottomLeft:
			while(bottomLeft(x, y, row, col)){
					sum+=cell[x][y];
				}
			break;
		default:
			while(bottomRight(x, y, row, col)){
					sum+=cell[x][y];
				}
			break;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int numberOfTestCases;
	vector<int> results;
	
	int rows = 0, columns = 0, maxSum = 0, sumForCalculatedCell = 0;

	cin >> numberOfTestCases;
	while(numberOfTestCases > 0){
		cin >> rows >> columns;
		
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				cin >> cell[i][j];
			}			
		}

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				sumForCalculatedCell = cell[i][j];
				
				int x = i, y = j;
				
				sumForCalculatedCell += calculateDiagonalSum(topLeft, i, j, rows, columns);
				sumForCalculatedCell += calculateDiagonalSum(topRight, i, j, rows, columns);
				sumForCalculatedCell += calculateDiagonalSum(bottomLeft, i, j, rows, columns);
				sumForCalculatedCell += calculateDiagonalSum(bottomRight, i, j, rows, columns);

				maxSum = sumForCalculatedCell>maxSum ? sumForCalculatedCell : maxSum;				
				sumForCalculatedCell = 0;
			}			
		}

		results.push_back(maxSum);
		maxSum = 0;
	 	numberOfTestCases--;
	}

	for(auto & result : results){
		cout << result << endl;
	}

	return 0;
}