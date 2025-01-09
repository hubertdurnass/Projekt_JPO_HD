#include "TaskManager.h"
#include <iostream>

int main() {
    hd::TaskManager manager("ListOfTasks.txt");
    manager.menu();

    return 0;
}
