/*
 * @author    : macab (macab@debian)
 * @file      : generic_graph
 * @created   : Saturday Apr 20, 2019 16:12:32 IST
*/
#include<bits/stdc++.h>
#include<iterator>
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
 * implementation of graph generic type !
 */

template<typename T>
class Graph{
        // adjcency list
        map<T, list<T>> adjList;
        public:
            Graph(){}
            void addEdge(T u, T v, bool isBiDir = true){
                adjList[u].push_back(v);
                if(isBiDir)
                        adjList[v].push_back(u);
            }

            void prinList(){

                for(auto itr = adjList.begin(); itr != adjList.end(); itr++){
                    cout << itr->first << " -> ";
                    for(auto connectedNode : itr->second){
                        cout << connectedNode << ", ";
                    }
                    cout << endl;
                }
            }
};

int main(){
	ios::sync_with_stdio(0);

    Graph<string> g;

    g.addEdge("Delhi", "Mumbai");
    g.addEdge("Lucknow", "Amritsar");
    g.addEdge("Delhi", "Lucknow");
    g.addEdge("Delhi", "Amritsar");

    g.prinList();


	return 0;
}

