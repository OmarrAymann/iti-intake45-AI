import os
import time
class Node:
    def __init__(self,data):
        self.data=data
        self.prev=None

class Stack:
    def __init__(self,size=2):
        self.arr =[]
        self.tos = 0
        self.size = size
        
    def push(self,data):
        pushed = False
        if self.tos < self.size:
            self.arr.append(data)
            self.tos += 1
            os.system("cls")
            print("Node pushed into the stack")
            time.sleep(2)
            os.system("cls")
            pushed = True
        else:
            os.system("cls")
            print("Stack is full")
            time.sleep(2)
            os.system("cls")
        return pushed
    def pop(self):
        #assume data is positive integer only
        popped = -1
        if self.tos > 0:
            popped = self.arr.pop()
            self.tos =self.tos - 1
        return popped
def menu():
    stack = Stack()
    while True:
        print("1) Push")
        print("2) Pop")
        print("3) Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            os.system("cls")
            data = input(" Enter data : ")
            if data.isdigit() == False:
                os.system("cls")
                print("Invalid data")
                time.sleep(2)
                os.system("cls")
            else:
                os.system("cls")
                stack.push(data)

        elif choice == '2':
            pop_node = stack.pop()
            os.system("cls")
            if (pop_node != -1):
                print("Data:", pop_node)
            else:
                print("Stack is empty")
            time.sleep(2)
            os.system("cls")

        elif choice == '3':
            break
        else:
            os.system("cls")
            print("try again")
            time.sleep(2)
            os.system("cls")

menu()