#ifndef LISTAG_H
#define LISTAG_H
#include "nodoG.h"

template <class T>
class listaG
{
public:
	listaG();
	virtual ~listaG();

	bool existe(const T& obj);
	void ingresarPrimero(const T& obj);
	void ingresarUltimo(const T& obj);

	nodoG<T*> getNodoLugar(int lugar);
	bool eliminarLugar(int lugar);

	string toString();

private:
	nodoG<T>* head;

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


template<class T>
inline listaG<T>::listaG()
{
	head = nullptr;
}

template<class T>
inline listaG<T>::~listaG()
{
	nodoG<T>* pex = head;
	while (head != nullptr) {
		head = head->getNext();
		delete pex;
		pex = head;
	}

}

template<class T>
inline bool listaG<T>::existe(const T& obj)
{
	nodoG<T>* pex = head;
	while (pex != nullptr) {
		if (pex->getObj() == obj) {
			return true;
		}
		pex = pex->getNext();
	}
	return false;
}

template<class T>
inline void listaG<T>::ingresarPrimero(const T& obj)
{
	head = new nodoG<T>((T*)&obj, head);
}

template<class T>
inline void listaG<T>::ingresarUltimo(const T& obj)
{
	nodoG<T>* pex = head;
	nodoG<T>* nuevo = nullptr;

	if (head == nullptr) {
		ingresarPrimero(obj);
	}
	else {
		while (pex->getNext() != nullptr) {
			pex = pex->getNext();
		}
		nuevo = new nodoG<T>((T*)&obj, nullptr);
		pex->setNext(nuevo);
	}

}

template<class T>
inline nodoG<T*> listaG<T>::getNodoLugar(int lugar)
{
	nodoG<T*> pex = head;
	int n = 0;

	if (lugar == 1) {
		return pex;
	}
	else {
		while (n + 1 < lugar && pex != nullptr) {
			pex = pex.getNext();
			n++;
		}
		if (n + 1 == lugar) {
			return pex;
		}
		if (pex == nullptr) {
			return nullptr;
		}
	}

}

template<class T>
inline bool listaG<T>::eliminarLugar(int lugar)
{
	nodoG<T>* pex = head;
	nodoG<T>* victima = nullptr;
	int n = 1;

	if (lugar == 1) {
		victima = head;
		head = head->getNext();
		delete victima;
		return true;
	}
	else {
		while (pex->getNext() != nullptr) {
			if (n + 1 == lugar) {
				victima = pex->getNext();
				pex->setNext(victima->getNext());
				delete victima;
				return true;
			}
			n++;
			pex = pex->getNext();
		}
	}
	return false;

}

template<class T>
inline string listaG<T>::toString()
{
	stringstream s;
	nodoG<T>* pex = head;
	int n = 1;
	while (pex != nullptr) {
		s << n << " - " << *pex->getObj() << endl;
		pex = pex->getNext();
		n++;
	}

	return s.str();
}



#endif // !LISTAG_H

