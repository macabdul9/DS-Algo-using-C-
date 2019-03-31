/*
 * @author    : macab (macab@debian)
 * @file      : inclusionexclusion
 * @created   : Wednesday Mar 27, 2019 18:57:58 IST
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
 * Problem 2: Given N prime numbers and a number M, find out how many
 * numbers from 1 to M are divisible by any of the N given prime numbers.
*/


int main(){
	ios::sync_with_stdio(0);

    int arr[] = {2, 3, 5, 7};
    int size = sizeof(arr)/sizeof(int);

    // so many variables !
    int pos, mul , setbits, mask, ans = 0, no = 100;

    // total subset 2^size but we take 2^size- 1 bcoz one set will have no element !
    for(int i = 1; i < (1 << size); i++){
        mask = i;
        setbits = __builtin_popcount(mask);
        mul = 1;
        pos = 0;
        while(mask > 0){
            if(mask & 1){
                mul *= arr[pos];
            }
            mask >>= 1;
            pos++;
        }
        if(setbits&1)
            ans += (no/mul);
        else
            ans -= (no/mul);

    }
    cout << ans << endl;



	return 0;
}

