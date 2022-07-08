#include<iostream>
#include<stack>    // including stack library 
using namespace std;
 
class MyStack // making class 
{
	private:
		 stack<string> s; 
	public:
		bool getcharacter(char a);
		string postfixToInfix(string exp);
		
};

bool MyStack::getcharacter(char x)  // this function return operand in form of bool expression 
{
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}
 
string MyStack::postfixToInfix(string exp)  // this function convert postfix to infix 
{

	for (int i=0; exp[i]!='\0'; i++)  // using loop
	{
	
		if (getcharacter(exp[i])) // calling function
		{
		string obj(1, exp[i]);
		s.push(obj);
		}

		else
		{
			string obj1 = s.top();
			s.pop();
			string obj2 = s.top();
			s.pop();
			s.push("(" + obj2 + exp[i] +
				obj1 + ")");
		}
	}

	return s.top();
}

 

int main() 
{
	MyStack s;
	string exp = "abc++";
	cout << s.postfixToInfix(exp); // calling function passing exp as a parameter
	return 0;
}

