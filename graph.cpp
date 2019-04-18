/*
 * @author    : macab (macab@debian)
 * @file      : graph
 * @created   : Friday Apr 19, 2019 04:28:50 IST
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
 * adjaceny list implementation of graph
 */

class Graph{
    // array of list of represent the arraylist represent of a graph !
    int v;
    list<int> *adjList;
    public:

        // constructor to initialize the graph having V vertices !
        Graph(int vertex){
            this->v = vertex;
            adjList = new list<int>[v];
        }

        // this function will add a bidirectional edge from vertex u to v
        void addEdge(int u, int v, bool isBidirectional = true){
            adjList[u].push_back(v);
            // if edge is bidirectional (in case of undirected graph)
            if(isBidirectional)
                    adjList[v].push_back(u);
        }

        // function to print graph !
        void printGraph(){
            for(int i = 0; i < v; i++){
                cout << i << "->";
                for(int each : adjList[i])
                        cout << each << ", ";
                cout << endl;
            }
        }

};

int main(){
	ios::sync_with_stdio(0);

    // time to create the object of the graph class !
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.printGraph();




	return 0;
}

