#ifndef PRODPERECEDERO_H
#define PRODPERECEDERO_H
#include "producto.h"

class prodPerecedero: public producto
{
public:
	prodPerecedero(); //con datos de fecha, con puntero a fecha, con puntero a atributo. Ver dudas en main.cpp
	virtual ~prodPerecedero();
	prodPerecedero(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, int dia, int mes, int anio, bool nacional, double peso);	
	prodPerecedero(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, fecha* fechaP, bool nacional, double peso);
	prodPerecedero(const prodPerecedero& obj);

	virtual string toString() const;

	//persistencia de datos

	virtual void guardar(fstream& strm) {

		strm << _categoria << SEPARA_VALOR;
		strm << _codigo << SEPARA_VALOR;
		strm << _nombreComercial << SEPARA_VALOR;

		strm << _descripcion << SEPARA_VALOR;
		strm << _precioCosto << SEPARA_VALOR;
		strm << _existencia << SEPARA_VALOR;
		strm << _limite << SEPARA_VALOR;

		strm << _nacional << SEPARA_VALOR;
		strm << _peso << SEPARA_VALOR;

		strm << _fechaPtr->getDia() << SEPARA_VALOR;
		strm << _fechaPtr->getMes() << SEPARA_VALOR;
		strm << _fechaPtr->getAnio() << SEPARA_REGISTRO;


	}

	static producto* recuperar(fstream& strm) {
		string categStr = "", codStr = "", nomStr = "", descrStr = "",
			precCoStr = "", exiStr = "", limitStr = "",
			nacStr = "", pesStr = "", diaStr = "", mesStr = "", anioStr = "";

		//getline(strm, categStr, SEPARA_VALOR); //se recupera en lista
		getline(strm, codStr, SEPARA_VALOR);
		getline(strm, nomStr, SEPARA_VALOR);
		getline(strm, descrStr, SEPARA_VALOR);
		getline(strm, precCoStr, SEPARA_VALOR);

		getline(strm, exiStr, SEPARA_VALOR);
		getline(strm, limitStr, SEPARA_VALOR);

		getline(strm, nacStr, SEPARA_VALOR);
		getline(strm, pesStr, SEPARA_VALOR);
		
		getline(strm, diaStr, SEPARA_VALOR);
		getline(strm, mesStr, SEPARA_VALOR);
		getline(strm, anioStr, SEPARA_REGISTRO);

		if (precCoStr == "" || exiStr == "" || limitStr == "" || nacStr == "" || pesStr=="" || diaStr=="" || mesStr =="" || anioStr=="") {
			return nullptr;
		}

		double precioCosto = convertirDouble(precCoStr);
		int existencia = convertirInt(exiStr);
		int limite = convertirInt(limitStr);

		bool nacional = false;
		if (nacStr == "1") {
			nacional = true;
		}
		double peso = convertirDouble(pesStr);
		int dia = convertirInt(diaStr);
		int mes = convertirInt(mesStr);
		int anio = convertirInt(anioStr);

		return new prodPerecedero(codStr, nomStr, descrStr, precioCosto, "02", existencia, limite, dia, mes, anio, nacional, peso);

	}



protected:
	bool _nacional;
	double _peso;
	fecha* _fechaPtr;
};


#endif // !PRODPERECEDERO_H


