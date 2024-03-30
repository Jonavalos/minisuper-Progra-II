#ifndef EMPAQUE_H
#define EMPAQUE_H
#include "bibliotecas.h"

class empaque
{

public:

	empaque();
	empaque(bool tripa);
	empaque(const empaque& obj);
	virtual ~empaque();

	bool getTripa();

	virtual string toString() const;

private:

	bool _tripa;

};

#endif // !EMPAQUE_H