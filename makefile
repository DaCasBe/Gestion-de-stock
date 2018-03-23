OBJETOS = item.o nodoEnlazadoArbolBinarioItem.o almacen.o funcionesAuxiliares.o principalAlmacen.o

CPPFLAGS = -c -g -Wall -ansi

INCLUDES = nodoEnlazadoArbolBinarioItem.hpp \
					 nodoItemInterfaz.hpp \
					 item.hpp itemInterfaz.hpp


objetivo: main.exe

#Opciones para NO depurar
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

#Para general a documentacion
doc: Doxyfile 
		doxygen

main.exe: $(OBJETOS)
												g++ $(OBJETOS) -o main.exe 	 

main.o: main.cpp funcionesAuxiliares.hpp almacen.hpp $(INCLUDES)
											g++ $(CPPFLAGS) main.cpp

funcionesAuxiliares.o: funcionesAuxiliares.cpp funcionesAuxiliares.hpp almacen.hpp $(INCLUDES)
											g++ $(CPPFLAGS) funcionesAuxiliares.cpp

almacen.o: almacen.cpp almacen.hpp $(INCLUDES)
							g++ $(CPPFLAGS) almacen.cpp

NodoEnlazadoArbolBinarioItem.o: nodoEnlazadoArbolBinarioItem.cpp $(INCLUDES)
																			g++ $(CPPFLAGS) nodoEnlazadoArbolBinarioItem.cpp

item.o: item.cpp item.hpp itemInterfaz.hpp
							g++ $(CPPFLAGS) item.cpp

clean:
	rm -rf *~ $(OBJETOS)

