#ifndef _LL_
#define _LL_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
using namespace std;

class LLN;
class LL {
private:
	LLN *head;
public:
	LL (); //Constructor
	~LL (); //Destructor
	void addfront (string S);
	void addback (string S);
	void print ();
	void addinorder (string S);
	void remove (string S);
	void remove_0 (string S);
	void sethead (LLN *h);
	void removelast (string S);
	void addbook(string S);
	void removebook(string S);
};

#endif
