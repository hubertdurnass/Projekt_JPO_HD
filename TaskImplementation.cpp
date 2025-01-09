#include "Task.h"

namespace hd {

/**
 * @brief Default constructor for Task.
 */
Task::Task() : description(""), done(false) {}

/**
 * @brief Parameterized constructor for Task.
 * @param description Description of the task.
 * @param done Status of the task (default is false).
 */
Task::Task(const std::string& description, bool done) 
    : description(description), done(done) {}

/**
 * @brief Equality operator for Task.
 * @param other Another Task to compare with.
 * @return True if tasks are equal, false otherwise.
 */
bool Task::operator==(const Task& other) const {
    return description == other.description && done == other.done;
}

/**
 * @brief Inequality operator for Task.
 * @param other Another Task to compare with.
 * @return True if tasks are not equal, false otherwise.
 */
bool Task::operator!=(const Task& other) const {
    return !(*this == other);
}

} // namespace hd
