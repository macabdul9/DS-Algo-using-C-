/*
 * @author    : macab (macab@debian)
 * @file      : runningstaircasedp
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


ll waysrecursion(ll steps){}

ll waysmemo(ll steps, ll memo[]){
    if(steps == 0) return 1; // you've reached on the top of the floor which is a legit way
    if(steps == 1) return 1;
    if(steps == 2) return 2;
    // n steps will take the excatly the sum of n - 1, n - 2, n - 3 steps
    if(memo[steps] == 0){
        memo[steps] = waysmemo(steps - 1, memo) + waysmemo(steps - 2, memo) + waysmemo(steps - 3, memo);
    }
    return memo[steps];
}
//this is fastest algorithm that works in O(n)-time complexity and O(1)-space complexity(needs only 3 extra space)
ll waysdp(ll steps, ll count, ll dp[]){

        if(steps < count)
                return dp[steps];
        if (count == steps)
                return dp[2];
        else{
            ll tmp = dp[2];
            dp[2] = dp[2] + dp[1] + dp[0];
            dp[0]= dp[1];
            dp[1] = tmp;
            return waysdp(steps, count + 1, dp);
        }


}

int main(){
    /*code goes here */
    ll dp[3];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    ll n;
    cin >> n;
    //ll memo[n + 1] = {0};
    //cout << waysmemo(n, memo);
    //
    cout << waysdp(n, 2, dp);

    return 0;
}

