#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using namespace std;

class Node {
private:
	Node* next;
	int a;
	int e;
public:
	Node(int na, int ne, Node *nnext = NULL);
	void setNext(Node *nnext);
	int getA();
	int getE();
	Node* getNext();
	int calc(int x);
};

#endif
