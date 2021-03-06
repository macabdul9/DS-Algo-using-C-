/*
 * @author    : macab (macab@debian)
 * @file      : cycle_in_ug_dfs
 * @created   : Thursday May 23, 2019 22:31:08 IST
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

        bool hasCycleHelper(int currentVertex, int incomingVertex, vector<bool> &visited){
                /* mark the current vertex visited */
                visited[currentVertex] = true;

                /* 
                 * for each adjacent vertex of the current vertex if there exit a vertex which 
                 * is visited and it is not incoming vertex it means there's cycle.
                 */
                for(int adjacentVertex: adjList[currentVertex]){
                        if(!visited[adjacentVertex]){
                                if(hasCycleHelper(adjacentVertex, currentVertex, visited))
                                        return true;
                        }else if(adjacentVertex !=  incomingVertex)
                                return true;
                }
                return false;

        }
        bool hasCycle(int currentVertex, int incomingVertex){
                vector<bool> visited(this->V, false);
                return hasCycleHelper(currentVertex, incomingVertex, visited);
                
        }
};

int main(){
	ios::sync_with_stdio(0);

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    //g.addEdge(4, 5);

    cout << boolalpha << g.hasCycle(0, -1) << endl;



	return 0;
}

