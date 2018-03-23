/*!	
	\file    almacen.hpp
	\brief   Definici�n de la clase Almacen
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
	\name M�todos p�blicos de la clase Almacen
*/
	private:
		int _codigo;	                               //!<  \brief C�digo del almac�n
		std::string _nombre;                           //!<  \brief Nombre del almac�n
		NodoEnlazadoArbolBinarioItem _arbol;           //!<  \brief �rbol binario ordenado de items del almac�n

/*!		
	\name  M�todos p�blicos de la clase Almacen
*/
	public: 


/*!	
	\name Constructor
*/

/*!		
	\brief     Constructor parametrizado 
	\note      Funci�n inline
	\post      Crea un nuevo objeto de la clase Almacen con valores por defecto para el c�digo y el nombre
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
	\brief  Devuelve el c�digo del almac�n
	\note   Funci�n inline
	\return N�mero entero que representa el c�digo num�rico del almac�n
*/
	inline int getCodigo()const{
		return _codigo;
	}

/*!		
	\brief  Devuelve el nombre de la asignatura
	\note   Funci�n inline
	\return Cadena que representa el nombre del almac�n
*/
	inline std::string getNombre()const{
		return _nombre;
	}


/*!		
	\brief  Indica si la asignatura tiene o no items
	\note   Funci�n inline
	\return Verdadero si no tiene items; falso, en caso contrario
*/
	inline bool estaVacia()const{
		//Se usa el m�todo del atributo _arbol
		return _arbol.isEmpty();
	}


/*!		
	\brief  Devuelve el n�mero de items
	\note   Funci�n inline
	\return N�mero entero que representa el n�mero de items del almac�n
*/
	inline int getNumeroItems()const{
		//Se usa el m�todo del atributo _arbol
		return _arbol.nItems();
	} 


/*!		
	\brief   Comprueba si existe un item con un nombre 
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   item buscado
	\return  Verdadero si existe el item; falso, en caso contrario
*/
	inline bool existeItem(Item const &item){
		//Se usa el m�todo del atributo _arbol
		return _arbol.exists(item);
	}


/*!		
	\brief   Comprueba si existe un item con un nombre 
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   nombre del item buscado
	\return  Verdadero si existe el item; falso, en caso contrario
*/
	inline bool existeItem(std::string const &nombre){
		//Se crea un item auxiliar con el nombre
		Item item(nombre,0);
   
		//Se llama a la funci�n exists de _arbol
		return _arbol.exists(item); 
	}


/*!		
	\brief  Devuelve el item con un nombre
	\note   Funci�n inline
	\param  nombre del item buscado
	\pre    Debe existir el item con el nombre indicado
	\return Referencia constante a un objeto de la clase Item
	\sa     existeItem
*/

	inline Item const &getItem(std::string const &nombre){
		//Precondici�n
		#ifndef NDEBUG
			assert(existeItem(nombre));
		#endif

		Item item(nombre,0); //Creamos un item con los datos recibidos

		return _arbol.getItem(item); //Devolvemos el item a buscar
	}



/*!		
	\brief     Devuelve el item con un nombre
	\note      Funci�n inline
	\warning   Funci�n sobrecargada
	\param     item que se busca en el almac�n
	\pre       Debe existir el item
	\return    Objeto de la clase Item
	\sa        existeItem
*/

	inline Item const &getItem(Item const &item){
		//Precondici�n
		#ifndef NDEBUG
			assert(existeItem(item));
		#endif

		return _arbol.getItem(item); //Devolvemos el item a buscar
	}



/*!		
	\brief     Devuelve el item que ocupa la posici�n indicada
	\note      Funci�n inline
	\warning   Funci�n sobrecargada
	\param     indice del item que se busca en el almac�n
	\pre       Debe existir el item
	\return    Objeto de la clase Item
	\sa        getNumeroItems
*/
	inline Item const &getItem(int indice){
		//Precondici�n
		#ifndef NDEBUG
			assert(indice<=getNumeroItems());
		#endif

		return _arbol.getItems(indice); //Devolvemos el item con el indice recibido
	}


/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el c�digo del item
	\note   Funci�n inline
	\param  codigo: dato de tipo entero que ser� el nuevo c�digo del almac�n
	\post   El c�digo del almac�n deber� tener el c�digo asignado
	\return void
	\sa     getCodigo
*/
	inline void setCodigo(int codigo){
		codigo=codigo;
		
		//Postcondici�n
		#ifndef NDEBUG
			assert(getCodigo()==codigo);
		#endif
	}
	

/*!		
	\brief  Modifica el nombre del almac�n
	\note   Funci�n inline
	\param  nombre: dato de tipo cadena que ser� el nuevo nombre del almac�n
	\post   El nombre del almac�n deber� tener el nombre asignado
	\return void
	\sa     getNombre
*/
	inline void setNombre(std::string const &nombre){
		_nombre=nombre;
		
		//Postcondici�n
		#ifndef NDEBUG
			assert(getNombre()==nombre);
		#endif
	}
	
