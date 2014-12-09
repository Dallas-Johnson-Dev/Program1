#ifndef _LLN_
#define _LLN_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
using namespace std;

class LL;
class LLN {
private:
	string s;
	LLN * next;

public:
	LLN (string S, LLN * n);
	~LLN();
	string gets (); //accessor
    LLN * getnext (); //getter
	void setnext (LLN *n); //setter OR mutator
	void print ();
	void printall ();
	void addback (string S);
	void addinorder (string S);	
	LLN * addinorder_0 (string S);
	LLN * remove (string S);
	void remove_0 (string S, LLN *prev, LL *l);
	bool removelast (string S, LLN *prev, LL *l);
	void addbook(string S);

};

#endif
