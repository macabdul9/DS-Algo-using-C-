/*
 * @author    : macab (macab@debian)
 * @file      : extractingbit
 * @created   : Friday Mar 22, 2019 01:03:56 IST
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

int getithBit(int num , int ith){
    return (num & (1 << ith)) != 0 ? 1 : 0;
}

int main(){
	ios::sync_with_stdio(0);

    // extract the ith bit of a number !

    int num, ith, mask, AND;
    while(true){
        cin >> num >> ith;
        mask = 1 << ith; // creating a mask ....having only ith bit 1
        AND = num & mask; // ANDing the number with mask so we get get ith bit rest 0
        AND = AND >> ith; // shift this AND by ith, 0th bit will be desired bit now
        AND = AND & 1;    // and it with 1 so we can get the answer !
        cout << AND << "  "<< getithBit(num, ith) << endl;
    }
	return 0;
}

