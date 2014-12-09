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

void LL::addfront (string S) {

	head = new LLN (S,head);
}

void LL::addback (string S) {

	if (head==NULL) head = new LLN (S,NULL);
	else head->addback (S);
	//LLN *P = head, *Q = NULL;
	//for (;P!=NULL;Q=P,P=P->getnext());
	////if (Q != NULL) Q->setnext (new LLN (S,NULL));
	////else head->setnext (new LLN (S,NULL));
	//(Q?Q:head)->setnext (new LLN  (S,NULL));
}

void LL::print () {
	
	//for (LLN *P = head; P != NULL; P=P->getnext()) 
	//	P->print ();
	if (head != NULL) head->printall ();
	cout << endl;
}

void LL::addinorder (string S) {

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

void LL::remove (string S) {

	if (!head) return;
	head = head->remove (S);
}

void LL::remove_0 (string S) {

	if (!head) return;
	//if (head->gets () == S) {
	//	LLN *t = head->getnext ();
	//	head->setnext (NULL);
	//	delete head;
	//	head = t;
	//} else
		
	head->remove_0 (S,NULL,this);
}

void LL::sethead (LLN *h) {head = h;}

void LL::addbook (string S) {
	if (head) head->addbook(S);

}
