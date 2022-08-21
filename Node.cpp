#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int na, int ne, Node *nnext) {
	a = na;
	e = ne;
	next = nnext;
}

void Node::setNext(Node *nnext) {
	next = nnext;
}

int Node::getA() {
	return a;
}

int Node::getE() {
	return e;
}

Node* Node::getNext() {
	return next;
}

int Node::calc(int x) {
	int res = a, i;
	for (i = 0; i < e; i++)
		res *= x;
	return res;
}
