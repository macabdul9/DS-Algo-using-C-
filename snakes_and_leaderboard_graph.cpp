/*
 * @author    : macab (macab@debian)
 * @file      : snakes_and_leaderboard_graph
 * @created   : Thursday Apr 25, 2019 05:01:39 IST
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
 * ---problem statement---
 *  given a 1 to N snakes and leaders board, starting and the ending points
 *  of all and leaders. We've to find out the  minimum nuber of dice throws
 *  to win the game. Each dice can have number from 1 to 6.
*/

/*
 * ---approach---
 *  suppose every level is a vertex of graph and whole  leaderboad is
 *  represented as graph.
 */

class Leaderboard{
    list<int> *adjList;
    int V;
    public:
        Leaderboard(int n){
            this->V = n;
            adjList = new list<int>[V];
        }
        void addEdge(int from, int to){
            adjList[from].push_back(to);
        }

        void shortestPath(int source, int dest){
            queue<int>  q;
            std::vector<bool> visited(this->V, false);
            std::vector<int> parent(this->V);

            q.push(source);
            visited[source] = true;
            while(!q.empty()){
                int currentVertex = q.front();
                q.pop();
                for(auto neighbour : adjList[currentVertex]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = currentVertex;
                    }
                }
            }
            for(auto path = dest; dest != source; dest = parent[dest])
                cout << path << "<--";
            cout << source << endl;
        }
};

int main(){
	ios::sync_with_stdio(0);

    // lets create the connectivity of leader board!
    //
    Leaderboard lb(36);
    // connectvity of first block!
    
    for(int i = 0; i < 36; i++){
        for(int j = i + 1; j <= i + 6 && j < 36; j++){
            lb.addEdge(i, j);
        }
    }
    // stair one
    lb.addEdge(0, 14);
    // stair two
    for(int i = 0; i < 4; i++)
        lb.addEdge(i, 6);

    // stair three
    for(int i = 2; i < 8; i++)
        lb.addEdge(i, 26);

    // stair four
    for(int i = 0; i < 17; i++)
        lb.addEdge(i, 28);

    // lets talk about snakes !
    // snake 1
    lb.addEdge(16, 3);
    // snake 2
    lb.addEdge(19, 5);
    // snake 3
    lb.addEdge(23, 15);
    // snake 4
    lb.addEdge(31, 29);
    // snake 5
    lb.addEdge(33, 11);


    lb.shortestPath(0, 35);


	return 0;
}

