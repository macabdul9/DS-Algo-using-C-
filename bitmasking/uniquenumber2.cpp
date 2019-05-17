/*
 * @author    : macab (macab@debian)
 * @file      : uniquenumber
 * @created   : Saturday Mar 23, 2019 02:17:34 IST
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
 * source : https://hack.codingblocks.com/practice/p/366/463
 * We are given an array containg n numbers. All the numbers are present
 * twice except for two numbers which are present only once. Find the unique
 * numbers in linear time without using any extra space
 */

void uniquenumber(vector<int> numbers, int XOR){
        // get the first set bit of XOR ! suppose ith bit is first setBit
        //cout << XOR << endl;
        int ith = 0;
        int tmp = XOR;
        while(!(tmp&1)){
                tmp = tmp >> 1;
                ith++;
        }
        //cout << ith << endl;
        int firstUniqueNumber = 0;

        int size = numbers.size();

        for(int i = 0; i < size; i++){

            if((numbers[i] >> ith) & 1){ // if ith bit of number[i] is first set same as XOR then it could be potential firstUniqueNumber
                firstUniqueNumber = firstUniqueNumber^numbers[i];
            }

        }
        int secondUniqueNumber = XOR^firstUniqueNumber;
        firstUniqueNumber < secondUniqueNumber ? cout << firstUniqueNumber << " " << secondUniqueNumber : cout << secondUniqueNumber << " " << firstUniqueNumber;
        numbers.clear();
}

int main(){
	ios::sync_with_stdio(0);

    int n, tmp, XOR;
    XOR = 0;
    cin >> n;
    vector<int> numbers(n);
    loop(i, 0, n){
        cin >> tmp;
        XOR = XOR^tmp;
        numbers[i] = tmp;
    }
    uniquenumber(numbers, XOR);
    cout << endl;
    numbers.clear();
	return 0;
}

