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
            vector<int> parent(this->V, -1);

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
            while(dest !=  -1){
                cout << dest << "<--";
                dest = parent[dest];
            }

            //cout << source << endl;
        }
};

int main(){
	ios::sync_with_stdio(0);


    Leaderboard lb(50);

    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;



    for(int u = 0; u < 36; u++){
        for(int dice = 1; dice <= 6; dice++){
            int v = u + dice + board[u + dice];
            lb.addEdge(u, v);
        }
    }

    lb.shortestPath(0, 35);

	return 0;
}

