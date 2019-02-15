/*
 * @author    : macab (macab@debian)
 * @file      : mincoindp
 * @created   : Thursday Feb 14, 2019 07:42:18 IST
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

/*
 * source : https://codingblocks.com/resources/dp-webinar/
 * */
const int coin[] = {1, 7, 10 };
int dp[MAX] = {0, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1};

int getmincoin(int n){
    if( n < 11) return dp[n];

    

}

int main(){
    /*code goes here*/
    int  n ;
    cin >> n;
    cout << "min coin = " << getmincoin(n);
    return 0;
}

