/*!	
	\file    almacen.hpp
	\brief   Definición de la clase Almacen
	\author  Daniel Castillo Bello
	\date    13-10-2017
	\version 1.0
*/

#ifndef _ALMACEN_HPP_
#define _ALMACEN_HPP_

#include <cassert>
#include <string>

#include "almacenInterfaz.hpp"
#include "nodoEnlazadoArbolBinarioItem.hpp"


/*!	
	\class Almacen
	\brief Representa la clase Almacen
*/
class Almacen:public AlmacenInterfaz{

/*!		
	\name Métodos públicos de la clase Almacen
*/
	private:
		int _codigo;	                               //!<  \brief Código del almacén
		std::string _nombre;                           //!<  \brief Nombre del almacén
		NodoEnlazadoArbolBinarioItem _arbol;           //!<  \brief Árbol binario ordenado de items del almacén

/*!		
	\name  Métodos públicos de la clase Almacen
*/
	public: 


/*!	
	\name Constructor
*/

/*!		
	\brief     Constructor parametrizado 
	\note      Función inline
	\post      Crea un nuevo objeto de la clase Almacen con valores por defecto para el código y el nombre
	\sa        setCodigo, setNombre
*/
	Almacen(int codigo=0,std::string const &nombre=""){
		this->setCodigo(codigo);
		this->setNombre(nombre);

		/*
			El constructor de NodoEnlazadoArbolBinarioItem
    			asigna valores nulos
		*/
	}


/*!	
	\name Observadores
*/

/*!		
	\brief  Devuelve el código del almacén
	\note   Función inline
	\return Número entero que representa el código numérico del almacén
*/
	inline int getCodigo()const{
		return _codigo;
	}

/*!		
	\brief  Devuelve el nombre de la asignatura
	\note   Función inline
	\return Cadena que representa el nombre del almacén
*/
	inline std::string getNombre()const{
		return _nombre;
	}


/*!		
	\brief  Indica si la asignatura tiene o no items
	\note   Función inline
	\return Verdadero si no tiene items; falso, en caso contrario
*/
	inline bool estaVacia()const{
		//Se usa el método del atributo _arbol
		return _arbol.isEmpty();
	}


/*!		
	\brief  Devuelve el número de items
	\note   Función inline
	\return Número entero que representa el número de items del almacén
*/
	inline int getNumeroItems()const{
		//Se usa el método del atributo _arbol
		return _arbol.nItems();
	} 


/*!		
	\brief   Comprueba si existe un item con un nombre 
	\note    Función inline
	\warning Función sobrecargada
	\param   item buscado
	\return  Verdadero si existe el item; falso, en caso contrario
*/
	inline bool existeItem(Item const &item){
		//Se usa el método del atributo _arbol
		return _arbol.exists(item);
	}


/*!		
	\brief   Comprueba si existe un item con un nombre 
	\note    Función inline
	\warning Función sobrecargada
	\param   nombre del item buscado
	\return  Verdadero si existe el item; falso, en caso contrario
*/
	inline bool existeItem(std::string const &nombre){
		//Se crea un item auxiliar con el nombre
		Item item(nombre,0);
   
		//Se llama a la función exists de _arbol
		return _arbol.exists(item); 
	}


/*!		
	\brief  Devuelve el item con un nombre
	\note   Función inline
	\param  nombre del item buscado
	\pre    Debe existir el item con el nombre indicado
	\return Referencia constante a un objeto de la clase Item
	\sa     existeItem
*/

	inline Item const &getItem(std::string const &nombre){
		//Precondición
		#ifndef NDEBUG
			assert(existeItem(nombre));
		#endif

		Item item(nombre,0); //Creamos un item con los datos recibidos

		return _arbol.getItem(item); //Devolvemos el item a buscar
	}



/*!		
	\brief     Devuelve el item con un nombre
	\note      Función inline
	\warning   Función sobrecargada
	\param     item que se busca en el almacén
	\pre       Debe existir el item
	\return    Objeto de la clase Item
	\sa        existeItem
*/

