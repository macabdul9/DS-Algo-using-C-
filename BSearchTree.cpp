#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

//structure of each node of the tree node
struct Node{
	Node* left;
	int data;
	Node* right;
};

//function to create node;
Node* createNode(int data);
//function to insert node into BST
Node* insert(Node* root, int data);
//function for pre-order traversal 
void preOrder(Node* root);
//function for post-order traversal
void inOrder(Node* root);
//function for post-order traversal
void postOrder(Node* root);
//function for level order traversal
void levelOrder(Node* root);
void levelOrderRecursive(queue<Node*> queue);


int main(int argc, char const *argv[]){
	/* code */
	Node* root = NULL;
	root = insert(root, 9);
	root = insert(root, 10);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 19);
	root = insert(root, 31);
	root = insert(root, 1);
	root = insert(root, 12);
	root = insert(root, 0);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 17);
	root = insert(root, 13);
	root = insert(root, 4);
	root = insert(root, 11);
	root = insert(root, 6);
										           

	cout << "pre-order traversal: ";
	preOrder(root);
	cout << endl;
	cout << "in-order traversal: ";
	inOrder(root);
	cout << endl;
	cout << "post-order traversal: ";
	postOrder(root);
	cout << endl;
	cout << "level-order traversal: ";
	levelOrder(root);
	cout << endl;
	cout << "level Order (Recursive) traversal: ";
	queue<Node*> queue;
	queue.push(root);
	levelOrderRecursive(queue);
	cout << endl;
	return 0;
}
Node* createNode(int data){
	Node* node = new Node();
	node->left = nullptr;
	node->data =  data;
	node->right = nullptr;
	return node;
}
Node* insert(Node* root, int data){
	//when BST is empty and to reach the 
	if(!root) {
		Node* node = createNode(data);
		return node; 
	}
	if (data < root->data )
	{
		root->left = insert(root->left, data);

	}else{
		root->right = insert(root->right, data);
	}
	return root;
}
/*--binary search tree

			  root
			   |
			   9
			/    \
		   3     10
		/    \      \
	  1 	  7      19
	/  \     /      /   \
   0    2   5	  12 	31
 	  	   / \	 /	\   
     	  4   6 11	 17
     	  			/
     	  		   13
		   	
										
*/  
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
void levelOrder(Node* root){
	if(!root)
		return;
	// store root node into queue
	queue<Node*> queue;
	queue.push(root);
	/*
		pop each node from the queue and push the child node (if not null) into
		the queue, keep doing this untill queue is empty.
	*/
	while(!queue.empty()){
		Node* node = queue.front();
		if(node->left != NULL)
			queue.push(node->left);
		if(node->right != NULL)
			queue.push(node->right);
		cout << node->data << " ";
		queue.pop();
	}

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