#pragma once
#include <string>

namespace hd {

class Task {
public:
    std::string description;
    bool done;

    Task();
    Task(const std::string& description, bool done = false);

    bool operator==(const Task& other) const;
    bool operator!=(const Task& other) const;
};

}
