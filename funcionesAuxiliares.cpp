/*!
	\file   funcionesAuxiliares.hpp
	\brief  Código de las funciones auxiliares del programa principal del almacén
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

	//Se muestran las opciones del menú
	posicion=8;

	//Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
   	std::cout << BBLUE;
	std::cout << "Programa principial | Opciones del menú   ";
	std::cout << RESET;

	LUGAR(posicion++,10);
	std::cout << IGREEN << "[1] Comprobar si el almacén está vacío";

	LUGAR(posicion++,10);
	std::cout << "[2] Cargar el almacén de un fichero";

	LUGAR(posicion++,10);
	std::cout << "[3] Grabar el almacén en un fichero";

	LUGAR(posicion++,10);
	std::cout << "[4] Consultar datos del almacén: código, nombre, lista de items";

	LUGAR(posicion++,10);
	std::cout << "[5] Modificar datos del almacén: código o nombre";

	LUGAR(posicion++,10);
	std::cout << "[6] Borrar el almacén";

	LUGAR(posicion++,10);
	std::cout << "[7] Consultar el almacén";

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
	std::cout << "Opción: ";
	std::cout << RESET;

	//Se lee el número de opción
	std::cin >> opcion;

	//Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}

void comprobarAlmacenVacio(Almacen const &almacen){
	std::cout << std::endl << IPURPLE "El almacén de nombre < " << almacen.getNombre() << " > ";

	if (almacen.estaVacia()){ //El almacén está vacío
		std::cout << "está vacío" << RESET;
	}

	else{ //El almacén no está vacío
		std::cout << "no está vacío" << RESET;
	}
}

void cargarAlmacen(Almacen &almacen){
	if(!almacen.estaVacio()){ //El almacén no está vacío
		borrarAlmacen(almacen); //Borramos el almacén
	}

	std::string nombreFichero;

	//Pedimos al usuario el nombre del fichero con la información del almacén a cargar
	std::cout << std::endl << YELLOW << "Introduzca el nombre del fichero " << BIYELLOW << "(no olvide la extensión .txt): " << RESET;
	std::cin >> nombreFichero;

	if(!almacen.cargarFichero(nombreFichero)){ //No se ha podido cargar el almacén
		std::cout << std::endl << BIRED << "Error: no se pudo abrir el fichero" << RESET << std::endl;
		std::cin.ignore();
	}

	else{ //Se ha podido cargar el almacén
		std::cout << std::endl << CYAN << "Almacén cargado correctamente" << RESET << std::endl;
		std::cin.ignore();
	}
}

void grabarAlmacén(Almacen &almacen){
	if(almacen.estaVacia()){ //El almacén está vacío
		std::cout << std::endl << BIRED << "Error: no hay ningún item cargado" << RESET << std::endl;
	}

	else{ //El almacén no está vacío
		std::string nombreFichero;

		//Pedimos al usuario el nombre del fichero en el que grabar la información del almacén
		std::cout << std::endl << BIYELLOW << "Introduzca el nombre del fichero (no olvide la extensión .txt): " << RESET;
		std::cin >> nombreFichero;

		if(!almacen.grabarFichero(nombreFichero)){ //No se ha podido grabar el almacén
			std::cout << std::endl << std::endl << BIRED << "Error: no se pudo abrir el fichero" << RESET << std::endl;
		}

		else{ //Se ha podido grabar el almacén
			std::cout << std::endl << CYAN << "Almacén grabado correctamente" << RESET << std::endl;
			std::cin.ignore();
		}
	}
}

void consultarAlmacen(Almacen &almacen){
	if(almacen.estaVacia()){ //El almacén está vacío
		std::cout << std::endl << BIRED << "Error: no hay ningún item cargado" << RESET << std::endl;
	}

	else{ //El almacén no está vacío
		//Mostramos la información del almacén
		std::cout << std::endl << BBLUE << "Código del almacén: " << BLUE << almacen.getCodigo() << RESET << std::endl << std::endl;
		std::cout << BBLUE << "Nombre del almacén: " << BLUE << almacen.getNombre() << RESET << std::endl << std::endl;
		std::cout << BBLUE << "Lista de items del almacén:" << BLUE << std::endl;

		almacen.consultarItems();
		
		std::cout << RESET;
	}
}

void modificarAlmacen(Almacen &almacen){
	int opcion;
	int codigo;
	std::string nombre;

	do{
		//Mostramos los datos del almacén
		std::cout << std::endl << BIBLUE << "Datos actuales del almacén: " << RESET << std::endl;
		std::cout << BBLUE << "Código: " << BLUE << almacen.getCodigo() << RESET << std::endl;
		std::cout << BBLUE << "Nombre: " << BLUE << almacen.getNombre() << RESET << std::endl << std::endl;

		//Preguntamos al usuario qué desea modificar
		std::cout << BGREEN << "Indique qué dato desea modificar: " << RESET << std::endl;
		std::cout << IGREEN << "(1) Código" << std::endl;
		std::cout << "(2) Nombre" << std::endl;
		std::cout << GREEN << "(0) Salir" << RESET << std::endl;
		std::cout << IYELLOW << "Opción: " << RESET;
		std::cin >> opcion;

		switch(opcion){
			case 0: //Salir
				break;

			case 1: //Modificar código
				//Pedimos al usuario el nuevo código del almacén
				std::cout << std::endl << IPURPLE "Nuevo código: " << RESET;
				std::cin >> codigo;

				almacen.setCodigo(codigo); //Modificamos el código de la asignatura

				break;

			case 2: //Modificar nombre
				//Pedimos al usuario el nuevo nombre del almacén
				std::cin.ignore();
				std::cout << std::endl << IPURPLE << "Nuevo nombre: " << RESET;
				getline(std::cin,nombre);

				almacen.setNombre(nombre); //Modificamos el nombre del almacén

				break;

			default: //Opción incorrecta
				std::cout << std::endl << BIRED << "Error: opción incorrecta" << RESET << std::endl << std::endl;

				break;
		}
	}while(opcion!=0);
}

void borrarAlmacen(Almacen &almacen){
	almacen.setCodigo(0); //Borramos el código del almacén
	almacen.setNombre(""); //Borramos el nombre del almacén

	//Borramos la lista de items
	while(!almacen.estaVacio()){	
		almacen.borrarItem(0);
	}

	std::cout << std::endl << CYAN << "Almacén borrado correctamente" << RESET << std::endl;
}

void consultarItemDeAlmacen(Almacen &almacen){
	if(almacen.estaVacio()){ //El almacén está vacío
		std::cout << std::endl << BIRED << "Error: no hay ningún item cargado" << RESET << std::endl;
	}

	else{ //El almacén no está vacío
		std::string nombre;

		//Pedimos al usuario los datos del item a consultar
		std::cout << std::endl << BIYELLOW << "Introduzca el nombre del item" << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		getline(std::cin,nombre);

		if(!almacen.existeItem(nombre)){ //No existe el item indicado por el usuario
			std::cout << std::endl << BIRED << "Error: el item " << nombre << " no pertenece al almacén" << RESET << std::endl;
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
	estudiante.leerItem(); //Pedimos al usuario la información del item a insertar

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
	if(almacen.estaVacio()){ //El almacén está vacío
		std::cout << std::endl << BIRED << "Error: no hay ningún item cargado" << RESET << std::endl;
	}
	
	else{ //El almacén no está vacío
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
		
				//Preguntamos al usuario qué desea modificar
				std::cout << std::endl;
				std::cout << BGREEN << "Indique qué dato desea modificar: " << RESET << std::endl;
				std::cout << IGREEN << "(1) Nombre" << std::endl;
				std::cout << "(2) Cantidad" << std::endl;
				std::cout << GREEN << "(0) Salir" << RESET << std::endl;
				std::cout << IYELLOW "Opción: " << RESET;
				std::cin >> opcion;
				std::cin.ignore(); //Se elimina el salto de línea del flujo de entrada
			
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
							std::cout << BIRED << "Error: no se puede modificar el nombre porque tendría la misma clave que otro item" << RESET << std::endl;
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
						std::cout << BIRED << "Error: opción incorrecta" << RESET << std::endl;
				}
			}while (opcion!=0);
		}
	
		else{
			std::cout << std::endl << BIRED << "Error: el item " << nombre << " no pertenece al almacén" << RESET;
		}
	}
}


void ed::borrarItemDeAlmacen(Almacen &almacen){
	if(almacen.estaVacio()){ //El almacén está vacío
		std::cout << std::endl << BIRED << "Error: no hay ningún item cargado" << RESET << std::endl;
	}
	
	else{ //El almacén no está vacío
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
			std::cout << std::endl << BIRED "Error: el item "<< nombre << " no pertenece al almacén" << RESET;
		}
	}
}
