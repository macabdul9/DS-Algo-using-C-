#include<bits/stdc++.h>
#define endl "\n"
using namespace std;


void subset(string str,string ans, int i){
    if(i == str.length()){
        cout << ans << endl;
        return;
    }
    subset(str, ans,  i + 1);
    ans.push_back(str[i]);
    subset(str, ans,  i + 1);
}
int main(){
        string str;
        cin >> str;
        subset(str, " ", 0);

}
