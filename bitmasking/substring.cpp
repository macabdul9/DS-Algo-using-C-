/*
 * @author    : macab (macab@debian)
 * @file      : substring
 * @created   : Friday Mar 22, 2019 19:01:03 IST
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

/*  --- given an string you've got to find all possible substrings of that string ie. ab "", a, b, ab
 */

// mask will be encoded subset means if the bit is 1 we will take that otherwise won't ie 101 its ac
void printSubstring(string str, int strl, int mask){
        string ans = "";
        for(int i = 0; i < strl;i++){
            if(mask & 1){
                ans += str[i];
            }
            mask = mask >> 1;
        }
        cout << ans  << " ";
}
void selectChars(string str, int strl){
        // there will be extacly 2^strl substrings from 0 to 2^strl - 1
        int range = 1 << strl; // 1 << strl == 2^strl

        for(int i = 0; i < range; i++){
            printSubstring(str, strl, i);
        }
}

// here's is the simple recursive function call that do the same thing as of above
// one we will take a char and once we won't !
//
void printSubstringRecursive(string str, string ans){
    if(str.length() == 0){
        cout << ans << " ";
        return;
    }
    // he we didn't take the the last char
    printSubstringRecursive(str.substr(1, str.length()), ans);
    // here we took
    ans += str[0];
    printSubstringRecursive(str.substr(1, str.length()), ans);

}

/*
 *  ---  compleixty analysis of both method  ---
 *  the bit masking method takes O(n*2^n) while recursive function call takes O(2^n)
 *  where n is the length of the string.
 */
int main(){
	ios::sync_with_stdio(0);

    string str;
    while(true){
        cin >> str;
        //selectChars(str, str.length());
        printSubstringRecursive(str, "");
        cout << endl;
    }

	return 0;
}

