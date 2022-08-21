#include <iostream>
#include "MultiPolyEquation.h"
#include "Poly.h"

using namespace std;

MultiPolyEquation::MultiPolyEquation() {
	n = 0;
}

MultiPolyEquation::MultiPolyEquation(int nn, Poly npoly[], char nopr[]) {
	n = nn;
	for (int i = 0; i < n; i++) {
		poly[i] = npoly[i];
		opr[i] = nopr[i];
	}
}

Poly MultiPolyEquation::calc() {
	Poly res;
	for (int i = 0; i < n;) {
		Poly term = poly[i];
		char topr = opr[i];
		i++;
		while (i < n && opr[i] == '*') {
			term = term * poly[i];
			i++;
		}
		if (topr == '+')
			res = res + term;
		else
			res = res -  term;
	}
	return res;
}
