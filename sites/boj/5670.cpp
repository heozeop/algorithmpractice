#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Trie {
private:
  map<string, Trie*> children;
  bool isLast;

  int findSameSectionLength(const string& s1, const string& s2) {
    int i = 0;
    while(i < s1.length() && i < s2.length() && s1[i] == s2[i]) {i++;}
    return i;
  }
public:
  Trie() {
    this->isLast = false;
  }
  ~Trie() {
    children.clear();
  }

  void concat(const string s, Trie* other) {
    children[s] = other;
  }

  void setLast(bool last) {isLast = last;}
  bool last() { return isLast;}

  void insert(string key) {
    if(key.size() < 1) {
      this->isLast = true;
      return;
    }
    int sameSectionLength = 0;
    string subStr = "";
    for(auto iter = children.begin(); iter != children.end(); iter++) {
      sameSectionLength = findSameSectionLength(iter->first, key);
      if(sameSectionLength == 0) continue;

      subStr = key.substr(0, sameSectionLength);
      if(sameSectionLength != iter->first.size()) {
        this->children[subStr] = new Trie();
        this->children[subStr]->concat(iter->first.substr(sameSectionLength), iter->second);
        this->isLast = false;
        children.erase(iter->first);
      }

      if(sameSectionLength == key.size()) {
        children[subStr]->setLast(true);
        return;
      }
      children[subStr]->insert(key.substr(sameSectionLength));
      return;
    }

    children[key] = new Trie();
    children[key]->insert("");
    return;
  }

  int search(string key, int count = 1) {
    for(int i = 1; i < key.size(); i++) {
      string subStr = key.substr(0,i);
      if(children.count(subStr) > 0) {
        return children[subStr]->search(key.substr(i), count + 1);
      }
    }
    return children.count(key) ? count : 0;
  }
  void print(int layer = 0) {
    if(children.size() < 1) {
      return;
    }
    for(auto iter = children.begin(); iter != children.end(); iter++) {
      for(int i = 0; i < layer; i++) {
        cout << "--";
      }
      cout << iter->first << " " << iter->second->last() << "\n";
      iter->second->print(layer + 1);
    }
  }
};
void solve();
double test(int);

int t;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

void solve() {
  cout << fixed;
  cout.precision(2);
  while(cin >> t) {
    if(cin.fail()) break;

    cout << test(t) << '\n';
  }
  return;
}

double test(int count) {
  Trie* root = new Trie();
  vector<string> words(count);
  for(int i = 0; i < count; i++) {
    cin >> words[i];
    root->insert(words[i]);
  }

  long long sum = 0;
  for(int i = 0; i < count; i++) {
    sum += root->search(words[i]);
  }
  delete root;
  return (double)(sum) / count;
}
