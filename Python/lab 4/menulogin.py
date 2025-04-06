import os
import time
from testlogin import *

def print_menu():
    os.system("cls")
    print("1) Register")
    print("2) Login")
    print("3) Exit")

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

if __name__ == "__main__":
    main()