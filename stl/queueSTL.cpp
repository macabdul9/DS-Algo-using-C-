#include<iostream>
#include<queue>

using namespace std;
/*
The functions supported by queue are :
    empty() – Returns whether the queue is empty
    size() – Returns the size of the queue
    front() – Returns a reference to the first element of the queue
    back() – Returns a reference to the last element of the queue
    push(g) – Adds the element ‘g’ at the end of the queue
    pop() – Deletes the first element of the queue

*/

void show(queue<int> q);
int main(){
	queue <int> q;
	q.push(10);
	q.push(20);
	q.push(0);
	q.push(3);
	q.push(1);
	q.push(41);
	cout << "fron = "<< q.front() <<"  back = " <<q.back()<<endl;
	q.pop();
	cout << "fron = "<< q.front() <<"  back = " <<q.back()<<endl;
	show(q);
}
void show(queue<int> q){
	while(!q.empty()){
		cout<< q.front()<<"\t" ;
		q.pop();
	}
	cout<<endl;
}