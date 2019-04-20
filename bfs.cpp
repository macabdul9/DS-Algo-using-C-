/*
 * @author    : macab (macab@debian)
 * @file      : bfs
 * @created   : Sunday Apr 21, 2019 03:43:08 IST
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
 * bfs graph traversal algorithm
 * time complexity O(V + E)
 */

//let's create a graph first !

class Graph{
    // adjacency list
    list<int> *adjList;
    // no of vertice
    int V;
    public:
        Graph(int v){
            this->V = v;
            // array of list called adjacency list used in adjacency list implemenation of graph
            adjList = new list<int>[V];

        }

        void addEdge(int u, int v, bool isBiDir = true){
            // if there is an edge between u to v , add v in the list[u]
            adjList[u].push_back(v);
            // if this edge is bidirection (defualt in case of undirected graph )
            if(isBiDir) adjList[v].push_back(u);
        }

        void printadjList(){
            int limit = this->V;
            for(int i = 0; i < limit; i++){
                cout << i << " -> ";
                for(auto element : adjList[i])
                        cout << element << " ";
                cout << endl;
            }
        }

        vector<int> bfs(int source){
            int maxsize = this->V;
            // for bfs we need a queue and a tracker that store visited element !
            queue<int> q;
            // initially every vertex will be univisited
            vector<bool> visited(maxsize, false);
            vector<int> traversed;

            // enter the source node into queue and then enter its adjacents and mark it visited
            q.push(source);
            visited[source] = true;

            while(!(q.empty())){
                int v = q.front();
                q.pop();
                traversed.push_back(v);
                // mark v visited as well
                visited[v] = true;
                for(auto x: adjList[v]){
                    // of a vertex is not visited, then push into the queue and mark it visited
                    if(visited[x] == false){
                        q.push(x);
                        visited[x] = true;
                    }
                }

            }

            // prin traversed vertices !
            //for(auto x : traversed)
            //        cout << x << " ";
            ///cout << endl;
            //
            return traversed;
        }


};

int main(){
	ios::sync_with_stdio(0);

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // g.printadjList();
    vi bfs = g.bfs(4);
    for(auto each : bfs)
            cout << each << " ";
    cout << endl;


	return 0;
}

