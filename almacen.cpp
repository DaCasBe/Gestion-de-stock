/*!	
	\file    almacen.cpp
	\brief   Definición de la clase Almacén
	\author  Daniel Castillo Bello
	\date    13-10-2017
	\version 1.0
*/

//Para los flujos de entrada/salida en ficheros
#include <fstream>  
#include <iostream>

//Para usar atof
#include <stdlib.h>

#include "almacen.hpp"

bool Almacen::cargarFichero(std::string const &nombreFichero){
	std::ifstream fichero;
	Item item;
	char nombre[30];
	char codigo[5];

	fichero.open(nombreFichero.c_str()); //Abrimos el fichero con el nombre recibido

	if(!fichero){ //No se ha podido abrir el fichero
		return false;
	}

	else{ //Se ha podido abrir el fichero
		//Leemos del fichero el nombre y el código del almacén
		fichero.getline(nombre,30,'\n');
		setNombre(nombre);
		fichero.getline(codigo,5,'\n');
		setCodigo(atoi(codigo));

		while(fichero >> item){ //Leemos del fichero los datos de un item
			if(!insertarItem(item)){ //Insertamos el item
				std::cout << "No ha podido insertarse un item" << std::endl;

				return false;
			}
		}

		fichero.close(); //Cerramos el fichero

		return true;
	}
}

bool Almacen::grabarFichero(std::string const &nombreFichero){
	std::ofstream fichero;

	fichero.open(nombreFichero.c_str()); //Abrimos el fichero con el nombre recibido

	if(!fichero){ //No se ha podido abrir el fichero
		return false;
	}

	else{ //Se ha podido abrir el fichero
		//Escribimos en el fichero el nombre y el código del almacén
		fichero << getNombre() << std::endl;
		fichero << getCodigo() << std::endl;

		_arbol.grabar(fichero); //Escribimos el en fichero la lista de items

		fichero.close(); //Cerramos el fichero

		return true;
	}
}
