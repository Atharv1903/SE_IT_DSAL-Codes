// Name - Atharv Uddhav Kharmate.
// Roll NO - 23141
// Division - SE-09
// Batch - F9

//Program :-

#include<iostream>
#include<string.h>
class node
{
	public:
	char d;
	node* next;
};

class stack
{
	node* top;
	public:
	stack()
      {
		top = NULL;
	}
	char pop();
	void push(char d1);
	void display();
	int empty();   
};

//================================================================

#include<iostream>
#include<string.h>

using namespace std;

char stack:: pop()
{
	if (empty() == 1)
	{
		cout << "\nUnderflow Condition ";
		return -1;
	}
	else
	{
		node* p = top;
		top = top->next;
		char x = p->d;
		delete p;
		return x;
	}
}

void stack::push(char d1)
{
	node* p = new node;
	p->d = d1;
	p->next = top;
	top = p;
}

int stack::empty()
{
	if (top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stack::display()
{
	node* p = top;
	while (p != NULL)
	{
		cout << p->d << "\n";
		p = p->next;
	}
}

//================================================================

#include <iostream>
#include <string.h>

using namespace std;

class expression : public stack
{
public:
	float Operation(char Op, float A, float B)
	{
		int I = 0;
		float P = 1;
		if (Op == '*')
			P = A * B;
		else if (Op == '/')
			P = A / B;
		else if (Op == '+')
			P = A + B;
		else if (Op == '-')
			P = A - B;
		else
			while (I++ < B)
				P = P * A;
		return P;
	}
	
      float Postfix_Evaluation(char String[20])
	{
		int I = 0;
		float Operand1, Operand2, Result;
		stack s;
		while (String[I] != '\0')
		{
			if (String[I] >= '0' && String[I] <= '9')
				s.push(String[I] - 48);
			else
			{
				Operand2 = s.pop();
				Operand1 = s.pop();
				Result = Operation((char)String[I], Operand1, Operand2);
				s.push(Result);
			}
			I++;
		}
		return s.pop();
	}

	float Prefix_Evaluation(char String[20])
	{
		int I = strlen(String);
		float Operand1, Operand2, Result;
		stack s;
		I--;
		while (I >= 0)
		{
			if (String[I] >= '0' && String[I] <= '9')
				s.push(String[I] - 48);
			else
			{
				Operand1 = s.pop();
				Operand2 = s.pop();
				Result = Operation((char)String[I], Operand1, Operand2);
				s.push(Result);
			}
			I--;
		}
		return s.pop();
	}
	
      int Priority(char x) 
	{
		if (x == '(')
		{
			return (0);
		}
		if (x == '+' || x == '-')
		{
			return (1);
		}
		if (x == '*' || x == '/' || x == '%')
		{
			return (2);
		}
		if (x == '^')
		{
			return (3);
		}
	}

	void infix_to_postfix(char String[])
	{
		char PostExpression[25], opr;
		int I = 0, J = 0, count;
		stack s;

		for (I = 0; I < strlen(String); I++)
		{
			if (isalnum(String[I]))
				PostExpression[J++] = String[I];
			else
			{
				if (String[I] == ')')
				{
					opr = s.pop();
					while (opr != '(')
					{
						PostExpression[J++] = opr;
						opr = s.pop();
					}
				}

				else
				{
						if (String[I] == '(')
						s.push(String[I]);
					else
					{
						while (!s.empty())
						{
							opr = s.pop();
							if (opr != '(' && Priority(opr) >= Priority(String[I]))
							{
								PostExpression[J++] = opr;
							}
							else
							{
								s.push(opr);
								break;
							}
						}
						s.push(String[I]);
					}
				} 
			}
		} 
		while (!s.empty())
		{
			PostExpression[J++] = s.pop();
		}
		PostExpression[J] = '\0';
		cout << "\nPostfix Expression is : " << PostExpression;
	}

	void InfixToPrefix(char String[20])
	{
		char PreExpression[20], opr;
		int I = 0, J = 0;
		I = strlen(String);
		I--;
		stack s;
		for (I = strlen(String); I >= 0; I--)
		{
			if (isalnum(String[I]))
				PreExpression[J++] = String[I];
			else
			{
				if (String[I] == '(')
				{
					opr = s.pop();
					while (opr != ')')
					{
						PreExpression[J++] = opr;
						opr = s.pop();
					}
				}

				else
				{
					if (String[I] == ')')
						s.push(String[I]);
					else
					{
						while (!s.empty())
						{
							opr = s.pop();
							if (opr != ')' && Priority(opr) >= Priority(String[I]))
							{
								PreExpression[J++] = opr;
							}
							else
							{
								s.push(opr);
								break;
							}
						} // End of while
						s.push(String[I]);
					}
				} // End of else
			}
		} 

		while (!s.empty())
			PreExpression[J++] = s.pop();
		PreExpression[J] = '\0';
		cout << " Prefix expression is : "; 
		for (I = J - 1; I >= 0; I--)
			cout << PreExpression[I];
	}
};

int main()
{
	expression s;
	int d1, i, ch1;
	char ch;
	char Infix_expression[100];
	char expression[100];
	do
	{
		cout << "\n\n\t************MENU************" << endl;
		cout << "\n\t1:Infix to postfix" << endl;
		cout << "\t2:Infix to Prefix" << endl;
		cout << "\t3:Postfix Evaluation" << endl;
		cout << "\t4:Prefix Evaluation" << endl;
		cout << "\t5:Exit" << endl;

		cout << "\nEnter your choice :\t";
		cin >> ch1;
		switch (ch1)
		{
		case 1:
			cout << "\nEnter the Infix Expression : ";
			cin >> Infix_expression;
			s.infix_to_postfix(Infix_expression);
			break;

		case 2:
			cout << "\nEnter the Infix Expression : ";
			cin >> Infix_expression;
			s.InfixToPrefix(Infix_expression);
			break;

		case 3: // evaluation of Postfix
			float answer;
			cout << "\nEnter the Postfix Expression : ";
			cin >> expression;
			answer = s.Postfix_Evaluation(expression);
			cout << "The answer is : " << answer << endl;
			break;

		case 4: // evaluation of Prefix
			float answer2;
			cout << "\n\n Enter the Prefix Expression : ";
			cin >> expression;
	   		answer2 = s.Prefix_Evaluation(expression);

			cout << "The answer is : " << answer2 << endl;

			break;
		case 5:
			cout << "\nExit." << endl;
			break;
		default:
			cout << "\nEnter a valid choice." << endl;
			break;
		}
	} while (ch1 != 5);
	return (0);
}

//Output :-

/*

************MENU************

		1:Infix to postfix
		2:Infix to Prefix
		3:Postfix Evaluation
		4:Prefix Evaluation
		5:Exit

Enter your choice :     1

Enter the Infix Expression : (A+B)/(C*D)

Postfix Expression is : AB+CD

************MENU************

		1:Infix to postfix
		2:Infix to Prefix
		3:Postfix Evaluation
		4:Prefix Evaluation
		5:Exit

Enter your choice :     2

Enter the Infix Expression : (A+B)/(C*D)
Prefix expression is :  /+AB*CD

************MENU************

		1:Infix to postfix
		2:Infix to Prefix
		3:Postfix Evaluation
		4:Prefix Evaluation
		5:Exit

Enter your choice :     3

Enter the Postfix Expression : 234*+5+
The answer is : 19


************MENU************

		1:Infix to postfix
		2:Infix to Prefix
		3:Postfix Evaluation
		4:Prefix Evaluation
		5:Exit

Enter your choice :     4


Enter the Prefix Expression : /+32*54
The answer is : 0


************MENU************

		1:Infix to postfix
		2:Infix to Prefix
		3:Postfix Evaluation
		4:Prefix Evaluation
		5:Exit

Enter your choice :     5

EXIT.
*/

