#ifndef ITERADORLISTAG_H
#define ITERADORLISTAG_H
#include "nodoG.h"
#include "producto.h"
template<class T>
class iteradorListaG
{
public:
	iteradorListaG(nodoG<T>* primero);
	virtual ~iteradorListaG();
	virtual bool masElementos();
	virtual T* proximoElemento();
	virtual string toString() const;

private:
	nodoG<T>* _actual;
	//el iterador apunta a la lista con _actual, itera sobre la lista, y luego se destruye
};


template<class T>
inline iteradorListaG<T>::iteradorListaG(nodoG<T>* primero)
	:_actual(primero){}

template<class T>
inline iteradorListaG<T>::~iteradorListaG()
{}

template<class T>
inline bool iteradorListaG<T>::masElementos()
{
	return _actual != nullptr;
}

template<class T>
inline T* iteradorListaG<T>::proximoElemento()
{
	T* obj = nullptr;
	if (masElementos()) {
		obj = _actual->getObj();
		_actual = _actual->getNext();
	}
	return obj;
}

template<class T>
inline string iteradorListaG<T>::toString() const
{
	return "";
}



#endif // !ITERADORLISTAG_H