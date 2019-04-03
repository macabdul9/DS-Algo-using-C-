/*
 * @author    : macab (macab@debian)
 * @file      : fastexponentaition
 * @created   : Wednesday Apr 03, 2019 05:53:16 IST
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

ull fastexp(ull x, ull p){
    ull res = 1;

    while(p){
        if(p & 1){
            res *= x;
        }
        x *= x;
        p >>= 1;

    }

    return res;

}

int main(){
	ios::sync_with_stdio(0);

    ull t, x, p;
    scanf("%llu", &t);
    while(t--){
        scanf("%llu%llu", &x, &p);
        printf("%llu\n", fastexp(x, p));
    }


	return 0;
}

