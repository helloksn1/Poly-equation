#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Poly.h"
#include "MultiPolyEquation.h"
#include "ManageFile.h"

using namespace std;

ManageFile::ManageFile() {
}

ManageFile::~ManageFile() {
}

ManageFile::ManageFile(char nin[], char nout[]) {
	strcpy_s(in, nin);
	strcpy_s(out, nout);
}

void ManageFile::setInFile(char nin[]) {
	strcpy_s(in, nin);
}

void ManageFile::setOutFile(char nout[]) {
	strcpy_s(out, nout);
}

void ManageFile::write(Poly& poly) {
	fstream fs(out, ios::out);
	Node *head = poly.getHead();
	while (head) {
		if (head -> getA() > 0) {
			if (head != poly.getHead()) fs << '+';
			if (head -> getA() != 1 || head -> getE() == 0) fs << head -> getA();
		} else {
			if (head -> getA() == -1 && head -> getE() != 0) fs << '-';
			else fs << head -> getA();
		}
		if (head -> getE() > 1) fs << "x^" << head -> getE();
		else if (head -> getE() == 1) fs << "x";
		head = head -> getNext();
	}
	fs << endl;
	fs.close();
}

Poly ManageFile::readSimple(char str[]) {
	int idx = 0;
	Poly res;
	while (str[idx]) {
		int pm = 1, a = 0;
		if (str[idx] == '+') {
			idx++;
			pm = 1;
		} else if (str[idx] == '-') {
			idx++;
			pm = -1;
		}
		if (str[idx] < '0' || str[idx] > '9') a = 1;
		else {
			while (str[idx] >= '0' && str[idx] <= '9') {
				a = a * 10 + str[idx] - '0';
				idx++;
			}
		}
		int e = 0;
		if (str[idx] == 'x') {
			e = 1;
			idx++;
		}
		if (str[idx] == '^') {
			e = 0;
			idx++;
		}
		while (str[idx] >= '0' && str[idx] <= '9') {
			e = e * 10 + str[idx] - '0';
			idx++;
		}
		res.addNode(pm * a, e);
	}
	return res;
}

Poly ManageFile::readSimple() {
	fstream fs(in, ios::in);
	char str[100];
	fs >> str;
	fs.close();
	return readSimple(str);
}

MultiPolyEquation ManageFile::read() {
	fstream fs(in, ios::in);
	char str[100] = {0};
	int i;

	fs >> str;
	fs.close();
	int idx = 0;
	Poly poly[100];
	char opr[100];
	int cnt = 0;

	while (str[idx]) {
		i = 0;
		if (idx == 0) opr[cnt] = '+';
		else {
			opr[cnt] = str[idx];
			idx++;
		}
		idx++;
		char cur[100] = {0};
		while (str[idx] != ')') {
			cur[i++] = str[idx++];
		}
		idx++;
		poly[cnt] = readSimple(cur);
		cnt++;
	}
	return MultiPolyEquation(cnt, poly, opr);
}