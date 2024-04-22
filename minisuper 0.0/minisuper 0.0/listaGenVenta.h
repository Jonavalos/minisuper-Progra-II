#ifndef LISTAGENVENTA_H
#define LISTAGENVENTA_H
#include "nodoGenVenta.h"

template <class T>
class listaGenVenta
{
public:
	listaGenVenta();
	virtual ~listaGenVenta();

	bool existe(const T& obj);
	void ingresarPrimero(const T& obj);
	void ingresarUltimo(const T& obj);

	nodoGenVenta<T>* getNodoLugar(int lugar);
	T* getObjLugar(int lugar);
	bool eliminarLugar(int lugar);
	int getCant();

	string toString() const;

	friend ostream& operator <<(ostream& COUT, const listaGenVenta& obj) {
		COUT << obj.toString() << endl;
		return COUT;
	}



private:
	nodoGenVenta<T>* head;

};

template<class T>
inline listaGenVenta<T>::listaGenVenta()
{
	head = nullptr;
}

template<class T>
inline listaGenVenta<T>::~listaGenVenta()
{
	nodoGenVenta<T>* pex = head;
	while (head != nullptr) {
		head = head->getNext();
		delete pex;
		pex = head;
	}

}

template<class T>
inline bool listaGenVenta<T>::existe(const T& obj)
{
	nodoGenVenta<T>* pex = head;
	while (pex != nullptr) {
		if (pex->getObj() == obj) {
			return true;
		}
		pex = pex->getNext();
	}
	return false;
}

template<class T>
inline void listaGenVenta<T>::ingresarPrimero(const T& obj)
{
	head = new nodoGenVenta<T>((T*)&obj, head);
}

template<class T>
inline void listaGenVenta<T>::ingresarUltimo(const T& obj)
{
	nodoGenVenta<T>* pex = head;
	nodoGenVenta<T>* nuevo = nullptr;

	if (head == nullptr) {
		ingresarPrimero(obj);
	}
	else {
		while (pex->getNext() != nullptr) {
			pex = pex->getNext();
		}
		nuevo = new nodoGenVenta<T>((T*)&obj, nullptr);
		pex->setNext(nuevo);
	}

}

template<class T>//hacer private
inline nodoGenVenta<T>* listaGenVenta<T>::getNodoLugar(int lugar)
{
	nodoGenVenta<T>* pex = head;
	int n = 0;

	if (lugar == 1) {
		return pex;
	}
	else {
		while (n + 1 < lugar && pex != nullptr) {
			pex = pex->getNext();
			n++;
		}
		if (n + 1 == lugar) {
			return pex;
		}
		if (pex == nullptr) {
			return nullptr;
		}
	}
	return nullptr;
}

template<class T>
inline T* listaGenVenta<T>::getObjLugar(int lugar)
{
	return getNodoLugar(lugar)->getObj();
}

template<class T>
inline bool listaGenVenta<T>::eliminarLugar(int lugar)
{
	nodoGenVenta<T>* pex = head;
	nodoGenVenta<T>* victima = nullptr;
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
inline int listaGenVenta<T>::getCant()
{
	nodoGenVenta<T>* pex = head;
	int n = 0;

	while (pex != nullptr) {
		n++;
		pex = pex->getNext();
	}

	return n;
}

template<class T>
inline string listaGenVenta<T>::toString() const
{
	stringstream s;
	nodoGenVenta<T>* pex = head;
	int n = 1;
	s << " ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ LISTA ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ " << endl;
	while (pex != nullptr) {
		s << n << " -> " << endl;
		s << *pex->getObj() << endl;
		pex = pex->getNext();
		n++;
	}
	s << " ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ " << endl;
	return s.str();
}


#endif // !LISTAGENVENTA_H