import os
import time

class Node:
    def __init__(self,id,name,position):
        self.data=(id,name,position)
        self.next=None
        self.prev=None

class Queue:
    def __init__(self,size=5):
        self.head=None 
        self.tail=None
        self.size =size
        self.counter=0


    def enqueue(self, id, name, position):
        if (self.counter == self.size):
            os.system("cls")
            print("Queue is full")
            time.sleep(2)
            os.system("cls")
        else:
            nd = Node(id, name, position)
            if self.head == None:
                self.head = nd
                self.tail = nd
            else:
                self.tail.next = nd
                nd.prev = self.tail
                self.tail = nd

            self.counter += 1
            os.system("cls")
            print(f"{self.counter}) Employee is added successfully")
            print("ID:", id, ", Name:", name, ", Position:", position)
            time.sleep(2)
            os.system("cls")

    def dequeue(self):
        if self.head == None:
            os.system("cls")
            print("Queue is empty")
            time.sleep(2)
            os.system("cls")
            return None
        nd = self.head
        self.head = nd.next
        if (self.head == None):
            self.tail = None
        self.counter = self.counter - 1
        return nd.data

    def display_all(self):
        cur = self.head
        if (self.counter == 0):
            os.system("cls")
            print("Queue is empty")
            time.sleep(2)
            os.system("cls")
        else:
            os.system("cls")
            print("Employees in the queue: \n")
            while cur:
                id, name, position = cur.data
                print("ID:", id, ", Name:", name, ", Position:", position)
                cur = cur.next
            time.sleep(2)
            os.system("cls")


    def delete_queue(self):
        self.head = None
        self.tail = None
        self.size = 0
        os.system("cls")
        print(" Queue empty ")
        time.sleep(2)   
        os.system("cls")

def menu():
    queue = Queue()
    while True:
        print("1) Enqueue")
        print("2) Dequeue")
        print("3) Display all employees")
        print("4) delete the queue")
        print("5) Exit")
        choice = input(" Enter your choice : ")
        if choice == "1":
            os.system("cls")
            id = input(" Enter id : ")
            if  id.isdigit() == False:
                os.system("cls")
                print(" Please enter numbers only")
                time.sleep(1)
                os.system("cls")
                continue

            name = input("Enter employee name: ")
            if name.isalpha() == False:
                os.system("cls")
                print("Please enter a valid name")
                time.sleep(2)
                os.system("cls")
                continue
            
            position = input("Enter employee position: ")
            if position.isalpha() == False:
                os.system("cls")
                print("Please enter a valid position")
                time.sleep(2)
                os.system("cls")
                continue
            queue.enqueue(id, name, position)
            os.system("cls")


        elif choice == "2":
            employee = queue.dequeue()
            if employee:
                os.system("cls")
                print("Employee ID:", employee[0], "Name:", employee[1] , "Position:", employee[2])
                time.sleep(2)
                os.system("cls")

        elif choice == "3":
            queue.display_all()

        elif choice == "4":
            queue.delete_queue()
        
        elif choice == "5":
            os.system("cls")
            print("Goodbye")
            time.sleep(2)
            os.system("cls")
            break

        else:
            print("\n Try again")
            time.sleep(2)
            os.system("cls")

menu()