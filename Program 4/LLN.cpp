#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
#include "LL.h"
using namespace std;

LLN::LLN (string S, LLN * n) {

	s = S;
	next = n;
}

LLN::~LLN () {

	delete next;
}

string LLN::gets () {return s;}//returns the string of the node.

LLN * LLN::getnext () {return next;}//returns the next node.

void LLN::print() {cout << s << endl;}

void LLN::printall () {  //prints all the nodes in the list starting with me in reverse order

	print ();
	if (next != NULL) next->printall ();

}

void LLN::addback (string S) { //Adds a node (If one does't already exist) into the back of the list.
    string temp1 = S;
    string temp2 = this->s;
    int i = 0;
    while(temp1[i])
    {
        temp1[i] = tolower(temp1[i]);
        i++;
    }
    i = 0;
    while(temp2[i])
    {
        temp2[i] = tolower(temp2[i]);
        i++;
    }
    if (temp2 == temp1) return;
	if (next==NULL) next = new LLN (S,NULL);
	else next->addback (S);
}

void LLN::setnext (LLN *n) {next = n;} //Sets the next node in the list.

void LLN::addinorder (string S) { //Adds a node in alphabetical order. We do a check here to determine whether or not the node we're probing for exists.
    string tempS = this->gets();
    for (int i = 0; i < S.length(); i++)
    {
        S[i] = tolower(S[i]);
    }
    for (int i = 0; i < tempS.length(); i++)
    {
        tempS[i] = tolower(tempS[i]);
    }
    if (!next || S < next->gets()){
    next = new LLN (S,next);
    }
	else
		next->addinorder (S);

}

LLN * LLN::addinorder_0 (string S) { //returns the "new head" of the portion of the linked list beginning with this

	if (s > S) return new LLN (S,this);
	if (!next) {next = new LLN (S,NULL); return this;}
	next = next->addinorder_0 (S);
	return this;
}

LLN * LLN::remove (string S) { //removes the first instance of S, returns the new head

	if (s==S) {
		LLN *t = next;
		next = NULL;
		delete this;
		return t;
	}
	if (next) next = next->remove (S);
	return this;
}

void LLN::remove_0 (string S, LLN *prev, LL *l) {//More complicated version of remove.

	if (s==S) {
		if (prev) prev->setnext (next);
		else l->sethead (next);
	    next = NULL;
		delete this;
	} else
		if (next) next->remove_0 (S,this,l);
}

bool LLN::removelast (string S, LLN *prev, LL *l) { //returns whether something was deleted

	bool del = false;
	if (next) del = next->removelast (S,this,l);
	if (del) return true;
	if (s==S) {
		if (prev) prev->setnext (next);
		else l->sethead (next);
	    next = NULL;
		delete this;
		return true;
	}
	return false;
}

void LLN::addbook(string S) { //Apparently this method isn't getting used, but it would do the same thing that addback would.
	if (s==S) {
	return;
	} else if (next != NULL) {
	next -> addbook(S);
	} else {
	next = new LLN(S,NULL);
	}
}
