#include<iostream>
#include<stack>    // including stack library 
using namespace std;
 
class MyStack // making class 
{
	private:
		 stack<char> s; 
         string num;
	public:
		int nextcharacter(char a);
		void infixToPostfix(string str);
		
};

int MyStack::nextcharacter(char elem) // This functions returns the next token in the input infix expression. The token may be an operator or  an operand.
{
    if(elem == '^')
        return 3;
    else if(elem == '/' || elem =='*')
        return 2;
    else if(elem == '+' || elem == '-')
        return 1;
    else
        return -1;
}
 


void MyStack::infixToPostfix(string fun) //Converts the input infix expression to postfix.It depending on whether it is an operand or operator or.
{
    for(int i = 0; i < fun.length(); i++) 
	{
        char elem = fun[i];
 
        
        if((elem >= 'a' && elem <= 'z') || (elem >= 'A' && elem <= 'Z') || (elem >= '0' && elem <= '9'))
            num += elem;
 
        
        else if(elem == '(')
            s.push('(');
 
        
        else if(elem == ')') 
		{
            while(s.top() != '(')
            {
                num += s.top();
                s.pop();
            }
            s.pop();
        }
 
        
        else 
		{
            while(!s.empty() && nextcharacter(fun[i]) <= nextcharacter(s.top())) 
			{
                num += s.top();
                s.pop(); 
            }
            s.push(elem);
        }
    }
 
    
    while(!s.empty()) 
	{
        num+= s.top();
        s.pop();
    }
 
    cout << num << endl;
}
 

int main() 
{
	MyStack s;
	
    string expression = "a+b*(c^d-e)^(f+g*h)-I";  // this expression is passing to function
    
   s. infixToPostfix(expression);   // calling function 
   
    return 0;
}
