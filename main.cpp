#include <iostream>
#include "TodoList.h"

void printUsageMessage() {
  cout << "Usage:" << endl;
  cout << "  ./TODO add [date] [task]" << endl;
  cout << "  ./TODO remove [task]" << endl;
  cout << "  ./TODO printList" << endl;
  cout << "  ./TODO printDay [day]" << endl;
}

void executeTodoListFunction(int argc, char *argv[]) {
  TodoList *todoList = new TodoList();
  string command = argv[1];
  if (command == "add") {
    if (argc != 4) {
      printUsageMessage();
    } else {
      todoList->add(argv[2], argv[3]);
    }
  } else if (command == "remove") {
    if (argc != 3) {
      printUsageMessage();
    } else {
      todoList->remove(argv[2]);
    }
  } else if (command == "printList") {
    if (argc != 2) {
      printUsageMessage();
    } else {
      todoList->printTodoList();
    }
  } else if (command == "printDay") {
    if (argc != 3) {
      printUsageMessage();
    } else {
      todoList->printDaysTasks(argv[2]);
    }
  } else {
    cout << "Error: \'" << command << "\' command is unkown" << endl;
    printUsageMessage();
  }
  delete todoList;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printUsageMessage();
  } else {
    executeTodoListFunction(argc, argv);
  }
}
