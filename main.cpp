#include <iostream>
using namespace std;



int main() {
    int num1=0;
    int num2=0;
    int num3=0;
    int sum;
    for (int i=0; i<3; i++) {
        cout<<"Enter a positive integer: ";
        if (i == 0) {
            cin>>num1;
        }else if (i==1){
            cin>>num2;
        }else if (i==2){
            cin>>num3;
        }
    }
    cout<<num1<<num2<<num3<<endl;
    return 0;
}

/*
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void theRules();
int UIandCalculations(double &points, int pullNumber);

int main() {
  string start;

  theRules();
  cout << "To start, type start: ";
  cin >> start;

  //starts looping
  if (start == "start") {
    double points = 0;
    int maxLoops = 10;

    for (int pullNumber = maxLoops; pullNumber > 0; --pullNumber) {
      UIandCalculations(points, pullNumber);

      if (pullNumber == 1) {
        cout << "No more pulls. Your final points: " << points << "\n";
        break;
      }

      char choice;
      cout << "Continue? (y/n):";
      cin >> choice;

      if (choice == 'n' || choice == 'N') {
        points += (pullNumber - 1) * 100;
        cout << "Remaining pulls: " << pullNumber - 1 << "\n";
        cout << "Your final points: " << points << "\n";
        break;
      }
    }
  }
  
  else cout << "Congrats FAILURE! You failed the IQ test XD, no game for you! Go study.";
  return 0;
}

//THE HOUSE RULES
void theRules() {
  cout << "> HOUSE RULES <\n";
  cout << "1. 5 numbers (1~5), 3 output per row\n";
  cout << "2. 10 pulls in total, unused pulls weighs 100 points each\n";
  cout << "3. 2nd row weighs full value, while 1st and 3rd row weighs half the value\n";
  cout << "4. Perfect combinations: 111 (+111), 222 (+222), 333 (+333), 444 (+444), 555 (+555)\n";
  cout << "5. Palindrome combinations: X1X (+100), X3X (+150), X5X (+200), X2X (-200), X4X (-400) \n";
  cout << "6. Sequential combinations: 123 (/4), 234 (/4), 345 (/4), 543 (x4), 432 (x4), 321 (x4)\n";
  cout << "\n\n";
}

//the ui and calculations
int UIandCalculations(double &points, int pullNumber) {
  int x = time(0);
  srand(x);
  int row1[3] = {1 + rand() % 5 , 1 + rand() % 5 , 1 + rand() % 5};
  int row2[3] = {1 + rand() % 5 , 1 + rand() % 5 , 1 + rand() % 5};
  int row3[3] = {1 + rand() % 5 , 1 + rand() % 5 , 1 + rand() % 5};

  //perfect combination for row1
  if (row1[0] == row1[1] && row1[1] == row1[2]) {
    switch (row1[1]) {
      case 1:
        points += 111;
        break;
      case 2:
        points += 222;
        break;
      case 3:
        points += 333;
        break;
      case 4:
        points += 444;
        break;
      case 5:
        points += 555;
        break;
    }
  }

  //sequential combination for row 1
  if (row1[0] == row1[1]-1 && row1[1] == row1[2]-1) {
      points /= 4;
  } else if (row1[0] == row1[1]+1 && row1[1] == row1[2]+1){
      points *= 4;
  }

  //palindrome combination for row 1
  if ((row1[0] == row1[2]) && (row1[1] != row1[0])){
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
        break;
    }
  }

  //perfect combination for row2
  if (row2[0] == row2[1] && row2[1] == row2[2]) {
    switch (row2[1]) {
      case 1:
        points += 111;
        break;
      case 2:
        points += 222;
        break;
      case 3:
        points += 333;
        break;
      case 4:
        points += 444;
        break;
      case 5:
        points += 555;
        break;
    }
  }

  //sequential combination for row 2
  if (row2[0] == row2[1]-1 && row2[1] == row2[2]-1) {
      points /= 4;
  } else if (row2[0] == row2[1]+1 && row2[1] == row2[2]+1){
      points *= 4;
  }

  //palindrome combination for row 2
  if ((row2[0] == row2[2]) && (row2[1] != row2[0])){
    switch (row2[1]){
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

  //perfect combination for row3
  if (row3[0] == row3[1] && row3[1] == row3[2]) {
    switch (row3[1]) {
      case 1:
        points += 111;
        break;
      case 2:
        points += 222;
        break;
      case 3:
        points += 333;
        break;
      case 4:
        points += 444;
        break;
      case 5:
        points += 555;
        break;
    }
  }
  
  //sequential combination for row 3
  if (row3[0] == row3[1]-1 && row3[1] == row3[2]-1) {
      points /= 4;
  } else if (row3[0] == row3[1]+1 && row3[1] == row3[2]+1){
      points *= 4;
  }

  //palindrome combination for row 3
  if ((row3[0] == row3[2]) && (row3[1] != row3[0])){
    switch (row3[1]){
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

  //display
  cout << "\nPull #" << pullNumber << ":\n\n";
  cout << "| " << row1[0] << " || " << row1[1] << " || " << row1[2] << " | \n";
  cout << "[ " << row2[0] << " ][ " << row2[1] << " ][ " << row2[2] << " ] \n";
  cout << "| " << row3[0] << " || " << row3[1] << " || " << row3[2] << " | \n";
  cout << "\n";
  cout << "Points: " << fixed << setprecision(0) << points << "\n";

  return points;
}
*/
