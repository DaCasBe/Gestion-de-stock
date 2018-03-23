/*! 	
	\file    nodoEnlazadoArbolBinarioItem.hpp
	\brief   Declaraci�n del TAD NodoEnlazadoArbolBinarioItem: nodo enlazado de �rbol binario con el campo informativo Item
	\author  Daniel Castillo Bello
	\date    08-10-2017
	\version 1.0
*/

#ifndef _NodoEnlazadoArbolBinarioItem_HPP_
#define _NodoEnlazadoArbolBinarioItem_HPP_

#include <fstream>
#include "nodoItemInterfaz.hpp"
#include "item.hpp"


/*!
	\class     NodoEnlazadoArbolBinarioItem
	\brief     Definici�n de la clase NodoEnlazadoArbolBinarioItem
	\note      Hereda de la clase NodoItemInterfaz
	\attention Todos los m�todos han sido definidos como "inline"
*/
class NodoEnlazadoArbolBinarioItem:public NodoItemInterfaz{

/*!		
	\name Atributos o m�todos privados
*/
	private:
		Item * _item;                              //!< \brief campo informativo del nodo 
		NodoEnlazadoArbolBinarioItem * _leftTree;  //!< \brief puntero al sub�rbol izquierdo
		NodoEnlazadoArbolBinarioItem * _rightTree; //!< \brief puntero al sub�rbol derecho
		NodoEnlazadoArbolBinarioItem * _parent;    //!< \brief puntero al nodo padre

/*!		
	\brief     Funci�n auxiliar para liberar la memoria de los nodos del �rbol binario
	\attention M�todo privado
	\note      Funci�n codificada en el fichero cpp
	\post      El �rbol est� vac�o
	\sa        hasLeftTree, getLeftTree, hasRightTree, getRightTree, ~NodoEnlazadoArbolBinarioItem, setLeftTree, setRightTree, setParent, isEmpty
*/
		void liberarMemoria();


/*!	
	\name Funciones o m�todos p�blicos
*/
	public:

/*!
	\name Constructor
*/

/*!		
	\brief     Constructor no parametrizado 
	\note      Funci�n inline
	\attention Funci�n sobrecargada
	\post      Crea un nuevo objeto de la clase NodoEnlazadoArbolBinarioItem sin estudiante, sin sub�rboles izquierdo y derecho y sin padre
	\sa        setItem, setLeftTree, setRightTree, setParent, getItem, getLeftTree, getRightTree, getParent
*/
		inline NodoEnlazadoArbolBinarioItem(){
			_item=NULL;
			setLeftTree(NULL);
			setRightTree(NULL);
			setParent(NULL);
			
			//Postcondici�n
			#ifndef NDEBUG
				assert(getLeftTree()==NULL and getRightTree()==NULL and getParent()==NULL);
			#endif
		}
 
/*!		
	\brief     Constructor parametrizado 
	\note      Funci�n inline
	\attention Funci�n sobrecargada
	\param     item: campo informativo del nodo 
	\param     lefTree: puntero al nodo lefTree
	\param     rightTree: puntero al nodo rightTree
	\post      Crea un nuevo objeto de la clase NodoEnlazadoArbolBinarioItem con los valores de los argumentos
	\sa        setItem, setLeftTree, setRightTree, setParent
*/
		inline NodoEnlazadoArbolBinarioItem(Item const &item,NodoEnlazadoArbolBinarioItem * lefTree,NodoEnlazadoArbolBinarioItem * rightTree){
			_item=new Item(item);
			setLeftTree(lefTree);
			setRightTree(rightTree);
			setParent(NULL);
			
			//Postcondici�n
			#ifndef NDEBUG
				assert(getItem()==item and getLeftTree()==lefTree and getRightTree()==rightTree);
			#endif
		}

/*!
	\name Destructor
*/
 
/*!		
	\brief Destructor
	\note  Funci�n inline
	\sa    liberarMemoria
*/
		~NodoEnlazadoArbolBinarioItem(){
			liberarMemoria(); //Liberamos la memoria del �rbol
		}


/*!
	\name Observadores
*/

/*!
	\brief   Comprueba si el campo informativo es nulo
	\warning Funci�n de tipo "const": no puede modificar al objeto actual
	\return  Verdadero, si el �rbol est� vac�o; falso, en caso contrario
*/
		inline bool isEmpty()const{
			return (_item==NULL);
		}


/*!	
	\brief  M�todo p�blico que permite conocer el campo informativo del nodo 
	\note   Funci�n inline
	\pre    El �rbol no est� vac�o
	\return Devuelve el valor del atributo _item
	\sa     isEmpty
*/
		 inline Item const &getItem()const{
		 	//Precondici�n
			#ifndef NDEBUG
			 	assert(isEmpty()==false);	
			#endif	

		 	return *(_item); //Se devuelve el contenido de la informaci�n apuntada por _item
		}


/*!
	\brief  Comprueba si existe el sub�rbol izquierdo 
	\note   Funci�n inline
	\return Verdadero, si el nodo tiene hijo izquierdo; falso en caso contrario
	\sa     getLeftTree
*/
		inline bool hasLeftTree()const{
			return (getLeftTree()!=NULL);
		}

/*!
	\brief   Comprueba si existe el sub�rbol derecho 
	\note    Funci�n inline
	\return  Verdadero, si el nodo tiene hijo derecho; falso en caso contrario
	\sa      getRightTree
*/
		
