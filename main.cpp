/*
 * Still Lame CS2-level Calculator
 */
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>

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

char to_op(const string& op){
	return op.c_str()[0];
}


bool is_operator(const string& op){
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

double operate(const double left, const double right, const char op){
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

//Processing function
void process_input(string token_string){
	//Inner variables
	string token;
	stack<double> values;
	//Convert to stream
	istringstream token_stream(token_string);
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
			if(values.size()<2){throw range_error("Not enough data on stack for operator:" + c_op);} //No, there isn't.
			//Grab values from stack, then operate on them
			double right=values.top();values.pop();
			double left=values.top();values.pop();
			double product=operate(left, right, c_op);
			values.push(product);
		}
		
		//Neither/nor. I can't work with this.
		else {
			string what_went_wrong("Invalid token received:");
			what_went_wrong+=token;
			throw domain_error(what_went_wrong);
			}
	}

	//Do we have only one value left?
	if(values.size()!=1) {throw range_error("Too many/few values left on stack.");}
	//Print it out
	cout<<"Result:"<<values.top()<<endl;
	//Pop last value from stack		
	values.pop();
}


int main(int argc, char *args[]){
	//Variables
	string token_string;
	//Read in operation
	while(std::getline(std::cin, token_string)){
		if(token_string.length()==0){break;}
		process_input(token_string);
	}
	return 0;
}

