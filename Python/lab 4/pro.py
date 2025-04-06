import os
import json
import re
import time
from tabulate import tabulate
from datetime import datetime

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
    global logged_in_email
    email = input("Email: ")
    password = input("Password: ")
    user_data = load_user_data()
    if email in user_data and user_data[email]["password"] == password:
        logged_in_email = email
        os.system("cls")
        print(f"hello :{user_data[email]['first_name']}")
        login_project()
    else:
        print("try again.")
        time.sleep(3)
        os.system("cls")

def print_menu():
    os.system("cls")
    print("1) Register")
    print("2) Login")
    print("3) Exit")

# def view_all_projects():
#     global logged_in_email
#     os.system("cls")
#     user_data = load_user_data()
#     projects = user_data[logged_in_email].get("projects", [])

#     if not projects:
#         print(f"No projects found for {logged_in_email}.")
#         time.sleep(2)
#         return
#     headers = ["Title", "Description", "Start Date", "End Date"]
#     table = [
#         [project["title"], project["description"], project["start_date"], project["end_date"]]
#         for project in projects
#     ]
#     print(f"Projects for {logged_in_email}: ")
#     print(tabulate(table, headers=headers, tablefmt="grid"))
#     time.sleep(10)

def view_all_projects():
    os.system("cls")
    user_data = load_user_data()
    all_projects = []
    for email, details in user_data.items():
        projects = details.get("projects", [])
        for project in projects:
            all_projects.append([
                email,
                project["title"],
                project["details"],
                project["start_date"],
                project["end_date"],
            ])
    if not all_projects:
        print("no project found")
        time.sleep(2)
        return
    
    headers = ["email", "title", "details", "start date", "end date"]
    print(tabulate(all_projects, headers=headers, tablefmt="grid"))
    time.sleep(4)

def edit_project():
    global logged_in_email
    os.system("cls")
    user_data = load_user_data()
    projects = user_data[logged_in_email].get("projects", [])
    if not projects:
        print("no project found")
        time.sleep(2)
        return

    headers = ["project number", "title", "details", "start date", "end date"]
    table = [
        [num + 1, project["title"], project["details"], project["start_date"], project["end_date"]]
        for num, project in enumerate(projects)
    ]
    print(tabulate(table, headers=headers, tablefmt="grid"))

    try:
        project_num = input("select your project number : ") 
        if (project_num.isdigit()):
            project_num = int(project_num) - 1
        else:
            print("try again")
        if (project_num < 0 or project_num >= len(projects)):
            print("try again")
            time.sleep(2)
            os.system("cls")
            return
    except ValueError:
        print("try again")
        time.sleep(2)
        os.system("cls")
        return

    project = projects[project_num]
    new_title = input("enter project title : ")
    new_details =input("enter project details : ")
    while True:
        try:
            new_start_date = input("enter project start date (YYYY-MM-DD): ")
            new_end_date = input("enter project end date (YYYY-MM-DD): ")
            start = datetime.strptime(new_start_date, "%Y-%m-%d")
            end= datetime.strptime(new_end_date, "%Y-%m-%d")
            if (start > end):
                print("start date cannot be after end date")
            else:
                break
        except ValueError:
            print("try again")

    project["title"] = new_title
    project["details"] = new_details
    project["start_date"] = new_start_date
    project["end_date"] = new_end_date

    user_data[logged_in_email]["projects"][project_num] = project
    save_user_data(user_data)
    print("project updated")
    time.sleep(2)
    os.system("cls")


def delete_project():
    global logged_in_email
    os.system("cls")
    user_data = load_user_data()
    projects = user_data[logged_in_email].get("projects", [])
    if not projects:
        print("no project found")
        time.sleep(2)
        return

    headers = ["project number", "title", "details", "start date", "end date"]
    table = [
        [num + 1, project["title"], project["details"], project["start_date"], project["end_date"]]
        for num, project in enumerate(projects)
    ]
    print(tabulate(table, headers=headers, tablefmt="grid"))

    try:
        project_num = input("select your project number : ") 
        if (project_num.isdigit()):
            project_num = int(project_num) - 1
        else:
            print("try again")
        if (project_num < 0 or project_num >= len(projects)):
            print("try again")
            time.sleep(2)
            os.system("cls")
            return
    except ValueError:
        print("try again")
        time.sleep(2)
        os.system("cls")
        return
    
    del projects[project_num]
    user_data[logged_in_email]["projects"] = projects
    save_user_data(user_data)
    print("project deleted")
    time.sleep(2)
    os.system("cls")
    headers = ["project number", "title", "details", "start date", "end date"]
    table = [
        [num + 1, project["title"], project["details"], project["start_date"], project["end_date"]]
        for num, project in enumerate(projects)
    ]
    print(tabulate(table, headers=headers, tablefmt="grid"))
    time.sleep(2)
    os.system("cls")

def search():
    global logged_in_email
    os.system("cls")
    user_data = load_user_data()
    projects = user_data[logged_in_email].get("projects", [])

    if not projects:
        print("no project found")
        time.sleep(2)
        return

    try:
        start_date_input = input("enter project start date (YYYY-MM-DD): ")
        end_date_input = input("enter project start date (YYYY-MM-DD): ")
        start_date = datetime.strptime(start_date_input, "%Y-%m-%d")
        end_date = datetime.strptime(end_date_input, "%Y-%m-%d")
    except ValueError:
        print("try again")
        time.sleep(2)
        return

    search_projects = [
        project for project in projects
        if (start_date <= datetime.strptime(project["start_date"], "%Y-%m-%d") <= end_date)
    ]

    if (not search_projects):
        print("no project found")
        time.sleep(2)
        return

    headers = ["project number", "title", "details", "start date", "end date",]
    table = [
        [num + 1, project["title"], project["details"], project["start_date"], project["end_date"]]
        for num, project in enumerate(search_projects)
    ]
    print(tabulate(table, headers=headers, tablefmt="grid"))
    time.sleep(2)

def add_project():
    global logged_in_email
    os.system("cls")
    user_data = load_user_data()
    title = input("enter project title : ")
    details = input("enter project details : ")
    while True:
        try:
            start_date = input("enter project start date (YYYY-MM-DD): ")
            end_date = input("enter project end date (YYYY-MM-DD): ")
            start = datetime.strptime(start_date, "%Y-%m-%d")
            end= datetime.strptime(end_date, "%Y-%m-%d")
            if (start > end):
                print("start date cannot be after end date")
            else:
                break
        except ValueError:
            print("try again")

    project_data = {
        "title": title,
        "details": details,
        "start_date": start_date,
        "end_date": end_date,
    }
    user_data[logged_in_email]["projects"] = []
    user_data[logged_in_email]["projects"].append(project_data)
    save_user_data(user_data)
    print("project added")
    time.sleep(2)
    os.system("cls")

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