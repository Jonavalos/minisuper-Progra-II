#include "controladora.h"
#include "decoradorProducto.h"
#include "carrito.h"
#include "cliente.h"
#include "venta.h"

int main() {

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
						   //cliente, decorador, total, iva			cant
	venta* venta1 = new venta(client1, decPan, 1762.8, 169);		//2
	venta* venta2 = new venta(client2, decArroz2, 1356, 130);		//1
	venta* venta3 = new venta(client1, decSalami, 6757.4, 598);		//4
	venta* venta4 = new venta(client2, decMiel3, 3976.47, 397.8);	//3
	listaVentas1->ingresaDeUltimo(*venta1);
	listaVentas1->ingresaDeUltimo(*venta2);
	listaVentas1->ingresaDeUltimo(*venta3);
	listaVentas1->ingresaDeUltimo(*venta4);

	//guardar--------
	//fstream strm1("../listaVentas.txt", ios::out);
	//if (strm1.good()) {
	//	listaVentas1->guardar(strm1);
	//	strm1.close();
	//}
	//cout << "***********************" << endl;
	//cout << "***********************" << endl;

	////recuperar-----
	//fstream strm2("../listaVentas.txt", ios::in);
	//if (strm2.good()) {
	//	cout << ContenedorLista::recuperar(strm2)->toString() << endl;
	//	strm2.close();
	//}


	controladora co(listaGenericaProducto, listaVentas1);
	co.control0();

	//delete listaGenericaProducto;
	//delete listaVentas1;

	return 0;
}