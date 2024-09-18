#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void theRules();

void CombinationsDivision(int row[3], double &points);
void CombinationsSqrt(int row[3], double &points);

int UI_n_Calc(double &points, int pullNumber);

// Global variables here, but strongly not recommended
int row1[3];
int row2[3];
int row3[3];
double points = 0;

int main() {
    string start;

    theRules();
    cout << "To start, type start: ";
    cin >> start;

    // Integrate the code from piriya here
    if (start == "start") {
        int maxLoops = 10;

        for (int pullNumber = maxLoops; pullNumber > 0; --pullNumber) {
            UI_n_Calc(points, pullNumber);

            char choice;
            cout << "Continue? (y/n):";
            cin >> choice;

            if (choice == 'n' || choice == 'N') {
                points += (pullNumber - 1) * 100;
                break;
            }
        }

        cout << "Final Points after 10 pulls: " << points << "\n";
    }

    return 0;
}

// THE HOUSE RULES
void theRules() {
    cout << "> HOUSE RULES <\n";
    cout << "1. 5 numbers (1~5), 3 output per row\n";
    cout << "2. 2nd row weighs full value, while 1st and 3rd row weighs half the value\n";
    cout << "3. Perfect combinations: 111 (+111), 222 (+222), 333 (+333), 444 (+444), 555 (+555)\n";
    cout << "4. Palindrome combinations: X1X (+100), X3X (+150), X5X (+200), X2X (-200), X4X (-400) \n";
    cout << "5. Sequential combinations: 123 (/4), 234 (/4), 345 (/4), 543 (sqrt), 432 (sqrt), 321 (sqrt)\n";
    cout << "\n\n";
}

// Command prompt UI and calculation are here
int UI_n_Calc(double &points, int pullNumber) {
    int x = time(0);
    srand(x);
    row1[0] = 1 + rand() % 5;
    row1[1] = 1 + rand() % 5;
    row1[2] = 1 + rand() % 5;

    row2[0] = 1 + rand() % 5;
    row2[1] = 1 + rand() % 5;
    row2[2] = 1 + rand() % 5;

    row3[0] = 1 + rand() % 5;
    row3[1] = 1 + rand() % 5;
    row3[2] = 1 + rand() % 5;

    // Palindrome combination by Sam
    // Palindrome combination row 1
    if ((row1[0] == row1[2]) && (row1[1] != row1[0])) {
        switch (row1[1]) {
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
            break;
        }
    }
    // Palindrome combination row 2

    if ((row2[0] == row2[2]) && (row2[1] != row2[0])) {
        switch (row2[1]) {
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
            break;
        }
    }
    // Palindrome combination row 3
    if ((row3[0] == row3[2]) && (row3[1] != row3[0])) {
        switch (row3[1]) {
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
            break;
        }
    }

    // Sequential combination by Majid =================
    // Sequential combinations: 123 (/4), 234 (/4), 345 (/4), 543 (sqrt), 432 (sqrt), 321 (sqrt)

    // Call these functions for each row in your main logic
    CombinationsDivision(row1, points);
    CombinationsSqrt(row1, points);

    CombinationsDivision(row2, points);
    CombinationsSqrt(row2, points);

    CombinationsDivision(row3, points);
    CombinationsSqrt(row3, points);

    
/*
    
   //for row 1
   if (row1[0] == row1[1]-1 && row1[1] == row1[2]-1) {
       points /= 4;
   } else if (row1[0] == row1[1]+1 && row1[1] == row1[2]+1){
       points = sqrt(points);
   }
   
   //for row 2
   if (row2[0] == row2[1]-1 && row2[1] == row2[2]-1) {
       points /= 4;
   } else if (row2[0] == row2[1]+1 && row2[1] == row2[2]+1){
       points = sqrt(points);
   }
   
   //for row 3
   if (row3[0] == row3[1]-1 && row3[1] == row3[2]-1) {
       points /= 4;
   } else if (row3[0] == row3[1]+1 && row3[1] == row3[2]+1){
       points = sqrt(points);
   }
   

   

   //Sequential combinations row1
   if (row1[0] == 1 && row1[1] == 2 && row1[2] == 3) {
       points /= 4;
   }
   if (row1[0] == 2 && row1[1] == 3 && row1[2] == 4) {
       points /= 4;
   }
   if (row1[0] == 3 && row1[1] == 4 && row1[2] == 5) {
       points /= 4;
   }
   if (row1[0] == 5 && row1[1] == 4 && row1[2] == 3) {
       points = sqrt(points);
   }
   if (row1[0] == 4 && row1[1] == 3 && row1[2] == 2) {
       points = sqrt(points);
   }
   if (row1[0] == 3 && row1[1] == 2 && row1[2] == 1) {
       points = sqrt(points);
   }
   
   //Sequential combinations row2
   if (row2[0] == 1 && row2[1] == 2 && row2[2] == 3) {
       points /= 4;
   }
   if (row2[0] == 2 && row2[1] == 3 && row2[2] == 4) {
       points /= 4;
   }
   if (row2[0] == 3 && row2[1] == 4 && row2[2] == 5) {
       points /= 4;
   }
   if (row2[0] == 5 && row2[1] == 4 && row2[2] == 3) {
       points = sqrt(points);
   }
   if (row2[0] == 4 && row2[1] == 3 && row2[2] == 2) {
       points = sqrt(points);
   }
   if (row2[0] == 3 && row2[1] == 2 && row2[2] == 1) {
       points = sqrt(points);
   }
   
   //Sequential combinations row3
   if (row3[0] == 1 && row3[1] == 2 && row3[2] == 3) {
       points /= 4;
   }
   if (row3[0] == 2 && row3[1] == 3 && row3[2] == 4) {
       points /= 4;
   }
   if (row3[0] == 3 && row3[1] == 4 && row3[2] == 5) {
       points /= 4;
   }
   if (row3[0] == 5 && row3[1] == 4 && row3[2] == 3) {
       points = sqrt(points);
   }
   if (row3[0] == 4 && row3[1] == 3 && row3[2] == 2) {
       points = sqrt(points);
   }
   if (row3[0] == 3 && row3[1] == 2 && row3[2] == 1) {
       points = sqrt(points);
   }
*/
    
    
    // Display
    cout << "\nPull #" << pullNumber << ":\n\n";
    cout << "| " << row1[0] << " || " << row1[1] << " || " << row1[2] << " | \n";
    cout << "[ " << row2[0] << " ][ " << row2[1] << " ][ " << row2[2] << " ] \n";
    cout << "| " << row3[0] << " || " << row3[1] << " || " << row3[2] << " | \n";
    cout << "\n";
    cout << "Points: " << points << "\n";

    return points;
}

// Sequential combinations by Majid
void CombinationsDivision(int row[3], double &points) {
    if (row[0] == 1 && row[1] == 2 && row[2] == 3) {
        points /= 4;
    }
    if (row[0] == 2 && row[1] == 3 && row[2] == 4) {
        points /= 4;
    }
    if (row[0] == 3 && row[1] == 4 && row[2] == 5) {
        points /= 4;
    }
}

// Pattern combinations
void CombinationsSqrt(int row[3], double &points) {
    if (row[0] == 5 && row[1] == 4 && row[2] == 3) {
        points = sqrt(points);
    }
    if (row[0] == 4 && row[1] == 3 && row[2] == 2) {
        points = sqrt(points);
    }
    if (row[0] == 3 && row[1] == 2 && row[2] == 1) {
        points = sqrt(points);
    }
}
