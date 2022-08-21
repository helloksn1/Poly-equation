#include <iostream>
#include "Node.h"
#include "List.h"
#include "Poly.h"

using namespace std;

Poly::Poly() {
}

Poly::Poly(int n, int a[], int e[]) {
	for (int i = 0; i < n; i++) {
		list.add(a[i], e[i]);
	}
}

Poly::~Poly() {
}

void Poly::init(int n, int a[], int e[]) {
	for (int i = 0; i < n; i++) {
		list.add(a[i], e[i]);
	}
}

int Poly::calc(int x) {
	Node *head = list.getHead();
	int res = 0;
	while (head) {
		res += head -> calc(x);
		head = head -> getNext();
	}
	return res;
}

Poly Poly::operator + (Poly& poly) {
	Poly res;
	Node *head0 = list.getHead(), *head1 = poly.list.getHead();
	while (head0 || head1) {
		if (!head0) {
			res.list.add(head1);
			head1 = head1 -> getNext();
		} else if (!head1) {
			res.list.add(head0);
			head0 = head0 -> getNext();
		} else if (head0 -> getE() == head1 -> getE()) {
			if (head0 -> getA() + head1 -> getA() != 0)
				res.list.add(head0 -> getA() + head1 -> getA(), head0 -> getE());
			head0 = head0 -> getNext();
			head1 = head1 -> getNext();
		} else if (head0 -> getE() > head1 -> getE()) {
			res.list.add(head0);
			head0 = head0 -> getNext();
		} else {
			res.list.add(head1);
			head1 = head1 -> getNext();
		}
	}
	return res;
}

Poly Poly::operator - (Poly& poly) {
	Poly res;
	Node *head0 = list.getHead(), *head1 = poly.list.getHead();
	while (head0 || head1) {
		if (!head0) {
			res.list.add(-head1 -> getA(), head1 -> getE());
			head1 = head1 -> getNext();
		} else if (!head1) {
			res.list.add(head0);
			head0 = head0 -> getNext();
		} else if (head0 -> getE() == head1 -> getE()) {
			if (head0 -> getA() - head1 -> getA() != 0)
				res.list.add(head0 -> getA() - head1 -> getA(), head0 -> getE());
			head0 = head0 -> getNext();
			head1 = head1 -> getNext();
		} else if (head0 -> getE() > head1 -> getE()) {
			res.list.add(head0);
			head0 = head0 -> getNext();
		} else {
			res.list.add(-head1 -> getA(), head1 -> getE());
			head1 = head1 -> getNext();
		}
	}
	return res;
}

Poly Poly::operator * (Poly &poly) {
	Poly res;
	Node *phead = poly.list.getHead();
	while (phead) {
		Poly cur;
		Node *thead = list.getHead();
		while (thead) {
			cur.list.add(thead -> getA() * phead -> getA(), thead -> getE() + phead -> getE());
			thead = thead -> getNext();
		}
		res = res + cur;
		phead = phead -> getNext();
	}
	return res;
}

Node* Poly::getHead() {
	return list.getHead();
}

void Poly::addNode(int a, int e) {
	list.add(a, e);
}
