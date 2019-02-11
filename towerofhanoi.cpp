/*
 * @author    : macab (macab@debian)
 * @file      : towerofhanoi
 * @created   : Monday Feb 11, 2019 06:33:17 IST
*/
#include<bits/stdc++.h>
#define endl 		         "\n"
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define rloop(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)
#define clr(x)                x.clear()
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
#define vs                    vector<string>
#define si                    set<int>
#define ss                    set<string>
#define mii                   map<int, int>
typedef long long int ll;
typedef unsigned int uint;
using namespace std;

void towerofhanoi(int disk, char source, char aux, char destination){
    if(disk <= 0) return;
    if(disk == 1){
        cout << "move " << source << " to " << destination << endl;
        return;
    }
    towerofhanoi(disk - 1, source, destination, aux);
    cout << "move " << source << " to " << destination << endl;
    towerofhanoi(disk - 1, aux, source, destination);
}

int main(){
    /*code goes here */
    towerofhanoi(3, 'A', 'B', 'C');
    return 0;
}

