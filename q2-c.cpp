#include<iostream>
#include<stack>    // including stack library 
using namespace std;
 
class MyStack // My class 
{
	private:
		 stack<string> s; 
	public:
		bool getcharacter(char a);
		string prefixToPostfix(string exp);
		
};

bool MyStack::getcharacter(char a)  // function returning get character in form of bool 
{
switch (a) 
	{
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

string MyStack::prefixToPostfix(string exp) // converting prefix to postfix
{
	
	int len = exp.size();   // storing size in integer variable


	for (int i = len - 1; i >= 0; i--)   // using loop
	{
		
		if (getcharacter(exp[i]))  // calling function 
		{
			
			string obj1 = s.top();
			s.pop();
			string obj2 = s.top();
			s.pop();

		
			string obj = obj1 + obj2 + exp[i];

			
			s.push(obj);
		}

	
		else {


			s.push(string(1, exp[i]));
		}
	}

	return s.top();
}

 

int main() 
{
	MyStack s;   // class object 
    string exp = "*+AB-CD";
	cout << "Postfix : " << s.prefixToPostfix(exp); // calling function 
	return 0;
}

