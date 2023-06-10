#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int MAX_SIZE = 8;

int n, m;
int arr[MAX_SIZE];

void input();
void solve();
void dfs(vector<int>& numberArray, vector<bool>& visited);
void printNumberArray(vector<int>& numberArray);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;

  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return; 
}

void solve() { 
  sort(arr, arr + n);

  vector<int> numberArray;
  vector<bool> visited(n, false);

  dfs(numberArray, visited);
  return; 
}

void dfs(vector<int>& numberArray, vector<bool>& visited) {
  if (numberArray.size() == m) {
    printNumberArray(numberArray);
    return;
  }

  int prevTemp = 0;
  for(int i = 0; i < n; ++i) {
    if(visited[i]) {
      continue;
    }

    if(prevTemp == arr[i]) {
      continue;
    }

    prevTemp = arr[i];
    visited[i] = true;
    numberArray.push_back(arr[i]);    
    dfs(numberArray, visited);
    numberArray.pop_back();
    visited[i] = false;
  }
}

void printNumberArray(vector<int>& numberArray) {
  for(int i = 0; i < numberArray.size(); ++i) {
    cout << numberArray[i] << " ";
  }
  cout << "\n";
}