/*!		
	\brief     Modifica el item indicado
	\note      Funci�n inline
	\attention Solamente se pueden modificar los atributos que no forman parte de la clave, es decir, la cantidad
	\param     item: objeto de tipo Item
	\pre       La clave del par�metro item (nombre) debe ser igual a la clave del item actual
	\post      La clave del par�metro item (nombre) debe ser igual a la clave del item actual
	\return    void
	\sa        existeItem
*/
	inline void setItem(Item const &item){
		//Precondici�n
		#ifndef NDEBUG
			assert(existeItem(item));
		#endif

		_arbol.setItem(item); //Modificamos el item

		//Postcondici�n
		#ifndef NDEBUG
			assert(existeItem(item));
		#endif
	}


/*!		
	\brief   Inserta un item de forma ordenada seg�n el nombre
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   nombre del item
	\param   cantidad del item
	\pre     No debe existir otro item con el mismo nombre
	\post    El item est� insertado en el almac�n
	\post    El n�mero de items debe haberse aumentado en uno
	\return  Verdadero, en el caso de que logre insertar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool insertarItem(std::string const &nombre,int cantidad){
		//Precondici�n
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

			//Postcondici�n
			#ifndef NDEBUG
				assert(existeItem(nombre) and old==getNumeroItems()-1);
			#endif

			return true;
		}
	}

/*!		
	\brief   Inserta un item de forma ordenada seg�n el nombre
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   item que se va a insertar
	\pre     El item no debe existir en el almac�n
	\post    El item est� insertado en el almac�n
	\post    El n�mero de items debe haberse aumentado en uno
	\return  Verdadero, en el caso de que logre insertar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool insertarItem(Item const &item){
		//Precondici�n
		#ifndef NDEBUG
			assert(!existeItem(item));
		#endif

		int old=getNumeroItems();

		if(existeItem(item)){ //Ya existe el item
			return false;
		}

		else{ //No existe el item
			_arbol.insert(item); //Insertamos el item

			//Postcondici�n
			#ifndef NDEBUG
				assert(existeItem(item) and old==getNumeroItems()-1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el item con el nombre indicado
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   nombre del item buscado
	\pre 	 Debe existir el item con el nombre indicado
	\post    No debe existir un item con el nombre indicado
	\post    El n�mero de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool borrarItem(std::string const &nombre){
		//Precondici�n
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

			//Postcondici�n
			#ifndef NDEBUG
				assert(!existeItem(nombre) and old==getNumeroItems()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el item indicado
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   item del almac�n
	\pre     Debe existir el item indicado
	\post    El n�mero de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      existeItem, getNumeroItems
*/
	inline bool borrarItem(Item const &item){
		//Precondici�n
		#ifndef NDEBUG
			assert(existeItem(item.getNombre()));
		#endif

		int old=getNumeroItems();

		if(!existeItem(item)){ //No existe el item
			return false;
		}

		else{ //S� existe el item
			_arbol.remove(item); //Borramos el item

			//Postcondici�n
			#ifndef NDEBUG
				assert(!existeItem(item.getNombre()) and old==getNumeroItems()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el item indicado
	\note    Funci�n inline
	\warning Funci�n sobrecargada
	\param   pos posici�n del item que se va a borrar
	\pre     El �ndice debe ser v�lido
	\post    El n�mero de items debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el item; falso, en caso contrario
	\sa      getNumeroItems
*/
	inline bool borrarItem(int pos){
		//Precondici�n
		#ifndef NDEBUG
			assert(pos<=getNumeroItems());
		#endif

		int old=getNumeroItems();

		if(pos>getNumeroItems()){ //La posici�n es mayor que el n�mero de items
			return false;
		}

		else{ //La posici�n no es mayor que el n�mero de items
			_arbol.remove(_arbol.getItem(pos)); //Borramos el estudiante en la posici�n indicada

			//Postcondici�n
			#ifndef NDEBUG
				assert(old==getNumeroItems()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief  Muestra por la pantalla la informaci�n de los items de un almac�n
	\note   Funci�n inline
	\return void
*/
	inline void consultarItems(){
 		_arbol.inorder();
	}


/*!		
	\brief  Carga un almac�n desde un fichero
	\param  nombreFichero: nombre del fichero del almac�n
	\return Verdadero, si se ha cargado correctamente; falso, en caso contrario
	\sa     insertarItem
*/
	bool cargarFichero(std::string const &nombreFichero);

/*!		
	\brief  Graba un almac�n en un fichero
	\param  nombreFichero: nombre del fichero del almac�n
	\return Verdadero, si se ha grabado correctamente; falso, en caso contrario
	\sa     getNombre, getCodigo
*/
	bool grabarFichero(std::string const &nombreFichero);
}; //Fin de la clase Almac�n

#endif // _ALMACEN_HPP_
