#ifndef NODOG_H
#define NODOG_H
#include "bibliotecas.h"

template<class T>
class nodoG
{
public:
	nodoG()
		: _obj(nullptr), _next(nullptr) {}

	nodoG(T* obj, nodoG<T>* next)
		: _obj(obj), _next(next) {}

	virtual ~nodoG() {
		if (_obj != nullptr) {
			delete _obj;
		}
		//elimina por completo, no solo de la lista
	}

	void setObj(T* obj) {
		this->_obj = obj;
	}

	void setNext(nodoG<T>* next) {
		this->_next = next;
	}

	T* getObj() {
		if (_obj!=nullptr) {
			return _obj;
		}
		return nullptr;
	}

	nodoG<T>* getNext() {
		return _next;
	}

private:
	T* _obj;
	nodoG<T>* _next;

};


#endif // !NODOG_H


