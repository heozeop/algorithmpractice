#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();

typedef pair<int,int> location;
const int CHICKEN_STORE = 2;
const int HOUSE = 1;
const int LOAD = 0;
const int DIRECTIONS[4][2] = {
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1},
};

int cityMap[51][51];
int n, m;

vector<location> findLocationOf(int type);
bool isOutOfCity(location currentLocation);
int getDistanceBetween(location from, location to);
int calculateChickenDistance(vector<location>& houseLocationList, vector<location>& storeLocationListToVisit);
int minChickenDistance(
  int selectedStoreNumberToVisit, 
  int currentIndex, 
  vector<location>& storeLocationList, 
  vector<location>& houseLocationList,
  vector<location>& selectedStoreLocationList
);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> cityMap[i][j];
    }
  }

  return;
}

void solve() {
  vector<location> houseLocationList = findLocationOf(HOUSE);
  vector<location> storeLocationList = findLocationOf(CHICKEN_STORE);
  vector<location> selectedStoreLocationList;

  int calculatedMinChickenDistance = minChickenDistance(0, 0, storeLocationList, houseLocationList, selectedStoreLocationList);
  cout << calculatedMinChickenDistance;
  return;
}

vector<location> findLocationOf(int type) { 
  vector<location> locationList;

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(cityMap[i][j] == type) {
        locationList.push_back({i,j});
      }
    }
  }

  return locationList;
}

int minChickenDistance(
  int selectedStoreNumberToVisit, 
  int currentIndex, 
  vector<location>& storeLocationList, 
  vector<location>& houseLocationList,
  vector<location>& selectedStoreLocationList
) {
  if (selectedStoreNumberToVisit == m) {
    return calculateChickenDistance(houseLocationList, selectedStoreLocationList);
  }

  if (currentIndex >= storeLocationList.size()) {
    return INT_MAX;
  }

  int minValue = INT_MAX;
  for(int i = currentIndex; i < storeLocationList.size(); ++i) {
    cityMap[storeLocationList[i].first][storeLocationList[i].second] = LOAD;
    selectedStoreLocationList.push_back(storeLocationList[i]);
    minValue = min(minValue, minChickenDistance(selectedStoreNumberToVisit + 1, i + 1, storeLocationList, houseLocationList, selectedStoreLocationList));
    cityMap[storeLocationList[i].first][storeLocationList[i].second] = CHICKEN_STORE;
    selectedStoreLocationList.pop_back();
  }

  return minValue;
}

int calculateChickenDistance(vector<location>& houseLocationList,  vector<location>& storeLocationListToVisit) {
  int distance = 0, localMinDistance;
  for(location house : houseLocationList) {
    localMinDistance = INT_MAX;;
    for(location closestStore:storeLocationListToVisit) {
      localMinDistance = min(localMinDistance, getDistanceBetween(house, closestStore));
    }

    distance += localMinDistance;
  }

  return distance;
}

bool isOutOfCity(location currentLocation) {
  return currentLocation.first < 1 || currentLocation.second < 1 || currentLocation.first > n || currentLocation.second > n;
}

int getDistanceBetween(location from, location to) {
  return abs(from.first - to.first) + abs(from.second - to.second);
}
