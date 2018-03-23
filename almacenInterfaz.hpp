/*!
	\file    almacenInterfaz.hpp
	\brief   Definici�n de la clase abstracta AlmacenInterfaz
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
	\name \name M�todos p�blicos de la clase AlmacenInterfaz
*/

/*!	
	\name Observadores
*/

/*!		
	\brief  Devuelve el c�digo del almac�n
	\note   Funci�n virtual pura
	\return N�mero entero que representa el c�digo num�rico del almac�n
*/
	virtual int getCodigo()const=0;

/*!		
	\brief  Devuelve el nombre del almac�n
	\note   Funci�n virtual pura
	\return Cadena que representa el nombre del almac�n
*/
	virtual std::string getNombre()const=0;

/*!		
	\brief  Indica si el almac�n tiene o no items
	\note   Funci�n virtual pura
	\return Verdadero si tiene uno o m�s items; falso, en caso contrario
*/
	virtual bool estaVacia()const=0;

/*!		
	\brief  Devuelve el n�mero de items
	\note   Funci�n virtual pura
	\return N�mero entero que representa el n�mero de items del almac�n
*/
	virtual int getNumeroItems()const=0;

/*!		
	\brief   Comprueba si existe un item con un nombre 
	\note    Funci�n virtual pura
	\warning Funci�n sobrecargada
	\param   nombre del item buscado
	\return  Verdadero si existe el item; falso, en caso contrario
*/
	virtual	bool existeItem(std::string const &nombre)=0;



/*!		
	\brief   Devuelve el item con un nombre 
	\note    Funci�n virtual pura
	\warning Funci�n sobrecargada
	\param   nombre del item buscado
	\pre     Debe existir el item con el nombre indicado
	\return  Objeto de la clase Item
	\sa      existeItem
*/
	virtual Item const &getItem(std::string const &nombre)=0;

/*!		
	\brief   Devuelve el item que ocupa la posici�n indicada
	\note    Funci�n virtual pura
	\warning Funci�n sobrecargada
	\param   indice n�mero que indica la posici�n del item en el almac�
	\pre     Debe existir el item que ocupe la posici�n indicada
	\return  Objeto de la clase Item
	\sa      getNumeroItems
*/
	virtual Item const &getItem(int indice)=0;


/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el c�digo del almac�n
	\note   Funci�n virtual pura
	\param  codigo: dato de tipo entero que ser� el nuevo c�digo del almac�n
	\post   El c�digo del almac�n deber� tener el c�digo asignado
	\return void
	\sa     getCodigo
*/
	virtual void setCodigo(int codigo)=0;
	

/*!		
	\brief  Modifica el nombre del almac�n
	\note   Funci�n virtual pura
	\param  nombre: dato de tipo cadena que ser� el nuevo nombre del almac�n
	\post   El nombre del almac�n deber� tener el nombre asignado
	\return void
	\sa     getNombre
*/
	virtual void setNombre(std::string const &nombre)=0;
	

/*!		
	\brief  Inserta un item de forma ordenada seg�n el nombre
	\note   Funci�n virtual pura
	\param  nombre del item
	\param  cantidad del item
	\pre    No debe existir otro item con el mismo nombre
	\post   El item est� insertado en el almac�n
	\post   El n�mero de items debe haberse aumentado en uno
	\return Verdadero, en el caso de que logre insertar el item; falso, en caso contrario
	\sa     existeItem, getNumeroItems
*/
	virtual	bool insertarItem(std::string const &nombre,int cantidad)=0;


/*!		
	\brief   Devuelve el item con un nombre
	\note    Funci�n virtual pura
	\warning Funci�n sobrecargada
	\param   nombre del item buscado
	\pre 	 Debe existir el item con el nombre indicado
	\post    No debe existir otro item con el mismo nombre
	\post    El n�mero de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	virtual	bool borrarItem(std::string const &nombre)=0;
}; //Fin de la clase AlmacenInterfaz

#endif
