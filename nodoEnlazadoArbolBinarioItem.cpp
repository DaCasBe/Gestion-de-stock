/*!
	\file    nodoEnlazadoArbolBinarioEstudiante.cpp
	\brief   CÃ³digo de la clase nodoEnlazadoArbolBinarioEstudiante
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

#include <cassert>
#include <fstream>

#include "nodoEnlazadoArbolBinarioEstudiante.hpp"
#include "estudiante.hpp"

void NodoEnlazadoArbolBinarioItem::liberarMemoria(){
	if(hasLeftTree()){ //Liberamos la memoria del subárbol hijo izquierdo
		getLeftTree()->liberarMemoria();
	}
			
	if(hasRightTree()){ //Liberamos la memoria del subárbol hijo derecho
		getRightTree()->liberarMemoria();
	}
	
	//Borramos los atributos del nodo raíz
	delete _item;
	delete getLeftTree();
	delete getRightTree();
		
	_item=NULL;
	setLeftTree(NULL);
	setRightTree(NULL);
	setParent(NULL);
	
	//Postcondición
	#ifndef NDEBUG
		assert(isEmpty());
	#endif
}

int NodoEnlazadoArbolBinarioItem::nItems()const{
	int items=0;

	if(!isEmpty()){
		items++; //Sumamos el item del nodo raíz

		if(hasLeftTree()){
			items=items+getLeftTree()->nItems(); //Sumamos los items de su subárbol hijo izquierdo
		}

		if(hasRightTree()){
			items=items+getRightTree()->nItems(); //Sumamos los items de su subárbol hijo derecho
		}
	}

	return items;
}

bool NodoEnlazadoArbolBinarioItem::exists(Item const &item){
	if(isEmpty()){
		return false; //Si el árbol está vacío, es imposible que exista el item
	}

	else{ //El árbol no está vacío
		if(getItem()==item){ //El nodo raíz contiene el item que buscamos
			return true;
		}

		else{ //El nodo raíz no contiene el item que buscamos
			if(item<getItem()){ //El item ha de encontrarse a la izquierda del árbol
				if(hasLeftTree()){
					return getLeftTree()->exists(item); //Buscamos el iem en el subárbol hijo izquierdo
				}

				else{
					return false;
				}
			}

			else{ //El item ha de encontrarse a la derecha del árbol
				if(hasRightTree()){
					return getRightTree()->exists(item); //Buscamos el item en el subárbol hijo derecho
				}

				else{
					return false;
				}
			}
		}
	}
}

Item const &NodoEnlazadoArbolBinarioItem::getItem(Item const &item){
	//Precondición
	#ifndef NDEBUG
		assert(exists(item));
	#endif

	if(getItem()==item){ //El nodo raíz contiene el item que buscamos
		return getItem();
	}

	else{
		if(item<getItem()){ //El item está a la izquierda
			return getLeftTree()->getItem(item); //Buscamos el item en el subárbol hijo izquierdo
		}

		else{ //El item está a la derecha
			return getRightTree()->getItem(item); //Buscamos el item en el subárbol hijo derecho
		}
	}
}

Item const &NodoEnlazadoArbolBinarioItem::getItem(int indice){
	//Precondición
	#ifndef NDEBUG
		assert(!isEmpty() and indice<=nItems());
	#endif

	if(hasLeftTree()){ //El nodo raíz tiene un subárbol hijo izquierdo
		if(indice==getLeftTree()->nItems()){ //El item está en el nodo raíz
			return getItem();
		}

		else if(indice<getLeftTree()->nItems()){ //El item está a la izquierda
			return getLeftTree()->getItem(indice); //Buscamos el item en el subárbol hijo izquierdo
		}

		else{ //El item está a la derecha
			return getRightTree()->getItem(indice-(getLeftTree()->nItems()+1)); //Buscamos el item en el subárbol hijo derecho
		}
	}

	else{ //El nodo raíz no tiene un subárbol hijo izquierdo
		if(indice==0){ //El item está en el nodo raíz
			return getItem();
		}

		else{ //El item está a la derecha
			return getRightTree()->getItem(indice-1); //Buscamos el item en el subárbol hijo derecho
		}
	}
}

Item const &NodoEnlazadoArbolBinarioItem::getMinor()const{
	//Precondición
	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	if(hasLeftTree()){ //El nodo raíz tiene un subárbol hijo izquierdo
		return getLeftTree()->getMinor();
	}

	else{ //El nodo raíz no tiene un subárbol hijo izquierdo, por lo tanto, es el que contiene el item menor
		return getItem();
	}
}

void NodoEnlazadoArbolBinarioItem::setObject(Item const &item){
	//Precondición
	#ifndef NDEBUG
		assert(exists(item));
	#endif

	if(item==getItem()){ //El nodo raíz contiene el item a modificar
		setItem(item); //Modificamos el item
	}
	
	else if(item<getItem()){ //El item es menor que el item del nodo actual
		getLeftTree()->setObject(item); //Buscamos el item en el subárbol hijo izquierdo
	}
	
	else{ //El item es mayor que el item del nodo actual
		getRightTree()->setObject(item); //Buscamos el item en el subárbol hijo derecho
	}

	//Postcondición
	#ifndef NDEBUG
		assert(exists(item));
	#endif
}

void NodoEnlazadoArbolBinarioItem::insert(Item const &item){
	//Precondición
	#ifndef NDEBUG
		assert(!exists(item));
	#endif

	if(isEmpty()){ //La lista esta vacía
		setItem(item); //Insertamos el item en el nodo raíz
	}

	else{ //La lista no esta vacía
		if(item<getItem()){ //El item es menor que el del nodo actual
			if(hasLeftTree()){ //El nodo actual tiene hijo izquierdo
				getLeftTree()->insert(item); //Insertamos el item en el subárbol hijo izquierdo
			}

			else{ //El nodo actual no tiene hijo izquierdo
				//Creamos un nuevo nodo con los datos del item a insertar y lo enlazamos como corresponde
				NodoEnlazadoArbolBinarioItem * nuevo;
				nuevo=new NodoEnlazadoArbolBinarioItem();

				nuevo->setItem(item);
				nuevo->setLeftTree(NULL);
				nuevo->setRightTree(NULL);
				nuevo->setParent(this);

				setLeftTree(nuevo);
			}
		}

		else{ //El item es mayor que el del nodo actual
			if(hasRightTree()){ //El nodo actual tiene hijo derecho
				getRightTree()->insert(item); //Insertamos el item en el subárbol hijo derecho
			}

			else{ //El nodo actual no tiene hijo derecho
				//Creamos un nuevo nodo con los datos del item a insertar y lo enlazamos como corresponde
				NodoEnlazadoArbolBinarioItem * nuevo;
				nuevo=new NodoEnlazadoArbolBinarioItem();

				nuevo->setItem(item);
				nuevo->setLeftTree(NULL);
				nuevo->setRightTree(NULL);
				nuevo->setParent(this);

				setRightTree(nuevo);
			}
		}
	}

	//Postcondición
	#ifndef NDEBUG
		assert(exists(item));
	#endif
}

void NodoEnlazadoArbolBinarioItem::remove(Item const &item){
	Item i(item); //Creamos un estudiante auxiliar
	
	//Precondición
	#ifndef NDEBUG
		assert(exists(i));
	#endif
	
	if(item==getItem()){ //El nodo actual contiene el item a eliminar
		NodoEnlazadoArbolBinarioItem * auxiliar; //Creamos un nodo auxiliar
		
		if(!hasLeftTree() and !hasRightTree()){ //El nodo actual no tiene hijos
			if(hasParent()){ //El nodo actual tiene padre
				if(getParent()->getLeftTree()==this){ //El nodo actual es el hijo izquierdo de su padre
					getParent()->setLeftTree(NULL);
				}

				else{ //El nodo actual es el hijo derecho de su padre
					getParent()->setRightTree(NULL);
				}
				
				//Borramos el item del nodo actual
				delete _item;
				_item=NULL;
			}
			
			else{ //El nodo atual no tiene padre
				//Borramos el item del nodo actual
				_item=NULL;
			}
		}

		else if(hasLeftTree() and !hasRightTree()){ //El nodo actual sólo tiene hijo izquierdo
			if(hasParent()){ //El nodo actual tiene padre
				if(getParent()->getLeftTree()==this){ //El nodo actual es el hijo izquierdo de su padre
					getParent()->setLeftTree(getLeftTree());
				}

				else{ //El nodo actual es el hijo derecho de su padre
					getParent()->setRightTree(getLeftTree());
				}
				
				getLeftTree()->setParent(getParent()); //Enlazamos el hijo del nodo actual con el padre de este
				
				_item=NULL; //Borramos el item el nodo actual
				
				//Desenlazamos y borramos el nodo actual
				auxiliar=this;
				auxiliar->setParent(NULL);
				auxiliar->setLeftTree(NULL);
				
				delete auxiliar;
			}

			else{ //El nodo actual no tiene padre
				*this=*getLeftTree(); //Hacemos que el nodo actual sea el hijo
				
				//Desenlazamos el nodo actual
				getParent()->setLeftTree(NULL);
				setParent(NULL);
			}
		}

		else if(!hasLeftTree() and hasRightTree()){ //El nodo actual sólo tiene hijo derecho
			if(hasParent()){ //El nodo actual tiene padre

				if(getParent()->getLeftTree()==this){ //El nodo actual es el hijo izquierdo de su padre
					getParent()->setLeftTree(getRightTree());
				}

				else{ //El nodo actual es el hijo derecho de su padre
					getParent()->setRightTree(getRightTree());
				}

				getRightTree()->setParent(getParent()); //Enlazamos el hijo del nodo actual con el padre de este
				
				_item=NULL; //Borramos el item el nodo actual
				
				//Desenlazamos y borramos el nodo actual
				auxiliar=this;
				auxiliar->setParent(NULL);
				auxiliar->setRightTree(NULL);
			
				delete auxiliar;
				
			}

			else{ //El nodo actual no tiene padre
				*this=*getRightTree(); //Hacemos que el nodo actual sea el hijo
				
				//Desenlazamos el nodo actual
				getParent()->setRightTree(NULL);
				setParent(NULL);
			}
		}

		else{ //El nodo actual tiene hijo izquierdo y hijo derecho
			setItem(getRightTree()->getMinor()); //Asignamos al nodo actual el item del descendiente menor de su hijo derecho
			getRightTree()->remove(getRightTree()->getMinor()); //Borramos el item del descendiente menor del hijo derecho del nodo actual
		}
	}

	else if(item<getItem()){ //El item es menor que el item del nodo actual
		getLeftTree()->remove(item); //Borramos el item en el subárbol hijo izquierdo
	}

	else{ //El item es mayor que el item del nodo actual
		getRightTree()->remove(item); //Borramos el item en el subárbol hijo derecho
	}

	//Postcondición
	#ifndef NDEBUG
		assert(!exists(i));
	#endif
}

void NodoEnlazadoArbolBinarioItem::inorder(){
	//Precondición
	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	if(hasLeftTree()){ //El nodo actual tiene hijo izquierdo
		getLeftTree()->inorder(); //Escribimos inorden el subárbol hijo izquierdo
	}

	getItem().escribirItem(); //Escribimos el item del nodo actual
	std::cout << std::endl;

	if(hasRightTree()){ //El nodo actual tiene hijo derecho
		getRightTree()->inorder(); //Escribimos inorden el subárbol hijo derecho
	}
}

void NodoEnlazadoArbolBinarioItem::grabar(std::ofstream &fichero){
	//Precondición
	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	fichero << getItem(); //Grabamos el item del nodo actual

	if(hasLeftTree()){ //El nodo actual tiene hijo izquierdo
		getLeftTree()->grabar(fichero); //Grabamos los items del subárbol hijo izquierdo
	}

	if(hasRightTree()){ //El nodo actual tiene hijo derecho
		getRightTree()->grabar(fichero); //Grabamos los items del subárbol hijo derecho
	}
}
