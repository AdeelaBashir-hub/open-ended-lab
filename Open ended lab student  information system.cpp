#include <iostream>
#include <string>

using namespace std;

// Structure to store student details
struct Student {
    int id;
    string name;
    int age;
    string department;
};

// Global array to store students
Student students[100];
int studentCount = 0;

// Function to add a student
void addStudent() {
    if (studentCount < 100) {
        cout << "\nEnter Student ID: ";
        cin >> students[studentCount].id;
        cin.ignore(); // Clear input buffer
        cout << "Enter Student Name: ";
        getline(cin, students[studentCount].name);
        cout << "Enter Student Age: ";
        cin >> students[studentCount].age;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, students[studentCount].department);

        studentCount++;
        cout << "Student added successfully!\n";
    } else {
        cout << "Student storage is full!\n";
    }
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\nList of Students:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age
             << ", Department: " << students[i].department << endl;
    }
}

// Function to search for a student by ID
void searchStudent() {
    int searchId;
    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId) {
            cout << "Student Found!\n";
            cout << "ID: " << students[i].id
                 << ", Name: " << students[i].name
                 << ", Age: " << students[i].age
                 << ", Department: " << students[i].department << endl;
            return;
        }
    }
    cout << "Student not found!\n";
}

// Function to delete a student by ID
void deleteStudent() {
    int deleteId;
    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteId) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student record deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

// Main function
int main() {
    int choice;
    do {
        cout << "\nStudent Information System";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student by ID";
        cout << "\n4. Delete Student by ID";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}