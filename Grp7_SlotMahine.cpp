#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void display_rules();
int UI_n_Calc();
int calculation;

int main(){
	
	string start;
	
	display_rules();
	cout << "To start, type start: ";
	cin >> start;
	
	//looping starts here
	if (start == "start"){
		int points;
		bool cont = true;
		char al;
		
		while (cont == 1){
			
			UI_n_Calc();
			
			//Continuation choice
			char choice;
			cout << "Continue? (y/n):";
			cin >> choice;
			if (choice == 'n' || choice == 'N'){
				cont = false;
			}
		}
	}
	
	
	return 0;
}

//display the rules for the player (uncompleted)
void display_rules() {
	cout << "Rules:\n";
	cout << "5 numbers (1~5), 3 output per row\n";
	cout << "2nd row weighs full value, while 1st and 3rd row weighs half the value\n";
    cout << "Perfect combinations: 111 (+111), 222 (+222), 333 (+333), 444 (+444), 555 (+555)\n";
    cout << "Sequential combinations: 123 (/4), 234 (/4), 345 (/4), 543 (sqrt), 432 (sqrt), 321 (sqrt)\n";
    cout << "\n\n";
}

//command prompt ui and calculation is here
int UI_n_Calc(){
	int points;
	int x = time(0);
	srand(x);
	int row1[3] = {1 + rand() % 5 , 1 + rand() % 5 , 1 + rand() % 5};
	int row2[3] = {1 + rand() % 5 , 1 + rand() % 5 , 1 + rand() % 5};
	int row3[3] = {1 + rand() % 5 , 1 + rand() % 5 , 1 + rand() % 5};

	//palindrome combination row 1
	if (row1[0] == row1[2]){
		switch (row1[1]){
			case 1:
				points = points + 50;
				break;
			
			case 2:
				points = points - 100;
				break;
			
			case 3:
				points = points + 75;
				break;
				
			case 4:
				points = points - 200;
				break;
				
			case 5:
				points = points + 100;
				break;
				
			default:
				points = points;
		}
	}

	//palindrome combination row 2
	if (row2[0] == row2[2]){
		switch (row1[1]){
			case 1:
				points = points + 100;
				break;
			
			case 2:
				points = points - 200;
				break;
			
			case 3:
				points = points + 150;
				break;
				
			case 4:
				points = points - 400;
				break;
				
			case 5:
				points = points + 200;
				break;
				
			default:
				points = points;
		}
	}
	
	//palindrome combination row 3
	if (row3[0] == row3[2]){
		switch (row1[1]){
			case 1:
				points = points + 50;
				break;
			
			case 2:
				points = points - 100;
				break;
			
			case 3:
				points = points + 75;
				break;
				
			case 4:
				points = points - 200;
				break;
				
			case 5:
				points = points + 100;
				break;
				
			default:
				points = points;
		}
	}	
	
	//the display part
	cout << "\n";
	cout << "Points: " << points << "\n";
	cout << "1st | " << row1[0] << " || " << row1[1] << " || " << row1[2] << " | \n";
	cout << "2nd | " << row2[0] << " || " << row2[1] << " || " << row2[2] << " | \n";
	cout << "3rd | " << row3[0] << " || " << row3[1] << " || " << row3[2] << " | \n";
	cout << "\n\n";

}
