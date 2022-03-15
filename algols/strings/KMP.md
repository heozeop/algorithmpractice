# KMP 알고리즘
O(n+m)에 문자열을 찾는 알고리즘 (n = 문서, m은 문자열)

# 기초 개념
## 접두사/접미사
### 접두사
앞에서 부터 차례로
### 접미사
뒤에서 부터 차례로

## Failure Function
### Failure function
- 주어진 문자열의 0~i까지 문자에 대해서 접두사와 접미사가 같은 부분 문자열 중 가장 긴 것의 길이

### Pi[i]는 failure function의 결과
- pi배열 조차도 문자열의 비교이기 때문에, kmp테크닉을 사용할 수 있다.
 
# 핵심 아이디어
## 일치했던 부분을 활용할 수 있다.
앞뒤로 같은 부분의 길이를 먼저 구해놓았기 때문에, 탐색의 수를 줄일 수 있다.

## 구현
### pi
```c++
vector<int> failureFunction(string s) {
  vector<int> pi(s.length(), 0);
  int j = 0;
  for(int i = 0 ; i < s.length() ; i++) { 
    while(j > 0 && s[i] != s[j]) j = pi[j - 1]; // 이전 기록들을 비교하며, 다음 찾을 위치를 확인합니다.

    if(s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
}
```
### kmp
```c++
vector<int> kmp(string t, string k, int pi[]) {
  vector<int> ans;
  int j = 0;
  for(int i = 0 ; i < t.length() ; i++) {
    while(j > 0 && t[i] != k[j]) j = pi[j - 1]; // 현재보다 작은 length를 보면서 다음 찾을 위치 선정

    if(t[i] == k[j]) {
      if(j == k.length() - 1) {
        ans.push_back(i - k.length() + 1); // 전체 찾은 경우, 기록해두기
        j = pi[j]; // 다음 찾을 위치 확인하기
      } else {
        ++j;
      }
    }
  }
  return ans;
}
```