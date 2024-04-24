#include "controladora.h"
#include "decoradorProducto.h"
#include "carrito.h"
#include "cliente.h"
#include "venta.h"
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

	producto* miel = new conserva("002", "miel", "es miel", 1020, "01", 1, 100, true);	
	producto* arroz = new prodPerecedero("003", "arroz", "es arroz", 1000, "02", 100, 100, 1, 1, 1, true, 300.5);
	producto* pan = new abarrote("004", "pan", "pan con queso", 650, "02", 100, 100, 1, 1, 1, true, 1.5, "Panaderia de pan");
	producto* salami = new embutido("005", "Salami", "Salami de la salada", 1150, "03", 1, 100, 1, 1, 1, true, 0.5, "Cerdo", "Pierna", false, "Iberico");

	listaG<producto>* listaGenericaProducto = new listaG<producto>();
	listaGenericaProducto->ingresarUltimo(*miel);
	listaGenericaProducto->ingresarUltimo(*arroz);
	listaGenericaProducto->ingresarUltimo(*pan);
	listaGenericaProducto->ingresarUltimo(*salami);
	//controladora co(listaGenericaProducto);
	//co.control0();

	/*compraProducto* car1 = new carrito();
	compraProducto* decMiel = new decoradorProducto(car1, miel);
	compraProducto* decArroz = new decoradorProducto(decMiel, arroz);
	compraProducto* decPan = new decoradorProducto(decArroz, pan);
	compraProducto* decSalami= new decoradorProducto(decPan, salami);
	compraProducto* decArroz2 = new decoradorProducto(decSalami, arroz);
	compraProducto* decMiel2 = new decoradorProducto(decArroz2, miel);
	compraProducto* decMiel3 = new decoradorProducto(decMiel2, miel);*/

	//decSalami->setCompraPtr(decPan);
	//decSalami->setProducto(salami);
	//decSalami->setPrecioAcumulado();

	/*cout << decSalami->toString() << endl;
	cout << "precio acumulado: " << endl;
	cout << decSalami->getPrecioAcumulado() << endl;*/

	/*cliente* client1 = new cliente("1111");*/
	/*venta* venta1 = new venta(client1, decMiel3);
	cout << venta1->toString() << endl;*/

	ContenedorLista* listaVentas1 = new ContenedorLista();
	
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);
	interfaz::crearFact(*listaGenericaProducto, listaVentas1);

	/*venta* venta1 = new venta(client1, decMiel3, 23864, 246);
	listaGenericaVenta->ingresaDeUltimo(*venta1);*/
	//cout << listaVentas1->toString();
	cout << listaVentas1->cedulasTop5Clientes();

	delete listaGenericaProducto;
	delete listaVentas1;

	return 0;
}
//TO DO
/*
-verificar que se pueda añadir al carrito segun sus existencias

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