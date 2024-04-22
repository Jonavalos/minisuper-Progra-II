#ifndef NODOGENVENTA_H
#define NODOGENVENTA_H
#include "bibliotecas.h"

template<class T>
class nodoGenVenta
{
public:
	nodoGenVenta()
		: _obj(nullptr), _next(nullptr) {}

	nodoGenVenta(T* obj, nodoGenVenta<T>* next)
		: _obj(obj), _next(next) {}

	virtual ~nodoGenVenta() {
		if (_obj != nullptr) {
			delete _obj;
		}
		//elimina por completo, no solo de la lista
	}

	void setObj(T* obj) {
		this->_obj = obj;
	}

	void setNext(nodoGenVenta<T>* next) {
		this->_next = next;
	}

	T* getObj() {
		return _obj;
	}

	nodoGenVenta<T>* getNext() {
		return _next;
	}

private:
	T* _obj;
	nodoGenVenta<T>* _next;

};


#endif // !NODOGENVENTA_H