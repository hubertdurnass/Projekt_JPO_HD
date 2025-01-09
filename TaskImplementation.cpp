#include "Task.h"

namespace hd {

Task::Task() : description(""), done(false) {}

Task::Task(const std::string& description, bool done) 
    : description(description), done(done) {}

bool Task::operator==(const Task& other) const {
    return description == other.description && done == other.done;
}

bool Task::operator!=(const Task& other) const {
    return !(*this == other);
}
} //hd
