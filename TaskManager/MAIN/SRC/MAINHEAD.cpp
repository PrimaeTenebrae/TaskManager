#include <iostream>
#include <fstream>
#include <cctype>
#include <bits/stdc++.h>
#include "../INCLUDE/TASKHEAD.hpp" 

std::string taskName , taskDescription , userInput , confirm , fullLine;

int numTasks;

std::vector<std::string> taskVector;

void addAllToVect()
{
    std::ifstream outFile("../STORE/TASKSTORE.txt");
    std::string line;

    taskVector.clear();

    while (getline(outFile , line))
    {
        taskVector.push_back(line);
    }

    outFile.close();
}

void helpUser()
{
    std::cout << "List of commands: \n\n";

    std::cout << "help - shows list of commands\n";
    std::cout << "tasks - Shows current number of tasks and list of tasks.\n";
    std::cout << "remove/removetask - Prompts user to remove a task.\n";
    std::cout << "add/addtask - Prompts user to add a task.\n";

    std::cout << "exit - Exits program.\n";
    
}

void listTasks()
{
    std::ifstream outFile("../STORE/TASKSTORE.txt");

    if (!outFile.is_open())
    {
        std::cout << "File failed to open\n\n";
    }

    std::string curLine;
    int count = 0;

    while (getline(outFile , curLine))
    {
        std::cout << count << ". " << curLine << "\n";
        count++;
    }
}

int taskCount()
{

    std::ifstream outFile("../STORE/TASKSTORE.txt");

    if (!outFile.is_open())
    {
        std::cout << "File failed to open.\n\n";
    }
    
    std::string curLine;

    numTasks = 0;

    while (getline(outFile , curLine) && !curLine.empty())
    {
        numTasks++;
    }
    
    return numTasks;
}

void addTaskFunc()
{

    std::ofstream outFile("../STORE/TASKSTORE.txt" , std::ios::trunc);

    if (!outFile.is_open())
    {
        std::cout << "Error opening file located in ../STORE \n\n";
        
        outFile.close();
    }

    std::cout << "Input the name of the task you wish to add: ";

    getline(std::cin , taskName);

    std::cout << "\n\n Do you wish to input a description of task? ";

    getline(std::cin , confirm);

    std::cout << "\n\n";

    if (confirm == "y" || confirm == "yes")
    {
        std:: cout << "Input a description of this task: ";
        getline(std::cin , taskDescription);

        fullLine = taskName + " | " + taskDescription;

        taskVector.push_back(fullLine);

    }
    else
    {
        fullLine = taskName + " | ";

        taskVector.push_back(fullLine);
    }

    for (std::string line : taskVector)
        {
            outFile << line << std::endl;
        }
    
    outFile.close();
}

void removeTaskFunc()
{
    if (size(taskVector) <= 0)
    {
        std::cout << "No tasks to remove...\n\n";
    }
    else
    {
    std::ofstream outFile ("../STORE/TASKSTORE.txt" , std::ofstream::trunc);

    if (!outFile.is_open())
    {
        std::cout << "Failed to open file containing tasks.";
        return;
    }

    std::string curLine;
    int userInt;

    for (std::string line : taskVector)
    {
        std::cout << line << "\n\n";
    }

    std::cout << "Choose a task from list above to remove: ";
    std::cin >> userInt;

    taskVector.erase(taskVector.begin() + userInt);

    for (std::string line : taskVector)
    {
        outFile << line << std::endl;
    }

    outFile.close();

    addAllToVect();
    }
}