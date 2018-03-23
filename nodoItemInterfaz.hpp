/*! 
	\file    nodoItemInterfaz.hpp
	\brief   Declaraci�n de la clase NodoItemInterfaz
	\author  Daniel Castillo Bello
	\date    08-10-2017
	\version 1.0
*/

#ifndef _NODOITEMINTERFAZ_HPP_
#define _NODOITEMINTERFAZ_HPP_

#include "item.hpp"

/*!
	\class NodoItemInterfaz
	\brief Indica los m�todos virtuales puros deber�n ser redefinidos en las clases herederas
*/
class NodoItemInterfaz{

/*!	
	\name Funciones o m�todos p�blicos de la clase Nodo
*/
	public:


/*!
	\brief     Destructor de la clase 
	\warning   Funci�n virtual pura: se debe redefinir en la clase heredera
	\attention Es necesario especificar esta funci�n para liberar memoria en la clase heredera
	\post      El �rbol est� vac�o
*/
	virtual ~NodoItemInterfaz(){
	
	}

/*!
	\name Observadores
*/

/*!	
	\brief   M�todo p�blico que permite conocer el campo informativo del nodo: un item
	\warning Funci�n virtual pura: se debe redefinir en la clase heredera
	\pre     El �rbol no est� vac�o
	\return  Devuelve el valor del campo informativo del nodo, es decir, una referencia a un item
*/
	virtual const Item & getItem()const=0;

/*!	
	\brief   M�todo p�blico que permite modificar el campo informativo del nodo: un item
	\warning Funci�n virtual pura: se debe redefinir en la clase heredera
	\post    El valor del campo informativo debe ser igual al item pasado como argumento
	\return  void
	\sa      getItem
*/
	virtual void setItem(Item const &item)=0;

}; //Fin de la clase NodoItemInterfaz

//Fin  _NODOITEMINTERFAZ_HPP_
#endif  
