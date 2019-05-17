/*
 * @author    : macab (macab@debian)
 * @file      : stringpermutation
 * @created   : Saturday Feb 09, 2019 03:00:53 IST
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

int function_call = 1;

void stringarrangement(string str, string ans){
    ++function_call;
    if(ans.length() == str.length()){
            cout << ans << endl;
            return;
    }
    for(int i = 0; i < str.length(); i++){
        stringarrangement(str, ans + str[i]);
    }
}

int main(){
    /*code goes here */
    string str = "abcd";
    stringarrangement(str, "");
    cout << "string length = " <<  str.length() << " total function_call = " << function_call;
    return 0;
}

