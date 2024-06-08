#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
        std::cout << "Студенты загружены из файла." << std::endl;
    } else {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
}

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Студенты не найдены." << std::endl;
        return;
    }

    std::cout << "Список студентов:" << std::endl;
    for (const auto& student : students) {
        std::cout << "Полное имя: " << student.fullName << ", Курс: " << student.course
                  << ", Факультет: " << student.faculty << ", Средний балл: " << student.gradePointAverage
                  << ", Возраст: " << student.age << std::endl;
    }
}

void searchStudents(const std::vector<Student>& students) {
    std::string searchField;
    std::cout << "Введите поле для поиска (fullName, course, faculty, gradePointAverage, age): ";
    std::cin >> searchField;

    bool found = false;
    for (const auto& student : students) {
        if (searchField == "fullName" && student.fullName == searchField) {
            std::cout << "Полное имя: " << student.fullName << ", Курс: " << student.course
                      << ", Факультет: " << student.faculty << ", Средний балл: " << student.gradePointAverage
                      << ", Возраст: " << student.age << std::endl;
            found = true;
        } else if (searchField == "course" && std::to_string(student.course) == searchField) {
            std::cout << "Полное имя: " << student.fullName << ", Курс: " << student.course
                      << ", Факультет: " << student.faculty << ", Средний балл: " << student.gradePointAverage
                      << ", Возраст: " << student.age << std::endl;
            found = true;
        } else if (searchField == "faculty" && student.faculty == searchField) {
            std::cout << "Полное имя: " << student.fullName << ", Курс: " << student.course
                      << ", Факультет: " << student.faculty << ", Средний балл: " << student.gradePointAverage
                      << ", Возраст: " << student.age << std::endl;
            found = true;
        } else if (searchField == "gradePointAverage" && std::to_string(student.gradePointAverage) == searchField) {
            std::cout << "Полное имя: " << student.fullName << ", Курс: " << student.course
                      << ", Факультет: " << student.faculty << ", Средний балл: " << student.gradePointAverage
                      << ", Возраст: " << student.age << std::endl;
            found = true;
        } else if (searchField == "age" && std::to_string(student.age) == searchField) {
            std::cout << "Полное имя: " << student.fullName << ", Курс: " << student.course
                      << ", Факультет: " << student.faculty << ", Средний балл: " << student.gradePointAverage
                      << ", Возраст: " << student.age << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Студенты с указанным значением поля не найдены." << std::endl;
    }
}
void addStudent(std::vector<Student>& students) {
    Student newStudent;
    std::cout << "Введите информацию о студенте:" << std::endl;
    std::cout << "Полное имя: ";
    std::getline(std::cin >> std::ws, newStudent.fullName);
    std::cout << "Курс: ";
    std::cin >> newStudent.course;
    std::cout << "Факультет: ";
    std::getline(std::cin >> std::ws, newStudent.faculty);
    std::cout << "Средний балл: ";
    std::cin >> newStudent.gradePointAverage;
    std::cout << "Возраст: ";
    std::cin >> newStudent.age;
    students.push_back(newStudent);
    std::cout << "Новый студент добавлен." << std::endl;
}

void deleteStudent(std::vector<Student>& students) {
    int index;
    std::cout << "Введите индекс студента для удаления: ";
    std::cin >> index;

    if (index < 0 || index >= students.size()) {
        std::cout << "Неверный индекс." << std::endl;
        return;
    }

    students.erase(students.begin() + index);
    std::cout << "Студент удален." << std::endl;
}

void saveStudents(const std::vector<Student>& students) {
    std::ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.fullName << " " << student.course << " " << student.faculty << " "
                 << student.gradePointAverage << " " << student.age << std::endl;
        }
        file.close();
        std::cout << "Студенты сохранены в файл." << std::endl;
    } else {
        std::cout << "Ошибка открытия файла." << std::endl;
    }
}

int main() {
    std::vector<Student> students;
    int choice;

    while (true) {
        std::cout << "Меню управления студентами:" << std::endl;
        std::cout << "1. Загрузить студентов" << std::endl;
        std::cout << "2. Отобразить студентов" << std::endl;
        std::cout << "3. Поиск студентов" << std::endl;
        std::cout << "4. Добавить студента" << std::endl;
        std::cout << "5. Удалить студента" << std::endl;
        std::cout << "6. Сохранить студентов" << std::endl;
        std::cout << "7. Выйти" << std::endl;
        std::cout << "Введите ваш выбор: ";
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
                std::cout << "Выход из программы..." << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
                break;
        }
    }
}