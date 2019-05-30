/*
 * @author      : macab (macab@macab)
 * @file        : cycle_in_ug_disjointSet
 * @created     : Friday May 31, 2019 00:06:17 IST
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define pb push_back 
using namespace std;


class DisjointSet{
        class Node{
            public:
            int data;
            int rank;
            Node* parent;
            Node(int data){
                    this->data = data;
                    this->rank = 0;
            }
            
        };
        public:
        map<int, Node*> container;
        void makeSet(int data){
                Node *node = new Node(data);
                node->parent = node; /* initially parent of each node will be that node itself */
                container[data] = node;
        }

        Node* findHelper(Node* node){
                if(node->parent == node) return node;
                node->parent = findHelper(node->parent);
        }
        Node* find(int data){
                return findHelper(container[data]);
        }
       
        void unionOfSet(int u, int v){
                Node *setA, *setB;
                setA = find(u);
                setB = find(v);

                if(setA->data == setB->data) return;

                if(setA->rank >= setB->rank){
                        setB->parent = setA;
                        if(setA->rank == setB->rank)
                                setA->rank += 1;
                        container[u] = setA;
                }else{
                        setA->parent = setB;
                        container[v] = setB;
                }
        }
};

class Graph{
        list<int> *adjList;
        int V;
        set<int> vertices; 
        multimap<int, int> edges;
        public:
        Graph(int v){
                this->V = v;
                adjList = new list<int>[V];
        }

        void addEdge(int u, int v, bool isBiDir = true){
                adjList[u].pb(v);
                if(isBiDir)
                        adjList[v].pb(u);
                edges.insert({u, v});
                vertices.insert(u);
                vertices.insert(v);
        }
        bool hasCycle(){
                DisjointSet ds;

                for(auto vertex : vertices)
                        ds.makeSet(vertex);

                for(auto edge : edges){
                    if((ds.find(edge.first))->data == (ds.find(edge.second))->data)
                        return true;
                    ds.unionOfSet(edge.first, edge.second);
                }

                return false;

        }
};


int main(){
	Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    cout << boolalpha << g.hasCycle() << endl;

	
	return 0;
}


