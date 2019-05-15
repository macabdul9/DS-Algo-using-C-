/*
 * @author    : macab (macab@debian)
 * @file      : cycle_in_undirectedgraph_dfs
 * @created   : Friday May 10, 2019 06:11:25 IST
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



        bool hasCycleUtil(int u, vector<bool> &visited, int parent){
            visited[u] = true;
            for(int v : adjList[u]){
                if(!visited[v])
                        if(hasCycleUtil(v, visited, u))
                                return true;

                else if(v != parent)
                        return true;
            }
            return false;
        }

        bool hasCycle(){
		    vector<bool> visited(this->V, false);

            if(hasCycleUtil(0, visited, -1))
                    return true;
            else
                    return false;
        }

};

int main(){
	ios::sync_with_stdio(0);

    Graph g(3);
    g.addEdge(0, 1);


    cout << boolalpha << g.hasCycle() << endl;


	return 0;
}

