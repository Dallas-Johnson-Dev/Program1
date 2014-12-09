#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
#include "LLN.h"
using namespace std;

LL::LL () {

	//cout << "Welcome to the constructor" << endl;
	head = NULL;
}

LL::~LL () {

	//cout << "Depart from mine presence, thou fool" << endl;
	delete head;
}

void LL::addfront (string S) {//This starts the recursive method for LLN::AddFront

	head = new LLN (S,head);
}

void LL::addback (string S) {//This also starts the recursive method for LLN::AddBack. Neither front or back return anything.

	if (head==NULL) head = new LLN (S,NULL);
	else head->addback (S);
	//LLN *P = head, *Q = NULL;
	//for (;P!=NULL;Q=P,P=P->getnext());
	////if (Q != NULL) Q->setnext (new LLN (S,NULL));
	////else head->setnext (new LLN (S,NULL));
	//(Q?Q:head)->setnext (new LLN  (S,NULL));
}

void LL::print () {//Uses printall to recursively print out everything in the list.

	//for (LLN *P = head; P != NULL; P=P->getnext())
	//	P->print ();
	if (head != NULL) head->printall ();
	cout << endl;
}

void LL::addinorder (string S) {//Starts the process for adding in alphabetical order.

	if (!head) head = new LLN (S,NULL);
	else head = head->addinorder_0 (S);

	//LLN *P = head, *Q = NULL;
	//for (;P && P->gets() < S; Q=P,P=P->getnext());
	//if (Q) Q->setnext (new LLN (S,P));
	//else head = new LLN (S,P);

	//if (!head || head->gets() > S)
	//	head = new LLN (S,head);
	//else
	//	head->addinorder (S);
}

void LL::remove (string S) {//Top level method for removing something from our list. We run a check with S to determine what to nuke.

	if (!head) return;
	head = head->remove (S);
}

void LL::remove_0 (string S) {//The more complicated remove method, but essentially the top level method to beign the recursive function for it.

	if (!head) return;
	//if (head->gets () == S) {
	//	LLN *t = head->getnext ();
	//	head->setnext (NULL);
	//	delete head;
	//	head = t;
	//} else

	head->remove_0 (S,NULL,this);
}

void LL::sethead (LLN *h) {head = h;}//sets the head of our list.

void LL::addbook (string S) {//This is an unused method, but it functions similarly to addback, only addback is what is being used.
	if (head) head->addbook(S);

}
