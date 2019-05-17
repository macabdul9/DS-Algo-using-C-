/*
 * @author    : macab (macab@debian)
 * @file      : stringsubseq
 * @created   : Saturday Feb 09, 2019 02:41:06 IST
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

void subseq(string str, string ans, int i){
    if(i == str.length()){
        cout << ans << endl ;
        return;
    }
    subseq(str, ans + "", i + 1);
    subseq(str, ans + str[i], i + 1);
}

int main(){
    /*code goes here */
    subseq("bcdc", "", 0);
    return 0;
}

