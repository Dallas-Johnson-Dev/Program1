//Dallas Johnson
//Recursive linked list editing (book titles)
//CS201

//Program 5 is still horribly broken, and the parser for that is also horribly ruined.
//I'll try to write the parser for this program, since that should finish it off and then I can copy THIS code to program 5. Still doing them at the same time, which is good.
#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"

using namespace std;


LL* booklist = new LL();

int getInput()
{
	string commandString = "";
	string command = "";
	string params = "";
	cout << "Enter a command (type help for more information): ";
	getline(cin, commandString);
	parseCommand(commandString, command);
    if (command == "add") {
        //just get this working before I have to split strings.
        string title = "";
        getline(cin, title);
        booklist -> addback(title);
	cout << "Current book(s): " << endl;
	booklist -> print();
        }
    else if (command == "remove")
        {
            string title = "";
            getline(cin, title);
            booklist->remove_0(title);
	    cout << "Current book(s): " << endl;
	    booklist -> print();
        }
    else if (command == "print")
	{
	    cout << "Current book(s): " << endl;
	    booklist -> print();
	}
    else if (command == "exit")
        {
            cout << "goodbye!" << endl;
	    return 0;
        }
    else {
	cout << "Invalid command!" << endl;
	}
    }

void parseCommand (string input, string &command, string &params) {
	bool commandFinished = false;
	string inputString = input;
	string commandOutput = command;
	string paramOutput = params;
	for (int i = 0; i < inputString.length(); i++)
		{
			if (inputString[i] == ' ') {
			commandFinished = true;
			}
			commandOutput = commandOutput + inputString[i];
			cout << commandOutput;
		}
}

int main(int argc, char** argv)
{
//Your autograder may flag this as infinite looping. This is how this program will run if we have an exit command.
	//bool running = true;
//Command parsing system similar to how my IRC bot handled this.
//commands: Add, Remove, Exit, Help (help will just show the previous three. Adding this for aesthetic value.
	bool isRunning = true;
	//for (int i = 1; i != 0; i = getInput());
	while (isRunning) {
		if (getInput() == 0) break;
	}
	delete booklist;
	return 0;
}

//still accepting the two paramters that I had put in before. HOW exactly we use them will be different.
