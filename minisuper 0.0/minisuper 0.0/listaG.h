#ifndef LISTAG_H
#define LISTAG_H
#include "nodoG.h"
#include "iteradorListaG.h"
template <class T>
class listaG
{
public:
	listaG();
	virtual ~listaG();

	bool existe(const T& obj);
	void ingresarPrimero(const T& obj);
	void ingresarUltimo(const T& obj);

	//nodoG<T>* getNodoLugar(int lugar);
	T* getObjLugar(int lugar);
	bool eliminarLugar(int lugar);
	int getCant();

	string toString() const;

	friend ostream& operator <<(ostream& COUT, const listaG& obj) {
		COUT << obj.toString() << endl;
		return COUT;
	}

	//
	virtual iteradorListaG<T>* getIterador() const {
		return new iteradorListaG<T>(head);
	}

private:
	nodoG<T>* head;

	//template<class T>//hacer private
	nodoG<T>* getNodoLugar(int lugar)
	{
		nodoG<T>* pex = head;
		int n = 0;

		if (lugar == 1) {
			return pex;
		}
		else {
			while (n + 1 < lugar && pex != nullptr) {
				pex = pex->getNext();
				n++;
			}
			if (n + 1 == lugar && pex != nullptr) {
				return pex;
			}
			if (pex == nullptr) {
				return nullptr;
			}
		}
		return nullptr;
	}
};

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
inline T* listaG<T>::getObjLugar(int lugar)
{
	return getNodoLugar(lugar)->getObj();
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
inline int listaG<T>::getCant()
{
	nodoG<T>* pex = head;
	int n = 0;

	while (pex != nullptr) {
		n++;
		pex = pex->getNext();
	}

	return n;
}

template<class T>
inline string listaG<T>::toString() const
{
	stringstream s;
	int n = 1;
	iteradorListaG<T>* i = getIterador();
	s << " ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ LISTA ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ " << endl;
	while (i->masElementos()) {
		s << n << " -> " << endl;
		s << *(i->proximoElemento()) << endl;
		n++;
	}
	s << " ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ " << endl;
	delete i;
	return s.str();
}


#endif // !LISTAG_H


