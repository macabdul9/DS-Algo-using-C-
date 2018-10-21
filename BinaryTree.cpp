#include <iostream>
#include <queue>
using namespace std;



struct Node{
  Node* left;
  int data;
  Node* right;
};

queue<Node*> q;

Node* createNode(int data){
  Node* node = new Node();
  node->left = NULL;
  node->data = data;
  node->right = NULL;
  return node;
}
Node* insert(Node* root, int data, queue<Node*> q){
  if(q.empty()){
    q.push(createNode(data));
    return q.front();
  }

  Node* tmp = q.front();
  q.pop();
  if(!tmp->left){
    tmp->left = insert(root, data, q);
  }
  else if(!tmp->right){
    tmp->right = insert(root, data, q);
  }
  q.push(tmp->left);
  q.push(tmp->right);
  insert(root, data, q);
  // return q.front();
}
void inOrder(Node* root){
	if (!root){
		return;
	}
	inOrder(root->left);
	cout<< root->data <<" ";
	inOrder(root->right);
}
int main(int argc, char const *argv[]) {
  Node* root;

  root = insert(root, 10, q);
  insert(root, 10, q);
  insert(root, 15, q);
  insert(root, 46, q);
  insert(root, 23, q);
  insert(root, 9, q);
  insert(root, 121, q);
  insert(root, 0, q);
  insert(root, -34, q);
  insert(root, 87, q);
  insert(root, 1, q);
  inOrder(root);
  return 0;
}
