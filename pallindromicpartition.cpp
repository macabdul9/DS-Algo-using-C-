/*
 * @author    : macab (macab@debian)
 * @file      : pallindromicpartition
 * @created   : Friday Mar 08, 2019 07:58:36 IST
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
/*
 * source :https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition
 * */

bool isPallindrome(string s){
    if(s.length() < 2) return true;
    loop(i, 0, s.length() / 2){
        if(s[i] != s[s.length() - 1 - i]) return false;
    }
    return true;
}

void printlist(list<string> list){
    if(list.size() == 0) return;

    while(!list.empty()){
        cout << list.front() << " ";
        list.pop_front();
    }
    cout << endl;
}

void partitioning(string str, list<string> list){
    if(str.length() == 0){
            printlist(list);
            return;
    }

    string s;
    s.append(1, str[0]);
    list.push_back(s);
    partitioning(str.substr(1, str.length()), list);
    list.pop_back();
    s = list.back();
    list.pop_back();
    s.push_back(str[0]);
    list.push_back(s);

    partitioning(str.substr(1, str.length()), list);

}

int main(){
    ios::sync_with_stdio(0);
    int t;
    string str = "bdul";
    list<string> list;
    list.push_back("a");
    partitioning(str, list);
    /*
    cin >> t;
    while(t-- > 0){
        cin >> str;
        cout << boolalpha << isPallindrome(str) << endl;
    }*/

    return 0;
}

