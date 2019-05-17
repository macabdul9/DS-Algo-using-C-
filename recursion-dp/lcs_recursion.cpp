/*
 * @author    : macab (macab@debian)
 * @file      : lcs_recursion
 * @created   : Tuesday Apr 23, 2019 22:11:40 IST
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
 * LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
 * A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example,
 * “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, ...etc are subsequences of “abcdefg”. So a string of length n has 2^n different
 * possible subsequences.
 */

// time complexity of this approach will be exponential in worst case
//

int lcsRecursion(string s1, int i, string s2, int j){
    /*
    if(s2.length() == 0) return "";

    string lcs = "";

    if(s1.find(s2[0]) != string::npos){
        return  lcs + s2[0] + lcsRecursion(s1.substr(s1.find(s2[0]) + 1, s1.length()), s2.substr(1, s2.length()));
    }else{
        return  lcs + lcsRecursion(s1, s2.substr(1, s2.length()));
    }
    */

    if (s1[i] == '\0' or s2[j] == '\0') return 0;
    else if(s1[i] == s2[j]) return 1 + lcsRecursion(s1, i+1, s2, j+1);
    else return max(lcsRecursion(s1, i + 1, s2, j), lcsRecursion(s1, i, s2, j + 1));


}


int main(){
	ios::sync_with_stdio(0);

    //string s1, s2;
    //cin >> s1 >> s2;

    cout << lcsRecursion("abdace", 0, "babce", 0) << endl;

	return 0;
}

