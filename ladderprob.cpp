/*
 * @author    : macab (macab@debian)
 * @file      : ladderprob
 * @created   : Tuesday Feb 26, 2019 00:36:40 IST
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
int getwaysrec(int n){
    if(n < 0) return 0; // just for prevention to avoid neg number
    if(n <= 2) return n;
    if(n == 3) return 4;

    return getwaysrec(n - 1) + getwaysrec(n - 2) + getwaysrec(n - 3);
}

int getwaysdpbootomup(int n){
    if(n < 0) return 0; // just for prevention to avoid neg number
    vi dp(3);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    int i, tmp;
    i  = 3;
    while(i < n){
        tmp = dp[2];
        dp[2] = dp[2] + dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = tmp;
        i++;
    }
    return dp[2];

}

int getwaysdptopdown(int n , vi dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] == 0){
            dp[n] = getwaysdptopdown(n - 1, dp) + getwaysdptopdown(n - 2, dp) + getwaysdptopdown(n - 3, dp);
        }
        return dp[n];
}



int main(){
    /*code goes here*/
    vector<int> dp(MAX);
    cout <<"recursion: " << getwaysrec(10) << endl;
    cout <<"dpbup: " << getwaysdpbootomup(100) << endl;
    cout << "dptdown: " << getwaysdptopdown(100, dp) << endl;
    //cout << dp[0] << " " << dp[1] << " " << dp[2] << endl;
    return 0;
}

