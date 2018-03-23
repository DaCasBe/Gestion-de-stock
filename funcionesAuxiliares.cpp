/*!
	\file   funcionesAuxiliares.hpp
	\brief  C�digo de las funciones auxiliares del programa principal del almac�n
	\author Daniel Castillo Bello
	\date   13-10-2017
*/

#include <iostream>
#include <string>

#include "funcionesAuxiliares.hpp"
#include "item.hpp"

#include "macros.hpp"

int menu(){
	int opcion;
	int posicion;

	//Se muestran las opciones del men�
	posicion=8;

	//Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
   	std::cout << BBLUE;
	std::cout << "Programa principial | Opciones del men�   ";
	std::cout << RESET;

	LUGAR(posicion++,10);
	std::cout << IGREEN << "[1] Comprobar si el almac�n est� vac�o";

	LUGAR(posicion++,10);
	std::cout << "[2] Cargar el almac�n de un fichero";

	LUGAR(posicion++,10);
	std::cout << "[3] Grabar el almac�n en un fichero";

	LUGAR(posicion++,10);
	std::cout << "[4] Consultar datos del almac�n: c�digo, nombre, lista de items";

	LUGAR(posicion++,10);
	std::cout << "[5] Modificar datos del almac�n: c�digo o nombre";

	LUGAR(posicion++,10);
	std::cout << "[6] Borrar el almac�n";

	LUGAR(posicion++,10);
	std::cout << "[7] Consultar el almac�n";

	LUGAR(posicion++,10);
	std::cout << "[8] Insertar un item";

	LUGAR(posicion++,10);
	std::cout << "[9] Modificar un item";

	LUGAR(posicion++,10);
	std::cout << "[10] Borrar un item";

	LUGAR(posicion++,10);
	std::cout << GREEN << "[0] Salir";

	LUGAR(posicion++,20);
	std::cout << IYELLOW;
	std::cout << "Opci�n: ";
	std::cout << RESET;

	//Se lee el n�mero de opci�n
	std::cin >> opcion;

	//Se elimina el salto de l�nea del flujo de entrada
	std::cin.ignore();

	return opcion;
}

void comprobarAlmacenVacio(Almacen const &almacen){
	std::cout << std::endl << IPURPLE "El almac�n de nombre < " << almacen.getNombre() << " > ";

	if (almacen.estaVacia()){ //El almac�n est� vac�o
		std::cout << "est� vac�o" << RESET;
	}

	else{ //El almac�n no est� vac�o
		std::cout << "no est� vac�o" << RESET;
	}
}

void cargarAlmacen(Almacen &almacen){
	if(!almacen.estaVacio()){ //El almac�n no est� vac�o
		borrarAlmacen(almacen); //Borramos el almac�n
	}

	std::string nombreFichero;

	//Pedimos al usuario el nombre del fichero con la informaci�n del almac�n a cargar
	std::cout << std::endl << YELLOW << "Introduzca el nombre del fichero " << BIYELLOW << "(no olvide la extensi�n .txt): " << RESET;
	std::cin >> nombreFichero;

	if(!almacen.cargarFichero(nombreFichero)){ //No se ha podido cargar el almac�n
		std::cout << std::endl << BIRED << "Error: no se pudo abrir el fichero" << RESET << std::endl;
		std::cin.ignore();
	}

	else{ //Se ha podido cargar el almac�n
		std::cout << std::endl << CYAN << "Almac�n cargado correctamente" << RESET << std::endl;
		std::cin.ignore();
	}
}

void grabarAlmac�n(Almacen &almacen){
	if(almacen.estaVacia()){ //El almac�n est� vac�o
		std::cout << std::endl << BIRED << "Error: no hay ning�n item cargado" << RESET << std::endl;
	}

	else{ //El almac�n no est� vac�o
		std::string nombreFichero;

		//Pedimos al usuario el nombre del fichero en el que grabar la informaci�n del almac�n
		std::cout << std::endl << BIYELLOW << "Introduzca el nombre del fichero (no olvide la extensi�n .txt): " << RESET;
		std::cin >> nombreFichero;

		if(!almacen.grabarFichero(nombreFichero)){ //No se ha podido grabar el almac�n
			std::cout << std::endl << std::endl << BIRED << "Error: no se pudo abrir el fichero" << RESET << std::endl;
		}

		else{ //Se ha podido grabar el almac�n
			std::cout << std::endl << CYAN << "Almac�n grabado correctamente" << RESET << std::endl;
			std::cin.ignore();
		}
	}
}

