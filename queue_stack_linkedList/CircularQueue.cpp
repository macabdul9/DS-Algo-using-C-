/*
 * @author    : macab (macab@debian)
 * @file      : CircularQueue
 * @created   : Friday Feb 08, 2019 06:20:41 IST
*/

#include<bits/stdc++.h>
#define endl 		         "\n"
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define rloop(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)
#define clr(x)                x.clear()
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
#define vs                    vector<string>
#define si                    set<int>
#define ss                    set<string>
#define mii                   map<int, int>
typedef long long int ll;
using namespace std;

// circular queue in cpp
struct Node{
    Node* prev;
    int data;
    Node* next;
};

// ends of the circularqueue
struct Ends{
    Node* front;
    Node* rear;
};

// function definitons
Node* createNode(int data);
Node* insertNode(int data);
Node* deleteNode();
void printQueue();
void getFrontandRear();

Node *front , *rear;


int main(){
    /*code goes here */
    // ;
    // front = nullptr;
    // rear = nullptr;
    front = rear = nullptr;
    int choice, data;;
    while(1){
        cout << "\n1. printQueue \n2.getFrontandRear\n3.push\n4.pop\n" << "enter you choice : ";
        cin >> choice;
        switch(choice){
            case 1: printQueue();
                    break;
            case 2: getFrontandRear();
                    break;
            case 3: cout << "\ninsert data to insert : ";
                    cin >> data;
                    rear = insertNode(data);
                    break;
            case 4: front = deleteNode();
                    break;
            default: cout << "\nplease enter the legit choice !";
                     break;
        }
    }
    return 0;
}


// function to creare the node
Node* createNode(int data){
    Node* node = new Node();
    node->prev = node->next = NULL;
    node->data = data;
    return node;
}

// function to insert the node into circularqueue
Node* insertNode(int data){
    Node* node = createNode(data);
    // if circularqueue is empty
    if(!front and !rear){
            front = rear = node;
            return rear;
    }
    Node *tmp1, *tmp2;
    tmp1 = front; //  tmp1 is current front
    tmp2 = rear;  // tmp2 is current rear
    tmp1->prev = NULL;
    tmp2->next = NULL; // cut the links
    tmp1->prev = node;
    node->next = tmp1;
    tmp2->next = node;
    node->prev = tmp2;
    rear = node; // new rear as insertion occurs at the rear of the circular queue
    return rear;
}
Node* deleteNode(){
    if(!front and !rear){
        cout << " queue is empty ..." << endl;
        return front;
    }
    Node *tmp1, *tmp2, *tmp3;
    tmp1 = front; //  tmp1 is current front
    tmp2 = front->next;  // tmp2 will be new front
    tmp3 = rear; // current rear
    tmp2->prev = NULL;
    tmp1->next = NULL;
    tmp1->prev = NULL;
    tmp3->next = NULL; // cut the links
    tmp2->prev = tmp3;
    tmp3->next = tmp2;
    delete(tmp1);
    front = tmp2; // new front
    return front;
}
void printQueue(){
    if(!front and !rear){
        cout << "\nqueue is empty fella...." << endl;
        return;
    }
    if(front == rear){
        cout << front->data << endl;
        return;
    }
    cout << " ⤹ "  << front->data << " ";
    Node *tmp =  front->next;
    while(tmp != front){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << " ⤸ " << endl;
    return;
}
void getFrontandRear(){
    if(!front and !rear){
        cout << "\nqueue is empty fella ...." << endl;
        return;
    }
    cout << " front = " << front->data << " rear = " << rear->data;
    return;
}
