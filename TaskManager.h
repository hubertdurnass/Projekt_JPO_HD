#pragma once
#include "Task.h"
#include <vector>
#include <string>

namespace hd {

class TaskManager {
private:
    std::vector<Task> tasks;
    std::string fileName;
    void save();
    void load();

public:
    TaskManager(const std::string& fileName);
    ~TaskManager();

    // Functions
    void addTask(const std::string& description);
    void deleteTask(int index);
    void editTask(int index, const std::string& newDescription);
    void markAsDone(int index);
    void displayTasks() const;
    void menu();

    Task& operator[](int index);
    const Task& operator[](int index) const;
};
} //hd
