#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

void input();
void solve();

const string placeName[4] = {
  "Billion",
  "Million",
  "Thousand",
  "Hundred",
};

const ll placeNumber[4] = {
  1000000000,
  1000000,
  1000,
  100,
};

const string englishNumber[10] = {
  "One", "Two", "Three", "Four", "Five",
  "Six", "Seven", "Eight", "Nine", 
};

const string tenPlaceName[10] = { 
  "Ten", "Twenty", "Thirty", "Fourty", "Fifty","Sixty", "Seventy", "Eighty", "Ninety"
};

const string tenthName[10] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

const string eleven = "Eleven";
const string twelve = "Twelve";

ll inputNumber;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> inputNumber;
  return;
}

void printUnderThousand(int partialInputNumber) {
  if (partialInputNumber / 100) {
    cout << englishNumber[(partialInputNumber / 100) - 1] << " " << placeName[3] << " ";
    partialInputNumber %= 100;
  }

  if (partialInputNumber / 10 == 1 && partialInputNumber % 10 != 0) { 
    cout << tenthName[partialInputNumber % 10 - 1] << " ";
    return;
  }

  if(partialInputNumber / 10) {
    cout << tenPlaceName[(partialInputNumber /10) - 1] << " ";
    partialInputNumber %= 10;
  }

  if (partialInputNumber > 0) {
    cout << englishNumber[(partialInputNumber) - 1] << " ";
  }
}

void solve() {
  if (inputNumber == 0) {
    cout << "Zero";
    return;
  }

  for (int i = 0; i < 3; i++) {
    if (inputNumber / placeNumber[i] > 0) {
      printUnderThousand(inputNumber / placeNumber[i]);
      cout << placeName[i] << " ";
      inputNumber %= placeNumber[i];
    }
  }
  
  printUnderThousand(inputNumber);

  return;
}
