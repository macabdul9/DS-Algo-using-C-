/*
 * @author    : macab (macab@debian)
 * @file      : square
 * @created   : Tuesday Mar 12, 2019 16:35:28 IST
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


int sqaure(int num){
    if(num == 1) return 1;

    return (2*num - 1) + sqaure(num - 1);
}

int main(){
	ios::sync_with_stdio(0);

	/*your code goes here*/
    int n;
    while(true){
        cin >> n;
        cout << "square of "<< n <<" by sqaure fun = " << sqaure(n) << endl ;
        cout << "square of "<< n <<" by power fun  = " << int(pow(n, 2)) << endl;
    }

	return 0;
}

