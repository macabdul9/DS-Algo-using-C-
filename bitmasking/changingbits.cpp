/*
 * @author    : macab (macab@debian)
 * @file      : changingbit
 * @created   : Thursday Mar 21, 2019 13:20:24 IST
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
 * two numbers are a and b, how many bit we need to change to make a == b ?
 */


// count the set bits in XOR of two number
// this takes the O(n) time ...n is number of bits
int countSetBits(int num){

    int count = 0;
    while(num > 0){
        count += num&1;
        num = num >> 1;
    }
    return count;
}

/*
 * -- n&n-1 hack--
 *  in this on each iteration one set bit get removed hence time complexity O(k) where K is number of set bits.
 *  */
int countSetBits1(int num){
    int count = 0;
    while(num > 0){
        num = num & (num - 1);
        count++;
    }
    return count;

}


int main(){

	ios::sync_with_stdio(0);

    int num1 , num2, XOR;


    while(true){

        cin >> num1 >> num2;

        XOR = num1^num2;

        cout << countSetBits(XOR)  << " " << countSetBits1(XOR)<< endl;
    }



	return 0;
}

