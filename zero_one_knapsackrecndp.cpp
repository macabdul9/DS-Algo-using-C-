/*
 * @author    : macab (macab@debian)
 * @file      : zero_one_knapsackrecndp
 * @created   : Sunday Mar 10, 2019 01:08:11 IST
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


int knapsack(vector<vector<int>> &item_list, int k, int current_max, int i){
    // my implementation as per the algo
    if(k < 0) return 0;
    if(k == 0 or i == 0) return current_max;
    return max(knapsack(item_list, k - item_list[i][0], item_list[i][1] + current_max, i - 1), knapsack(item_list,  k, current_max, i - 1));


    /* more elegant looking code
    // if bag if full or checked all items
    if(k == 0 or n == 0) return 0;

    int include = 0, exclude = 0;
    // putting an item into the bag
    if(k >= item_list[n - 1][0]){
        include = item_list[n - 1][1] + knapsack(item_list, k - item_list[n - 1][0], n - 1);
    }
    // not putting an item into the bag
    exclude = 0 + knapsack(item_list, k,  n - 1);
    return max(include, exclude);
    */


}

int main(){
	ios::sync_with_stdio(0);

	/*your code goes here*/
    int t, n, k, w, p;
    cin >> t;
    while(t-- > 0){
        cin >> n >> k;
        vector<vector<int>> item_list(n, vector<int>(2)); // 2d vector for weight - price
        for(int i = 0; i < n; i++){
            cin >> w >> p;
            item_list[i][0] = w;
            item_list[i][1] = p;
        }


        cout << knapsack(item_list, k, 0, n - 1) << endl;



        item_list.clear();

    }
	return 0;
}

