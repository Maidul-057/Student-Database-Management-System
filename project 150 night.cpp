#include<bits/stdc++.h>
using namespace std;


struct Student {
    int rollNumber;
    string name,Father_Name,Mother_Name,course;
    int age;

};


void addStudent(Student students[], int& count) {
     cin.ignore();
    cout << "Enter Name: ";
    getline(cin, students[count].name);
    cout<< "Enter Father Name: ";
    getline(cin, students[count].Father_Name);
    cout<< "Enter Mother Name: ";
    getline(cin, students[count].Mother_Name);
    cout << "Enter Roll Number: ";
    cin >> students[count].rollNumber;
    cout << "Enter Age: ";
    cin >> students[count].age;
    cout << "Enter Course: ";
    cin.ignore();
    getline(cin, students[count].course);
    count++;
    cout << "Student added successfully!"<<endl<<endl;
}


void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students in the database."<<endl;;
        return;
    }

        cout << "Students are: "<<endl;;
    for (int i = 0; i < count; ++i) {
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Name: " << students[i].name << endl;
        cout<<"Father Name: " << students[i].Father_Name<<endl;
        cout<<"Mother Name: " << students[i].Mother_Name<<endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl << endl;
    }
}

void deleteStudent(Student students[], int& count, int roll) {
    int index = -1;


    for (int i = 0; i < count; ++i) {
        if (students[i].rollNumber == roll) {
            index = i;
            break;
        }
    }


    if (index != -1) {
        for (int i = index; i < count - 1; ++i) {
            students[i] = students[i + 1];
        }
        count--;
        cout << "Student with Roll Number " << roll << " deleted successfully!"<<endl;
    } else {
        cout << "Student with Roll Number " << roll << " not found.\n";
    }
}

void searchStudentbyroll(const Student students[], int count, int rollNumberToSearch) {
    bool found = false;

    for (int i = 0; i < count; ++i) {
        if (students[i].rollNumber == rollNumberToSearch) {
            cout << "Student found!\n";
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "Name: " << students[i].name << endl;
            cout<<"Father Name: " << students[i].Father_Name<<endl;
            cout<<"Mother Name: " << students[i].Mother_Name<<endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll Number " << rollNumberToSearch << " not found."<<endl;
    }
}

void searchStudentbyName(const Student students[], int count, const string& nameToSearch) {
    bool found = false;

     int paisi=0;
    for (int i = 0; i < count; ++i) {
        if (students[i].name == nameToSearch) {
            cout <<endl<< "Student found!"<<endl;
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "Name: " << students[i].name << endl;
            cout<<"Father Name: " << students[i].Father_Name<<endl;
            cout<<"Mother Name: " << students[i].Mother_Name<<endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            found = true;
            paisi++;

        }
    }

    if (!found) {
        cout << nameToSearch << " is not found in the database."<<endl<<endl;
    }
    else{ if(paisi>1)
                    {cout<<"You have "<<paisi<<" Student with the same name"<<endl;}
          else {cout<<"Found 1 Student!"<<endl;}
        }
    if(paisi>1){
             cout<<"Can you find your specific student by roll?" <<endl<<"1. YES"<<endl<<"2. NO"<<endl;
             int option;
             cin>>option;
             if(option==1){
                    cout << "Enter the Roll Number to search: ";
                    int rollToSearch,studentCount;
                                 cin >> rollToSearch;

                                 searchStudentbyroll(students, studentCount, rollToSearch);

                            }
             else if(option==2){
                    cout<<endl;
                     }
             else{ cout<<"Please follow the instruction!!"<<endl;}
                  }
}



int main() {
    const int MAX_STUDENTS = 1000;
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int rollToSearch;
    string nameToSearch;
    int choice;
    int choiceIs;
    do {
        cout << "Student Database Management System"<<endl<<endl;
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout<<"5. Exit\n";
        cout<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                int rollToDelete;
                cout << "Enter the Roll Number to delete: ";
                cin >> rollToDelete;
                deleteStudent(students, studentCount, rollToDelete);
                break;
            case 4: cout<<"How can you search your student?"<<endl;
                    cout<<"1. By Name"<<endl<<"2. By Roll"<<endl;
                    cin>>choiceIs;
                    switch(choiceIs){
                             case 1:
                                cout << "Enter the Name to search: ";
                                cin.ignore();
                                getline(cin, nameToSearch);

                                searchStudentbyName(students, studentCount, nameToSearch);
                                break;
                             case 2:
                                 cout << "Enter the Roll Number to search: ";
                                 cin >> rollToSearch;

                                 searchStudentbyroll(students, studentCount, rollToSearch);
                                break;
                             default :
                                 cout<<"You click wrong key "<<endl;}
                                 break;
            case 5:
                cout << "Exiting the program. Goodbye!"<<endl;
                break;

            default:
                cout << "Invalid choice"<<endl;
        }
    } while (choice != 5);

    return 0;
}
