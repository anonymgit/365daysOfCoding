'''
A common for compilers and text editors is determining whether the parantheses in a string is balanced and properly nested.
For example, the string '((()))()' contains properly nested pairs of parantheses, while the strings '())' and '(()' do not.
Give an algorithm that returns true if a string contains properly nested and balanced parantheses, and false if otherwise.
For a full credit, identify the position of the first offending parantheses if the string is not properly nested and balanced.

'''


class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
            self.items.append(item)

    def pop(self):
        return self.items.pop()

    def isEmpty(self):
        return self.items == []

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)
    
    def scan_the_string(self, string):
        for i in string:
            if i == '(':
                self.push(i)
            elif i == ')':
                if self.isEmpty():
                    return "It's an Invalid String"
                else:
                    self.pop()
        if self.isEmpty():
            return "It's a Valid String"
        else:
            return "It's an Invalid String"
        
if __name__ == "__main__":      
    s = Stack()
    string = input("Enter the string: ")
    print(s.scan_the_string(string))