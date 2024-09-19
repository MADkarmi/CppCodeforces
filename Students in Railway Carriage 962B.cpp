#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int totalNumberOfSeats, numberOfProgrammersToPlace, numberOfAthletesToPlace, numberOfEmptySeats = 0, numberOfStudentsWhoCanSeat = 0;
	string seats(200005, 'x');
	
	cin >> totalNumberOfSeats >> numberOfProgrammersToPlace >> numberOfAthletesToPlace;
	
	if(numberOfProgrammersToPlace < numberOfAthletesToPlace){
		swap(numberOfProgrammersToPlace,numberOfAthletesToPlace);
	}

	
	for(int i = 0; i < totalNumberOfSeats; i++){
		cin >> seats[i];
		if(seats[i] == '.'){
			numberOfEmptySeats++;
			if(numberOfProgrammersToPlace > 0){
				if(i == 0){
					numberOfStudentsWhoCanSeat++;
					numberOfProgrammersToPlace--;
					seats[i] = 'p';
				}
				if(i > 0){
					if(seats[i-1] != 'p'){
						numberOfStudentsWhoCanSeat++;
						numberOfProgrammersToPlace--;
						seats[i] = 'p';
					}
				}
			}
		}
	} 
	
	numberOfEmptySeats -= numberOfStudentsWhoCanSeat;
	numberOfStudentsWhoCanSeat += min(numberOfEmptySeats, numberOfAthletesToPlace);

	cout << numberOfStudentsWhoCanSeat;

	return 0;
}