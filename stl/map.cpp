#include<iostream>
#include<string>
#include<map>

#define endl "\n"
#define endt "\t"



using namespace std;

int main(){
    map<string, int > mp;
    //inserting into map
    mp.insert(pair<string, int>("Abdul", 001));
    mp.insert(pair<string, int>("Chaudhary", 401));
    mp.insert(pair<string, int>("Arsalan", 601));
    //iterator object
    map<string, int>::iterator itr;
    //printing element
    for(itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first << "\t" << itr->second << endl;
    cout << endl;
    //assign the whole map to another
    map<string, int > mp1(mp.begin(), mp.end());
    for(itr = mp1.begin(); itr != mp1.end(); itr++)
        cout << itr->first << "\t" << itr->second << endl;
    cout << endl;

    cout << mp.count("Abdul") << endl;

    return 0;
}

