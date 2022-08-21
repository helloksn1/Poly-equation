#ifndef _MANAGEFILE_H_
#define _MANAGEFILE_H_

#include <iostream>
#include "Poly.h"
#include "MultiPolyEquation.h"

using namespace std;

class ManageFile {
private:
	char in[100];
	char out[100];
public:
	ManageFile();
	~ManageFile();
	ManageFile(char nin[], char nout[]);
	void setInFile(char nin[]);
	void setOutFile(char nout[]);
	void write(Poly& poly);
	static Poly readSimple(char str[]);
	Poly readSimple();
	MultiPolyEquation read();
};

#endif