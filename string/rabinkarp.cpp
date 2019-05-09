/*
 * @author    : macab (macab@debian)
 * @file      : rabinkarp
 * @created   : Wednesday May 08, 2019 23:34:10 IST
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

ull hashFun(string str){
    ull hashValue = 0;
    int str_len = str.length();
    loop(i, 0, str_len){
        hashValue += (int(str[i])*pow(10, str_len - 1 - i));
    }

    return hashValue;
}

/* modify the hashValue of the string after every new char arrival ! */
ull hashModifier(ull hash, char old, char newChar, int p_len){
    /*
     a*10^2 + b*10^1 + c*10^0
     supposed new char has arrived is d then has value will be:
     b*10^2 + c*10^1 + d*10^0
    */

    return (hash - int(old)*pow(10, p_len - 1))*10 + int(newChar);

}

// time complexity of this function in worst case will be  some O(n - m + 1) where n is length of string and m is length of pattern !

int rabinkarp(string str, string pattern){
    int s_len, p_len;
    s_len = str.length();
    p_len = pattern.length();

    if(s_len < p_len) return -1;

    ull patternHash, currentHash;

    patternHash = hashFun(pattern);

    currentHash = hashFun(str.substr(0, p_len));

    if(currentHash == patternHash) return 0;

    for(int i = 0; i <= s_len - p_len; i++){
        if(currentHash == patternHash)
                return i; // start index;
        else
                currentHash = hashModifier(currentHash, str[i], str[i + p_len], p_len);
    }

    return -1;
}

int main(){
	ios::sync_with_stdio(0);

    cout << rabinkarp("ccaaccaaedba", "ba") << endl;

	return 0;
}

