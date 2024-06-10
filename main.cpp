#include <iostream>
#include <fstream>
#include <string>
#include <vector>

char delimiter = ',';

struct Student {
    std::string fullName;
    int course;
    std::string faculty;       
    double gradePointAverage;
    int age;
};

void loadStudents(std::vector<Student>& students) {
    std::ifstream file("students.txt");
    if (file.is_open()) {
        Student student;
        while (file >> student.fullName >> student.course >> student.faculty >> student.gradePointAverage >> student.age) {
            students.push_back(student);
        }
        file.close();
        std::cout << "Students uploaded from a file." << std::endl;
    } else {
        std::cout << "File opening error." << std::endl;
    }
}

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students found." << std::endl;
        return;
    }

    std::cout << "List of students:" << std::endl;
    for (const auto& student : students) {
        std::cout << "Full name: " << student.fullName << ", Course: " << student.course
                  << ", Faculty: " << student.faculty << ", Grade Point Average: " << student.gradePointAverage
                  << ", Age: " << student.age << std::endl;
    }
}

void searchStudents(const std::vector<Student>& students) {
    std::string searchField;
    std::cout << "Enter the search field (fullName, course, faculty, gradePointAverage, age): ";
    std::cin >> searchField;

    bool found = false;
    for (const auto& student : students) {
        if (searchField == "fullName" && student.fullName == searchField) {
            std::cout << "Fuul name: " << student.fullName << ", Course: " << student.course
                      << ", Faculty: " << student.faculty << ", Grade Point Average: " << student.gradePointAverage
                      << ", age: " << student.age << std::endl;
            found = true;
        } else if (searchField == "course" && std::to_string(student.course) == searchField) {
            std::cout << "Full name: " << student.fullName << ", Course: " << student.course
                      << ", Faculty: " << student.faculty << ", Grade Point Average: " << student.gradePointAverage
                      << ", age: " << student.age << std::endl;
            found = true;
        } else if (searchField == "faculty" && student.faculty == searchField) {
            std::cout << "Full name: " << student.fullName << ", Course: " << student.course
                      << ", Faculty: " << student.faculty << ", Grade Point Average: " << student.gradePointAverage
                      << ", age: " << student.age << std::endl;
            found = true;
        } else if (searchField == "gradePointAverage" && std::to_string(student.gradePointAverage) == searchField) {
            std::cout << "Full name: " << student.fullName << ", Course: " << student.course
                      << ", Faculty: " << student.faculty << ", Grade Point Average: " << student.gradePointAverage
                      << ", age: " << student.age << std::endl;
            found = true;
        } else if (searchField == "age" && std::to_string(student.age) == searchField) {
            std::cout << "Full name: " << student.fullName << ", Course: " << student.course
                      << ", Faculty: " << student.faculty << ", Grade Point Average: " << student.gradePointAverage
                      << ", age: " << student.age << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Students with the specified field value were not found." << std::endl;
    }
}
void addStudent(std::vector<Student>& students) {
    Student newStudent;
    std::cout << "Enter the information about the student:" << std::endl;
    std::cout << "Full name: ";
    std::getline(std::cin >> std::ws, newStudent.fullName);
    std::cout << "Course: ";
    std::cin >> newStudent.course;
    std::cout << "Faculty: ";
    std::getline(std::cin >> std::ws, newStudent.faculty);
    std::cout << "Grade Point Average: ";
    std::cin >> newStudent.gradePointAverage;
    std::cout << "Age: ";
    std::cin >> newStudent.age;
    students.push_back(newStudent);
    std::cout << "A new student has been added." << std::endl;
}

void deleteStudent(std::vector<Student>& students) {
    int index;
    std::cout << "Enter the student's index to delete: ";
    std::cin >> index;

    if (index < 0 || index >= students.size()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    students.erase(students.begin() + index);
    std::cout << "The student has been removed." << std::endl;
}

void saveStudents(const std::vector<Student>& students) {
    std::ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.fullName << " " << student.course << " " << student.faculty << " "
                 << student.gradePointAverage << " " << student.age << std::endl;
        }
        file.close();
        std::cout << "The students are saved to a file." << std::endl;
    } else {
        std::cout << "Error opening the file." << std::endl;
    }
}

int main() {
    std::vector<Student> students;
    int choice;

    while (true) {
        std::cout << "Student Management Menu:" << std::endl;
        std::cout << "1. Upload students" << std::endl;
        std::cout << "2. Display students" << std::endl;
        std::cout << "3. Student Search" << std::endl;
        std::cout << "4. Add a student" << std::endl;
        std::cout << "5. Delete a student" << std::endl;
        std::cout << "6. Save students" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadStudents(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudents(students);
                break;
            case 4:
                addStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                saveStudents(students);
                break;
            case 7:
                std::cout << "Exit the program..." << std::endl;
                return 0;
            default:
                std::cout << "Wrong choice. Try again." << std::endl;
                break;
        }
    }
}