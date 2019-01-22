/*
 queue implementation using doubly linked list
 here enque and deque operation takes constant time - O(1)
*/

#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int data;
	Node* next;
};
//structure that holds head and tail of the Queueueue
struct Queue
{
	Node* front;
	Node* rear;
};
//for enQueueue and deQueueue operation we need to pass  the front and rear.
Node* createNode(int data);
Queue enQue(Queue ends, int data);
Queue deQue(Queue ends);
void printQueue(Queue ends);

int main(int argc, char const *argv[])
{
	//ends
	Queue ends;
	ends.front = NULL;
	ends.rear = NULL;
	int data, choice;
	while(true){
		cout<<"\n1.enque\n2.deque\n";
		cout << "enter choice : ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"enter data to enque: ";
					cin>>data;
					ends = enQue(ends, data);
					printQueue(ends);
					break;
			case 2: ends = deQue(ends);
					printQueue(ends);
					break;
			default:cout<<"wrong choice\n";
					break;

		}
	}

	return 0;
}
Node* createNode(int data){
	Node* node = new Node();
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	return node;

}
void printQueue(Queue ends){
	//here front for forward print to print in reverse order we can take rear
	Node* tmp = ends.front;
	cout << "Queue: ";
	if (tmp == NULL){
		cout << "empty !";
		return;
	}
	while(tmp != NULL){
		cout  << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << "\n";
}
Queue enQue(Queue ends, int data){
	Node* node = createNode(data);

	if (ends.front == NULL)
	{
		ends.front = node;
		ends.rear = node;
		return ends;
	}

	Node* tmp =  ends.rear;
	tmp->next = node;
	node->prev = tmp;
	ends.rear = node;
	return ends;
}
Queue deQue(Queue ends){
	if (ends.front == NULL)
	{
		/* code */
		cout<<"queue is empty so can not be deQued\n";
		return ends;
	}
	Node* tmp = ends.front;
	ends.front = tmp->next;
	tmp->next = NULL;

	delete(tmp);
	return ends;
}