		inline bool hasRightTree()const{
			return (getRightTree()!=NULL);
		}

/*!
	\brief   Comprueba si existe el nodo padre 
	\note    Funci�n inline
	\return  Verdadero, si el nodo tiene padre; falso en caso contrario
	\sa  	 getParent
*/
		inline bool hasParent()const{
			return (getParent()!=NULL);
		}

/*!	
	\brief   M�todo p�blico que permite acceder al sub�rbol izquierdo
	\note    Funci�n inline
	\warning M�todo "const" que no modifica el objeto de la clase
	\return  Devuelve el puntero al nodo _leftTree
*/
		inline NodoEnlazadoArbolBinarioItem * getLeftTree()const{
		 	return _leftTree;
		}


/*!	
	\brief   M�todo p�blico que permite acceder al sub�rbol derecho
	\note    Funci�n inline
	\warning M�todo "const" que no modifica el objeto de la clase
	\return  Devuelve el puntero al nodo rightTree
*/
		inline NodoEnlazadoArbolBinarioItem * getRightTree()const{
		 	return _rightTree;
		}

/*!	
	\brief   M�todo p�blico que permite acceder al nodo padre
	\note    Funci�n inline
	\warning M�todo "const" que no modifica el objeto de la clase
	\return  Devuelve el puntero al nodo rightTree
*/
		inline NodoEnlazadoArbolBinarioItem * getParent()const{
		 	return _parent;
		}

/*!
	\brief   Devuelve el n�mero de elementos o items del �rbol binario
	\note    Funci�n codificada en el fichero cpp
	\warning M�todo "const" que no modifica el objeto de la clase
	\return  items que tiene el �rbol
	\sa      isEmpty, hasLeftTree, getLeftTree, hasRightTree, getRightTree
*/
	    	int nItems()const;


/*!
	\brief  Comprueba si existe el item buscado
	\note   Funci�n codificada en el fichero cpp
	\param  item con el nombre del item a buscar
	\return Verdadero, si el item existe; falso, en caso contrario
	\sa     isEmpty, getItem, hasLeftTree, getLeftTree, hasRightTree, getRightTree
*/
		bool exists(Item const &item);


/*!
	\brief     Develve un item que existe
	\note      Funci�n codificada en el fichero cpp
	\attention Funci�n sobrecargada
	\warning   M�todo "const" que no modifica el objeto de la clase
	\param     item con el nombre del item que se quiere obtener
	\pre       Existe el item que se quiere obtener
	\return    Item
	\sa        exists, getItem, getLeftTree, getRightTree
	
*/
		Item const &getItem(Item const &item);


/*!
	\brief     Develve un item que existe
	\note      Funci�n codificada en el fichero cpp
	\attention Funci�n sobrecargada
	\warning   M�todo "const" que no modifica el objeto de la clase
	\param     indice del item que se quiere obtener
	\pre       El �rbol no esta vac�o
	\pre       El �ndice debe ser menor o igual al n�mero de items del �rbol
	\return    Item
	\sa        isEmpty, nItems, hasLeftTree, getLeftTree, getItem, getRightTree
*/
		Item const &getItem(int indice);

/*!
    \brief   Devuelve el menor item del �rbol actual
	\note    Funci�n codificada en el fichero cpp
	\warning M�todo "const" que no modifica el objeto de la clase
	\pre     El �rbol no esta vac�o
	\return  Item
	\sa      isEmpty, hasLeftTree, getLeftTree, getItem
*/
		Item const &getMinor()const;

/*!
	\name Modificadores
*/

/*!	
	\brief   M�todo p�blico que permite modificar el campo informativo del nodo
	\note    Funci�n inline
	\warning La clase Item debe tener sobrecargado el operador de asignaci�n "="
	\param   nuevoItem: nuevo valor del campo informativo
	\post    El campo informativo del nodo actual es igual al par�metro pasado como argumento
	\return  void
	\sa      getItem
*/
		inline void setItem(Item const &nuevoItem){
			//Si el item actual es nulo
			if(_item==NULL){
				//Se reserva memoria y se copia el nuevo item
				_item=new Item(nuevoItem);
			}

			//Si ya se ha reservado memoria para item
			else{
				//Se copia el nuevo item en el item actual
				*(_item)=nuevoItem;
			}
			
			//Postcondici�n
			#ifndef NDEBUG
				assert(getItem()==nuevoItem);
			#endif
		}		


/*!	
	\brief  M�todo p�blico que permite modificar el sub�rbol izquierdo
	\note   Funci�n inline
	\param  lefTree: nuevo puntero al nodo lefTree
	\post   El hijo izquierdo es igual al par�metro pasado como argumento
	\return void
	\sa     getLeftTree
*/
		inline void setLeftTree(NodoEnlazadoArbolBinarioItem * lefTree){
			_leftTree=lefTree;
			
			//Postcondici�n
			#ifndef NDEBUG
				assert(getLeftTree()==lefTree);
			#endif
		}

		
/*!	
	\brief  M�todo p�blico que permite modificar el sub�rbol derecho
	\note   Funci�n inline
	\param  rightTree: nuevo puntero al nodo rightTree
	\post   El hijo derecho es igual al par�metro pasado como argumento
	\return void
	\sa     getRightTree
*/
		inline void setRightTree(NodoEnlazadoArbolBinarioItem * rightTree){
			_rightTree=rightTree;
			
			//Postcondici�n
			#ifndef NDEBUG
				assert(getRightTree()==rightTree);
			#endif
		}


/*!	
	\brief  M�todo p�blico que permite modificar el nodo padre
	\note   Funci�n inline
	\param  parent: nuevo puntero al nodo padre
	\post   El nodo padre es igual al par�metro pasado como argumento
	\return void
	\sa     getParent
*/
		inline void setParent(NodoEnlazadoArbolBinarioItem * parent){
			_parent=parent;
			
			//Postcondici�n
			#ifndef NDEBUG
				assert(getParent()==parent);
			#endif
		}



/*!
	\brief     Modifica los datos de un item
	\note      Funci�n codificada en el fichero cpp
	\attention Permitir� modificar la cantidad
	\param     item con el nombre del item a modificar
	\pre       Existe el item con el nombre del item
	\post      Existe el item con el nombre del item
	\return    void
	\sa        exists, setItem
*/
		void setObject(Item const &item);

/*!
	\brief  Inserta un item de forma ordenada por el nombre
	\note   Funci�n codificada en el fichero cpp
	\param  item que contiene la informacion del item a insertar
	\pre    No existe el item a insertar
	\post   Existe el item insertado
	\return void
	\sa     exists, isEmpty, setItem, getItem, hasLeftTree, getLeftTree, setLeftTree, setRightTree, setParent, hasRightTree, getRightTree
*/
 		void insert(Item const &item);

/*!
	\brief  Borra el estudiante indicado como par�metro
	\note   Funci�n codificada en el fichero cpp
	\param  item con el nombre del item a borrar
	\pre    Existe el item a borrar
	\post   No existe el item borrado
	\return void
	\sa     exists, getItem, hasLeftTree, hasRightTree, hasParent, getParent, getLeftTree, setLeftTree, setRightTree, setParent, ~NodoEnlazadoArbolBinarioItem, setItem, getMinor
*/
		void remove(Item const &item);


/*!
	\name Escritura
*/

/*!
	\brief  Escribe los estudiantes usando el recorrido "en orden"
	\note   Funci�n codificada en el fichero cpp
	\pre    El �rbol no esta vac�o
	\return void
	\sa 	isEmpty, getLeftTree, getItem, getRightTree
*/
	 	void inorder();


/*!
	\brief  Graba un nodo en un fichero de texto
	\note   Funci�n codificada en el fichero cpp
	\param  fichero en el que se va a grabar el �rbol
	\pre    El �rbol no esta vac�o
	\return void
	\sa     isEmpty, getItem, hasLeftTree, getLeftTree, hasRightTree, getRightTree
*/
		void grabar(std::ofstream &fichero);

}; //Fin de la clase NodoEnlazadoArbolBinarioItem

//Fin  _NodoEnlazadoArbolBinarioItem_HPP_
#endif  
