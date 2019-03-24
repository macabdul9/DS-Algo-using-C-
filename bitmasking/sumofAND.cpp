/*
 * @author    : macab (macab@debian)
 * @file      : sumofAND
 * @created   : Sunday Mar 24, 2019 12:10:36 IST
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
 * source : https://www.geeksforgeeks.org/calculate-sum-of-bitwise-and-of-all-pairs/
 *
 * Given an array “arr[0..n-1]” of integers, calculate sum of “arr[i] & arr[j]” for all
 * the pairs in the given where i < j. Here & is bitwise AND operator.
 * Expected time complexity is O(n).
 */

int getandsum(vi &numbers){
    // calculate the set bits
    int size = numbers.size();
    int sum, k;
    sum = 0;
    loop(i, 0, 32){
        k = 0; //number of ith set bit !
        loop(j, 0, size){
            if(numbers[j]&(1<<i)){
                k++;
            }
        }
        sum += (1<<i)*(k*(k-1)/2);
    }

    return sum;
}


int main(){
	ios::sync_with_stdio(0);
    int t, n, tmp;
    vi numbers;
    cin >> t;
    while(t-->0){
        cin >> n;
        loop(i, 0, n){
            cin >> tmp;
            numbers.emplace_back(tmp);
        }
        cout << getandsum(numbers) << endl;
        numbers.clear();
    }


	return 0;
}

