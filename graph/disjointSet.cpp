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
 * source : https://www.youtube.com/watch?v=ID00PMy0-vE
 *
 * Disjoint sets using path compression and union by rank
 * Supports 3 operations
 * 1) makeSet
 * 2) union
 * 3) findSet
 *
 * For m operations and total n elements time complexity is O(m*f(n)) where f(n) is
 * very slowly growing function. For most cases f(n) <= 4 so effectively
 * total time will be O(m). Proof in Coreman book.
 *
 */


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


// time complexity of this function will be O(1) , as it takes no extra time(considering the fact that map assigning takes constant time)
void makeSet(int data){
    Node* node = new Node();
    node->rank = 0;
    node->data = data;
    node->parent = node;
    container[data] = node;
}


// find representative takes O() think
Node* findHelper(Node* &node){
        if(node->parent == node)
                return node;
        // path compression : parent of each node will be the node whose parent is itself (called repreentative of the set)
        node->parent = findHelper(node->parent);

}

Node* find(int data){
            return findHelper(container[data]);
}


// time complexity of union operation(union of two compressed set) will be contsant I say !
void unionOfSet(int u, int v){
    Node *setA , *setB;

    // get the representative of the both sets
    setA = find(u);
    setB = find(v);

    // if representative of both sets are same it means they're already in same set so union is meaningless !
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
    unionOfSet(2, 3);
    unionOfSet(4, 5);
    unionOfSet(6, 7);
    unionOfSet(5, 6);
    unionOfSet(3, 7);

    makeSet(11);
    makeSet(12);
    makeSet(13);
    makeSet(14);


    unionOfSet(11, 12);
    unionOfSet(13, 14);
    unionOfSet(11, 14);

    unionOfSet(7, 14);

    cout << find(14)->data << endl;

	return 0;
}

