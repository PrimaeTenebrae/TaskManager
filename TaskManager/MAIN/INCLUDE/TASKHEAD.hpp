#ifndef TASKHEAD_HPP  
#define TASKHEAD_HPP 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
#include <vector>

extern std::string taskName , taskDescription , confirm , userInput;

extern std::vector<std::string> taskVector;

extern int numTasks;

extern void helpUser();

extern void listTasks();

extern void addTaskFunc();

extern void removeTaskFunc();

extern void addAllToVect();

extern void addToVect();

extern int taskCount();

#endif