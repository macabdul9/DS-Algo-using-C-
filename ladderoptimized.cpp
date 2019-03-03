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
typedef unsigned long long int ull;
using namespace std;

//time complexity of this prob is O(n)
int waystopdowndp(int steps, vi &dp, int maxjump){ // k is max jump
    dp.push_back(1);
    // to reach ith step it will be sum of ways of last k steps
    for(int i = 1; i <= steps; i++){
        // dp[i] = sum of last k if k > dp.size() else sum of dp
        int ans = 0;
        int limit = maxjump;
        for(int j = dp.size() - 1; limit > 0; j--){
                if(j < 0) break; // if dp is smaller than the k itself
                ans += dp[j]; // add
                limit--;
        }
        dp.push_back(ans);
    }
    return dp[steps];
}
/*
 * dp of nth will be sum of dp of last k alright !
 * hence dp of (n + 1)th will also be dp of k alright !
 * nth = dp[n - 1] + dp[n - 2] + .......+ dp[n - k];
 * (n + 1)th = dp[n + 1 - 1] + dp[ n + 1 - 2] + ........dp[n + 1 - k];
 *           = dp[n] + dp[n -1] + dp[n - 2] + ......dp[n + 1 - k];
 *           = dp[n] + dp[n] - dp[n - k];
 *  dp[n + 1] = 2*dp[n] - dp[n - k];
 *
 *  let's do it !
 * */
int waysoptimized(int steps, vi &dp, int k){ // k is maxjump
    dp[0] = 1;
    for(int i = 1; i <= steps; i++){
        if(i - k >= 0)
            dp[i] = 2*dp[i - 1] - dp[i - 1 - k];
        else{ // took some help from above function
            vi aux;
            dp[i] = waystopdowndp(i, aux, k);
        }
    }
    return dp[steps];
}

int main(){
    /*code goes here*/
    int steps = 20;
    vi dp ;
    cout << waystopdowndp(steps, dp, 17) << endl;
    dp.clear();
    cout << waysoptimized(steps, dp, 17) << endl;

    return 0;
}

