/*
 * @author    : macab (macab@debian)
 * @file      : multimap
 * @created   : Thursday Mar 07, 2019 15:11:22 IST
*/
#include<bits/stdc++.h>
#define endl 		         "\n"
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    /*code goes here*/
    /*
    multimap<int, int> mm;
    mm.insert(pii(3, 5));
    mm.insert(pii(1, 6));
    mm.insert(pii(7, 12));
    multimap<int, int>::iterator itr;
    for(itr = mm.begin(); itr != mm.end(); itr++)
            cout << itr->first << "\t"<< itr->second << endl ;
    itr = mm.upper_bound(MAX);
    cout << itr->first << "\t" << itr->second << endl;

    */
    vector<vector<int>> twod(10, vector<int>(2, 1));

    for(int i = 0; i < twod.size(); i++){
        for(int j = 0; j < twod[i].size(); j++){
            cout <<  twod[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}

