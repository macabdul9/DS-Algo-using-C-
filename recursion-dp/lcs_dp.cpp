/*
 * @author    : macab (macab@debian)
 * @file      : lcs_dp
 * @created   : Tuesday Apr 23, 2019 23:42:01 IST
*/
#include<bits/stdc++.h>
#define endl                  "\n"
#define merge(a, b)           a##b
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define rloop(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)
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
#define vll                   vector<long long int>
#define vs                    vector<string>
#define si                    set<int>
#define ss                    set<string>
#define sll                   set<long long int>
#define mii                   map<int, int>
#define mll                   map<long long int, long long int>
#define msi                   map<string, int>
#define umii                  unordered_map<int, int>
#define umsi                  unordered_map<string, int>
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned long long int ull;
using namespace std;
/*
 * longest common subsequence prob using dynamic programming
 * -- top-down approach !
 *
 */

/*
 * ----optimization----
 *  lcs using recursion takes exponetial time O(2^n) in worst case while
 *  lcs using dp takes only O(n x m) time
 */

int lcsDP(string s1, int i, string s2, int j, vector<vector<int>> &dp){
    if(s1[i] == '\0' or s2[j] == '\0') return 0;

    if(dp[i][j] != -1)
            return dp[i][j];
    else if(s1[i] == s2[j]){
            dp[i][j] = 1 + lcsDP(s1, i + 1, s2, j + 1, dp);
            return dp[i][j];
    }
    else{
            dp[i][j] = max(lcsDP(s1, i + 1, s2, j, dp), lcsDP(s1, i, s2 , j + 1, dp));
            return dp[i][j];
    }
}


int main(){
	ios::sync_with_stdio(0);

    int l1, l2;
    string s1, s2;
    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, -1));

    cout << lcsDP(s1, 0, s2, 0, dp) << endl;

	return 0;
}

