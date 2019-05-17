/*
 * @author    : macab (macab@debian)
 * @file      : mincoin
 * @created   : Sunday Mar 03, 2019 06:34:01 IST
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

// time-comlexity : k^amount , which is huge
int mincoinneeded(int amount, vi &coins){
    if(!amount) return 0; // if no amount left
    if(amount < 0) return MAX; // if amount becomes less than zero then this won't be a valid distribution
    int min_coins = MAX;
    //check all possible path from amount to zero iterating over coins
    loop(i, 0, coins.size()){
        int tmp = 1 + mincoinneeded(amount - coins[i], coins);
        if(tmp < min_coins)
                min_coins = tmp;
    }
    return min_coins;
}

// time comlexity - O(k.amount) k = coins.size()
int mincoinbudp(int amount, vi &coins){
    sort(coins.begin(), coins.end()); // sort the coins for convenient
    vi dp(amount + 1, INT_MAX); // set a dp vector INT_MAX that means it takes maximum for each
    dp[0] = 0; // set 0
    /*
     * we can reach i amount of rupees from i - coins[k] (k = 0, 1, 3, .....coins.size() where i - coins[k] >= 0) hence dp[i] will be minimum of all */
    rloop(i, 1, amount){
        loop(j, 0, coins.size()){
            if(i - coins[j] >= 0 and dp[i - coins[j]] < INT_MAX)
                    dp[i] = min(dp[i], dp[i -  coins[j]] + 1);
        }
    }
    return dp[amount];
}

int main(){
    /*code goes here*/
    vi coins;
    coins = {2, 3, 5, 6};
    //int ans = mincoinneeded(27, coins);
    //ans != MAX ? cout << ans << endl : cout << "NA" << endl;
    int ans = mincoinneeded(10, coins);
    ans != INT_MAX ? cout << ans << endl : cout << "NA" << endl;
    return 0;
}

