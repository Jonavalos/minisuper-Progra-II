#ifndef CONSERVA_H
#define CONSERVA_H
#include "producto.h"
class conserva: public producto
{
public:
	conserva();
	virtual ~conserva();
	conserva(string codigo, string nombreComercial, string descripcion, double precioCosto, string categoria, int existencia, int limite, bool envasado);
	conserva(const conserva& obj);
	
	virtual string toString() const;

	virtual void guardar(fstream& strm) {
		strm << _categoria << SEPARA_VALOR;
		strm << _codigo << SEPARA_VALOR;
		strm << _nombreComercial << SEPARA_VALOR;

		strm << _descripcion << SEPARA_VALOR;
		strm << _precioCosto << SEPARA_VALOR;
		strm << _existencia << SEPARA_VALOR;
		strm << _limite << SEPARA_VALOR;

		strm << _envasado << SEPARA_REGISTRO;
	}

	static producto* recuperar(fstream& strm) {
		string categStr = "", codStr = "", nomStr = "", descrStr = "", 
			precCoStr = "", exiStr = "", limitStr = "", envaStr = "";

		//getline(strm, categStr, SEPARA_VALOR); //se recupera en lista
		getline(strm, codStr, SEPARA_VALOR);
		getline(strm, nomStr, SEPARA_VALOR);
		getline(strm, descrStr, SEPARA_VALOR);
		getline(strm, precCoStr, SEPARA_VALOR);

		getline(strm, exiStr, SEPARA_VALOR);
		getline(strm, limitStr, SEPARA_VALOR);
		getline(strm, envaStr, SEPARA_REGISTRO);

		if (precCoStr == "" || exiStr == "" || limitStr == "" || envaStr == "") {
			return nullptr;
		}
			
		double precioCosto = convertirDouble(precCoStr);
		int existencia = convertirInt(exiStr);
		int limite = convertirInt(limitStr);

		bool envasado = false;
		if (envaStr == "1") {
			envasado = true;
		}
			
		return new conserva(codStr, nomStr, descrStr, precioCosto, "01", existencia, limite, envasado);

	}


private:
	bool _envasado;

};

#endif // !CONSERVA_H



