/*
 * Name: Harrison Holt 
 * Date Submitted: 2-6-23 
 * Lab Section: 005 
 * Assignment Name: Lab 2 
 */

#include <string>
#include <stack>
#include <iostream>
using namespace std; 
int p(char character) {
    if (character == '*' || character == '/' || character == '%')
                return 2;
        else if (character == '+' || character == '-')
                return 1;
        else
                return -1;
}

bool valid(string infix[], int length)
{
        stack<string> userStack;
        string c;

        for (int i = 0; i < length; i++) {

                if (infix[i][0] == '(') {

                        // Push the element in the stack
                        userStack.push(infix[i]);
                        continue;
                }

                switch (infix[i][0]) {

                case ')':
                        if (userStack.empty())
                        {
                                return 0;
                        }
                        c = userStack.top();
                        userStack.pop(); // pop one bracket
                        break;

                default:
                        break;
                }
        }
        // if stack is not empty then return false
        return (userStack.empty()); 
}

int infixToPostfix(string infix[], int length, string postfix[])
{
        int count = 0;
        if (!valid(infix,length)) {
                return 0;
        }

        std::stack<string> userStack;

        userStack.push("P");

        for (int i = 0; i < length; i++) {
                // if string is a number then add it directly to the postfix expression
                if(isdigit(infix[i][0]))
                        postfix[count++] = infix[i];

                // If the character is an ‘(‘, put it to the stack. 
                else if (infix[i][0] == '(') {
                        userStack.push(infix[i]);
        }
                else if (infix[i][0] == ')') {
                        while (userStack.top()[0] != 'P' && userStack.top()[0] != '(') {
                                string  c = userStack.top();
                                userStack.pop();
                                postfix[count++] = c;
                        }
                        if (userStack.top()[0] == '(')
                        {
                                userStack.pop();
                        }
                } 
                else {

while (userStack.top()[0] != 'P' && p(infix[i][0]) <= p(userStack.top()[0])) {
                                string c = userStack.top();
                                userStack.pop();
                                postfix[count++] = c;
                        }
                        userStack.push(infix[i]);
                }

        }
        //Pop all the remaining elements from the stack 
        while (userStack.top()[0] != 'P') {
                string c = userStack.top();

                userStack.pop();
                postfix[count++] = c;
        }

        return count;
}
/* int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
                         "5", "-", "6", "+", "7", ")", "*",
                         "8"};
    string postfixExp[15];
    int postfixLength;

    cout << "Infix expression: ";
    for (int i=0; i<15; i++)
    {
        cout << infixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: 15" << endl << endl;

    postfixLength = infixToPostfix(infixExp, 15, postfixExp);

    cout << "Postfix expression: ";
    for (int i=0; i<postfixLength; i++)
    {
        cout << postfixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: " << postfixLength << endl;
    
    return 0;
}
*/ 
