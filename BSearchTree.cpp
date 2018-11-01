#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#define endl "\n"


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

//double order traversal
void doubleOrder(Node* root);

//triple order traversal
void tripleOrder(Node* root);

//search operation in BST
bool search(Node* root, int target);

//min element
int min(Node* root);
// max element
int max(Node* root);

//function to delete a node from a BST
void deleteNode(Node* root, int data);

int getHeight(Node* root);

int countNode(Node* root);

int countLeafNode(Node* root);






int main(int argc, char const *argv[]){
	/* code */
	Node* root = NULL;
	/*
		Although root is not going to change after the first insert
	*/
	root = insert(root, 9);
	insert(root, 10);
	insert(root, 3);
	insert(root, 7);
	// insert(root, -3);
	insert(root, 0);
	insert(root, -5);
	//insert(root, 1);
	// insert(root, 4);
	// insert(root, -11);
	insert(root, 19);
	insert(root, 31);
	insert(root, 12);
	insert(root, 5);
	insert(root, 2);
	insert(root, 17);
	insert(root, 13);
	//insert(root, 11);
	insert(root, 6);
	//insert(root, 20);

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
	// cout << "level Order (Recursive) traversal: ";
	// queue<Node*> queue;
	// queue.push(root);
	// levelOrderRecursive(queue);
	// cout << endl;
	// cout << "double-order traversal: ";
	// doubleOrder(root);
	// cout << endl;
	// cout << "triple-order traversal: ";
	// tripleOrder(root);
	// cout << endl;
	cout << "min element = " << min(root) << endl;
	cout << "max element = " << max(root) << endl;
	cout << "height = " << getHeight(root) << endl;
	cout << "total nodes = " << countNode(root) << endl;
	cout << "total leaf nodes = " << countLeafNode(root) << endl;
	int target, data, choice;
	while (true) {
		/* code */
		cout << "choose opteration\n1.search\n2.delete :\n";
		cin>>choice;
		switch (choice) {
			case 1: cout << "enter target to search in tree" << endl;
							cin>>target;
							if(search(root, target))
								cout << target << " is present in tree" << endl;
							else
								cout << target << " is not present in tree" << endl;
							break;
			//case 2: cout << "level-order traversal before deletion : ";
							//levelOrder(root);
							//cout << endl;
							//cout << "enter the node->data to delete it must be a in tree:\n";
							//cin >> data;
							//deleteNode(root, data);
							//cout << "level-order traversal after deletion : ";
							//levelOrder(root);
							//cout << endl;
							//break;
			default: cout << "invalid choice !\n";
		}
	}
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
		 3     11
	 /   \    \
  1 	 7    19
 / \  /    /  \
0  2 5	  12 	31
 	  / \	 /	\
   4  6 10	17
     	  		/
     	  	13


*/

int getHeight(Node* root){
	if(!root or !root->left and !root->right)
		return 0;
	return 1 + max(getHeight(root->left), getHeight(root->right));

}

int countNode(Node* root){
	if(!root)
		return 0;
	if(!root->left and !root->right)
		return 1;
	return 1 + countNode(root->left) + countNode(root->right);
}

int countLeafNode(Node* root){
	if(!root)
		return 0;
	if(!root->left and !root->right)
		return 1;
	return countLeafNode(root->left) + countLeafNode(root->right);
}

// void deleteNode(Node* root, int data){
// 	if(!root){
// 		cout << "there is no such node ! \n";
// 		return;
// 	}
// 	if(data < root->data){
// 		deleteNode(root->left, data);
// 	}else if(data > root->data){
// 		deleteNode(root->right, data);
// 	}else {
// 		//element found
// 		Node* tmp;
// 		//if target  node has two children then replace with maz in left subtree
// 		if(root->left && root->right){
// 			tmp = root->left;
// 			while (tmp->right) {
// 				/* code */
// 				tmp = tmp->right;
// 			}
// 			root->data = tmp->data;
// 			deleteNode(root->left, tmp->data);
// 		}else{
// 			//if target node has only one node;
// 			tmp = root;
// 			if(!root->left)
// 				root = root->right;
// 			if(!root->right)
// 				root = root->left;
// 			free(tmp);
// 		}
// 	}
//
//
//
//
//
// 	/*
// 	if(root->data == data){
// 		Node* tmp1 = root->right;
// 		if(tmp1->left == NULL){
// 			swap(root->data, tmp1->data);
// 			deleteNode(root, tmp1->data);
// 			return;
// 		}else{
// 			Node* tmp2 = tmp1->left;
// 			while (tmp2->left != NULL) {
// 				/// code
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->left;
// 			}
// 			swap(root->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 	}
// 	//if target node is left child node
// 	if(root->left->data == data){
// 		Node* tmp1;
// 		Node* tmp2;
// 		//if target node delete has no child
// 		if(root->left->left == NULL and root->left->right == NULL){
// 			Node* tmp = root->left;
// 			root->left = NULL;
// 			delete(tmp);
// 			return;
// 		}
// 		//if target node has only one child -left child only
// 		else if(root->left->left != NULL and root->left->right == NULL){
// 			tmp1 = root->left;
// 			tmp2 = tmp1->left;
// 			if(tmp2->right == NULL ){
// 				root->left = tmp2;
// 				tmp1->left = NULL;
// 				delete(tmp1);
// 				return;
// 			}
// 			while(tmp2->right != NULL){
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->right;
// 			}
// 			swap(root->left->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 		//if target has only one child-right child only
// 		else if(root->left->left == NULL and root->left->right != NULL){
// 			tmp1 = root->left;
// 			tmp2 = tmp1->right;
// 			if(tmp2->left == NULL ){
// 				root->left = tmp2;
// 				tmp1->right = NULL;
// 				delete(tmp1);
// 				return;
// 			}
// 			while(tmp2->left != NULL){
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->left;
// 			}
// 			swap(root->left->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 		//if target node has two children
// 		else{
// 			tmp1 = root->left;
// 			tmp2 = tmp1->right;
// 			while (tmp2->left != NULL) {
// 				/// code
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->left;
// 			}
// 			swap(root->left->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 	}else if(root->right->data == data){
// 		Node* tmp1;
// 		Node* tmp2;
// 		//if target node delete has no child
// 		if(root->right->left == NULL and root->right->right == NULL){
// 			Node* tmp = root->right;
// 			root->right = NULL;
// 			delete(tmp);
// 			return;
// 		}
// 		//if target node has only one child -left child only
// 		else if(root->right->left != NULL and root->right->right == NULL){
// 			tmp1 = root->right;
// 			tmp2 = tmp1->left;
// 			if(tmp2->right == NULL ){
// 				root->right = tmp2;
// 				tmp1->left = NULL;
// 				delete(tmp1);
// 				return;
// 			}
// 			while(tmp2->right != NULL){
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->right;
// 			}
// 			swap(root->right->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 		//if target has only one child-right child only
// 		else if(root->right->left == NULL and root->right->right != NULL){
// 			tmp1 = root->right;
// 			tmp2 = tmp1->right;
// 			if(tmp2->left == NULL ){
// 				root->right = tmp2;
// 				tmp1->right = NULL;
// 				delete(tmp1);
// 				return;
// 			}
// 			while(tmp2->left != NULL){
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->left;
// 			}
// 			swap(root->right->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 		//if target node has two children
// 		else{
// 			tmp1 = root->right;
// 			tmp2 = tmp1->right;
// 			while (tmp2->left != NULL) {
// 				// code
// 				tmp1 = tmp2;
// 				tmp2 = tmp2->left;
// 			}
// 			swap(root->right->data, tmp2->data);
// 			deleteNode(tmp1, tmp2->data);
// 		}
// 	}
// 	else if(data < root->data){
// 		deleteNode(root->left, data);
// 	}
// 	else if(data > root->data){
// 		deleteNode(root->right, data);
// 	}
// 	*/
// 	return;
// }

bool search(Node* root, int target){
		if (!root) {
			/* code */
			return false;
		}
		if (root->data == target) {
			/* code */
			return true;
		}
		if (target < root->data) {
			/* code */
			return search(root->left, target);
		}else{
			return search(root->right, target);
		}
}

void preOrder(Node* root){
	if (!root)
		return;
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

int min(Node* root){
	if(!(root->left))
		return root->data;
	return min(root->left);
}

int max(Node* root){
	if(!(root->right))
		return root->data;
	return max(root->right);
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
