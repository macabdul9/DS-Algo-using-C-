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
  if(!root)
    return createNode(data);

  if(!root->left){
    root->left = insert(root->left, data, q);
  }
  else if(!root->right){
    root->right = insert(root->right, data, q);
  }
  else{
    q.push(root->left);
    q.push(root->right);
    root = q.front();
    q.pop();
    insert(root, data, q);
  }
}
void preOrder(Node* root){
	if (!root)
	{
		return;
	}

	cout<< root->data <<" ";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Node* root){
	if (!root){
		return;
	}
	inOrder(root->left);
	cout<< root->data <<" ";
	inOrder(root->right);
}

void postOrder(Node* root){
	if (!root){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<< root->data <<" ";
}
void levelOrderRecursive(queue<Node*> queue){
	if(queue.empty())
		return;
	Node* node = queue.front();
	cout << node->data << " ";
	if(node->left != NULL)
		queue.push(node->left);
	if(node->right != NULL)
		queue.push(node->right);
	queue.pop();
	levelOrderRecursive(queue);
}

void doubleOrder(Node* root){
	if(!root)
		return;
	cout << root->data <<" ";
	doubleOrder(root->left);
	cout << root->data << " ";
	doubleOrder(root->right);
}
//triple order traversal
void tripleOrder(Node* root){
	if(!root)
		return;
	cout << root->data << " ";
	tripleOrder(root->left);
	cout << root->data << " ";
	tripleOrder(root->right);
	cout << root->data << " ";
}

int main(int argc, char const *argv[]) {
  Node* root = NULL;
  /* store the first insert return value because it will b root Node
  after that no need to store other return values */
  root = insert(root, 1, q);
  insert(root, 13, q);
  insert(root, 15, q);
  insert(root, 0, q);
  insert(root, 34, q);
  insert(root, -3, q);
  insert(root, 4, q);
  insert(root, 17, q);
  insert(root, 90, q);
  insert(root, -27, q);
  insert(root, 78, q);

  cout << "pre-order traversal: ";
  preOrder(root);
  cout << endl;
  cout << "in-order traversal: ";
  inOrder(root);
  cout << endl;
  cout << "post-order traversal: ";
  postOrder(root);
  cout << endl;
  cout << "level Order (Recursive) traversal: ";
  queue<Node*> queue;
  queue.push(root);
  levelOrderRecursive(queue);
  cout << endl;
  cout << "double-order traversal: ";
  doubleOrder(root);
  cout << endl;
  cout << "triple-order traversal: ";
  tripleOrder(root);
  cout << endl;

  return 0;
}
