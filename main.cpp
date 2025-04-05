#include "TaskManager.hpp"
#include <iostream>

/**
 * @brief Main function to run the Task Manager application.
 * @return Exit status.
 */
int main() {
    hd::TaskManager manager("ListOfTasks.txt");
    manager.menu();
    return 0;
}
