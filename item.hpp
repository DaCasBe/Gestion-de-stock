/*!	
	\file    item.hpp
	\brief   Declaración del TAD Item
	\author  Daniel Castillo Bello
	\date    08-10-2017
	\version 1.0
*/

#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <string>
#include <iostream>
#include <cassert>

#include "itemInterfaz.hpp"

/*!	
  \class Item
  \brief Declaración de los atributos y métodos de la clase Item
*/
class Item:public ItemInterfaz{

/*!		
	\name Atributos o métodos privados de la clase Item
*/
	private:
		std::string _nombre;    //!< \brief Nombre del item
		int _cantidad;          //!< \brief Cantidad del item

/*!		
	\name \name Métodos públicos de la clase Item
*/
	public:

/*!	
	\name Constructores
*/
		
/*!		
	\brief Constructor parametrizado con todos los argumentos con valores por defecto
	\note  Función inline
	\param nombre del item creado
	\param cantidad: cantidad del item creado
	\post  Crea un nuevo objeto de la clase Item con los valores de los argumentos
	\sa    setNombre, setCantidad
*/
	Item(std::string nombre="",int cantidad=0){
		setNombre(nombre);
		setCantidad(cantidad);
	}
	
		
/*!		
	\brief Constructor de copia  
	\note  Función inline
	\param item: objeto de tipo Item
	\post  Crea un nuevo objeto de la clase Item con los valores de un Item existente
	\sa    setNombre, setCantidad
*/
	Item(const Item &item){
		setNombre(item.getNombre());
		setCantidad(item.getCantidad());
	}


/*!		
	\brief Destructor  
	\note  Función inline
	\sa    setNombre, setCantidad
*/
	~Item(){
		setNombre("");
		setCantidad(0);
	}


/*!	
	\name Observadores
*/

/*!	
	\brief  Método público que permite conocer el nombre del item
	\note   Función inline
	\return Devuelve el nombre del item
*/
	inline const std::string &getNombre()const{
		return _nombre;
	}


/*!	
	\brief  Método público que permite conocer la cantidad del item
	\note   Función inline
	\return Devuelve la cantidad del item
*/
	inline int getCantidad()const{
		return _cantidad;
	}


/*!	
	\name Modificadores
*/
		
/*!	
	\brief  Método público que permite modificar el nombre del item
	\note   Función inline
	\param  nombre: nuevo nombre del item
	\post   El nombre del item es igual al parámetro pasado como argumento
	\return void
	\sa     getNombre
*/
	inline void setNombre(const std::string &nombre){
		_nombre=nombre;
		
		//Postcondición
		#ifndef NDEBUG
			assert(getNombre()==nombre);
		#endif
	}

		
/*!	
	\brief  Método público que permite modificar la cantidad del item
	\note   Función inline
	\param  cantidad: nueva cantidad del item
	\post   La cantidad del item es igual al parámetro pasado como argumento
	\return void
	\sa     getCantidad
*/
	inline void setCantidad(const int &cantidad){
		_cantidad=cantidad;
		
		//Postcondición
		#ifndef NDEBUG
			assert(getCantidad()==cantidad);
		#endif
	}
		
/*!	
	\name Funciones de E/S
*/
		
/*!		
	\brief Lee por teclado los datos de un item
	\post  Se modifican los atributos del item usando valores introducidos por el teclado
*/
	void leerItem();

	
/*!		
	\brief Imprime por pantalla los datos de un item    
	\pre   El item debe tener sus datos cumplimentados
*/
	void escribirItem()const;


/*!	
	\name Operadores
*/
	
/*!		
	\brief  Operador de asignación entre objetos de tipo Item  
	\param  item: objeto de tipo Item
	\post   El objeto actual es igual al parámetro
	\return Devuelve una referencia al objeto actual
*/
	Item &operator=(const Item &item);
		
/*!		
	\brief  Operador que compara la igualdad lexicográfica por el nombre de dos items
	\param  item: objeto de tipo Item
	\return Verdadero, si el nombre de los items son iguales; falso, en caso contrario
*/
	bool operator==(const Item &item)const;

		
/*!		
	\brief  Operador que compara la desigualdad lexicográfica por el nombre de dos items
	\param  item: item
	\return Verdadero si el item actual precede lexicográficamente al item pasado como argumento; falso, en caso contrario
*/
	bool operator<(const Item &item)const;



//! \name Funciones amigas para poder acceder a la parte privada de la clase Item

/*!		
	\brief  Operador de inserción  
	\param  i: flujo de entrada
	\param  item: objeto de tipo Item
	\post   Se modifican los atributos del item usando los valores insertados por el flujo de entrada
	\return Devuelve el stream de entrada
*/
	friend std::istream &operator>>(std::istream &i,Item &item);

/*!		
	\brief  Operador de extracción  
	\param  o: flujo de salida
	\param  item: objeto de tipo Item
	\post   Se escriben los valores de los atributos del item en el flujo de salida
	\return Devuelve el stream de salida
*/
	friend std::ostream &operator<<(std::ostream &o,Item const &item);
	
}; //Fin de la clase Item

//Fin de _ITEM_HPP_
#endif
