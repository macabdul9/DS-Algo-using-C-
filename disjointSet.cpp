/*
 * @author    : macab (macab@debian)
 * @file      : disjointSet
 * @created   : Tuesday Apr 30, 2019 21:06:03 IST
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
 * disjoint set of data using union and path compression
 */

//template<typename T>

struct Node{
    int rank;
    int data;
    Node* parent;
};


/*
 * initially(set of single element) rank of the set will be zero and parent(also will be representative of that set)
 * will be same node.
*/

map<int, Node*> container;

void makeSet(int data){
    Node* node = new Node();
    node->rank = 0;
    node->data = data;
    node->parent = node;
    //container.insert({data, node});
    container[data] = node;
}

Node* findHelper(Node* &node){
        if(node->parent == node)
                return node;
        else return findHelper(node->parent);

}

Node* find(int data){
            return findHelper(container[data]);
}

void unionOfSet(int u, int v){
    Node *setA , *setB;

    setA = find(u);
    setB = find(v);

    if(setA->rank == setB->rank){
        setB->parent = setA;
        setA->rank += 1;
        container[u] = setA;
    }else if(setA->rank > setB->rank){
        setB->parent = setA;
        container[u] = setA;
    }else{
        setA->parent = setB;
        container[v] = setB;
    }

}

int main(){
	ios::sync_with_stdio(0);

    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    makeSet(5);
    makeSet(6);
    makeSet(7);

    unionOfSet(1, 2);
    unionOfSet(3, 4);
    unionOfSet(2, 4);

    cout << find(3)->data;

	return 0;
}

