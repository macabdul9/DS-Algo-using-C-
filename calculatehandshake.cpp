#include<iostream>
int calculateHandshake(int n);
int main(){
	std::cout<< calculateHandshake(6);
}
int calculateHandshake(int n){
	if (n < 2){
		return 0;
	}
	else{
		return calculateHandshake(n - 1) + n - 1;
	}
}