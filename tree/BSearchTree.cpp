#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#define MAX 100000

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

//function to delete a node from a BST
Node* deleteNode(Node* root, int data);

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
		cout << "\nchoose opteration\n1.search\n2.insert\n3.delete :\n";
		cin>>choice;
		switch (choice) {
			case 1: cout << "enter target to search in tree" << endl;
							cin>>target;
							if(search(root, target))
								cout << target << " is present in tree" << endl;
							else
								cout << target << " is not present in tree" << endl;
							break;
     case 2:  cout << "enter the element to insert " << endl;
              cin >> data;
              root = insert(root, data);
              preOrder(root);
              break;
			case 3: cout << "level-order traversal before deletion : ";
							levelOrder(root);
							cout << endl;
							cout << "enter the node->data to delete it must be a in tree:\n";
							cin >> data;
							root = deleteNode(root, data);
							cout << "level-order traversal after deletion : ";
							levelOrder(root);
							cout << endl;
							break;
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
	if(search(root, data)){
		std::cout << "node is already there in bst insert other value" << '\n';
		return root;
	}
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

Node* deletingNode(Node* node, int data){
	if(!node ) return NULL;
	if(!node->left and !node->right and node->left->data == data or node->right->data == data) return node;
	if(node->data == data) return node;

	if (node->data > data)
		return deletingNode(node->left, data);
	else
		return deletingNode(node->right, data);
}
Node* deleteNode(Node* node, int data){
    /*
     * there will be two scnerio to delete a node
     * 1. node is a leaf
     * 2. node is a non-leaf
     *      a. node has only one node
     *      b. node has two child
     *
     */

		 Node* tmp = deletingNode(node, data);
		 if(tmp == NULL){
			 std::cout << "node is not present in the bst" << '\n';
			 return node;
		 }
		 Node* max;
		 if(tmp->data == data){
				if(node->left){
					max = node->left;
				}
				while(max->right and max->right->right){
					max = max->right;
				}
				swap(max->data, tmp->data);
				Node* target = max

		 }
    // if node has no child
    //Node* targetNode;
    // if(tmp->left == NULL and tmp->right == NULL){
    //           tmp->data = MAX;
		// 					tmp = NULL;
    // }else{
		//
		// }
    return node;
}

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
