import os
import json
import re
import time

def vname(name):
    return name.isalpha()

def vemail(email):
    x = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    if(re.match(x, email)):
        return True
    else:
        return False

def vpassword(password, confirm_password):
    if len(password) < 8:
        print("Password must be at least 8 characters")
        return False
    if not re.search(r'[A-Z]', password):
        print("Password must contain at least one uppercase letter")
        return False
    if not re.search(r'[a-z]', password):
        print("Password must contain at least one lowercase letter")
        return False
    if not re.search(r'[0-9]', password):
        print("Password must contain at least one number")
        return False
    if not re.search(r'[!@#$%^&*(),.?\":{}|<>]', password):
        print("Password must contain at least one special character")
        return False
    if password != confirm_password:
        print("wrong password")
        return False
    return True

userdata_file = "menu.json"

def load_user_data():
    if not os.path.exists(userdata_file):
        with open(userdata_file, "w") as file:
            json.dump({}, file)
    try:
        with open(userdata_file, "r") as file:
            return json.load(file)
    except json.JSONDecodeError:
        return {}

def save_user_data(data):
    with open(userdata_file, "w") as file:
        json.dump(data, file, indent=4)

def register():
    os.system("cls")
    while True:
        first_name = input("Please enter your first name: ")
        if (vname(first_name)):
            break
        else:
            print("try again")

    while True:
        last_name = input("last name: ")
        if (vname(last_name)):
            break
        else:
            print("try again")

    while True:
        email = input("Email: ")
        if vemail(email):
            break
        else:
            print("try again")

    while True:
        password = input("Password: ")
        confirm_password = input("Confirm Password: ")
        if vpassword(password, confirm_password):
            break
        else:
            print("try again")

    z = r"^01[0-25][0-9]{8}$"
    while True:
        mobile_phone = input("number : ")
        if re.match(z, mobile_phone):
            break
        else:
            print("try again.")

    user_data = load_user_data()

    if email in user_data:
        print("email already login")
    else:
        user_data[email] = {
            "first_name": first_name,
            "last_name": last_name,
            "password": password,
            "mobile_phone": mobile_phone,
        }
        save_user_data(user_data)
        print("user added")
        time.sleep(2)
        os.system("cls")

def login():
    os.system("cls")
    email = input("Email: ")
    password = input("Password: ")
    user_data = load_user_data()
    if email in user_data and user_data[email]["password"] == password:
        os.system("cls")
        print(" Hello ")
        time.sleep(5)
    else:
        os.system("cls")
        print("try again.")