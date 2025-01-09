import os
import time

class Node:
    def __init__(self,id,name,position):
        self.data=(id,name,position)
        self.next=None
        self.prev=None
class Double_linkedlist:
    def __init__(self):
        self.head=None
        self.tail=None

    def add(self,id,name,position):
        nd=Node(id,name,position)
        # if the list is empty
        if (self.head==None):
            self.head=nd
            self.tail=nd
        else:
            self.tail.next=nd
            nd.prev=self.tail
            self.tail=nd
    
    def insert(self,loc,id,name,position):
        nd = Node(id, name, position)
        # if the list is empty
        if (self.head == None): 
            self.head = nd
            self.tail = nd
        # insert at the beginning of the list
        if(loc == 0): 
            nd.next = self.head
            self.head.prev = nd
            self.head = nd
        else: 
            i = 0
            current = self.head
            while (i < (loc - 1) and current != None):
                current = current.next
                i = i + 1
            if (current == self.tail or current == None):
                nd.prev = self.tail
                self.tail.next = nd
                self.tail = nd
            else:
                current.next.prev = nd
                nd.next = current.next
                current.next = nd
                nd.prev = current

    # delete a node at a specific location
    def delete(self, loc):
        deleted = False
        nd = None
        if (self.head != None):
            nd = self.head
            if(loc == 0):
                if (self.head == self.tail):
                    self.head = None
                    self.tail = None
                else:
                    self.head.prev = None
                    self.head = self.head.next
                deleted = True
            else:
                i = 0
                while (i < loc and nd != None):
                    nd = nd.next
                    i = i + 1
                if nd != None:
                    # if the node is the last node
                    if (nd == self.tail):
                        self.tail = self.tail.prev
                        self.tail.next = None
                    # if the node is in the middle
                    else:
                        nd.prev.next = nd.next
                        nd.next.prev = nd.prev
            deleted = True
        return deleted

    def delete_by_id(self,id):
        flag = False
        curr = self.head
        while curr != None:
            if curr.data[0] ==id:
                if curr == self.head:
                    self.head = curr.next
                    if self.head:
                        self.head.prev = None
                    else:
                        self.tail = None   
                elif curr == self.tail:
                    self.tail = curr.prev
                    self.tail.next = None
                else:
                    curr.prev.next = curr.next
                    curr.next.prev = curr.prev
                flag = True
                break
            curr = curr.next 
        return flag
    
    def update_by_id(self, id, new_id, new_name, new_position):
        cur = self.head
        while cur != None:
            if cur.data[0] == id:
                cur.data = (new_id, new_name, new_position)
                return True
            cur = cur.next
        return False



    def Display_all_emp(self):
        cur=self.head
        while(cur != None):
            print("ID:", cur.data[0], "Name:", cur.data[1], "Position:", cur.data[2])
            cur=cur.next  

    def delete_all(self):
        self.head=None
        self.tail=None

def menu():
    double_linkedlist = Double_linkedlist()
    while True:
        print(" 1) Add Employee")
        print(" 2) update data of employee")
        print(" 3) Delete a employee by id")
        print(" 4) update data of employee id")
        print(" 5) Display all employees")
        print(" 6) Delete all")
        print(" 7) Exit")

        choice = input(" Enter your choice : ")
        if choice == '1':
            os.system("cls")
            id = input("Enter employee id: ")
            if id.isdigit() == False:
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            name = input("Enter employee name: ")
            if name.isalpha() == False:
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            position = input("Enter employee position: ")
            if position.isalpha() == False:
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            double_linkedlist.add(id, name, position)
            os.system("cls")
            print("employee added successfully")
            time.sleep(2)
            os.system("cls")

        elif choice == '2':
            os.system("cls")
            cur=double_linkedlist.head
            print("All employees :")
            i=0
            while(cur != None):
                print(f"{i})ID:", cur.data[0], ", Name:", cur.data[1], ", Position:", cur.data[2])
                cur=cur.next 
                i=i+1
            loc = int(input("Enter position to insert: "))
            if (loc < 0 and loc.isdigit() == False):
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            id = input("Enter employee id: ")
            if id.isdigit() == False:
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            name = input("Enter employee name: ")
            if name.isalpha() == False:
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            position = input("Enter employee position: ")
            if position.isalpha() == False:
                os.system("cls")
                print("please try again")
                time.sleep(2)
                os.system("cls")
                continue

            current = double_linkedlist.head
            i = 0
            while (current != None and i < loc):
                current = current.next
                i += 1
            if current == None:
                print(f"No employee found at position {loc}.")
            else:
                double_linkedlist.delete(loc)
                print("Existing employee data deleted.")
                double_linkedlist.insert(loc, id, name, position)
                print("employee data updated ")
            time.sleep(2)
            os.system("cls")

        elif choice == '3':
            os.system("cls")
            id = input("Enter employee ID to delete: ")
            if double_linkedlist.delete_by_id(id):
                os.system("cls")
                print("employee deleted ")
                time.sleep(2)
                os.system("cls")
            else:
                os.system("cls")
                print("employee id not found")
                time.sleep(2)
                os.system("cls")  

        elif choice == '4':
            os.system("cls")
            id = input("Enter employee ID to update: ")
            new_id = input("Enter new employee ID: ")
            new_name = input("Enter new employee name: ")
            new_position = input("Enter new employee position: ")
            if double_linkedlist.update_by_id(id, new_id,new_name,new_position) == True:
                os.system("cls")
                print("employee data updated ")
                time.sleep(2)
                os.system("cls")
            else:
                os.system("cls")
                print("employee id not found")
                time.sleep(2)
                os.system("cls")

        elif choice == '5':
            os.system("cls")
            print(" All employees :")
            double_linkedlist.Display_all_emp()
            time.sleep(2)
            os.system("cls")

        elif choice == '6':
            double_linkedlist.delete_all()
            os.system("cls")
            print("all employees deleted")
            time.sleep(2)
            os.system("cls")

        elif choice == '7':
            os.system("cls")
            print("goodbye")
            time.sleep(2)
            os.system("cls")
            break
        else:
            print("try again")
            time.sleep(2)
            os.system("cls")



menu()