/*
 * @author    : macab (macab@debian)
 * @file      : runningstaircase
 * @created   : Sunday Feb 10, 2019 03:23:04 IST
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
/*
 * A child is running up a staircase with n steps, and can hop either 1 step, 2 steps or 3
 * steps at a time. Implement a method to count how many possible ways the child can run up
 * to the stairs
 * */
ll getways1(int n ){
    if(n < 0) return 0;
    if(n == 0) return 1;
    return getways1(n - 1) + getways1(n - 2) + getways1(n - 3);
}
ll getways2(ll n){
    /*
    if( n == 0)return 1; // it means child has reached on the floor
    if( n < 0) return 0; // over stepping
    */
    // lets make it little quicker very little in fact.
    if(n == 1)return 1; // we will have only one way to climb one step just 1
    if(n == 2)return 2; // 1-1 and 2 total 2 ways
    if(n == 3)return 4;  // 1-1-1 , 2-1,  1-2, and 3 hence total 3 ways

    return getways2(n - 1) + getways2(n - 2) + getways2(n - 3);
}

int main(){
    /*code goes here */
    ll n;
    // Record start time
    //auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    // Record end time
   // auto finish = std::chrono::high_resolution_clock::now();

    while(true){
        cin >> n;

        // Record start time
        auto start = std::chrono::high_resolution_clock::now();
        // Portion of code to be timed
        cout << getways2(n) << endl;
        // Record end time
        auto finish = std::chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "time take = " <<fixed<<elapsed.count() << endl;

        // Record start time
        start = std::chrono::high_resolution_clock::now();
        // Portion of code to be timed
        cout << getways1(n) << endl;
        // Record end time
        finish = std::chrono::high_resolution_clock::now();
        elapsed = finish - start;
        cout << "time taken = " <<fixed<< elapsed.count() << endl;


    }
    return 0;
}

