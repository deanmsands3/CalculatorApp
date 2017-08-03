/*
 * Still Lame CS2-level Calculator
 */
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
//Borrowed from https://stackoverflow.com/a/29169409
bool is_number(const std::string& s)
{
    try
    {
        std::stod(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}

char to_op(const string &op){
	return op.c_str()[0];
}


bool is_operator(string op){
	if(op.length()>1){return false;}
	char c_op=to_op(op);

	switch(c_op){
		case '+':
			return true;
		case '-':
			return true;
		case '*':
			return true;
		case '/':
			return true;
		case '^':
			return true;
		case '%':
			return true;
		default:
			return false;
	}

}

double operate(double left, double right, char op){
	switch(op){
		case '+':
			return left+right;
		case '-':
			return left-right;
		case '*':
			return left*right;
		case '/':
			return left/right;
		case '^':
			return pow(left,right);
		case '%':
			return fmod(left,right);
		default:
			return 0;
	}
}


int main(int argc, char *args[]){
	//Variables
	stack<double> values;
	string token_string;
	//Read in operation
	while(std::getline(std::cin, token_string)){
		//Convert to stream
		istringstream token_stream(token_string);
		string token;
		//Empty stack if not empty (should be empty)
		while(!values.empty()){values.pop();}
		//Read tokens into stack
		while(token_stream>>token){
			//If it's a number, push the number form onto the values stack
			if(is_number(token)){
				values.push(stod(token));
			}

			//Is this an operator
			else if(is_operator(token)){
				char c_op=to_op(token);
				//Is there enough to work with?
				if(values.size()<2){return -1;} //No, there isn't.
				//Operate on the values
				double right=values.top();values.pop();
				double left=values.top();values.pop();
				double product=operate(left, right, c_op);
				values.push(product);
			}

			else {cout<<"Invalid token received:"<<token<<endl; return -1;}

		}
		//Do we have only one value left?
		if(values.size()!=1) {cout<<"Too many/few values left on stack."<<endl;return -1;}
		//Print it out
		cout<<"Result:"<<values.top()<<endl;
	}
	return 0;
}

