#include <algorithm>
#include <iostream>
using namespace std;

const int MAXSIZE = 1001;

int sequence[MAXSIZE];
int leftSide[MAXSIZE];
int rightSide[MAXSIZE];

int sizeOfSequence;

int main(void) {
  cin >> sizeOfSequence;

  for (int i = 0; i < sizeOfSequence; i++) {
    cin >> sequence[i];
  }

  for (int i = 0; i < sizeOfSequence; i++) {
    leftSide[i] = 1;
    rightSide[sizeOfSequence - i - 1] = 1;
    for (int j = 0; j < i; j++) {
      if (sequence[j] < sequence[i]) {
        if (leftSide[i] < leftSide[j] + 1)
          leftSide[i] = leftSide[j] + 1;
      }

      if (sequence[sizeOfSequence - j - 1] < sequence[sizeOfSequence - i - 1]) {
        if (rightSide[sizeOfSequence - i - 1] <
            rightSide[sizeOfSequence - j - 1] + 1)
          rightSide[sizeOfSequence - i - 1] =
              rightSide[sizeOfSequence - j - 1] + 1;
      }
    }
  }
  int maxVal = 0;
  for (int i = 0; i < sizeOfSequence; i++) {
    maxVal = max(maxVal, leftSide[i] + rightSide[i] - 1);
  }
  cout << maxVal << endl;
}