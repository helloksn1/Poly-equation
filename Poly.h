#ifndef _POLY_H_
#define _POLY_H_

#include <iostream>
#include "Node.h"
#include "List.h"
using namespace std;

class Poly {
private:
	List list;
public:
	Poly();
	Poly(int n, int a[], int e[]);
	~Poly();
	void init(int n, int a[], int e[]);
	int calc(int x);
	Poly operator + (Poly& poly);
	Poly operator - (Poly& poly);
	Poly operator * (Poly &poly);
	friend ostream& operator << (ostream& out, const Poly& poly) {
		Poly temp(poly);
		Node *head = temp.getHead();
		while (head) {
			if (head -> getA() > 0) {
				if (head != temp.getHead()) out << '+';
				if (head -> getA() != 1 || head -> getE() == 0) out << head -> getA();
			} else {
				if (head -> getA() == -1 && head -> getE() != 0) out << '-';
				else out << head -> getA();
			}
			if (head -> getE() > 1) out << "x^" << head -> getE();
			else if (head -> getE() == 1) out << "x";
			head = head -> getNext();
		}
		return out;
	}
	Node* getHead();
	void addNode(int a, int e);
};

#endif
