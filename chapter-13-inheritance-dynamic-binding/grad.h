#ifndef GRAD_H
#define GRAD_H

#include "core.h"

class Grad: public Core {
public:
	// both constructors impilicity use Core::Core() to initialize the base part
	Grad(): thesis(0) {}
	Grad(std::istream& is) { read(is); }
	double grade() const;
	std::istream& read(std::istream&);
protected:
	Grad* clone() const { return new Grad(*this); }
private:
	double thesis;
};

#endif