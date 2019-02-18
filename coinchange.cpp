/*
 * @author    : macab (macab@debian)
 * @file      : coinchange
 * @created   : Saturday Feb 16, 2019 03:35:02 IST
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

mii mm;

int coinchange(int amount, vi coins){
    if(!amount) return 1; //no amount left
    if(amount < 0) return 0; //

    //return coinchange(amount - 10) + coinchange(amount - 7) + coinchange(amount - 1);
    for(int i = 0; i < coins.size(); i++){
        int current = coinchange(amount - coins[i], coins);
        if(!current)
                continue;
        else if(current == 1)
                mm.insert(pii(amount, current));
        else if(mm.find(amount - coins[i]) != mm.end()){
                mm.insert(pii(amount, 1 + mm.at(amount - coins[i])));
        }else{
            coinchange(amount - coins[i], coins);
        }
    }
    return mm.at(amount)->second;
}

int main(){
    /*code goes here*/
    vector<int> coins;
    //coins.push_back(10);
    coins = {2, 7, 10};
    //cout << coins.size() << endl;
    coinchange(14, coins);
    cout << mm.at(14) << endl;
    //mii::iterator itr;
    //cout << "key\tvalue" << endl;
    //for(itr =  mm.begin(); itr != mm.end(); itr++)
    //        cout << itr -> first << "\t" << itr -> second << endl;

    return 0;
}

