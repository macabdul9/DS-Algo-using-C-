#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main(){
    /*
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(7);
    v.push_back(3);
    v.push_back(1);

    set<int> s;
    set<int>::iterator itr;

    for(unsigned int i = 0; i < v.size(); i++)
            s.insert(v[i]);

    for(itr = s.begin(); itr != s.end(); itr++)
            cout << *itr << " ";
    */

    map<int, string> mp;
    mp.insert(pair<int, string>(001, "abdul"));
    mp.insert(pair<int, string>(004, "xyz"));
    mp.insert(make_pair(000, "abc"));

    map<int, string>::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr ++)
            cout << itr->first << " "<< itr->second << endl;

    return 0;
}
