/*
 * @author    : macab (macab@debian)
 * @file      : graph
 * @created   : Saturday Mar 16, 2019 12:15:41 IST
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

/* structure of the node of the graph
struct Node{
    int data;
    Node* link;
};
*/

// adjacency list implementation using multiset

// creating a node


// insert a node with their adjacence node


void insertNode(vector<vector<int>> &adjacency_list, map<int, int> &adjacency_map, int data, vector<int> &adjacent_nodes){ // adjacency map tells about the index of each node in adjacency list

    // add the node to the list to the node
    adjacency_map.insert({data, adjacency_list.size()});
    // create a new entry in adjacency list
    vector<int> newnode;
    // intialize it with the data we have to insert
    newnode.emplace_back(data);

    int adjacent;

    //cout << "adjacency map size = " << adjacency_map.size() << " adjacent_nodes size  = " << adjacent_nodes.size() << endl;

    // add adjacent node the adjancey list
    loop(i, 0, adjacent_nodes.size()){
        // if adjacent node[i] is not a node in the map(not in the adjacent_map)
        if(adjacency_map.find(adjacent_nodes[i]) != adjacency_map.end()){
        	// index of adjacent node from the adjacent matrix
            adjacent = adjacency_map.at(adjacent_nodes[i]);
            // adding to the adjacency list
            adjacency_list[adjacent].emplace_back(data);
            // newnode will be another entry in the adjacency list
            newnode.emplace_back(adjacency_list[adjacent][0]);
        }
    }
    // insert new entry in adjacency list obtained by new node
    adjacency_list.emplace_back(newnode);
    return;
}

void printAdjacenyList(vector<vector<int>> &adjacency_list){
    loop(i, 0, adjacency_list.size()){
        loop(j, 0, adjacency_list[i].size()){
             cout << adjacency_list[i][j] << " ";
        }
        cout << endl;
    }
    return;
}


int main(){
	ios::sync_with_stdio(0);


    // this is adjacecny list
    vector<vector<int>> adjacency_list;

    // this tells each node and their index in adjacency list(key = node  , value = index)
    map<int, int> adjacency_map;

    //this tells the adjacent node of the node we want to insert
    vector<int> adjacent_nodes;

    int data, n, tmp;
    while(true){
        cin >> data >> n;
        loop(i, 0, n){
            cin >> tmp;
            adjacent_nodes.emplace_back(tmp);
        }
        insertNode(adjacency_list, adjacency_map, data, adjacent_nodes);
        printAdjacenyList(adjacency_list);
        adjacent_nodes.clear();
    }

	return 0;
}

