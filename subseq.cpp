#include<iostream>
#include<vector>
#include<string>

#define endl "\n"
#define endt "\t"

using namespace std;


void getsubseq(string str, vector<string> subseq, int n){
    if( n >= str.length() )
            return;

    string tmp;
    for(int i = 0; i < subseq.size(); i++){
        tmp = subseq[i];
        tmp.push_back(str[i]);
        subseq.push_back(tmp);
    }
    getsubseq(str, subseq, n + 1);
}

int main(){
    string str;
    cin >> str;
    vector <string> subseq;
    subseq.push_back("");
    getsubseq(str, subseq, 0);

    for(int i = 0; i < subseq.size(); i++)
            cout << subseq[i] << endl;

    return 0;
}
