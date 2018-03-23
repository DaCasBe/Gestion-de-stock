/*!	
	\file    item.cpp
	\brief   Código auxiliar de las funciones de la clase Item
	\author  Daniel Castillo Bello
	\date    08-10-2017
	\version 1.0
*/


#include <iostream>
#include <stdio.h>
#include "item.hpp"
#include "macros.hpp"

/*
	Definiciones de las funciones lectura y escritura de la clase Item
*/

void Item::leerItem(){
	std::cout << IYELLOW << "Introduce el nombre: " << RESET;
	std::getline(std::cin,_nombre);

	std::cout << IYELLOW << "Introduce la cantidad: " << RESET;
	std::cin >> _cantidad;
	
	std::cin.ignore();
}


void Item::escribirItem()const{
	std::cout << BBLUE << "Nombre: " << BLUE << getNombre() << RESET << std::endl;

	std::cout << BBLUE << "Cantidad: " << BLUE << getCantidad() << RESET << std::endl;
}

Item &Item::operator=(const Item &item){
	//Se comprueba que no sean el mismo objeto
	if(this!=&item){
		setNombre(item.getNombre());
		setTeoria(item.getTeoria());
	}

	//Postcondición
	#ifndef NDEBUG
		assert((*this)==item);
	#endif
	
	//Se devuelve el objeto actual
	return * this;
}


bool Item::operator==(const Item &e)const{
	return (getNombre()==item.getNombre());
}


bool Item::operator<(const Item &item)const{
	if(getNombre()<item.getNombre()){
		return true;
	}

	else{
		return false;
	}
}

std::istream &operator>>(std::istream &i,Item &item){
	std::getline(i,item._nombre);
	i >> item._cantidad;
	i.ignore();

	//Se devuelve el flujo de entrada
	return i;
}


std::ostream &operator<<(std::ostream &o,Item const &item){
	o << item._nombre << std::endl;
	o << item._teoria << std::endl;

	//Se devuelve el flujo de salida
	return o;
}
