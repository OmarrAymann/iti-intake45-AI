import os
import time
from tabulate import tabulate
from datetime import datetime
from register_login import *
from project_functions import *

def print_login():
    
    print("1) add project")
    print("2) view all projects")
    print("3) edit project")
    print("4) delete project")
    print("5) search date of project")
    print("6) Exit")

def main():
    while True:
        print_menu()
        try:
            option = int(input("Choose an option number: "))
        except ValueError:
            print("try again")
            time.sleep(2)
            os.system("cls")
            continue

        if option == 1:
            register()
        elif option == 2:
            login()
        elif option == 3:
            print("good bye <3")
            break
        else:
            print("try again.")
            time.sleep(2)
            os.system("cls")
        
def login_project():
    while True:
        print_login()
        try:
            option = int(input("Choose an option number: "))
        except ValueError:
            print("try again")
            time.sleep(2)
            os.system("cls")
            continue

        if option == 1:
            add_project()
        elif option == 2:
            view_all_projects()
        elif option == 3:
            edit_project()
        elif option == 4:
            delete_project()
        elif option == 5:
            search()
        elif option == 6:
            break
        else:
            print("try again.")
            time.sleep(2)
            os.system("cls")
        

if __name__ == "__main__":
    main()