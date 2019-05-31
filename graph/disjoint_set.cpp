/*
 * @author      : macab (macab@macab)
 * @file        : disjoint_set
 * @created     : Saturday Jun 01, 2019 01:10:20 IST
*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define pb push_back 
using namespace std;

/* disjoint set using tree 
 * path compression method */

class DisjointSet{
        
        class Node{
                public:
                int data;
                int rank;
                Node* parent;
                    Node(int data){
                        this->data = data;
                        this->rank = 0; /* initially rank will be zero */
                    }
        };
        /*container*/
        map<int, Node*> container;

        public:
        void makeSet(int data){
            Node* node = new Node(data);
            node->parent = node;
            container[data] = node;
        }

        Node* findHelper(Node* node){
                if(node->parent == node ) return node;

                // return findHelper(node->parent);
                /* above just don't do compression, what if each node of the set get connected to the representative
                 * of that set means each node of the set will have same parent then path will compressed 
                 */
                node->parent = findHelper(node->parent);

        }

        /* finds the representative node of a set to whom given data belong */
        Node* find(int data){
            return findHelper(container[data]);
        }

        /* union is the operation to find the union set of two set union of set will 
         * give a new set which will have the representative one the them with higher rank,
         * if the rank of both representative is same and rank of representative of new set
         * will be increased by 1.
         */

        /* finds the union of two set two whom given data belong */
        void unionOfSet(int u, int v){
                /* basically setA and setB are the representative node of sets to whom u and v belong */
                Node* setA = find(u);                
                Node* setB = find(v); 

                /* of u and v belongs to same set it means union is not possible */
                if(setA->data == setB->data) return;

                if(setA->rank >= setB->rank){
                        setB->parent = setA;
                        /* check if both have same rank */
                        if(setA->rank == setB->rank){
                                setA->rank += 1;
                        }
                        container[setA->data] = setA;
                }else{
                        setA->parent = setB;
                        container[setB->data] = setB;
                }


        }


};


int main(){
	
    DisjointSet *ds = new DisjointSet();

    ds->makeSet(0);
    ds->makeSet(1);
    ds->makeSet(2);
    ds->makeSet(3);
    ds->makeSet(4);
    ds->makeSet(5);


    ds->unionOfSet(0, 1);
    ds->unionOfSet(0, 2);
    ds->unionOfSet(0, 3);
    ds->unionOfSet(3, 4);
    ds->unionOfSet(1, 5);

    cout << ds->find()->data << endl; 
	
	return 0;
}


