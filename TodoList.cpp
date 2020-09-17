#include "TodoList.h"

TodoList::TodoList() {
  string days[7] = {
    "Sunday:",
    "Monday:",
    "Tuesday:",
    "Wednesday:",
    "Thursday:",
    "Friday:",
    "Saturday:"
  };
  daysOfTheWeek.insert(todoTasks.end(), days, days+7);
  readFile();
}

TodoList::~TodoList() {
  writeFile();
}

/*
*   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
*/
void TodoList::add(string _duedate, string _task) {
  cout << "Item added" << endl;
}

/*
*   Removes an item from the todo list with the specified task name
*
*   Returns 1 if it removes an item, 0 otherwise
*/
int TodoList::remove(string _task) {
  cout << "Item removed" << endl;
  return 0;
}

/*
*   Prints out the full todo list to the console
*/
void TodoList::printTodoList() {
  cout << "Todo list:" << endl;
  int dayIndex = 0;
  for (int i = 0; i < todoTasks.size(); i++) {
    cout << todoTasks.at(i) << endl;
    if (todoTasks.at(i) == daysOfTheWeek.at(dayIndex)) {
      dayIndex++;
      if (todoTasks.at(i + 1) == "") {
        cout << "- no tasks" << endl; // Prints if a certain day has no tasks
      }
    }
  }
}

/*
*   Prints out all items of a todo list with a particular due date (specified by _duedate)
*/
void TodoList::printDaysTasks(string _date) {
  int i = 0;
  try {
    while (true) {
      string todoTask = todoTasks.at(i);
      //cout << todoTask.substr(0, todoTask.length() - 1) << endl;
      if (todoTask.substr(0, todoTask.length() - 1) == _date) {
        i++;
        cout << _date << "\'s tasks:" << endl;
        if (todoTasks.at(i) == "") {
          cout << "- no tasks" << endl;
        }
        break;
      }
      i++;
    }
    while (todoTasks.at(i) != "") {
      cout << todoTasks.at(i) << endl;
      i++;
    }
  } catch(out_of_range& e) {
    cout << "Error: \'" << _date << "\' is not a day of the week" << endl;
  }

}

/*
*   Reads contents of todoList file and assigns it to a vector<string> variable
*/
void TodoList::readFile() {
  ifstream file;
  file.open("TodoList.txt");
  string task;
  if (file) {
    while (getline(file, task)) {
      todoTasks.push_back(task);
    }
  } else {
    for (int i = 0; i < 7; i++) {
      todoTasks.push_back(daysOfTheWeek.at(i));
      todoTasks.push_back("");
    }
  }
  file.close();
}
/*
*   Writes all content to todolist file
*/
void TodoList::writeFile() {
  ofstream file;
  file.open("TodoList.txt");
  for (int i = 0; i < todoTasks.size(); i++) {
    file << todoTasks.at(i) << endl;
  }
  file.close();
}
