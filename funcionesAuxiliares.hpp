/*!
	\file   funcionesAuxiliares.hpp
	\brief  Prototipos de las funciones auxiliares del programa principal del almac�n
	\author Daniel Castillo Bello
	\date   13-10-2017
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "almacen.hpp" 

/*!		
	\brief   Men� para acceder a las diferentes funciones
	\return  Entero que indica la opci�n seleccionada
*/
	int menu();

/*!		
	\brief   Comprueba si el almac�n esta vac�o
	\param   almacen: almacen del que se quiere comprobar si esta vac�o o no
	\return  void
*/
	void comprobarAlmacenVacio(Almacen const &almacen);

/*!		
	\brief   Carga un almac�n desde un fichero de texto
	\param   almacen: dato de tipo Almacen en el que se carga la informaci�n
	\return  void
	\sa      borrarAlmacen
*/
	void cargarAlmacen(Almacen &almacen);

/*!		
	\brief   Graba un almac�n en un fichero de texto
	\param   almacen: dato de tipo Almacen que contiene la informaci�n a grabar
	\return  void
*/
	void grabarAlmacen(Almacen &almacen);

/*!		
	\brief   Muestra los datos de un almac�n por la pantalla
	\param   almacen: dato de tipo Almacen que contiene la informaci�n a mostrar
	\return  void
*/
	void consultarAlmacen(Almacen &almacen);
	
/*!		
	\brief   Permite al usuario modificar los datos de un almac�n
	\param   almacen: dato de tipo Almac�n que contiene la informaci�n a modificar
	\return  void
*/
	void modificarAlmacen(Almacen &almacen);

/*!		
	\brief   Borra un almac�n
	\param   almacen: dato de tipo almacen que se pretende borrar
	\return  void
*/
	void borrarAlmacen(Almacen &almacen);

/*!		
	\brief   Consulta la informaci�n de un item especificado por el usuario
	\param   almacen: dato de tipo Almacen en el que se encuentra el item
	\return  void
*/
	void consultarItemDeAlmacen(Almacen &almacen);

/*!		
	\brief   Inserta un item en un almac�n
	\param   almacen: dato de tipo Almacen en el que se pretende insertar el item
	\return  void
*/
	void insertarItemEnAlmacen(Almacen &almacen);

/*!		
	\brief   Modifica la informaci�n de un item especificado por el usuario
	\param   almacen: dato de tipo Almacen en el que se encuentra el item
	\return  void
*/
	void modificarItemDeAlmacen(Almacen &almacen);

/*!		
	\brief   Borra un item especificado por el usuario de un almac�n
	\param   almacen: dato de tipo Almacen en el que se encuentra el item 
	\return  void
*/
	void borrarItemDeAlmacen(Almacen &almacen);

//Fin de _FUNCIONESAUXILIARES_HPP_
#endif
