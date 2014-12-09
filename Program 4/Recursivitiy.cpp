//Dallas Johnson
//Recursive linked list editing (book titles)
//CS201

//Program 5 is still horribly broken, and the parser for that is also horribly ruined.
//I'll try to write the parser for this program, since that should finish it off and then I can copy THIS code to program 5. Still doing them at the same time, which is good.
#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
#include "Recursitivity.h"

using namespace std;


LL* booklist = new LL();

//This is where our program starts. It begins here with a simple infinite loop for-loop that waits for the i= function to return 0, thus killing the method.
int main(int argc, char** argv)
{
	for(int i = 1; i != 0; i = getInput());
	delete booklist;
	return 0;
}

//clever function to always run in a for loop. This is essentially the body of the main just split off into an inner for loop function to run when it doesn't return 0.
int getInput()
{
	string commandString = "";
	cout << "Enter a command (type help for more information): ";
	getline(cin, commandString);
	//Split strings with the substring command.
	int i = 0;
	while (commandString[i] && commandString[i] != ' ') {
        char c = commandString[i];
        commandString[i]=tolower(c);
        i++;
	}
    if (commandString.substr(0,4) == "add ") {
        //just get this working before I have to split strings.
        string title;
        if (commandString[4] == '"') {
            title = commandString.substr(5);
            title.erase(title.length()-1);
        } else {
            title = commandString.substr(4);
        }

        //booklist -> addback(title);
        booklist->addinorder(title);
        cout << "Current book(s): " << endl;
        booklist -> print();
        }
    else if (commandString.substr(0,7) == "remove ")
        {
            string title = commandString.substr(7);
            booklist->remove_0(title);
            cout << "Current book(s): " << endl;
            booklist -> print();
        }
    else if (commandString.substr(0,5) == "print")
	{
	    cout << "Current book(s): " << endl;
	    booklist -> print();
	}
    else if (commandString.substr(0,4) == "exit")
        {
            cout << "goodbye!" << endl;
            return 0;
        }
    else if (commandString.substr(0,4) == "help")
    {
        cout << "Commands: " << endl;
        cout << "Add (book)" << endl;
        cout << "Remove (book)" << endl;
        cout << "Print" << endl;
        cout << "Exit" << endl;
    }
    else {
	cout << "Invalid command!" << endl;
	}
}

//still accepting the two paramters that I had put in before. HOW exactly we use them will be different.