void consultarAlmacen(Almacen &almacen){
	if(almacen.estaVacia()){ //El almac�n est� vac�o
		std::cout << std::endl << BIRED << "Error: no hay ning�n item cargado" << RESET << std::endl;
	}

	else{ //El almac�n no est� vac�o
		//Mostramos la informaci�n del almac�n
		std::cout << std::endl << BBLUE << "C�digo del almac�n: " << BLUE << almacen.getCodigo() << RESET << std::endl << std::endl;
		std::cout << BBLUE << "Nombre del almac�n: " << BLUE << almacen.getNombre() << RESET << std::endl << std::endl;
		std::cout << BBLUE << "Lista de items del almac�n:" << BLUE << std::endl;

		almacen.consultarItems();
		
		std::cout << RESET;
	}
}

void modificarAlmacen(Almacen &almacen){
	int opcion;
	int codigo;
	std::string nombre;

	do{
		//Mostramos los datos del almac�n
		std::cout << std::endl << BIBLUE << "Datos actuales del almac�n: " << RESET << std::endl;
		std::cout << BBLUE << "C�digo: " << BLUE << almacen.getCodigo() << RESET << std::endl;
		std::cout << BBLUE << "Nombre: " << BLUE << almacen.getNombre() << RESET << std::endl << std::endl;

		//Preguntamos al usuario qu� desea modificar
		std::cout << BGREEN << "Indique qu� dato desea modificar: " << RESET << std::endl;
		std::cout << IGREEN << "(1) C�digo" << std::endl;
		std::cout << "(2) Nombre" << std::endl;
		std::cout << GREEN << "(0) Salir" << RESET << std::endl;
		std::cout << IYELLOW << "Opci�n: " << RESET;
		std::cin >> opcion;

		switch(opcion){
			case 0: //Salir
				break;

			case 1: //Modificar c�digo
				//Pedimos al usuario el nuevo c�digo del almac�n
				std::cout << std::endl << IPURPLE "Nuevo c�digo: " << RESET;
				std::cin >> codigo;

				almacen.setCodigo(codigo); //Modificamos el c�digo de la asignatura

				break;

			case 2: //Modificar nombre
				//Pedimos al usuario el nuevo nombre del almac�n
				std::cin.ignore();
				std::cout << std::endl << IPURPLE << "Nuevo nombre: " << RESET;
				getline(std::cin,nombre);

				almacen.setNombre(nombre); //Modificamos el nombre del almac�n

				break;

			default: //Opci�n incorrecta
				std::cout << std::endl << BIRED << "Error: opci�n incorrecta" << RESET << std::endl << std::endl;

				break;
		}
	}while(opcion!=0);
}

void borrarAlmacen(Almacen &almacen){
	almacen.setCodigo(0); //Borramos el c�digo del almac�n
	almacen.setNombre(""); //Borramos el nombre del almac�n

	//Borramos la lista de items
	while(!almacen.estaVacio()){	
		almacen.borrarItem(0);
	}

	std::cout << std::endl << CYAN << "Almac�n borrado correctamente" << RESET << std::endl;
}

void consultarItemDeAlmacen(Almacen &almacen){
	if(almacen.estaVacio()){ //El almac�n est� vac�o
		std::cout << std::endl << BIRED << "Error: no hay ning�n item cargado" << RESET << std::endl;
	}

	else{ //El almac�n no est� vac�o
		std::string nombre;

		//Pedimos al usuario los datos del item a consultar
		std::cout << std::endl << BIYELLOW << "Introduzca el nombre del item" << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		getline(std::cin,nombre);

		if(!almacen.existeItem(nombre)){ //No existe el item indicado por el usuario
			std::cout << std::endl << BIRED << "Error: el item " << nombre << " no pertenece al almac�n" << RESET << std::endl;
		}

		else{ //Existe el item indicado por el usuario
			//Mostramos las notas del item
			std::cout << std::endl << BBLUE << "Cantidad de " << almacen.getItem(nombre).getNombre() << " " << almacen.getItem(nombre).getApellidos() << ": " << almacen.getItem(nombre).getCantidad() << RESET << std::endl;
		}
	}
}

void insertarItemEnAlmacen(Almacen &almacen){
	Item item;

	std::cout << std::endl << BIYELLOW << "Introduzca los datos del item" << RESET << std::endl;
	estudiante.leerItem(); //Pedimos al usuario la informaci�n del item a insertar

	if(!almacen.existeItem(item)){ //No existe el item indicado por el usuario
		if(!almacen.insertarItem(item)){ //No se ha podido insertar el item
			std::cout << std::endl << BIRED << "Error: no se ha podido insertar el item indicado" << RESET << std::endl;
		}

		else{ //Se ha podido insertar el item
			std::cout << std::endl << CYAN << "Item insertado correctamente" << RESET << std::endl;
		}
	}

	else{ //Existe el item indicado por el usuario
		std::cout << std::endl << BIRED << "Error: ya existe el item indicado" << RESET << std::endl;
	}
}

