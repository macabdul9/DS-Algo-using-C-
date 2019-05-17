/*
 * @author    : macab (macab@debian)
 * @file      : fibdp
 * @created   : Monday Feb 11, 2019 07:39:40 IST
*/
#include<bits/stdc++.h>
#define endl 		         "\n"
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define rloop(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)
#define clr(x)                x.clear()
#define MOD                   1000000007
#define MAX                   1e9
#define MIN                   -1e9
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define psi                   pair<string, int>
#define pci                   pair<char, int>
#define all(p)                p.begin(),p.end()
#define max(x,y)              (x>y)?x:y
#define min(x,y)              (x<y)?x:y
#define vi                    vector<int>
#define vs                    vector<string>
#define si                    set<int>
#define ss                    set<string>
#define mii                   map<int, int>
typedef long long int ll;
typedef unsigned int uint;
using namespace std;

ll fibdp(ll n, ll walk, ll dp[]){
    if(n < 1) return 0;
    if(n < 3) return 1;
    if(walk == n)return dp[1];
    ll tmp = dp[0] + dp[1];
    dp[0] = dp[1];
    dp[1] = tmp;
    return fibdp(n, walk + 1, dp);

}

int main(){
    /*code goes here */
    int test ;
    ll n;
    cin >> test;
    while(test -- > 0){
        ll *dp = new ll[2];
        dp[0] = 1;
        dp[1] = 1;
        cin >> n;
        cout << fibdp(n, 2, dp);
        delete []dp;
    }
    return 0;
}

