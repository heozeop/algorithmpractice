#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

const int MAX_TRUCK_LENGTH = 1001;

int n, w, l;
int truckWeightList[MAX_TRUCK_LENGTH];

int main(void) {
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> w >> l;
  for (int i = 1; i <= n; i++) {
    cin >> truckWeightList[i];
  }
  return;
}

void solve() {
  int weightOnBridge = 0;
  int startTime = 0;
  queue<int> truckOnBridge;
  for (int i = 1; i <= n; i++) {
    while (1) {
      if (truckOnBridge.size() == w) {
        weightOnBridge -= truckOnBridge.front();
        truckOnBridge.pop();
      }

      if (weightOnBridge + truckWeightList[i] <= l) {
        break;
      }

      truckOnBridge.push(0);
      startTime++;
    }

    truckOnBridge.push(truckWeightList[i]);
    weightOnBridge += truckWeightList[i];
    startTime++;
  }

  cout << startTime + w << endl;

  return;
}
