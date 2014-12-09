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

string LLN::gets () {return s;}

LLN * LLN::getnext () {return next;}

void LLN::print() {cout << s << endl;}

void LLN::printall () {  //prints all the nodes in the list starting with me in reverse order

	print ();
	if (next != NULL) next->printall ();

}

void LLN::addback (string S) {

	if (next==NULL) next = new LLN (S,NULL);
	else next->addback (S);
}

void LLN::setnext (LLN *n) {next = n;}

void LLN::addinorder (string S) {

	if (!next || next->gets() > S) 
		next = new LLN (S,next);
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

void LLN::remove_0 (string S, LLN *prev, LL *l) {

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

void LLN::addbook(string S) {
	if (s==S) {
	return;
	} else if (next != NULL) {
	next -> addbook(S);
	} else {
	next = new LLN(S,NULL);
	}
}
