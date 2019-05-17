/*
 * @author    : macab (macab@debian)
 * @file      : rodcutting
 * @created   : Friday Mar 29, 2019 23:46:59 IST
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
 * cut the rod to get maximum revenue !
 *
 */


int getmaxrevn(vector<int> peice_length, vector<int> peice_price, int rod_length){

    if(rod_length == 0 or rod_length < peice_length[0]) // assuming that possible cuttings are in sorted order !
            return 0;

    int max_revn = MIN;

    for(int i = 0 ; i < peice_length.size(); i++){
        int revn = 0;
        // if current length of rod is >= curren length of the peice then it could be a valid cut !
        if(peice_length[i] <= rod_length)
            revn = peice_price[i] + getmaxrevn(peice_length, peice_price, rod_length - peice_length[i]);
        if(revn > max_revn)
                max_revn = revn;

    }

    return max_revn;
}

// time complexity for this function will be better exceed O(k*k*n)
// if the cuts are not uniform like 1, 2, 3, 4.
int getmaxrevnbottomupdp(vi peice_length, vi peice_price, int rod_length){
    // if cut is not possible then we're saying that max revenue will be -1
    // ie. cuts 3, 7  price 10, 20 rod_length = 4 then simply cut is not possible !
    vi maxrev(rod_length + 1, MIN);
    // max revenue for rod_length zero
    maxrev[0] = 0;

    int total_cuts = peice_length.size();

    for(int i = 1; i <= rod_length; i++){
        // check for all the points from where we can reach to the length i
        for(int j = 0; j < i; j++){
            // find a cut by which we can reach length i from that point,  mentioned above !
            for(int k = 0; k < total_cuts; k++){
                if(j + peice_length[k] == i and maxrev[j] != MIN){
                    maxrev[i] = max(maxrev[i], maxrev[j] + peice_price[k]);
                }
            }
        }
    }

    return maxrev[rod_length];
}

int main(){
	ios::sync_with_stdio(0);
    int t, cuts, rod_length, tmp;
    cin >> t;
    while(t--){
        cin >> cuts;

        vector<int> peice_length(cuts);
        vector<int> peice_price(cuts);

        for(int i = 0; i < cuts; i++){
            cin >> tmp;
            peice_length[i] = tmp;
        }
        for(int i = 0 ; i < cuts; i++){
            cin >> tmp;
            peice_price[i] = tmp;
        }
        cin >> rod_length;

        cout << "by recursion "<< getmaxrevn(peice_length, peice_price, rod_length) << endl;
        cout << "by bottom up dp " << getmaxrevnbottomupdp(peice_length, peice_price, rod_length) << endl;
        peice_length.clear();
        peice_price.clear();
    }

	return 0;
}

