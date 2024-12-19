#include <iostream>
#include <fstream>
#include <cctype>
#include <bits/stdc++.h>
#include "../INCLUDE/TASKHEAD.hpp" 

int main(int argc , char *argv[])
{
    addAllToVect();

    std::cout << "\nTask Manager(type" << " word exit " << " to exit): " << "\n";

while (true)
{

    std::cout << "\n" << "What would you like to do? " << "\n";
    std::getline(std::cin , userInput);
    std::cout <<"\n";

    std::transform(userInput.begin(), userInput.end(), userInput.begin(), 
    ::tolower); 

    if (userInput == "help")
    {
        std::cout << "\n";
  
        helpUser();
    }

    if (userInput == "tasks")
    {
        std::cout << "Total Tasks: " << taskCount() << "\n";

        listTasks();

    }
    
    if (userInput == "add" || userInput == "addtask")
    {
        addTaskFunc();
    }
    if (userInput == "remove" || userInput == "removetask")
    {
        removeTaskFunc();
    }

    if (userInput == "exit")
    {
        break;
    }

}

return 0;

}