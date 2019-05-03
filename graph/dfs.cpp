/*
 * @author    : macab (macab@debian)
 * @file      : dfs
 * @created   : Saturday Apr 27, 2019 21:52:26 IST
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

class Graph{
    list<int> *adjList;
    int V;
    public:
        Graph(int v){
            this->V = v;
            adjList = new list<int>[V];
        }

        void addEdge(int u, int v, bool isBiDir = true){
            adjList[u].push_back(v);
            if(isBiDir)
                    adjList[v].push_back(u);
        }

        void dfs(int source, vector<bool> &visited){
            cout << source << " ";
            visited[source] = true;
            for(auto neighbour : adjList[source]){
                if(!visited[neighbour])
                        dfs(neighbour, visited);
            }
        }
};

int main(){
	ios::sync_with_stdio(0);

    Graph g(11);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(3, 9);
    g.addEdge(3, 10);
    g.addEdge(4, 3);
    g.addEdge(6, 5);
    g.addEdge(5, 8);
    g.addEdge(5, 7);
    g.addEdge(7, 8);

    vector<bool> visited(11, false);

    g.dfs(2, visited);


	return 0;
}

