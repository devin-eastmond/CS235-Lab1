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
  string newTask = "- " + _task;
  int i = getDayIndex(_duedate);
  while (todoTasks.at(i) != "") {
    i++;
  }
  todoTasks.insert(todoTasks.begin() + i, newTask);
  cout << "\'" << _task << "\' task added to " << _duedate << endl;
}

int TodoList::remove(string _task) {
  string taskToRemove = "- " + _task;
  bool taskRemoved = false;
  for (int i = 0; i < todoTasks.size(); i++) {
    if (todoTasks.at(i) == taskToRemove) {
      todoTasks.erase(todoTasks.begin() + i);
      taskRemoved = true;
      break;
    }
  }
  if (taskRemoved) {
    cout << "Successfully removed task \'" << _task << "\'" << endl;
  } else {
    cout << "Error: could not find task \'" << _task << "\' in your todo list" << endl;
  }
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
    cout << "Error: \'" << day << "\' is not a day of the week" << endl;
    exit(1);
  }
}
