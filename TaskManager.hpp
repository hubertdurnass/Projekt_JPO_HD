#pragma once
#include "Task.hpp"
#include <vector>
#include <string>

namespace hd {

/**
 * @class TaskManager
 * @brief Class managing a list of tasks.
 */
class TaskManager {
private:
    std::vector<Task> tasks; /**< Vector of tasks */
    std::string fileName; /**< File name to save/load tasks */
    void save(); /**< Saves tasks to file */
    void load(); /**< Loads tasks from file */

public:
    /**
     * @brief Constructor for TaskManager.
     * @param fileName Name of the file to save/load tasks.
     */
    TaskManager(const std::string& fileName);

    /**
     * @brief Destructor for TaskManager.
     */
    ~TaskManager();

    /**
     * @brief Adds a new task.
     * @param description Description of the task.
     */
    void addTask(const std::string& description);

    /**
     * @brief Deletes a task by index.
     * @param index Index of the task to delete.
     */
    void deleteTask(int index);

    /**
     * @brief Edits a task description.
     * @param index Index of the task to edit.
     * @param newDescription New description of the task.
     */
    void editTask(int index, const std::string& newDescription);

    /**
     * @brief Marks a task as done.
     * @param index Index of the task to mark as done.
     */
    void markAsDone(int index);

    /**
     * @brief Displays all tasks.
     */
    void displayTasks() const;

    /**
     * @brief Shows the menu for task management.
     */
    void menu();

    /**
     * @brief Index operator for TaskManager.
     * @param index Index of the task to access.
     * @return Reference to the task.
     */
    Task& operator[](int index);

    /**
     * @brief Const index operator for TaskManager.
     * @param index Index of the task to access.
     * @return Const reference to the task.
     */
    const Task& operator[](int index) const;
};

} // namespace hd
