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

void TodoList::add(string _duedate, string _task) {
  cout << "Item added" << endl;
}

int TodoList::remove(string _task) {
  cout << "Item removed" << endl;
  return 0;
}

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

void TodoList::printDaysTasks(string _date) {
  int i = getDayIndex(_date);
  if (i == -1) {
    // Print error msg if input doesn't match day of the week
    cout << "Error: \'" << _date << "\' is not a day of the week" << endl;
  } else {
    i++;
    cout << _date << "\'s tasks:" << endl;
    if (todoTasks.at(i) == "") {
      // Print output message if there are no tasks for the day
      cout << "- no tasks" << endl;
    } else {
      // Print out all tasks for that day of the week
      while (todoTasks.at(i) != "") {
        cout << todoTasks.at(i) << endl;
        i++;
      }
    }
  }

  /*try {
    // Find the day of the week in the todoTasks vector
    while (true) {
      string todoTask = todoTasks.at(i);
      if (todoTask.substr(0, todoTask.length() - 1) == _date) {
        i++;
        // if the day is found, print out a heading
        cout << _date << "\'s tasks:" << endl;
        if (todoTasks.at(i) == "") {
          // Print output message if there are no tasks for the day
          cout << "- no tasks" << endl;
        }
        break;
      }
      i++;
    }
    // Print out all tasks for that day of the week
    while (todoTasks.at(i) != "") {
      cout << todoTasks.at(i) << endl;
      i++;
    }
  // Print error msg if input doesn't match day of the week
  } catch(out_of_range& e) {
    cout << "Error: \'" << _date << "\' is not a day of the week" << endl;
  }*/

}

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

void TodoList::writeFile() {
  ofstream file;
  file.open("TodoList.txt");
  for (int i = 0; i < todoTasks.size(); i++) {
    file << todoTasks.at(i) << endl;
  }
  file.close();
}

int TodoList::getDayIndex(string day) {
  try {
    int i = 0;
    while (true) {
      string todoTask = todoTasks.at(i);
      if (todoTask.substr(0, todoTask.length() - 1) == day) {
        return i;
      }
      i++;
    }
  } catch(out_of_range& e) {
    // The day does not exist in the array
    return -1;
  }
}
