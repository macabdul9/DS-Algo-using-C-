/*
 * @author    : macab (macab@debian)
 * @file      : shortest_distance
 * @created   : Sunday Apr 21, 2019 06:10:40 IST
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

// algorithm to find shortest distance of every node from a source node ! using bfs technique
// bfs application

class Graph{
    int V;
    list<int> *adjList;

    public:
        Graph(int v){
                this->V = v;
            adjList = new list<int>[v];
        }

        void addEdge(int u, int v, bool isBidir = true){
            adjList[u].push_back(v);
            if(isBidir)adjList[v].push_back(u);
        }

        void shortestDistance(int source){
            // distance data
            vi distance(V, 0);
            // supplmentary queue for bfs traversal
            queue<int> q;
            // visited track record, initially every vertex is considered as unvisited
            vector<bool> visited(V, false);

            q.push(source);
            visited[source] = true;

            while(!q.empty()){
                /*  ---BFS---
                 *  get the front of the queue and all its univisited adjacent vertices
                 *  and then remove the the fornt push the poped vertex an array, this array will be traversed vertices
                 */

                int current_vertex = q.front();
                q.pop();
                for(auto neighbour : adjList[current_vertex]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        distance[neighbour] = distance[current_vertex] + 1;

                    }
                }
            }

            // print the distance array ! in bfs order
            for(auto each : distance)
                    cout << each << " ";
            cout << endl;
        }
};

int main(){
	ios::sync_with_stdio(0);

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.shortestDistance(0);




	return 0;
}

