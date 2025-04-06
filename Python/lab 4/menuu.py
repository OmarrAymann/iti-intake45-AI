import os
import json
import re
import time

userdata = "menu.json"

def user_data():
    with open(userdata, "w") as file:
        json.dump({}, file)
    with open(userdata, "r") as file:
        return json.load(file)

def savedata(data):
    with open(userdata, "w") as file:
        json.dump(data, file, indent=4)

def vemail(email):
    x = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    if re.match(x, email):
        return True
    else:
        return False

def vpassword(password, confirm_password):
    if len(password) < 8:
        print("Password must be at least 8 characters")
        return False
    if not re.search(r'[A-Z]', password):
        print("Password must contain at least one uppercase letter.")
        return False
    if not re.search(r'[a-z]', password):
        print("Password must contain at least one lowercase letter.")
        return False
    if not re.search(r'[0-9]', password):
        print("Password must contain at least one number.")
        return False
    if not re.search(r'[!@#$%^&*(),.?":{}|<>]', password):
        print("Password must contain at least one special character.")
        return False
    if password != confirm_password:
        print("wrong password ,please try again")
        return False
    return True

def register():
    os.system("cls")
    first_name = input("please enter your first name: ")
    last_name = input("last name: ")
    email = input("Email: ")
    while True:
        email = input("Email: ")
        if vemail(email):
            break
        print("try again.")
    
    password = input("Password: ")
    confirm_password = input("Confirm Password: ")
    if not vpassword(password, confirm_password):
        return
    
    z = r"^01[0-25][0-9]{8}$"
    mobile_phone = input("number : ")
    if not re.match(z, mobile_phone):
        print("try again")
        return
    user_data = userdata()
    user_data[email] = {
        "first_name": first_name,
        "last_name": last_name,
        "password": password,
        "mobile_phone": mobile_phone,
    }
    savedata(user_data)
    print("user added")

def login():
    os.system("cls")
    print("login : ")
    email = input("Email: ")
    password = input("Password: ")
    user_data = userdata()
    if email in user_data and user_data[email]["password"] == password:
        print(f"Login successful\n,{user_data[email]['first_name']}")
    else:
        print("invalid")

def print_menu():
    
    print("1) Register")
    print("2) Login")
    print("3) Exit")


def main():
    while True:
        print_menu()
        try:
            option = int(input("welcome\nplease choose your option number : "))
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
            print("Good bye <3")
            break
        else:
            print("try again")
            time.sleep(2)
            os.system("cls")

if __name__ == "__main__":
    main()
