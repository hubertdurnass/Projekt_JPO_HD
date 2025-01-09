#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <limits>

namespace hd {

TaskManager::TaskManager(const std::string& fileName) : fileName(fileName) {
    load();
}

TaskManager::~TaskManager() {
    save();
}

void TaskManager::save() {
    std::ofstream file(fileName);
    for (const auto& task : tasks) {
        file << task.description << "\n" << task.done << "\n";
    }
}

void TaskManager::load() {
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string description;
        bool done;
        while (std::getline(file, description)) {
            file >> done;
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            tasks.emplace_back(description, done);
        }
    }
}

void TaskManager::addTask(const std::string& description) {
    tasks.emplace_back(description);
}

void TaskManager::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void TaskManager::editTask(int index, const std::string& newDescription) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].description = newDescription;
    }
}

void TaskManager::markAsDone(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].done = true;
    }
}

void TaskManager::displayTasks() const {
    for (int i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << (tasks[i].done ? "[x] " : "[ ] ") << tasks[i].description << "\n";
    }
}

void TaskManager::menu() {
    int choice;
    do {
        std::cout << "1. Add task\n";
        std::cout << "2. Delete task\n";
        std::cout << "3. Edit task\n";
        std::cout << "4. Mark task as done\n";
        std::cout << "5. Display tasks\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter a choice: ";
        std::cin >> choice;

        std::string description;
        int index;

        switch (choice) {
            case 1:
                std::cout << "Enter the task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(description);
                break;
            case 2:
                std::cout << "Enter the task number to be deleted: ";
                std::cin >> index;
                deleteTask(index - 1);
                break;
            case 3:
                std::cout << "Enter the task number to edit: ";
                std::cin >> index;
                std::cout << "Enter the new task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                editTask(index - 1, description);
                break;
            case 4:
                std::cout << "Enter the task number to mark as done: ";
                std::cin >> index;
                markAsDone(index - 1);
                break;
            case 5:
                displayTasks();
                break;
            case 6:
                break;
            default:
                std::cout << "Wrong choice. Try again! \n";
                break;
        }
    } while (choice != 6);
}

Task& TaskManager::operator[](int index) {
    return tasks[index];
}

const Task& TaskManager::operator[](int index) const {
    return tasks[index];
}
} //hd
