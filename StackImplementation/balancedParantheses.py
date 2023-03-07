'''
A common for compilers and text editors is determining whether the parantheses in a string is balanced and properly nested.
For example, the string '((()))()' contains properly nested pairs of parantheses, while the strings '())' and '(()' do not.
Give an algorithm that returns true if a string contains properly nested and balanced parantheses, and false if otherwise.
For a full credit, identify the position of the first offending parantheses if the string is not properly nested and balanced.

'''


class Stack:
    def __init__(self):
        # Initialize the stack with an empty list
        self.items = []                     

    def push(self, item):
            # Function to push an item to the top of the stack
            self.items.append(item)

    def pop(self):
        # Function to pop an item to the top of the stack
        return self.items.pop()

    def isEmpty(self):
        # Function to check if the stack is empty
        return self.items == []
    
    # Method to scan the string for balanced parentheses
    def scan_the_string(self, string):
        # Iterate over each character in the string
        for i in string:
            # If the character is an opening parenthesis, push it onto the stack
            if i == '(':
                self.push(i)
                # If the character is a closing parenthesis, pop the stack and check if the popped item matches an opening parenthesis
            elif i == ')':
                # If the stack is empty, the string is invalid
                if self.isEmpty():
                    return "It's an Invalid String"
                else:
                    # Otherwise, remove the top item from the stack
                    self.pop()
        # If the stack is empty after scanning the entire string, the string is valid
        if self.isEmpty():
            return "It's a Valid String"
        # Otherwise, the string is invalid
        else:
            return "It's an Invalid String"
        
# Main block of code that creates an instance of the Stack class and scans a string for balanced parentheses      
if __name__ == "__main__":   
    # Create an instance of the Stack class   
    s = Stack()
    # Prompt the user to enter a string
    string = input("Enter the string: ")
    # Scan the string for balanced parentheses using the scan_the_string method of the Stack class and print the result
    print(s.scan_the_string(string))