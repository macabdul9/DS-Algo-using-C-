#ifndef BINARYTREE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define BINARYTREE_H

#include<bits/stdc++.h>
//function to create node;
Node* createNode(int data);
//function for pre-order traversal
void preOrder(Node* root);
//function for post-order traversal
void inOrder(Node* root);
//function for post-order traversal
void postOrder(Node* root);
//function for level order traversal
void levelOrderRecursive(queue<Node*> queue);
//double order traversal
void doubleOrder(Node* root);
//triple order traversal
void tripleOrder(Node* root);
#endif
