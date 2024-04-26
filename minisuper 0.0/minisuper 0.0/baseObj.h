#ifndef BASOBJ_H
#define BASOBJ_H
#include "bibliotecas.h"

class baseObj
{
public:
	virtual ~baseObj(){}
	virtual string toString() const = 0;



};


#endif // !BASOBJ_H

