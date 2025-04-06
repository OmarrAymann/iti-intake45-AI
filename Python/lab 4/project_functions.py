import os
import time
from tabulate import tabulate
from datetime import datetime
from register_login import *
from project import *

# def view_all_projects():  #view project of logged in email
#     global logged_in_email
#     os.system("cls")
#     user_data = load_user_data()
#     projects = user_data[logged_in_email].get("projects", [])

#     if not projects:
#         print("no project found")
#         time.sleep(2)
#         return
#     headers = ["title", "details", "start date", "end date"]
#     table = [
#         [project["title"], project["details"], project["start_date"], project["end_date"]]
#         for project in projects
#     ]
#     print(f"projects for {logged_in_email}: ")
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
    new_start_date = input("enter project start date (YYYY-MM-DD): ")
    new_end_date =input("enter project end date (YYYY-MM-DD): ")
    try:
        if new_start_date != project["start_date"]:
            time.strptime(new_start_date, "%Y-%m-%d")
        if new_end_date != project["end_date"]:
            time.strptime(new_end_date, "%Y-%m-%d")
    except ValueError:
        print("try again")
        time.sleep(2)
        os.system("cls")
        return

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