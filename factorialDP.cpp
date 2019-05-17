#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 100001
using namespace std;

int dp[MAX];

int getFact(int n){
  if(n < 3){
    if(dp[n]){
      return dp[n];
    }
    else{
      dp[n] = n;
      return dp[n];
    }
  }
  return n*getFact(n - 1);
}
int main(int argc, char const *argv[]) {
  int n;
  cin >>n;
  cout << getFact(n);
  return 0;
}
