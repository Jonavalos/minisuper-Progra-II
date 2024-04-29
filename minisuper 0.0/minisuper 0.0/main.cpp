#include "controladora.h"
#include "decoradorProducto.h"
#include "carrito.h"
#include "cliente.h"
#include "venta.h"
#include "ansi_term.h"
int main() {
	//2
	//cout << "hello world!" << endl;
	
	//producto* ptr1 = new producto("001", "papas", "son papas", 1000, "02", 100, 100);
	//delete ptr1;

	/*producto* ptr2 = new conserva("002", "miel", "es miel", 1000, "01", 100, 100, true);
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
	cout << p8;*/

	producto* miel = new conserva("002", "miel", "es miel", 1020, "01", 150, 1, true);	
	producto* arroz = new abarrote("003", "arroz", "es arroz", 1000, "02", 150, 2, 1, 1, 3, true, 300.5, "arroz inc.");
	producto* pan = new abarrote("004", "pan", "pan con queso", 650, "02", 150, 3, 1, 1, 1, true, 1.5, "Panaderia de pan");
	producto* salami = new embutido("005", "Salami", "Salami de la salada", 1150, "03", 100, 5, 1, 1, 1, true, 0.5, "Cerdo", "Pierna", false, "Iberico");

	listaG<producto>* listaGenericaProducto = new listaG<producto>();
	listaGenericaProducto->ingresarUltimo(*miel);
	listaGenericaProducto->ingresarUltimo(*arroz);
	listaGenericaProducto->ingresarUltimo(*pan);
	listaGenericaProducto->ingresarUltimo(*salami);
	

	compraProducto* car1 = new carrito();
	compraProducto* decMiel = new decoradorProducto(car1, miel);
	compraProducto* decArroz = new decoradorProducto(decMiel, arroz);
	compraProducto* decPan = new decoradorProducto(decArroz, pan);
	compraProducto* decSalami= new decoradorProducto(decPan, salami);
	compraProducto* decArroz2 = new decoradorProducto(decSalami, arroz);
	compraProducto* decMiel2 = new decoradorProducto(decArroz2, miel);
	compraProducto* decMiel3 = new decoradorProducto(decMiel2, miel);

	//creando ventas-------
	ContenedorLista* listaVentas1 = new ContenedorLista();
	cliente* client1 = new cliente("1111");
	cliente* client2 = new cliente("2222");	  
						   //cliente, decorador, total, iva
	venta* venta1 = new venta(client1, decPan, 111, 0.13);
	venta* venta2 = new venta(client2, decArroz2, 222, 0.13);
	venta* venta3 = new venta(client1, decSalami, 333, 0.13);
	venta* venta4 = new venta(client2, decMiel3, 444, 0.13);
	listaVentas1->ingresaDeUltimo(*venta1);
	listaVentas1->ingresaDeUltimo(*venta2);
	listaVentas1->ingresaDeUltimo(*venta3);
	listaVentas1->ingresaDeUltimo(*venta4);

	//cout << listaVentas1->toString() << endl;


	controladora co(listaGenericaProducto, listaVentas1);
	co.control0();

	//interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	//interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	//interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	//interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	//interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	//interfaz::crearFact(*listaGenericaProducto, listaVentas1);

	//delete listaGenericaProducto;
	//delete listaVentas1;

	return 0;
}
//TO DO
/*
*/


//Recomendaciones:
/*
-usar los ifndef define endif
-con los accesores booleanos, usar 'is' en lugar de 'get' (isOpen, getOpen)
-usar todos los tipos de constructores hasta evacuar dudas con georges (ver ejemplo en prodPerecedero)
-templates en .h y no .cpp
*/


//Dudas:
/*
-el importe es el total con respecto a las cantidades o con respecto al precio costo de un producto?

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
-opciones menu de la interfaz
-lugar invalido en lista (eliminar inexistente)

*/