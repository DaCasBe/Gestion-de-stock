/*!
	\file    almacenInterfaz.hpp
	\brief   Definición de la clase abstracta AlmacenInterfaz
	\author  Daniel Castillo Bello
	\date    13-10-2017
	\version 1.0
*/

#ifndef __ALMACENINTERFAZ_HPP__
#define __ALMACENINTERFAZ_HPP__

#include <string>
#include "item.hpp"


/*!
	\class AlmacenInterfaz
	\brief Especificaciones de la clase virtual pura AlmacenInterfaz
*/
class AlmacenInterfaz{

/*!		
	\name \name Métodos públicos de la clase AlmacenInterfaz
*/

/*!	
	\name Observadores
*/

/*!		
	\brief  Devuelve el código del almacén
	\note   Función virtual pura
	\return Número entero que representa el código numérico del almacén
*/
	virtual int getCodigo()const=0;

/*!		
	\brief  Devuelve el nombre del almacén
	\note   Función virtual pura
	\return Cadena que representa el nombre del almacén
*/
	virtual std::string getNombre()const=0;

/*!		
	\brief  Indica si el almacén tiene o no items
	\note   Función virtual pura
	\return Verdadero si tiene uno o más items; falso, en caso contrario
*/
	virtual bool estaVacia()const=0;

/*!		
	\brief  Devuelve el número de items
	\note   Función virtual pura
	\return Número entero que representa el número de items del almacén
*/
	virtual int getNumeroItems()const=0;

/*!		
	\brief   Comprueba si existe un item con un nombre 
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   nombre del item buscado
	\return  Verdadero si existe el item; falso, en caso contrario
*/
	virtual	bool existeItem(std::string const &nombre)=0;



/*!		
	\brief   Devuelve el item con un nombre 
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   nombre del item buscado
	\pre     Debe existir el item con el nombre indicado
	\return  Objeto de la clase Item
	\sa      existeItem
*/
	virtual Item const &getItem(std::string const &nombre)=0;

/*!		
	\brief   Devuelve el item que ocupa la posición indicada
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   indice número que indica la posición del item en el almacé
	\pre     Debe existir el item que ocupe la posición indicada
	\return  Objeto de la clase Item
	\sa      getNumeroItems
*/
	virtual Item const &getItem(int indice)=0;


/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el código del almacén
	\note   Función virtual pura
	\param  codigo: dato de tipo entero que será el nuevo código del almacén
	\post   El código del almacén deberá tener el código asignado
	\return void
	\sa     getCodigo
*/
	virtual void setCodigo(int codigo)=0;
	

/*!		
	\brief  Modifica el nombre del almacén
	\note   Función virtual pura
	\param  nombre: dato de tipo cadena que será el nuevo nombre del almacén
	\post   El nombre del almacén deberá tener el nombre asignado
	\return void
	\sa     getNombre
*/
	virtual void setNombre(std::string const &nombre)=0;
	

/*!		
	\brief  Inserta un item de forma ordenada según el nombre
	\note   Función virtual pura
	\param  nombre del item
	\param  cantidad del item
	\pre    No debe existir otro item con el mismo nombre
	\post   El item está insertado en el almacén
	\post   El número de items debe haberse aumentado en uno
	\return Verdadero, en el caso de que logre insertar el item; falso, en caso contrario
	\sa     existeItem, getNumeroItems
*/
	virtual	bool insertarItem(std::string const &nombre,int cantidad)=0;


/*!		
	\brief   Devuelve el item con un nombre
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   nombre del item buscado
	\pre 	 Debe existir el item con el nombre indicado
	\post    No debe existir otro item con el mismo nombre
	\post    El número de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	virtual	bool borrarItem(std::string const &nombre)=0;
}; //Fin de la clase AlmacenInterfaz

#endif
