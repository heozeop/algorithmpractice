#include <algorithm>
#include <iostream>
using namespace std;

const int MAXIMUMVALUE = 1000000002;
const int MIMIMUMVALUE = -1000000002;
const int MAXSIZEOFARRAY = 15;
const int NUMBEROFOPERATOR = 4;

int numbers[MAXSIZEOFARRAY];
int operators[4];
int numberOfArray;
long long maxNum = MIMIMUMVALUE, minNum = MAXIMUMVALUE;

long long calculator(int opType, long long value, int index) {
  switch (opType) {
  case 0:
    return value + numbers[index];
  case 1:
    return value - numbers[index];
  case 2:
    return value * numbers[index];
  case 3:
    if (value < 0 || numbers[index] < 0) {
      return -1 * (abs(value) / abs(numbers[index]));
    }
    return value / numbers[index];
  }
}

long long calAndPrintLargestAndLowestResults(long long value, int remain) {
  if (remain == 1) {
    return value;
  }

  long long temp;
  for (int i = 0; i < NUMBEROFOPERATOR; i++) {
    if (operators[i] == 0)
      continue;

    operators[i]--;
    temp = calAndPrintLargestAndLowestResults(
        calculator(i, value, numberOfArray - remain + 1), remain - 1);
    maxNum = max(maxNum, temp);
    minNum = min(minNum, temp);
    operators[i]++;
  }
  return temp;
}

int main(void) {
  cin >> numberOfArray;
  for (int i = 0; i < numberOfArray; i++) {
    cin >> numbers[i];
  }
  for (int i = 0; i < NUMBEROFOPERATOR; i++) {
    cin >> operators[i];
  }

  calAndPrintLargestAndLowestResults(numbers[0], numberOfArray);
  cout << maxNum << "\n" << minNum;
}
