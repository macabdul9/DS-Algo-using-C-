#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1000001
using namespace std;

ll getFib(int n){
  if(n < 2){
    return n;
  }
  return getFib(n - 1) + getFib(n - 2);
}
int main(int argc, char const *argv[]) {
  ll n;
  while(true){
    cin >>n;
    cout << getFib(n);
  }
  return 0;
}
