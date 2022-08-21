#include <iostream>
#include "Node.h"
#include "List.h"
#include "Poly.h"
#include "MultiPolyEquation.h"
#include "ManageFile.h"

using namespace std;

int main() {
	int a0[] = {1, 1, 1, 1};
	int e0[] = {3, 2, 1, 0};
	int a1[] = {1, 1, 1};
	int e1[] = {4, 3, 2};
	int a2[] = {1, 2, 3, 4, 5};
	int e2[] = {4, 3, 2, 1, 0};

	Poly p0, p1, p2;
	p0.init(4, a0, e0);
	p1.init(3, a1, e1);
	p2.init(5, a2, e2);

	cout << "p0(x)=" << p0 << endl;
	cout << "p1(x)=" << p1 << endl;
	cout << "p2(x)=" << p2 << endl;
	cout << endl;

	Poly add00 = p0 + p1;
	cout << "p0(x)+p1(x)=" << add00 << endl;
	Poly mis00 = p0 - p1;
	cout << "p0(x)-p1(x)=" << mis00 << endl;
	Poly mut00 = p0 * p1;
	cout << "p0(x)*p1(x)=" << mut00 << endl; 
	cout << endl;

	Poly add02 = p0 + p2;
	cout << "p0(x)+p2(x)=" << add02 << endl;
	Poly mis02 = p0 - p2;
	cout << "p0(x)-p1(x)=" << mis02 << endl;
	Poly mut02 = p0 * p2;
	cout << "p0(x)*p2(x)=" << mut02 << endl; 
	cout << endl;

	char atxt[] = "a.txt";
	ManageFile mf;
	mf.setOutFile(atxt);
	mf.write(mut00);
	cout << "Saved p0(x)*p1(x) to a.txt" << endl;
	mf.setInFile(atxt);
	cout << "Read from a.txt: " << mf.readSimple() << endl;

	char b0txt[] = "b0.txt";
	mf.setInFile(b0txt);
	MultiPolyEquation b0 = mf.read();
	cout << "Content of b0.txt: " << b0 << endl;
	cout << "Calculation result of b0.txt: b0(x)=" << b0.calc() << endl;
	cout << endl;

	cout << "p0(3)=" << p0.calc(3) << endl;
	cout << "b0(3)=" << b0.calc().calc(3) << endl;
	cout << endl;

	char b1txt[] = "b1.txt";
	mf.setInFile(b1txt);
	MultiPolyEquation b1 = mf.read();
	cout << "Content of b1.txt: " << b1 << endl;
	cout << "Calculation result of b1.txt: b1(x)=" << b1.calc() << endl;
	cout << endl;

	cout << "b1(5)=" << b1.calc().calc(5) << endl;

	char b2txt[] = "b2.txt";
	mf.setInFile(b2txt);
	MultiPolyEquation b2 = mf.read();
	cout << "Content of b2.txt: " << b2 << endl;
	cout << "Calculation result of b2.txt: b2(x)=" << b2.calc() << endl;
	cout << endl;

	cout << "b2(2)=" << b2.calc().calc(2) << endl;
	return 0;
}
