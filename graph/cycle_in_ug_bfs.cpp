/*
 * @author      : macab (macab@macab)
 * @file        : cycle_in_ug_bfs
 * @created     : Thursday May 30, 2019 22:10:10 IST
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define pb push_back 
using namespace std;

class Graph{
        /* adjacency list */
        list<int> *adjList;
        
        /* number of vertex */
        int V;

        public:
        /* constructor to initialize the graph */
        Graph(int v){
                this->V = v;
                adjList = new list<int>[V];
        }

        /* function to connect the grapg vertices */
        void addEdge(int u, int v, bool isBiDir = true){
                adjList[u].pb(v);
                if(isBiDir)
                        adjList[v].pb(u);
        }




        /* time complexity for this function will be same as bfs  O(V + E)*/
        bool hasCycle(int start){

                vector<int> flag(this->V, -1);
                /* 
                 * here three flags will be used
                 * -1 : unvisited when vertex is not in the queue
                 *  0 : visited but not traversed, when vertex is in the queue
                 *  1 : visited and traversed, when we pop the vertex from the queue
                 *  initially all vertex will be univisited, hence flag will be -1. 
                 */

                queue<int> q;
                q.push(start);
                flag[start] = 0;
                int currentVertex ;
                while(!q.empty()){
                        currentVertex = q.front();
                        for(auto adjacentVertex : adjList[currentVertex]){
                                /* if adjacent of the currentVertex is already visited that means there exit a cycle */
                                if(flag[adjacentVertex] == 0){
                                    return true;
                                }
                                else if(flag[adjacentVertex] == -1){
                                        q.push(adjacentVertex);
                                        flag[adjacentVertex] = 0;
                                }

                        }

                        /* since all the adjacent vertices of the currentVertex have been visited hence we will pop it */ 
                        flag[currentVertex] = 1;  
                        q.pop();

                }

                return false;

        }

};


int main(){


    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 5);
    //g.addEdge(3, 4);
    //g.addEdge(4, 5); */

    cout << boolalpha << g.hasCycle(0) << endl;



	
	
	return 0;
}


