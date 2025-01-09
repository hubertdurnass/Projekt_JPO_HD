#pragma once
#include <string>

/**
 * @namespace hd
 * Namespace hd to encapsulate all classes and functions.
 */
namespace hd {

/**
 * @class Task
 * @brief Class representing a task.
 */
class Task {
public:
    std::string description; /**< Description of the task */
    bool done; /**< Status of the task (done or not) */

    /**
     * @brief Default constructor for Task.
     */
    Task();

    /**
     * @brief Parameterized constructor for Task.
     * @param description Description of the task.
     * @param done Status of the task (default is false).
     */
    Task(const std::string& description, bool done = false);

    /**
     * @brief Equality operator for Task.
     * @param other Another Task to compare with.
     * @return True if tasks are equal, false otherwise.
     */
    bool operator==(const Task& other) const;

    /**
     * @brief Inequality operator for Task.
     * @param other Another Task to compare with.
     * @return True if tasks are not equal, false otherwise.
     */
    bool operator!=(const Task& other) const;
};

} // namespace hd
