/*
 * @author    : macab (macab@debian)
 * @file      : incrediblehulk
 * @created   : Saturday Mar 23, 2019 04:43:33 IST
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
 * source : https://hack.codingblocks.com/practice/p/366/135

 * statement : The Incredible Hulk has to defeat an enemy who is
 * N steps above the level where he is standing (assume it as the 0th level).
 * Hulk, because of his incredible jumping ability can take jumps in power of 2.
 * In order to defeat the enemy as quickly as possible he has to reach the Nth step in minimum moves possible.
 * Help Hulk to find the same and contribute in saving the Mother Earth

 */


// brute force approach !
int minmove(int h){
    if(h == 0) return 0;

    // min move initially suppose 0.
    int move = 0;

    // to find the max possible jump
    int maxjump, tmp;

    // to see current level of the hulk
    int currentlevel = 0;
    int target = h ;
    while(currentlevel < target){
        tmp = h;
        maxjump = 1; // smallest possible jump means it is possible for evey case
        while(tmp > 1){
            tmp = tmp >> 1;
            maxjump = maxjump << 1;
        }
        h -= maxjump;
        currentlevel += maxjump;
        move++;
    }

    return move;
}

// here is super sexy solution
// minmove will be number of set bits, so just coun the set bits

int minmoveefficient(int h ){
    int minmove = 0;
    while(h >> 0){
        h&1 ? ++minmove : 1;
        h = h >> 1;
    }
    return minmove;
}


int main(){
	ios::sync_with_stdio(0);

    int t, h;
    cin >> t;
    while(t-- >0){
        cin >> h;
        cout << minmove(h) << " " <<  minmoveefficient(h) << endl;;
    }



	return 0;
}

