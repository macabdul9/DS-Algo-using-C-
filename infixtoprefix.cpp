#include <iostream>
#include <string>
#include<stack>

using namespace std;

bool isBalanced(string exp);
string getPrefix(string exp);

int main(int argc, char const *argv[])
{
	string exp;
	getline(cin, exp);
	// isBalanced(exp);

	return 0;
}
string getPrefix(string exp){
	string result = "";
	string op =  "/*+-^";
	string opening = "({[";
	string closing = ")}]";

	if (isBalanced(exp))
	{
		/* code */
		stack<string> stack;
		for (int i = 0; i < exp.length(); ++i)
		{
			/* code */
			if (opening.find()< opening.length())
			{
				/* code */
				stack.push(exp[i])
			}
			

		}

	}else{
		return "unbalanced expression !"
	}
	return result
	

}
bool isBalanced(string exp){
	stack<char> stack; 
	string opening = "[{(";
	string closing = "]})";
	for(int i = 0; i < exp.length(); i++){
		if(opening.find(exp[i]) < opening.length()){
			stack.push(exp[i]);
		}else if (closing.find(exp[i]) < closing.length()){
			if(stack.empty() or  closing.find(exp[i]) != opening.find(stack.top())){
				return false;
			}else{
				stack.pop();
			}
		}
	}
	if(stack.empty()){
		return true;
	}else{
		return false;
	}
}