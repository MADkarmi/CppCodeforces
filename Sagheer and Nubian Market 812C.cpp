#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long int priceCalculation(long long int k, long long int numberOfSouvenirs, vector<long long int> &costRecalculation, const vector<long long int> &baseCostOfSouvenir){
    for (long long int i = 0; i < numberOfSouvenirs; i++)
    {
        costRecalculation[i] = baseCostOfSouvenir[i] + (i+1)*k;
    }

    sort(costRecalculation.begin(), costRecalculation.end());

    long long int price = 0;
    for (long long int i = 0; i < k; i++)
    {
        price += costRecalculation[i];
    }

    return price;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int numberOfSouvenirs, price = 0;
    long long int sagheerBudget;
	cin >> numberOfSouvenirs >> sagheerBudget;

    vector<long long int> baseCostOfSouvenir(numberOfSouvenirs);
    vector<long long int> costRecalculation(numberOfSouvenirs);

    for(auto &souvenir : baseCostOfSouvenir){
        cin >> souvenir;
    }

    long long int highPoint = numberOfSouvenirs, lowPoint = 0, mediumPoint, maxNumberOfSouvenirs = 0, minimalTotalCost = 0;
    while ( highPoint >= lowPoint )
    {
        mediumPoint = (lowPoint + highPoint)/2;

        price = priceCalculation(mediumPoint, numberOfSouvenirs, costRecalculation, baseCostOfSouvenir);
        if(price == sagheerBudget){
            cout<< mediumPoint << " "  << sagheerBudget << endl;
            return 0;
        }

        if(price > sagheerBudget){
            highPoint = mediumPoint - 1;
        }
        else{
            lowPoint = mediumPoint + 1;
            maxNumberOfSouvenirs = mediumPoint;
            minimalTotalCost = price;
        }
    }

    cout << maxNumberOfSouvenirs << " " << minimalTotalCost << endl;
	return 0;
}