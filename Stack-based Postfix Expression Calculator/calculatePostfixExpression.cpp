#include <string>
#include <stack>
#include <iostream>
using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string

// Function to evaluate given postfix expression

int calculatePostfixExpression(string expression[], int length)

{

// create an empty stack

stack<int> stack;

//Return 0 if expression is zero-length or if there are insufficient operands for an operation
if (length == 0)

return 0;

// traverse the given expression
for (int i = 0; i < length; i++) {

// if current string is an operand(number), push it to the stack
if (atoi(expression[i].c_str())) {

stack.push(stoi(expression[i]));

} // if current string is an operator
else {

// pop top two elements from the stack
int x = stack.top();

stack.pop();

int y = stack.top();

stack.pop();

// evaluate the expression x op y, and push the result back to the stack
if (expression[i] == "+")

stack.push(y + x);

else if (expression[i] == "-")

stack.push(y - x);

else if (expression[i] == "*")

stack.push(y * x);

else if (expression[i] == "/")

stack.push(y / x);

else if (expression[i] == "%")

stack.push(y % x);

}

}

/* After evaluation of the expression, the final result should be the only value
 on the stack, return 0 if the stack is non-empty after popping the result */ 

int result = stack.top();

stack.pop();

if(stack.empty())

return result;

else

return 0;

}
/* int main()

{

string expression[] = {"8", "5", "-"};

int len = sizeof(expression)/sizeof(expression[0]); //calculate length of expression

cout << calculatePostfixExpression(expression, len); //calling calculatePostfixExpression()

return 0;

}
*/ 
