/*
 * @author    : macab (macab@debian)
 * @file      : listsubset
 * @created   : Monday Mar 04, 2019 11:59:41 IST
*/
#include<bits/stdc++.h>
#define endl 		         "\n"
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
 * subset of a list ie: {1, 2, 3} = { (), ( 1 ), ( 2 ), (1, 2), (3), (1, 3), (2, 3), (1, 2, 3)}
 * */
void printlist(vi &list){
    for(auto x : list)
            cout << x << " ";
    cout << endl;
}

void subset(vi &set, int itr, vector<vector<int>> &subsetlist){
        if(itr >= set.size()) return;
        // on the arrival of new element total subset will be doubled and having new arrived element extra than others
        int old_size = subsetlist.size();
        loop(i, 0, old_size){
            vector<int> aux = subsetlist[i];
            aux.push_back(set[itr]);
            subsetlist.push_back(aux);
        }
        subset(set, itr + 1, subsetlist);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    /*code goes here*/
    // this  contains all possible subset
    vector<vector<int>> subsetlist;
    vector<int> phi;
    subsetlist.push_back(phi);
    vector<int> set = {1, 2, 3, 4, 5, 6, 8, 9, 10};

    subset(set, 0, subsetlist);

    for(int i = 0; i < subsetlist.size(); i ++){
        for(int j = 0 ; j < subsetlist[i].size(); j++){
            cout << subsetlist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

