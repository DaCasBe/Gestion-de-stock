/*!
	\file   funcionesAuxiliares.hpp
	\brief  Prototipos de las funciones auxiliares del programa principal del almacén
	\author Daniel Castillo Bello
	\date   13-10-2017
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "almacen.hpp" 

/*!		
	\brief   Menú para acceder a las diferentes funciones
	\return  Entero que indica la opción seleccionada
*/
	int menu();

/*!		
	\brief   Comprueba si el almacén esta vacío
	\param   almacen: almacen del que se quiere comprobar si esta vacío o no
	\return  void
*/
	void comprobarAlmacenVacio(Almacen const &almacen);

/*!		
	\brief   Carga un almacén desde un fichero de texto
	\param   almacen: dato de tipo Almacen en el que se carga la información
	\return  void
	\sa      borrarAlmacen
*/
	void cargarAlmacen(Almacen &almacen);

/*!		
	\brief   Graba un almacén en un fichero de texto
	\param   almacen: dato de tipo Almacen que contiene la información a grabar
	\return  void
*/
	void grabarAlmacen(Almacen &almacen);

/*!		
	\brief   Muestra los datos de un almacén por la pantalla
	\param   almacen: dato de tipo Almacen que contiene la información a mostrar
	\return  void
*/
	void consultarAlmacen(Almacen &almacen);
	
/*!		
	\brief   Permite al usuario modificar los datos de un almacén
	\param   almacen: dato de tipo Almacén que contiene la información a modificar
	\return  void
*/
	void modificarAlmacen(Almacen &almacen);

/*!		
	\brief   Borra un almacén
	\param   almacen: dato de tipo almacen que se pretende borrar
	\return  void
*/
	void borrarAlmacen(Almacen &almacen);

/*!		
	\brief   Consulta la información de un item especificado por el usuario
	\param   almacen: dato de tipo Almacen en el que se encuentra el item
	\return  void
*/
	void consultarItemDeAlmacen(Almacen &almacen);

/*!		
	\brief   Inserta un item en un almacén
	\param   almacen: dato de tipo Almacen en el que se pretende insertar el item
	\return  void
*/
	void insertarItemEnAlmacen(Almacen &almacen);

/*!		
	\brief   Modifica la información de un item especificado por el usuario
	\param   almacen: dato de tipo Almacen en el que se encuentra el item
	\return  void
*/
	void modificarItemDeAlmacen(Almacen &almacen);

/*!		
	\brief   Borra un item especificado por el usuario de un almacén
	\param   almacen: dato de tipo Almacen en el que se encuentra el item 
	\return  void
*/
	void borrarItemDeAlmacen(Almacen &almacen);

//Fin de _FUNCIONESAUXILIARES_HPP_
#endif
