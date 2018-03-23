/*! 	
	\file    itemInterfaz.hpp
	\brief   Declaraci�n del TAD itemInterfaz
	\author  Daniel Castillo Bello
	\date    08-10-2017
	\version 1.0
*/

#ifndef _ITEMINTERFAZ_HPP_
#define _ITEMINTERFAZ_HPP_

#include <string>

/*!
	\class ItemInterfaz
	\brief Indica los m�todos virtuales puros de interfaz que ser�n redefinidos en las clase heredera
*/
class ItemInterfaz{

/*!	
	\name Funciones o m�todos p�blicos de la clase ItemInterfaz
*/
	public:

/*!		
	\brief Destructor  
	\note  Funci�n virtual
	\sa    setNombre, setCantidad
*/
	virtual ~ItemInterfaz(){
	
	}


/*!
	\name Observadores
*/

/*!	
	\brief   M�todo p�blico que permite conocer el nombre del item
	\warning Funci�n virtual pura: se debe redefinir en la clase heredera
	\return  Devuelve el nombre del item
*/
	virtual const std::string &getNombre()const=0;

		
/*!	
	\brief   M�todo p�blico que permite conocer la cantidad del item
	\warning Funci�n virtual pura: se debe redefinir en la clase heredera
	\return  Devuelve la cantidad del item
*/
	virtual int getCantidad()const=0;


/*!
	\name Modificadores
*/
		
/*!	
	\brief   M�todo p�blico que permite modificar el nombre del item
	\warning Funci�n virtual pura: se debe redefinir en la clase heredera
	\param   nombre: nuevo nombre del item
	\post    El nombre del item es igual al par�metro pasado como argumento
	\return  void
	\sa      getNombre
*/
	virtual void setNombre(const std::string &nombre)=0;

		
/*!	
	\brief   M�todo p�blico que permite modificar la cantidad del item
	\warning Funci�n virtual pura: se debe redefinir en la clase heredera
	\param   cantidad: nueva cantidad del item
	\post    La cantidad del item es igual al par�metro pasado como argumento
	\return  void
	\sa      getCantidad
*/
	virtual void setCantidad(const int &cantidad)=0;
	
}; //Fin de la clase EstudianteInterfaz

//Fin  _ESTUDIANTEINTERFAZ_HPP_
#endif  
