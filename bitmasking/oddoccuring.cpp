/*
 * @author    : macab (macab@debian)
 * @file      : oddoccuring
 * @created   : Wednesday Mar 20, 2019 15:52:33 IST
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

int main(){
	ios::sync_with_stdio(0);

	/*your code goes here*/
    int arr[] = {1, 4, 2, 1, 4, 2, 5, 6, 1 , 3 , 4, 3, 4, 1, 6, 4, 5, 1, 1, 5, 6, 1, 4, 7, 8};

    int size = sizeof(arr)/sizeof(int);
    int tmp, flag;
    set<int> s;

    for(int i = 0; i < size; i++){
        flag = 1;
        tmp = arr[i];
        for(int j = 0; j < size; j++){
            if(i != j){
                tmp = arr[i]^arr[j];
                if(!tmp)
                    flag = !flag;
            }
        }

        if(flag)
            s.emplace(arr[i]);
    }
    for(auto x : s)
            cout << x << " ";
    s.clear();

    return 0;
}

