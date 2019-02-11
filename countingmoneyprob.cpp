/*
 * @author    : macab (macab@debian)
 * @file      : countingmoneyprob
 * @created   : Monday Feb 11, 2019 19:52:26 IST
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
#define mll                   map<ll, ll>
typedef long long int ll;
typedef unsigned int uint;
using namespace std;

mll notes_quant;
const int M = 2000;

ll countingmoneyprob(ll amount, ll notes[], ll track){
    if(!amount)return 0;

    if(amount > M){
        notes_quant.insert(pii(M, amount/M));
        return amount/M + countingmoneyprob(amount%M, notes, track);
    }
    int i;
    loopr(i, track , 0){
        if(notes[i] <= amount){
            //cout << notes[i] << " "; // means this is a largest valid notes note
            if(notes_quant.find(notes[i]) != notes_quant.end())
                    notes_quant.find(notes[i])->second += 1;
            else
                    notes_quant.insert(pii(notes[i], 1));

            return 1 + countingmoneyprob(amount - notes[i], notes, i);
        }
    }
}

int main(){
    /*code goes here */
    // notes descrip
    ll amount ;
    ll notes[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    while(true){
        cin >> amount;
        cout << endl << "minimum notes needed = " << countingmoneyprob(amount, notes, 9) << endl;
        cout << "notes\tquantity" << endl;
        for(mll::iterator itr = notes_quant.begin(); itr != notes_quant.end(); itr ++)
                cout << itr->first << "\t" << itr->second << endl;
        notes_quant.erase(notes_quant.begin(), notes_quant.end());
    }

    return 0;
}

