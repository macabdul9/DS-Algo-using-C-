/*
 * @author    : macab (macab@debian)
 * @file      : TavasandSaddas
 * @created   : Saturday Mar 23, 2019 06:31:08 IST
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
 * source : https://codeforces.com/problemset/status
 */




/*
 * To solve the codeforces problem, to find the position of lucky number
 *  in a collection of lucky numbers containing the same number of digits,
 *  we can simply replace 4 by 0 and 7 by 1. The number we get from here plus
 *  one will give us this position. To find the final answer, we can simply
 *  find the sum of the above result plus the sum of series (2^1 + 2^2 + .. + 2^(x-1))
 *  where x represents the number of digits of the given initial number.
 */

int totalluckynumber(int n){
    int position = 0;
    string str = to_string(n);
    string binary = "";
    for(int i = 0; i <str.length(); i++){
        if(str[i] - '0' == 7)
            binary.append("1");
        else
            binary.append("0");
    }

    for(int i = 0; i<binary.length(); i++){
        if(binary[binary.length() - 1 - i] - '0' == 1)
                position += (1 << i);
    }
    //cout << position << endl;
    position += 1;

    for(int i = 1; i < str.length(); i++){
        position += (1 << i);
    }
    return position;

}
int main(){
	ios::sync_with_stdio(0);

    int n;
    cin >> n;
    cout << totalluckynumber(n) << endl;

	return 0;
}

