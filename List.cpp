#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

List::List() {
	head = NULL;
}

List::List(const List& list) {
	Node *lhead = list.head, *tail = NULL;
	while (lhead) {
		Node *copyed = new Node(lhead -> getA(), lhead -> getE());
		if (lhead != list.head) tail -> setNext(copyed);
		else head = copyed;
		tail = copyed;
		lhead = lhead -> getNext();
	}
}

List List::operator = (const List& list) {
	deleteAll();
	Node *lhead = list.head, *tail = NULL;
	while (lhead) {
		Node *copyed = new Node(lhead -> getA(), lhead -> getE());
		if (lhead != list.head) tail -> setNext(copyed);
		else head = copyed;
		tail = copyed;
		lhead = lhead -> getNext();
	}
	return *this;
}

List::~List() {
	deleteAll();
}

void List::deleteAll() {
	Node *t = head;
	while (head) {
		t = head -> getNext();
		delete head;
		head = t;
	}
}

void List::add(int na, int ne) {
	Node* nnode = new Node(na, ne);
	if (head == NULL) {
		head = nnode;
	} else {
		Node *tail = head;
		while (tail -> getNext()) tail = tail -> getNext();
		tail -> setNext(nnode);
	}
}

void List::add(Node *node) {
	Node* nnode = new Node(node -> getA(), node -> getE());
	if (head == NULL) {
		head = nnode;
	} else {
		Node *tail = head;
		while (tail -> getNext()) tail = tail -> getNext();
		tail -> setNext(nnode);
	}
}

void List::remove() {
	Node *t = head;
	if (head) head = head -> getNext();
	delete t;
}

Node* List::getHead() {
	return head;
}
