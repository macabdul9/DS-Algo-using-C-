/*
 * @author      : macab (macab@macab)
 * @file        : workingwithranges
 * @created     : Thursday Jun 06, 2019 10:28:48 IST
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define pb push_back 
using namespace std;


int main(){
	
    vector<int> v;
    v.eb(1);
    v.eb(2);
    v.eb(3);
    v.eb(4);
    v.eb(5);

 
    vector<int>::iterator itr = v.begin();
    //reverse(v.begin(), v.end());
    
    random_shuffle(v.begin(), v.end());
    for(; itr != v.end(); itr ++)
        cout << *itr << " ";
    

	return 0;
}


