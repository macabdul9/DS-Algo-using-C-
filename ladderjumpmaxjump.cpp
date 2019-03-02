/*
 * @author    : macab (macab@debian)
 * @file      : ladderjumpmaxjump
 * @created   : Saturday Mar 02, 2019 22:39:32 IST
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
#define msi                   map<string, int>
#define umii                  unordered_map<int, int>
#define umsi                  unordered_map<string, int>
typedef long long int ll;
typedef unsigned int uint;
using namespace std;

int waystopdowndp(int steps, vi &dp, int maxjump){ // k is max jump
    dp.push_back(1);
    //dp.push_back(1);
    //dp.push_back(2);
    //dp.push_back(4);
    for(int i = 1; i <= steps; i++){
        // dp[i] = sum of last k if k > dp.size() else sum of dp
        int ans = 0;
        int limit = maxjump;
        for(int j = dp.size() - 1; limit > 0; j--){
                if(j < 0) break;
                ans += dp[j];
                limit--;
        }
        dp.push_back(ans);
    }


    return dp[steps];
}

int main(){
    /*code goes here*/
    int steps = 14;
    vi dp ;
    cout << waystopdowndp(steps, dp, 14) << endl;
    return 0;
}

