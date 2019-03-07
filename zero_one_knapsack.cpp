/*
 * @author    : macab (macab@debian)
 * @file      : zero_one_knapsack
 * @created   : Thursday Mar 07, 2019 12:20:40 IST
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

/*0-1knapsack is a famous dp prob which states that In a store there's n items A1, A2, A3, ....An with random weight and price
 * prices are P1, P2, P3, ....Pn, a theif went to the store and wants to steal the items but unforutantely his bag can contain
 * upto only k kgs so the problem is how he can steal max price ie: 3, 4, 8 (items weight) their prices are: 8, 13, 7 and his/her bag
 * can cary only 8 kg so he will pick 3, 4 kg item. (assuming that that each item has only one unit.
 */
/* solution 1 : gready apprach say we gotta pick max p/w item but this will fail ie: item = 7, 4, 4 price = 15, 8, 8.  k = 10
 * so as per dp we should pick 7 kg item cuz it has highest p/w but nah ! this ain't the optimal solution and he picks 4,4 total price would be
 * 16 which is higher than that's what the optimal sol is.
 */
/* solution 2: find all subarrays whose weight is <= k and choose max sum price subarray
 */

vector<int> maxprice(vector<vector<int>> &items_price, int bag_capacity){
    multimap<int, vector<int>> possible_sol; // subarray - sum means items and their aggregate price
    multimap<int, vector<int>>::iterator itr;
    vector<int> start;
    //start.push_back(0);
    possible_sol.insert({0, start}); // initially empty sol in case if there's no possible sol ie items = 2, 3 price = 10, 34. k = 1
    vector<int> tmp;
    for(int i = 0; i < items_price.size(); i++){

        int size = possible_sol.size();
        int l = 0;
        itr = possible_sol.begin();

        while(l < size){
            tmp = itr->second;
            if(accumulate(tmp.begin(), tmp.end(), 0) + items_price[i][0] <= bag_capacity){
                tmp.push_back(items_price[i][0]);
                int new_price = itr->first + items_price[i][1];
                possible_sol.insert({new_price, tmp});
            }
            tmp.clear();
            itr++;
            l++;
        }

    }

    multimap<int, vector<int>>::iterator max = possible_sol.begin();

    for(itr = possible_sol.begin(); itr != possible_sol.end(); itr++){
        if(itr->first > max->first)
                max = itr;
    }
    tmp = max->second;
    tmp.push_back(max->first);
    return tmp;
}

int main(){

    int t, n, price, tmp, k;
    cin >> t;
    while(t-- > 0){
        cin >> n;
        vector<vector<int>> items_price(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            cin >> tmp >> price;
            items_price[i][0] = tmp;
            items_price[i][1] = price;
        }
        cin >> k;
        vector<int> ans = maxprice(items_price, k);
        for(int i = 0; i < ans.size() - 1; i++)
                cout << ans[i] << " ";
        cout << endl << ans[ans.size() - 1];
        items_price.clear();
    }

    return 0;
}

