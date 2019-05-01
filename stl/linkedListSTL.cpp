#include <iostream>
#include <list>
using namespace std;

/*
	Functions used with List :
	front() – Returns the value of the first element in the list
	back() – Returns the value of the last element in the list
	push_front(g) – Adds a new element ‘g’ at the beginning of the list
	push_back(g) – Adds a new element ‘g’ at the end of the list
	pop_front() – Removes the first element of the list, and reduces size of the list by 1
	pop_back() – Removes the last element of the list, and reduces size of the list by 1
	begin() – Returns an iterator pointing to the first element of the list
	end() – Returns an iterator pointing to the theoretical last element which follows the last element
	empty() – Returns whether the list is empty(1) or not(0)
	insert() – Inserts new elements in the list before the element at a specified position
	erase() – Removes a single element or a range of elements from the list
	assign() – Assigns new elements to list by replacing current elements and resizes the list
	remove() – Removes all the elements from the list, which are equal to given element
	reverse() – Reverses the list
	size() – Returns the number of elements in the list
	sort() – Sorts the list in increasing order
*/

void show(list<int> myList);
int main(int argc, char const *argv[])
{
	list<int> myList;
	myList.push_front(10);
	myList.push_front(20);
	myList.push_front(30);
	myList.push_front(40);
	myList.push_front(50);
	myList.push_front(60);
	show(myList);
	return 0;
}
void show(list<int> myList){
	while(!myList.empty()){
		cout<<myList.front()<<"\t";
		myList.pop_front();
	}
	cout << endl;
}