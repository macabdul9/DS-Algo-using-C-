/*
 stack implementation using singly linked list
 here push and pop operation takes constant time - O(1)
 */

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* createNode(int data);
Node* push(Node* head, int data);
Node* pop(Node* head);
void printList(Node* head);
int main(int argc, char const *argv[])
{
	// head node - initially points to null
	Node* head = NULL;
	int choice, data;
	while(true){
		cout<<"1.push\n2.pop\n";
		cout << "enter choice : ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"enter data to push: ";
					cin>>data;
					head = push(head, data);
					printList(head);
					break;
			case 2: head = pop(head);
					printList(head);
					break;
			default:cout<<"wrong choice\n";
					break;
					
		}
	}
	return 0;
}

Node* createNode(int data){
	Node* node = new Node();
	node->next = NULL;
	node->data = data;
}

void printList(Node* head){
	cout<< "stack:  ";
	if (head == NULL){
		cout <<"empty\n";
		return;
	}
	Node* tmp = head;
	while(tmp !=NULL){
		cout<< tmp->data <<" ";
		tmp = tmp->next;
	}
	cout << "\n";
	return;
}

Node* push(Node* head, int data){
	Node* node = createNode(data);

	if (head == NULL)
	{
		/* if list is empty then first node will be head node */
		return node;

	}
	node->next = head;
	head = node;
	return head;
}

Node* pop(Node* head){
	if (head == NULL)
	{
		/* code */
		cout<< "stack is empty, so can not be poped !\n";
		return head;
	}
	Node* tmp = head;
	head = tmp->next;
	delete(tmp);
	return head;
}
