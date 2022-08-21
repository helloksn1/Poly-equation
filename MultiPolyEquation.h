#ifndef _MULTIPOLYEQUATION_H_
#define _MULTIPOLYEQUATION_H_

#include <iostream>
#include "Poly.h"

using namespace std;

class MultiPolyEquation {
private:
	int n;
	Poly poly[100];
	char opr[100];
public:
	MultiPolyEquation();
	MultiPolyEquation(int nn, Poly npoly[], char nopr[]);
	Poly calc();
	friend ostream& operator << (ostream& out, MultiPolyEquation& mpe) {
		for (int i = 0; i < mpe.n; i++) {
			if (!(i == 0 && mpe.opr[i] == '+')) out << mpe.opr[i];
			out << "(" << mpe.poly[i] << ")";
		}
		return out;
	}
};

#endif
