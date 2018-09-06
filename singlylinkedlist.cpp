#include <iostream>
using namespace std;

//node 
struct Node
{
	int data;
	Node* next; 
};
//declaration of a function to find the size of linked list --O(n)
int size(Node* head);
//declaration of a function to print the list
void printList(Node* head);
//declaration of a function to insert a node at begining--O(1)
Node* insertBegining(int data,Node* head);
//declaration of a function to insert a node at a specific index-- O(n)
void insertAt(int data,Node* head, int index);
//declaration of a function to delete a node from begining-- O(1)
Node* deleteBegining(Node* head);
//declaration of a function to delete a delete a node form specfic index--O(1)
void deleteAt(Node* head, int index);
/*
	few functions above return a Node* (head node basically) becuase they change the head node and we get new head 
	node each time
*/
/*
	We could handle both deletetion/insertion from begining and from any specific index with a single function
	But in that scenerio we have to handle that in if case resulting a lengthy function , which is bad practice.
*/ 

//function decalaration to to reverse a linked list --O(n)
Node* reverse(Node* head);

//recursive function to reverse a linked list
Node* reverseRecursively(Node* prev, Node* current, Node* next);

int main(int argc, char const *argv[])
{
	Node* head = NULL;
	int choice,data,index ;
	
	while(true){
		cout << "\n1.enter node at begining\n2.delete node from begining\n3.enter node at index\n4.delete node from index\n5.reverse linked list\n";
		cin>>choice;
		switch(choice){
			case 1: cout << "enter data\n";
					cin>>data;
					head = insertBegining(data, head);
					printList(head);
					break;
			case 2: head = deleteBegining(head);
				    printList(head);
				    break;
			case 3: cout << "enter data\n";
					cin>>data;
					cout << "enter index\n";
					cin>>index;
					insertAt(data, head, index);
					printList(head);
					break;
			case 4: cout << "enter index\n";
					cin>>index;
					deleteAt(head, index);
					printList(head);
					break;
			case 5: head = reverse(head)
					//head = reverseRecursively(NULL, head, NULL);
				    printList(head);
				    break;
			default:cout<<"you have entered wrong choice\n";
					break;
		}
		
	}

	return 0;
}
//function to get size of the linked list
int size(Node* head){
	int cout = 0;
	while(head !=NULL){
		head = head->next;
		cout++;
	}
	return cout;
}
//function to print to linked list
void printList(Node* head){
	Node *tmp = head;
	cout << "\nlinked list is :";
	while(tmp != NULL){
		cout <<tmp->data<<" ";
		tmp = tmp->next; 
	}
	cout<<"\n";
}
//insert at begining 
Node* insertBegining(int data, Node* head){
	// creating a node
	Node *node = new Node();
	// data part
	node->data = data;
	// a node has created node link node will point to null
	node->next = head;
	// head node will point to newly added node
	head = node;
	return head;
}
//insert at particular index 
void insertAt(int data, Node* head, int index){
	//checking validity of index
	if(index > size(head) or index < 1){
		cout << "invalid index ...index cant be greater(or less than 1) than size of the list\n";
		return; 
	}
	Node* tmp = head;
	Node* node = new Node();
	//set the data
	node->data = data;
	int count = 0;
	//reaching (index - 1)th node
	while(count < index -1){
		tmp = tmp->next;
		count++;
	}
	node->next = tmp->next;
	tmp->next = node;
}
//delete the begining node
Node* deleteBegining(Node* head){
	Node* tmp =  head;
	head = tmp->next;
	free(tmp);
	return head;
}
//delete the node from a specific index
void deleteAt(Node* head, int index){
	Node* tmp = head;
	if(index > size(head) or index < 1){
		cout << "invalid index ...index cant be greater(or less than 1) than size of the list\n";
		return; 
	}
	int count = 0;
	//reaching (index - 1)th node 
	while (count < index - 1){
		tmp = tmp->next;
		count++;
	}
	//node that has to be delete
	Node* node = tmp->next;
	//assign pre node's next (that has to be delete) to the post node  
	tmp->next = node->next;
	free(node);
}
//reverse a node
Node* reverse(Node* head){
	Node* tmp =  head;
	//previous node which initially points to null
	Node* prev = NULL;
	Node* node;
	while(tmp != NULL){
		node = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = node;
	}
	head = prev;
	return head;
}
/* function to reverse a linked list recrusively
Node* reverseRecursively(Node* prev, Node* current, Node* next){
	if(current == NULL){
		return prev;
	}
	else{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		return reverseRecursively(prev, current, next);
	}
}
*/