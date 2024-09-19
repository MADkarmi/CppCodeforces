#include <cstdint>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cmath>

using namespace std;

struct Point{
	double x, y;

	Point(){};
	Point(double x, double y) :x(x), y(y){}

	Point operator - (const Point &b) const{
		return Point(x - b.x, y - b.y);
	}

	Point operator + (const Point &b) const{
		return Point(x + b.x, y + b.y);
	}

	Point operator * (const double k) const{
		return Point(k * x, k * y);
	}

	Point operator / (const double k) const{
		return Point(x / k, y / k);
	}

	double Slope(){
		return y / x;
	}
};

typedef Point Vector;

double Len(Vector V){
	return sqrt(V.x * V.x + V.y * V.y);
}

double Cross(Vector &a,Vector &b){
	return a.x * b.y - a.y * b.x;
}

double DistanceToLine(Point P,Point A,Point B){
	Vector V1 = B-A, V2 = P-A;
	return fabs(Cross(V1,V2))/Len(V1);
}

int numberOfVertices;
Point p[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	double result=1e10;

	cin >> numberOfVertices;
	for(int i = 0; i < numberOfVertices ; i++){
		cin >> p[i].x >> p[i].y;
	}

	for(int i = 0; i < numberOfVertices; i++){
		for(int j = i + 1; j < numberOfVertices; j++){
			if(result > Len(p[i] - p[j])){
				result = Len(p[i] - p[j]);
			}
		}
	}

	double d;
	for(int i = 1; i < numberOfVertices + 1; i++){
		d = DistanceToLine(p[i%numberOfVertices], p[(i-1)%numberOfVertices], p[(i+1)%numberOfVertices])/2;
		if(result > d){
			result = d;
		}
	}
	cout << fixed << setprecision(10) << result << endl;
	return 0;
}