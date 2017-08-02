/*
 * Lame CS1-level Calculator
 */
#include <iostream>

using namespace std;
int main(int argc, char *args[]){
	//Variables
	char op;
	double a,b,c;	
	//Ask for operation
	cout<<"Select Operation: Add (+), Subtract (-), Multiply (*), Divide (/)"<<endl;
	cin>>op;
	//Ask for operands
	cout<<"Input first number:";
	cin>>a;
	cout<<"Input second number:";
	cin>>b;
	
	switch(op){
		case '+':
			c=a+b;
			break;
		case '-':
			c=a-b;
			break;
		case '*':
			c=a*b;
			break;
		case '/':
			c=a/b;
			break;
		default:	
			cout<<"Error: Try again."<<endl;
			return -1;
	}
	cout<<a<<op<<b<<"="<<c<<endl;
	
	return 0;
}