void modificarItemDeAlmacen(Almacen &almacen){
	if(almacen.estaVacio()){ //El almac�n est� vac�o
		std::cout << std::endl << BIRED << "Error: no hay ning�n item cargado" << RESET << std::endl;
	}
	
	else{ //El almac�n no est� vac�o
		int opcion;
		bool control;
		std::string nombre;
		int cantidad;
		Item item;
		Item nuevoItem;

		//Pedimos al usuario el nombre del item a modificar
		std::cout << BIYELLOW << "Introduzca el nombre del item: " << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		std::getline(std::cin,nombre);

		control=almacen.existeItem(nombre);	

		if(control){ //Existe el item indicado por el usuario
			item=almacen.getItem(nombre);

			do{
				//Mostramos los datos del item
				std::cout << std::endl << BIBLUE << "Datos actuales del item: " << RESET << std::endl;
				item.escribirItem();
		
				//Preguntamos al usuario qu� desea modificar
				std::cout << std::endl;
				std::cout << BGREEN << "Indique qu� dato desea modificar: " << RESET << std::endl;
				std::cout << IGREEN << "(1) Nombre" << std::endl;
				std::cout << "(2) Cantidad" << std::endl;
				std::cout << GREEN << "(0) Salir" << RESET << std::endl;
				std::cout << IYELLOW "Opci�n: " << RESET;
				std::cin >> opcion;
				std::cin.ignore(); //Se elimina el salto de l�nea del flujo de entrada
			
				switch(opcion){
					case 0: 
						//Fin de las modificaciones
						break;
						
					case 1:
						nuevoItem=item;

						std::cout << std::endl << IPURPLE << "Nuevo nombre: " << RESET;
						std::getline(std::cin,nombre);
						nuevoItem.setNombre(nombre);

						//Se comprueba que no existe otro item con la misma clave
						if(!almacen.existeItem(nuevoItem)){
							//Como se ha modificado un campo de la clave, se borra el antiguo item y se inserta el item modficado de forma ordenada
							almacen.borrarItem(item);
							almacen.insertarItem(nuevoItem);	

							item=nuevoItem;
						}
					
						//Se indica que ya existe un item con la misma clave
						else{
							std::cout << BIRED << "Error: no se puede modificar el nombre porque tendr�a la misma clave que otro item" << RESET << std::endl;
						}
					
						break;

					case 2:
						std::cout << std::endl << IPURPLE << "Nueva cantidad: " << RESET;
						std::cin >> cantidad;
						item.setCantidad(cantidad);

						//Se modifica su cantidad
						almacen.setItem(item);
					
						break;

					default:
						std::cout << BIRED << "Error: opci�n incorrecta" << RESET << std::endl;
				}
			}while (opcion!=0);
		}
	
		else{
			std::cout << std::endl << BIRED << "Error: el item " << nombre << " no pertenece al almac�n" << RESET;
		}
	}
}


void ed::borrarItemDeAlmacen(Almacen &almacen){
	if(almacen.estaVacio()){ //El almac�n est� vac�o
		std::cout << std::endl << BIRED << "Error: no hay ning�n item cargado" << RESET << std::endl;
	}
	
	else{ //El almac�n no est� vac�o
		bool control;
		std::string nombre;
		Item item;

		//Pedimos al usuario el nombre del item a borrar
		std::cout << BIYELLOW << "Introduzca el nombre del item" << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		std::getline(std::cin,nombre);

		control=almacen.existeItem(nombre);	

		if(control){ //Existe el item indicado por el usuario
			almacen.borrarItem(nombre); //Borramos el estudiante indicado

			control=almacen.existeItem(nombre);	

			if(control){ //No se ha borrado el item indicado
				std::cout << std::endl << BIRED << "Error: el item no ha podido ser borrado" << RESET << std::endl;
			}

			else{ //Se ha borrado el item indicado
				std::cout << std::endl << CYAN << "El item ha sido borrado correctamente" << RESET << std::endl;
			}
		}	

		else{ //No existe el item indicado por el usuario
			std::cout << std::endl << BIRED "Error: el item "<< nombre << " no pertenece al almac�n" << RESET;
		}
	}
}
