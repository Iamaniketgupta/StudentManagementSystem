/*
  ------------------------  ERP STUDENT MANAGEMENT SYSTEM --------------------
  MADE BY: ANIKET GUPTA & BRIJESH KUMAR
  Roll Number :2229981 & 22CSE115
  SUBMITTED TO: MS NISHA ARORA

  TECHNOLOGY USED: C++, VsCode, File Handling, Object Oriented Programming

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
using namespace std;

// parent class
class Person
{
public:
    void entryPanel();
    void viewTimeTable();
};

// student Class
class Student : public Person
{
private:
    string pass;
    
    void studentPanel();
    void performanceReport();
    void timeTable();
    void showProfile();
    void showMyRecord();
    void viewAttendance();

public:
    string name;
    string id;
    void studentLogin();
};

// Student panel function
void Student::studentPanel()
{
    cout << "\t\t\t========================-- STUDENT PANEL --==========================\n";
    cout << "\t\t\t\t\t\tWelcome " << name << endl;
    cout << "\t\t\t=====================================================================\n";
    cout << "\t\t\t 1. MY PROFILE\n";
    cout << "\t\t\t 2. PERFORMANCE REPORT\n";
    cout << "\t\t\t 3. ATTENDANCE REPORT\n";
    cout << "\t\t\t 4. TIME TABLE\n";
    cout << "\t\t\t 5. LOGOUT\n";
    cout << "\t\t\t 6. EXIT\n";

    cout << "\t\t\t Enter Option Number : ";
    char ch;
    cin >> ch;

    switch (ch)
    {
    case '1':
        system("cls");
        showMyRecord();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        studentPanel();
        break;

    case '2':
        system("cls");
        performanceReport();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        studentPanel();
        break;

    case '3':
        system("cls");
        viewAttendance();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        studentPanel();
        break;
    case '4':
        system("cls");
        viewTimeTable();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        studentPanel();
        break;
    case '5':

         system("cls");
        cout << "\t\t\t\n\n\nLOGGING OUT.";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        system("cls");
        entryPanel();
        break;
    case '6':
        cout << "\t\t\t\n\n\nEXITING.";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        exit(0);
        break;
    }
}

void Student::viewAttendance()
{
    ifstream attendanceFile("attendance.txt");

    if (!attendanceFile.is_open())
    {
        cout << "Failed to open the attendance file." << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(attendanceFile, line))
    {
        if (line.find("Roll No.: " + id) != string::npos)
        {
            found = true;
            cout << "Attendance details for Roll No. " << id << ":\n\n"
                 << line << endl;

            while (getline(attendanceFile, line) && line != "=============================")
            {
                cout << line << endl;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "No attendance record found for Roll No. " << id << endl;
    }

    attendanceFile.close();
}

void Student::showMyRecord()
{
    ifstream read("studentsRecord.txt");

    if (!read.is_open())
    {
        cout << "Failed to open the students record file." << endl;
        return;
    }

    bool found = false;
    string line;

    while (getline(read, line))
    {
        if (line.find("Roll No. :" + id) != string::npos)
        {
            found = true;
            cout << "Student record for Roll No. " << id << ":\n\n"
                 << line << endl;

            while (getline(read, line) && line != "============================================")
            {
                cout << line << endl;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "No record found for Roll No. " << id << endl;
    }

    read.close();
    system("pause");
    system("cls");
    studentPanel();
}

void Student::performanceReport()
{
    ifstream marksFile("exam_marks.txt");

    if (!marksFile.is_open())
    {
        cout << "Failed to open the exam marks file." << endl;
        return;
    }

    bool found = false;
    string line;

    while (getline(marksFile, line))
    {
        if (line.find("Roll No.: " + id) != string::npos)
        {
            found = true;
            cout << "Performance report for Roll No. " << id << ":\n\n"
                 << line << endl;

            while (getline(marksFile, line) && line != "=============================================================================")
            {
                cout << line << endl;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "No performance report found for Roll No. " << id << endl;
    }

    marksFile.close();
    system("pause");
    system("cls");
    studentPanel();
}

void Student::studentLogin()
{
    cout << "\t\t\t========================-- STUDENT LOGIN --==========================\n";

    cout << "\t\t\t  ENTER NAME : ";
    cin.ignore();
    getline(cin, name);

    cout << "\t\t\t  ENTER ROLL NUMBER : ";
    getline(cin, id);

    cout << "\t\t\t  ENTER PASSWORD : ";
    cin >> pass;

    // Open the registered users file for reading
    ifstream read("registeredUsers.txt");
    bool loggedIn = false;

    if (!read.is_open())
    {
        // Handling the error
        cout << "Failed to open the file." << endl;
        return;
    }

    string line;
    string Sdname, tempId, Sdpass;

    while (getline(read, line))
    {
        if (line.find("Name :") != string::npos)
        {
            Sdname = line.substr(6);
        }
        else if (line.find("Roll Number :") != string::npos)
        {
            tempId = line.substr(13);
        }
        else if (line.find("Password :") != string::npos)
        {
            Sdpass = line.substr(10);

            // Checking values
            if (Sdname == name && tempId == id && Sdpass == pass)
            {
                loggedIn = true;
                break;
            }
        }
    }

    read.close();

    if (loggedIn)
    {
        cout << "\t\t\t\nLogin Successful!\n\n"
             << endl;
        cout << "\nRedirecting TO DASHBOARD.";

        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        system("cls");
        studentPanel();
    }
    else
    {
        system("cls");
        cout << "\t\t\t\nLogin Failed. Invalid credentials." << endl;
        entryPanel();
    }
}

// Admin Class
class Admin : public Person
{
private:
    string pass;
    string name;

    void adminPanel();
    void updateAdmin();
    void uploadTimeTable();
    void uploadExamMarks();
    void StudentRecords();
    void searchRecord();
    void addStudent();
    void markAttendance();

public:
    void adminLogin();
};

void Admin::markAttendance()
{
    string stuId;
    cout << "Enter the student's Roll No.: ";
    cin >> stuId;

    cout << "Mark attendance for OOPS (P for present, A for absent): ";
    char at;
    cin >> at;

    ofstream attendanceFile("attendance.txt");

    if (!attendanceFile.is_open())
    {
        cout << "Failed to open the attendance file." << endl;
        return;
    }

    attendanceFile << "Roll No.: " << stuId << "\t OOPS Attendance: " << (at == 'P' || at == 'p' ? 1 : 0)
                   << "\t Total Classes: 1\n=============================\n";

    attendanceFile.close();

    cout << "Attendance marked for student with Roll No. " << stuId << endl;
    cout << "Want to mark more ? (Y/N)";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        markAttendance();
    }
    system("pause");
    system("cls");
    adminPanel();
}

void Admin::uploadExamMarks()
{
    ofstream marksFile("exam_marks.txt", ios::app);

    if (!marksFile.is_open())
    {
        cout << "Failed to open the exam marks file." << endl;
        return;
    }

    string rollNumber;
    cout << "Enter the roll number of the student: ";
    cin >> rollNumber;

    double oops, maths, dsa, dos, de;

    cout << "Enter marks for OOPS: ";
    cin >> oops;

    cout << "Enter marks for MATHS: ";
    cin >> maths;

    cout << "Enter marks for DSA: ";
    cin >> dsa;

    cout << "Enter marks for DOS: ";
    cin >> dos;

    cout << "Enter marks for DE: ";
    cin >> de;

    marksFile << "Roll No.: " << rollNumber << "\t OOPS: " << oops << "\t MATHS: " << maths
              << "\t DSA: " << dsa << "\t DOS: " << dos << "\t DE: " << de
              << "\n=============================================================================\n";

    cout << "Exam marks uploaded successfully."
         << endl;

    marksFile.close();
    cout << "Wanna Add More ? (y/n) : ";
    char op;
    cin >> op;
    if (op == 'y' || op == 'Y')
    {
        uploadExamMarks();
    }
}

void Admin::uploadTimeTable()
{
    cout << "\n\n\n\t\t\t===========--- Upload Time Table ---===================\n";

    ofstream timetableFile("timetable.txt", ios::app);

    if (!timetableFile.is_open())
    {
        cout << "Failed to open the timetable file." << endl;
        return;
    }

    string course, day, time;
    cout << "\t\t\t Enter Course: ";
    cin.ignore();
    getline(cin, course);

    cout << "\t\t\t Enter Day: ";
    getline(cin, day);

    cout << "\t\t\t Enter Time: ";
    getline(cin, time);

    timetableFile << "Course: " << course << "\t Day: " << day << "\t Time: " << time << endl;

    timetableFile.close();

    cout << "\n\n Time Table uploaded successfully." << endl;
}

void Person::viewTimeTable()
{
    cout << "\n\n\n\t\t\t===========--- View Time Table ---===================\n";

    ifstream timetableFile("timetable.txt");

    if (!timetableFile.is_open())
    {
        cout << "Failed to open the timetable file." << endl;
    }

    string line;
    while (getline(timetableFile, line))
    {
        cout << line << endl;
    }

    timetableFile.close();
}

void Admin::searchRecord()
{
    ifstream read("studentsRecord.txt");
    if (read.is_open())
    {
        string searchRoll;
        bool found = false;

        cout << "Enter the Roll No. of the student to search for: ";
        cin.ignore();
        getline(cin, searchRoll);

        string line;
        string record;
        bool inRecord = false;

        while (getline(read, line))
        {
            if (line.find("Roll No. :" + searchRoll) != string::npos)
            {
                inRecord = true;
                record = line;
            }
            else if (inRecord)
            {
                record += "\n" + line;
                if (line == "============================================")
                {
                    cout << "\nFound record:\n\n"
                         << record << endl;
                    found = true;
                    inRecord = false;
                }
            }
        }

        if (!found)
        {
            cout << "No record found for " << searchRoll << endl;
        }

        read.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
}

void Admin::addStudent()
{

    cout << "\n\n\n\t\t\t===========--- Add Students Record ---===================\n\n";
    // opening in append mode
    ofstream write("studentsRecord.txt", ios::app);
    Admin user;
    if (write.is_open())
    {
        string name, roll, dob, gend, contact, address;
        cout << "\t\t\t Roll Number : ";
        cin.ignore();
        getline(cin, roll);

        cout << "\t\t\t Name : ";
        getline(cin, name);

        cout << "\t\t\t Date Of Birth in (dd/mm/yy) : ";
        getline(cin, dob);

        cout << "\t\t\t Gender : ";

        getline(cin, gend);
        cout << "\t\t\t Contact : ";

        getline(cin, contact);

        cout << "\t\t\t Address : ";
        getline(cin, address);

        write << "Roll No. :" << roll << endl;
        write << "Name :" << name << endl;
        write << "DOB :" << dob << endl;
        write << "Gender :" << gend << endl;
        write << "Contact :" << contact << endl;
        write << "Address :" << address << endl;
        write << "============================================\n";

        cout << "SUCCESSFULLY ADDED...";
        write.close();
        cout << "Wanna Add More ? (y/n) : ";
        char op;
        cin >> op;
        if (op == 'y' || op == 'Y')
        {
            addStudent();
        }
    }
    else
    {
        cout << "\n\n FAILED TO ACCESS THE DATABASE";
        system("pause");
    }
}

void Admin::StudentRecords()

{

    ifstream read("studentsRecord.txt");
    if (read.is_open())
    {
        string line;
        while (getline(read, line))
        {
            cout << line << endl;
        }
        read.close();
    }
    else
    {
        cout << "Failed to open..";
        return;
    }
}

void Admin ::updateAdmin()
{
    string name2;
    string pass2;
    ofstream write("Admin.txt");

    cout << "\n\n\t\t\tNew Name : ";
    cin.ignore();
    getline(cin, name2);

    cout << "\n\n\t\t\tNew Password : ";

    getline(cin, pass2);

    system("pause");
    if (!write.is_open())
    {
        // Handling the error
        cout << "Failed to open the file." << endl;
        return;
    }

    write << "Name :" << name2 << endl;
    write << "Password :" << pass2 << endl;

    cout << "\n\nAdmin has Successfully Updated....";

    cout << "\n\n\t\tRedirecting to the Admin Panel.";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
}

// class register
class Register
{
private:
    string pass;

public:
    string name;
    string id;

    void registeration();
};

// class login
class Login : public Person
{
public:
    void login();
};

// Admin panel function
void Admin::adminPanel()
{
    ifstream read("Admin.txt");
    string line;
    while (getline(read, line))
    {
        if (line.find("Name :") != string::npos)

            name = line.substr(6);
        break;
    }
    read.close();

    cout << "\n\n";
    cout << "\t\t\t========================-- ADMIN PANEL --==========================\n";
    cout << "\t\t\t\t\t\t WELCOME " << name << endl;
    cout << "\t\t\t===================================================================\n";
    cout << "\t\t\t 1. MY PROFILE\n";
    cout << "\t\t\t 2. SHOW STUDENTS RECORD\n";
    cout << "\t\t\t 3. SEARCH RECORD\n";
    cout << "\t\t\t 4. ADD RECORD\n";
    cout << "\t\t\t 5. MARK ATTENDANCE\n";
    cout << "\t\t\t 6. UPLOAD EXAMINATION MARKS\n";
    cout << "\t\t\t 7. UPLOAD TIME TABLE\n";
    cout << "\t\t\t 8. VIEW TIME TABLE\n";
    cout << "\t\t\t 9. UPDATE ADMIN\n";
    cout << "\t\t\t 0. LOGOUT\n";

    cout << "\t\t\t Enter Option Number : ";
    int ch;
    cin >> ch;

    Login l;
    switch (ch)
    {
    case 1:
        system("cls");
        cout << "\n\n\n\t\t\t=======------- MY PROFILE ---=====================" << endl;
        cout << "\n\t\t\t NAME : " << name << endl;
        cout << "\t\t\t POSITION : Assistant Professor (Incharge of B.tech CSE )" << endl;
        cout << "\t\t\t DEPARTMENT : Engineering B.Tech" << endl;
        cout << "\t\t\t ASSOCIATED WITH PCTE INSTITUTE OF ENGINEERING AND TECHNOLOGY" << endl;

        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;

    case 2:
        system("cls");
        StudentRecords();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;
    case 3:
        system("cls");
        searchRecord();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;
    case 4:

        system("cls");
        addStudent();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;

    case 5:

        system("cls");
        markAttendance();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;
    case 6:

        system("cls");
        uploadExamMarks();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;

    case 7:
        system("cls");
        uploadTimeTable();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;

    case 8:
        system("cls");
        viewTimeTable();
        cout << "\n\n GO BACK" << endl;
        system("pause");
        system("cls");
        adminPanel();
        break;
    case 9:

        system("cls");
        updateAdmin();
        system("cls");
        l.login();
        break;

    case 0:
        system("cls");
        cout << "\t\t\t\n\n\nLOGGING OUT.";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        system("cls");
        l.login();
        break;

    default:
        cout << "\t\t\t\n\n* * * Please Enter a Valid Option * * *\n\n";
        system("cls");
        adminPanel();
        break;
    }
}

// admin login
void Admin::adminLogin()
{
    cout << "\t\t\t========================-- ADMIN LOGIN --==========================\n";
    string Sdname;
    string Sdpass;

    ifstream read("Admin.txt");

    if (!read.is_open())
    {

        cout << "Failed to Open File";
        return;
    }

    cout << "\t\t\t  ENTER NAME : ";
    cin.ignore();
    getline(cin, Sdname);
    cout << "\t\t\t  ENTER PASSWORD : ";
    cin >> Sdpass;

    bool loginSuccessful = false;
    string line;
    string tempname, temppass;

    while (getline(read, line))
    {
        if (line.find("Name :") != string::npos)
        {
            tempname = line.substr(6);
        }
        else if (line.find("Password :") != string::npos)
        {
            temppass = line.substr(10);

            // Checking values
            if (Sdname == tempname && Sdpass == temppass)
            {
                loginSuccessful = true;
                cout << "\t\t\t\nLogin Successful!\n\n"
                     << endl;
                cout << "Redirecting to DASHBOARD.";
                sleep(1);
                cout << ".";
                sleep(1);
                cout << ".";
                sleep(1);
                cout << ".";
                sleep(1);
                system("cls");
                adminPanel();
                break;
            }
        }
    }

    if (!loginSuccessful)
    {
        cout << "\t\t\t\nLogin Failed. Invalid credentials." << endl;
        entryPanel();
    }
}

// funtion to register
void Register::registeration()
{
    cout << "\t\t\t========================-- REGISTER HERE --==========================\n";

    system("pause");

    Login l;

    // creating and opening file in append mode
    ofstream write("registeredUsers.txt", ios::app);

    cout << "\t\t\t  ENTER NAME : ";
    cin.ignore();
    getline(cin, name);

    cout << "\t\t\t  ENTER ROLL NUMBER : ";
    getline(cin, id);

    cout << "\t\t\t  ENTER PASSWORD : ";
    getline(cin, pass);

    // appending in file
    write << "Name :" << name << endl;
    write << "Roll Number :" << id << endl;
    write << "Password :" << pass << endl;
    write << "===================================" << endl;

    // closing the file
    write.close();
    system("cls");
    cout << "\t\t\t\nRegistered Successfully -- Please Login\n";
    l.login();
}

void Login::login()
{
    cout << "\t\t\t========================-- WELCOME --==========================\n";
    cout << "\t\t\t 1. ADMIN LOGIN\n";
    cout << "\t\t\t 2. STUDENT LOGIN\n";
    cout << "\t\t\t 3. GO BACK\n";
    cout << "\t\t\t 4. EXIT\n";
    char ch;
    Admin user;
    Student stu;
    cout << "\t\t\t Enter Option Number : ";
    cin >> ch;

    switch (ch)
    {
    case '1':
        system("cls");
        user.adminLogin();
        break;
    case '2':
        system("cls");
        stu.studentLogin();
        break;
    case '3':
        system("cls");
        entryPanel();
        break;
    case '4':
        exit(0);
        break;
    default:
        system("cls");
        cout << "\t\t\t\n\n* * * Please Enter a Valid Option * * *\n\n";
        login();
        break;
    }
}

// entry panel
void Person::entryPanel()
{
    cout << "\t\t\t========================-- WELCOME --==========================\n";
    cout << "\t\t\t 1. LOGIN\n";
    cout << "\t\t\t 2. REGISTER\n";
    cout << "\t\t\t 3. EXIT\n";
    char ch;
    Register user;
    cout << "\t\t\t Enter Option Number : ";
    cin >> ch;
    Login l;
    switch (ch)
    {
    case '1':
        system("cls");
        l.login();
        break;
    case '2':
        system("cls");
        user.registeration();
        break;
    case '3':
        exit(0);
        break;
    default:
        system("cls");
        cout << "\t\t\t\n\n* * * Please Enter a Valid Option * * *\n\n";
        entryPanel();
        break;
    }
}
int main()
{
    Person p;
    char a = 3;
    cout << " \n\n\t\t-------------------ERP STUDENT MANAGEMENT SYSTEM --------------------\n";
    cout << "\t\t\t\tMade with " << a << " by Aniket Gupta & Brijesh Kumar\n";
    cout << "\t--------------------------------------------------------------------------------------\n";
    p.entryPanel();

    return 0;
}
