/*
 * @author    : macab (macab@debian)
 * @file      : egg_dropping
 * @created   : Saturday May 18, 2019 20:12:04 IST
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
 * there is a builind having n floor and you're given k eggs find
 * find the floor in min number of test from where if you drop the egg
 * then egg will  break
 */


/* bottom-up dp */

int drop(int eggs, int floors){
    if(eggs == 0 or floors == 0) return -1;

    vector<vi> sol(eggs + 1, vi(floors + 1, 0));

    for(int i = 0; i <= floors; i++)
            sol[1][i] = i;
    for(int i = 1; i <= eggs; i++)
            sol[i][1] = 1;

    /*
    for(int i = 0; i <= eggs; i++){
        for(int j = 0; j <= floors ; j++)
                cout << sol[i][j] << " ";
        cout << endl;
    }
    */

    for(int e = 2; e <= eggs; e++){
        for(int f = 2; f <= floors; f++){
            sol[e][f] = MAX;
            for(int k = 1; k <= f; k++){
                sol[e][f] = min(sol[e][f], 1 + max(sol[e - 1][k - 1], sol[e][f - k ]));
            }
        }
    }


    /*
    cout << endl;
    for(int i = 0; i <= eggs; i++){
        for(int j = 0; j <= floors ; j++)
                cout << sol[i][j] << " ";
        cout << endl;
    }
    */

    return sol[eggs][floors];
}


int calculateRecursive(int eggs, int floors){
        if(eggs == 1){
            return floors;
        }
        if(floors == 0){
            return 0;
        }
        int min = 1000;
        for(int i=1; i <= floors; i++){
            int val = 1 + max(calculateRecursive(eggs-1, i-1),calculateRecursive(eggs, floors-i));
            if(val < min){
                min = val;
            }
        }
        return min;
}

int main(){
	ios::sync_with_stdio(0);

    unsigned int eggs, floors;
    cin >> eggs >> floors;
    cout << drop(eggs, floors) << endl;




	return 0;
}

