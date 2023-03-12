/**
 
A common for compilers and text editors is determining whether the parantheses in a string is balanced and properly nested.
For example, the string '((()))()' contains properly nested pairs of parantheses, while the strings '())' and '(()' do not.
Give an algorithm that returns true if a string contains properly nested and balanced parantheses, and false if otherwise.
For a full credit, identify the position of the first offending parantheses if the string is not properly nested and balanced.
  
*/

#include <iostream>
using namespace std;

class Stack 
{
    public:
        int top;
        int size;
        char *stack;
        Stack(int size) {
            this->size = size;
            top = -1;
            stack = new char[size];
        }
        void push(char data) {
            if (top == size - 1) {
                cout << "Stack Overflow" << endl;
                return;
            }
            stack[++top] = data;
        }
        char pop() {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return stack[top--];
        }
        char peek() {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return stack[top];
        }
        bool isEmpty() {
            return top == -1;
        }
        bool isFull() {
            return top == size - 1;
        }
};

int main() 
{
    

}