	inline Item const &getItem(Item const &item){
		//Precondición
		#ifndef NDEBUG
			assert(existeItem(item));
		#endif

		return _arbol.getItem(item); //Devolvemos el item a buscar
	}



/*!		
	\brief     Devuelve el item que ocupa la posición indicada
	\note      Función inline
	\warning   Función sobrecargada
	\param     indice del item que se busca en el almacén
	\pre       Debe existir el item
	\return    Objeto de la clase Item
	\sa        getNumeroItems
*/
	inline Item const &getItem(int indice){
		//Precondición
		#ifndef NDEBUG
			assert(indice<=getNumeroItems());
		#endif

		return _arbol.getItems(indice); //Devolvemos el item con el indice recibido
	}


/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el código del item
	\note   Función inline
	\param  codigo: dato de tipo entero que será el nuevo código del almacén
	\post   El código del almacén deberá tener el código asignado
	\return void
	\sa     getCodigo
*/
	inline void setCodigo(int codigo){
		codigo=codigo;
		
		//Postcondición
		#ifndef NDEBUG
			assert(getCodigo()==codigo);
		#endif
	}
	

/*!		
	\brief  Modifica el nombre del almacén
	\note   Función inline
	\param  nombre: dato de tipo cadena que será el nuevo nombre del almacén
	\post   El nombre del almacén deberá tener el nombre asignado
	\return void
	\sa     getNombre
*/
	inline void setNombre(std::string const &nombre){
		_nombre=nombre;
		
		//Postcondición
		#ifndef NDEBUG
			assert(getNombre()==nombre);
		#endif
	}
	
/*!		
	\brief     Modifica el item indicado
	\note      Función inline
	\attention Solamente se pueden modificar los atributos que no forman parte de la clave, es decir, la cantidad
	\param     item: objeto de tipo Item
	\pre       La clave del parámetro item (nombre) debe ser igual a la clave del item actual
	\post      La clave del parámetro item (nombre) debe ser igual a la clave del item actual
	\return    void
	\sa        existeItem
*/
	inline void setItem(Item const &item){
		//Precondición
		#ifndef NDEBUG
			assert(existeItem(item));
		#endif

		_arbol.setItem(item); //Modificamos el item

		//Postcondición
		#ifndef NDEBUG
			assert(existeItem(item));
		#endif
	}


/*!		
	\brief   Inserta un item de forma ordenada según el nombre
	\note    Función inline
	\warning Función sobrecargada
	\param   nombre del item
	\param   cantidad del item
	\pre     No debe existir otro item con el mismo nombre
	\post    El item está insertado en el almacén
	\post    El número de items debe haberse aumentado en uno
	\return  Verdadero, en el caso de que logre insertar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool insertarItem(std::string const &nombre,int cantidad){
		//Precondición
		#ifndef NDEBUG
			assert(!existeItem(nombre));
		#endif

		int old=getNumeroItems();
		Item item(nombre,cantidad); //Creamos un item con los datos recibidos

		if(existeItem(item)){ //Ya existe el item
			return false;
		}

		else{ //No existe el item
			_arbol.insert(item); //Insertamos el item

			//Postcondición
			#ifndef NDEBUG
				assert(existeItem(nombre) and old==getNumeroItems()-1);
			#endif

			return true;
		}
	}

/*!		
	\brief   Inserta un item de forma ordenada según el nombre
	\note    Función inline
	\warning Función sobrecargada
	\param   item que se va a insertar
	\pre     El item no debe existir en el almacén
	\post    El item está insertado en el almacén
	\post    El número de items debe haberse aumentado en uno
	\return  Verdadero, en el caso de que logre insertar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool insertarItem(Item const &item){
		//Precondición
		#ifndef NDEBUG
			assert(!existeItem(item));
		#endif

		int old=getNumeroItems();

		if(existeItem(item)){ //Ya existe el item
			return false;
		}

		else{ //No existe el item
			_arbol.insert(item); //Insertamos el item

			//Postcondición
			#ifndef NDEBUG
				assert(existeItem(item) and old==getNumeroItems()-1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el item con el nombre indicado
	\note    Función inline
	\warning Función sobrecargada
	\param   nombre del item buscado
	\pre 	 Debe existir el item con el nombre indicado
	\post    No debe existir un item con el nombre indicado
	\post    El número de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool borrarItem(std::string const &nombre){
		//Precondición
		#ifndef NDEBUG
			assert(existeItem(nombre));
		#endif

		int old=getNumeroItems();
		Item item(nombre,0); //Creamos un item con los datos recibidos

		if(!existeItem(item)){ //No existe el item
			return false;
		}

		else{ //Si existe el item
			_arbol.remove(item); //Borramos el item

			//Postcondición
			#ifndef NDEBUG
				assert(!existeItem(nombre) and old==getNumeroItems()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el item indicado
	\note    Función inline
	\warning Función sobrecargada
	\param   item del almacén
	\pre     Debe existir el item indicado
	\post    El número de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool borrarItem(Item const &item){
		//Precondición
		#ifndef NDEBUG
			assert(existeItem(item.getNombre()));
		#endif

		int old=getNumeroItems();

		if(!existeItem(item)){ //No existe el item
			return false;
		}

		else{ //Sí existe el item
			_arbol.remove(item); //Borramos el item

			//Postcondición
			#ifndef NDEBUG
				assert(!existeItem(item.getNombre()) and old==getNumeroItems()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el item indicado
	\note    Función inline
	\warning Función sobrecargada
	\param   pos posición del item que se va a borrar
	\pre     El índice debe ser válido
	\post    El número de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      getNumeroItems
*/
	inline bool borrarItem(int pos){
		//Precondición
		#ifndef NDEBUG
			assert(pos<=getNumeroItems());
		#endif

		int old=getNumeroItems();

		if(pos>getNumeroItems()){ //La posición es mayor que el número de items
			return false;
		}

		else{ //La posición no es mayor que el número de items
			_arbol.remove(_arbol.getItem(pos)); //Borramos el estudiante en la posición indicada

			//Postcondición
			#ifndef NDEBUG
				assert(old==getNumeroItems()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief  Muestra por la pantalla la información de los items de un almacén
	\note   Función inline
	\return void
*/
	inline void consultarItems(){
 		_arbol.inorder();
	}


/*!		
	\brief  Carga un almacén desde un fichero
	\param  nombreFichero: nombre del fichero del almacén
	\return Verdadero, si se ha cargado correctamente; falso, en caso contrario
	\sa     insertarItem
*/
	bool cargarFichero(std::string const &nombreFichero);

/*!		
	\brief  Graba un almacén en un fichero
	\param  nombreFichero: nombre del fichero del almacén
	\return Verdadero, si se ha grabado correctamente; falso, en caso contrario
	\sa     getNombre, getCodigo
*/
	bool grabarFichero(std::string const &nombreFichero);
}; //Fin de la clase Almacén

#endif // _ALMACEN_HPP_
