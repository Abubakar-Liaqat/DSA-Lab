#include<iostream>
#include <string>
using namespace std;
template <typename T>
class Stack
{
	T arr[100];
	int top;
	int size;
public:
	Stack()
	{
		for (int i = 0; i < 100; i++) arr[i] = T();

		top = -1;
		size = 100;
	}
	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == size - 1;
	}
	void push(T val)
	{
		if (top != size - 1)
		{
			top++;
			arr[top] = val;
		}
	}
	T pop()
	{
		if (top != -1)
		{
			top--;
			return arr[top+1];
		}
		else
		{
			cout << "EMPTY STACK ! ";
			return T();
		}
	}
	T Top()
	{
		if (!isEmpty())
		{
			return arr[top];
		}
		else
		{
			cout << "EMPTY STACK ! ";
			return T();
		}
	}
	void display()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
	}


};
int prec(char c)
{
	if (c == '^') return 3;
	else if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else return -1;
}

string InfixtoPostfix(string str)
{
	Stack<char> s;
	string res=string();
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z'
			|| str[i] >= 'A' && str[i] <= 'Z')
		{
			res += str[i];
		}
		else if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{ //case for popping when closing is detected and we have to pop until opening isnt found
			while (!s.isEmpty() && s.Top() != '(')
			{//pop untill opening braces isnt found at the top of stack
				res += s.Top();
				s.pop();
			}
			if (!s.isEmpty())
			{//cant let opening stay in stack pop it too
				s.pop();
			}
		}
		//case for operator
		else
		{
			while (!s.isEmpty() && prec(str[i]) <= prec(s.Top())) 
			{
				res += s.Top();
				s.pop();
			}
			s.push(str[i]);
		}
		

	}
	while (!s.isEmpty())
	{
		res += s.Top();
		s.pop();
	}
	return res;

}
string ReverseInfixforPrefix(string& str)
{
	string rev;
	int index=0;
	for (int i = str.length()-1; i >= 0; i--)// -1 too tackle the null character
	{
		
		
			if (str[i] == '(') 
			{
				rev+= ')';
			}
		
		else if (str[i] == ')') 
			{
				rev+= '(';
			}
		else
			{
				rev += str[i];
			}

		 
	}
	 
	return rev;

}


string InfixtopPrefix(string str)
{
	Stack<char> s;
	string res;
	str=ReverseInfixforPrefix(str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z'
			|| str[i] >= 'A' && str[i] <= 'Z')
		{
			res += str[i];
		}
		else if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{ //case for popping when closing is detected and we have to pop until opening isnt found
			while (!s.isEmpty() && s.Top() != '(')
			{//pop untill opening braces isnt found at the top of stack
				res += s.Top();
				s.pop();
			}
			if (!s.isEmpty())
			{//cant let opening stay in stack pop it too
				s.pop();
			}
		}
		//case for operator
		else
		{
			while (!s.isEmpty() && prec(str[i]) <= prec(s.Top()))
			{
				res += s.Top();
				s.pop();
			}
			s.push(str[i]);
		}


	}
	while (!s.isEmpty())
	{
		res += s.Top();
		s.pop();
	}
	return ReverseInfixforPrefix(res);

}

string PostToInfix(string str)
{
	Stack<string> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z'
			|| str[i] >= 'A' && str[i] <= 'Z')
		{
			s.push(string(1, str[i]));
		}
		else
		{
			string op1 = s.Top();
			s.pop();
			string op2 = s.Top();
			s.pop();
			s.push("(" + op2 + str[i] + op1 + ")");
		}
	}
	return s.Top();
}
string PreToInfix(string str)
{
	Stack<string> s;
	for (int i = str.length()-1; i >=0; i--)
	{
		if (str[i] >= 'a' && str[i] <= 'z'
			|| str[i] >= 'A' && str[i] <= 'Z')
		{
			s.push(string(1, str[i]));
		}
		else
		{
			string op1 = s.Top();
			s.pop();
			string op2 = s.Top();
			s.pop();
			s.push("(" + op1 + str[i] + op2 + ")");
		}
	}
	return s.Top();
}

string PostToPre(string str)
{
	string infix = PostToInfix(str);
	string prefix = InfixtopPrefix(infix);
	return prefix;
}
string PreToPost(string str)
{
	string infix = PreToInfix(str);
	string postfix = InfixtoPostfix(infix);
	return postfix;
}


void menu()
{
	string expression;
	int choice;

	while (true)
	{
		cout << "\nChoose an option:" << endl;
		cout << "1. Infix to Postfix" << endl;
		cout << "2. Infix to Prefix" << endl;
		cout << "3. Postfix to Infix" << endl;
		cout << "4. Prefix to Infix" << endl;
		cout << "5. Postfix to Prefix" << endl;
		cout << "6. Prefix to Postfix" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter Infix Expression: ";
			cin >> expression;
			cout << "Postfix: " << InfixtoPostfix(expression) << endl;
			break;
		case 2:
			cout << "Enter Infix Expression: ";
			cin >> expression;
			cout << "Prefix: " << InfixtopPrefix(expression) << endl;
			break;
		case 3:
			cout << "Enter Postfix Expression: ";
			cin >> expression;
			cout << "Infix: " << PostToInfix(expression) << endl;
			break;
		case 4:
			cout << "Enter Prefix Expression: ";
			cin >> expression;
			cout << "Infix: " << PreToInfix(expression) << endl;
			break;
		case 5:
			cout << "Enter Postfix Expression: ";
			cin >> expression;
			cout << "Prefix: " << PostToPre(expression) << endl;
			break;
		case 6:
			cout << "Enter Prefix Expression: ";
			cin >> expression;
			cout << "Postfix: " << PreToPost(expression) << endl;
			break;
		case 7:
			cout << "Exiting program." << endl;
			return;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
}

int main()
{
	menu();  // Call the menu function to start the program
	return 0;
}