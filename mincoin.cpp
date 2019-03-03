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

int mincoinneeded(int amount, vi &coins){
    if(!amount) return 0; // if no amount left
    if(amount < 0) return MAX; // if amount is less than zero then this won't be a valid distribution
    int min_coins = MAX;
    loop(i, 0, coins.size()){
        int tmp = 1 + mincoinneeded(amount - coins[i], coins);
        if(tmp < min_coins)
                min_coins = tmp;
    }
    return min_coins;
}
int main(){
    /*code goes here*/
    vi coins;
    coins = {1, 7, 19 , 10};
    cout << mincoinneeded(38, coins) << endl;
    return 0;
}

