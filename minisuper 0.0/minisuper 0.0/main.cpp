#include "bibliotecas.h"
#include "conserva.h"
#include "prodPerecedero.h"
#include "abarrote.h"
#include "embutido.h"

int main() {
	//2
	//cout << "hello world!" << endl;
	
	//producto* ptr1 = new producto("001", "papas", "son papas", 1000, "02", 100, 100);
	//delete ptr1;

	producto* ptr2 = new conserva("002", "miel", "es miel", 1000, "01", 100, 100, true);
	producto* ptr3 = new conserva(*((conserva*)ptr2));
	delete ptr2;
	cout << *ptr3 << endl;
	delete ptr3;


	conserva p1("102", "miel", "es miel", 1000, "01", 100, 100, true);
	conserva p2(p1);
	cout << p2 << endl;


	producto* ptr4 = new prodPerecedero("003", "arroz", "es arroz", 1000, "02", 100, 100, 1, 1, 1, true, 300.5);
	producto* ptr5 = new prodPerecedero(*((prodPerecedero*)ptr4));
	delete ptr4;
	cout << *ptr5;
	delete ptr5;

	prodPerecedero p3("103", "arroz", "es arroz", 1000, "02", 100, 100, 1, 1, 1, true, 300.5);
	prodPerecedero p4(p3);
	cout << p4;

	producto* abarrotePtr = new abarrote("004", "pan", "pan con queso", 650, "02", 100, 100, 1, 1, 1, true, 1.5, "Panaderia de pan");
	producto* aPtr = new abarrote(*((abarrote*)abarrotePtr));
	delete abarrotePtr;
	cout << *aPtr;
	delete aPtr;

	abarrote p5("004", "pan", "pan con queso", 650, "02", 100, 100, 1, 1, 1, true, 1.5, "Panaderia");
	abarrote p6(p5);
	cout << p6;

	producto* embutidoPtr = new embutido("005", "Salami", "Salami de la salada", 1150, "03", 100, 100, 1, 1, 1, true, 0.5, "Cerdo", "Pierna", false, "Iberico");
	producto* ePtr = new embutido((embutido&)*embutidoPtr);
	delete embutidoPtr;
	cout << *ePtr;
	delete ePtr;

	embutido p7("005", "Salami", "Salami de la salada", 1150, "03", 100, 100, 1, 1, 1, true, 0.5, "Cerdo", "Pierna", false, "Iberico");
	embutido p8(p7);
	cout << p8;

	return 0;
}

//Recomendaciones:
/*
-usar los ifndef define endif
-con los accesores booleanos, usar 'is' en lugar de 'get' (isOpen, getOpen)
-usar todos los tipos de constructores hasta evacuar dudas con georges (ver ejemplo en prodPerecedero)

*/


//Dudas:
/*
-porcentaje de ganancia implica creacion de un getGanancia en producto?
-en fecha, se puede usar la fecha default(constructor sin parametros) como fecha actual?

-El DRC del enunciado trae todas los atributos? se pueden modificar?
--en 'producto', se tendria que hacer otro parametro de fecha de ingeso? (segun el DRC)
--en 'perecedero', se tendria que hacer otro parametro de fecha de vencimiento? (segun el DRC)

-En los constructores de sub-clases, se llena el constructor de la clase base con los valores o con un puntero de la clase?
(hice varios posibles constructores, si no se usan, se pueden borrar al final) (ver ejemplo en 'prodPerecedero')

*/

//Posibles exepciones:
/*
-categoria invalida
-fecha invalida
-limite/existencia
-ingreso opcion menu
*/