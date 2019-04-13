/*
 * @author    : macab (macab@debian)
 * @file      : kmp
 * @created   : Friday Apr 12, 2019 23:06:51 IST
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

// this function naievly search for pattern matching ! and takes O(n + m) where n - length of string and m is length of pattern !
int naivepatternmatching(string str, string pat){
    int len_str = str.length();
    int len_pat = pat.length();
    int k;
    loop(i, 0, len_str){

            for(int j = 0, k = i; k < len_str; j++, k++){

                // if last char of pattern is matched then it means string contains the pattern !
                if(str[k] == pat[j] and j == len_pat - 1) return 1;

                // if some jth char of pattern is matched then check for next char in pattern !
                else if(str[k] == pat[j]) continue;

                // if not matched check from next substring in string !
                else break;

        }
    }

    return -1;
}

/*
 * above algorithm takes O(m*n) time and to improve that we have a algorithm called knuth-morris-pratt matching !
 * which run faster than the naive algorithm and takes O(m + n) by avoiding already matched patten
 */

// pi-table or lps table !

vector<int> pi_table(string pattern){
    int pat_len = pattern.length();
    vector<int> table(pat_len, 0);
    // first char will hold zero !
    table[0] = 0;
    int i, j;
    for(i = 0, j = 1; j < pat_len; j++){
        if(pattern[i] == pattern[j]){
            table[j] = i + 1;
            i++;
        }
        else{
            i = table[i - 1];
            while(i){
                if(pattern[i] == pattern[j]){
                    table[j] = i + 1;
                    break;
                }else{
                    i = table[i - 1];
                }
            }
            if(i == 0 and pattern[i] == pattern[j])
                    table[j] = i + 1;

        }
    }
    return table;
}

int kmp(string str, string pattern){
    int str_len = str.length();
    int pat_len = pattern.length();
    vi table = pi_table(pattern);
    int j;
    for(int i = 0, j = 0; i < str_len; i++,j++){
        if(str[i] != pattern[j]){
            j - 1 < 0 ? j = pattern[0] : j = pattern[j - 1];

        }
        if(str[i] == pattern[j] and j + 1 == pat_len) return 1;

    }
    return -1;
}


int main(){
	ios::sync_with_stdio(0);
    cout << naivepatternmatching("abcsdchfvscwejfhbdcdksavfvsldbfvdddbfv", "x") << " " << kmp("abcsdchfvscwejfhbdcdksavfvsldbfvdddbfv", "fv");
    string pattern = "abcdabca";
    /*
    vi table = pi_table(pattern);
    cout << pattern << endl;
    for(auto x : table)
            cout << x << " ";
    cout << endl;
    */
	return 0;
}

