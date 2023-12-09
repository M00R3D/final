#include <iostream>
#include <string>
#include <cstdlib> // Necesario para el sistema de pausa

// Definición de la estructura del nodo
template<typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
};

// Función para visualizar la lista
template<typename T>
void visualizarLista(Nodo<T>* head) {
    Nodo<T>* temp = head;
    std::cout << "Lista resultante: ";
    while (temp != nullptr) {
        std::cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}

// Función para insertar un nodo en cualquier posición de la lista
template<typename T>
void insertarEnPosicion(Nodo<T>*& head, T valor, int posicion) {
    Nodo<T>* nuevoNodo = new Nodo<T>;
    nuevoNodo->dato = valor;

    if (posicion == 1 || head == nullptr) {
        nuevoNodo->siguiente = head;
        head = nuevoNodo;
    } else {
        Nodo<T>* temp = head;
        for (int i = 1; i < posicion - 1 && temp != nullptr; ++i) {
            temp = temp->siguiente;
        }
        if (temp != nullptr) {
            nuevoNodo->siguiente = temp->siguiente;
            temp->siguiente = nuevoNodo;
        } else {
            std::cout << "Posición no válida." << std::endl;
            delete nuevoNodo;
        }
    }
}

// Función para borrar el primer nodo de la lista
template<typename T>
void borrarPrimerNodo(Nodo<T>*& head) {
    if (head != nullptr) {
        Nodo<T>* temp = head;
        head = head->siguiente;
        delete temp;
    } else {
        std::cout << "La lista está vacía. No hay nodos para borrar." << std::endl;
    }
}

// Función para borrar el último nodo de la lista
template<typename T>
void borrarUltimoNodo(Nodo<T>*& head) {
    if (head != nullptr) {
        if (head->siguiente == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Nodo<T>* temp = head;
            while (temp->siguiente->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            delete temp->siguiente;
            temp->siguiente = nullptr;
        }
    } else {
        std::cout << "La lista está vacía. No hay nodos para borrar." << std::endl;
    }
}

// Función para borrar un nodo en cualquier posición de la lista
template<typename T>
void borrarEnPosicion(Nodo<T>*& head, int posicion) {
    if (head != nullptr) {
        if (posicion == 1) {
            Nodo<T>* temp = head;
            head = head->siguiente;
            delete temp;
        } else {
            Nodo<T>* temp = head;
            for (int i = 1; i < posicion - 1 && temp != nullptr; ++i) {
                temp = temp->siguiente;
            }
            if (temp != nullptr && temp->siguiente != nullptr) {
                Nodo<T>* nodoABorrar = temp->siguiente;
                temp->siguiente = temp->siguiente->siguiente;
                delete nodoABorrar;
            } else {
                std::cout << "Posición no válida." << std::endl;
            }
        }
    } else {
        std::cout << "La lista está vacía. No hay nodos para borrar." << std::endl;
    }
}

int main() {
    // Tipo de dato de la lista
    char opcionTipo;
    std::cout << "Elija el tipo de dato para la lista (i: int, c: char, s: string): ";
    std::cin >> opcionTipo;

    switch (opcionTipo) {
        case 'i':
        {
            Nodo<int>* head = nullptr;
            int opcionMenu;
            int otro;

            do {
                std::cout << "MENU:" << std::endl;
                std::cout << "1. Insertar en cualquier posición" << std::endl;
                std::cout << "2. Borrar primer nodo" << std::endl;
                std::cout << "3. Borrar último nodo" << std::endl;
                std::cout << "4. Borrar en cualquier posición" << std::endl;
                std::cout << "5. Visualizar lista" << std::endl;
                std::cout << "6. Salir" << std::endl;
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionMenu;

                switch (opcionMenu) {
                    case 1:
                    {
                        int valor, posicion;
                        std::cout << "Ingrese el dato para el nuevo nodo: ";
                        std::cin >> valor;
                        std::cout << "Ingrese la posición donde desea insertar el nodo: ";
                        std::cin >> posicion;
                        insertarEnPosicion(head, valor, posicion);
                        break;
                    }
                    case 2:
                        borrarPrimerNodo(head);
                        break;
                    case 3:
                        borrarUltimoNodo(head);
                        break;
                    case 4:
                    {
                        int posicion;
                        std::cout << "Ingrese la posición del nodo que desea borrar: ";
                        std::cin >> posicion;
                        borrarEnPosicion(head, posicion);
                        break;
                    }
                    case 5:
                        visualizarLista(head);
                        break;
                    case 6:
                        break;
                    default:
                        std::cout << "Opción no válida." << std::endl;
                        break;
                }

                if (opcionMenu != 6) {
                    std::cout << "¿Desea realizar otra operación? (1: Sí, 0: No): ";
                    std::cin >> otro;
                } else {
                    otro = 0;
                }

            } while (otro == 1);

            // Liberar la memoria de los nodos al salir
            Nodo<int>* temp = head;
            while (temp != nullptr) {
                Nodo<int>* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            break;
        }
        case 'c':
        {
            Nodo<char>* head = nullptr;
            int opcionMenu;
            char otro;
            do {
                std::cout << "MENU:" << std::endl;
                std::cout << "1. Insertar en cualquier posición" << std::endl;
                std::cout << "2. Borrar primer nodo" << std::endl;
                std::cout << "3. Borrar último nodo" << std::endl;
                std::cout << "4. Borrar en cualquier posición" << std::endl;
                std::cout << "5. Visualizar lista" << std::endl;
                std::cout << "6. Salir" << std::endl;
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionMenu;

                switch (opcionMenu) {
                    case 1:
                    {
                        char valor;
                        int posicion;
                        std::cout << "Ingrese el dato para el nuevo nodo: ";
                        std::cin >> valor;
                        std::cout << "Ingrese la posición donde desea insertar el nodo: ";
                        std::cin >> posicion;
                        insertarEnPosicion(head, valor, posicion);
                        break;
                    }
                    case 2:
                        borrarPrimerNodo(head);
                        break;
                    case 3:
                        borrarUltimoNodo(head);
                        break;
                    case 4:
                    {
                        int posicion;
                        std::cout << "Ingrese la posición del nodo que desea borrar: ";
                        std::cin >> posicion;
                        borrarEnPosicion(head, posicion);
                        break;
                    }
                    case 5:
                        visualizarLista(head);
                        break;
                    case 6:
                        break;
                    default:
                        std::cout << "Opción no válida." << std::endl;
                        break;
                }

                if (opcionMenu != 6) {
                    std::cout << "¿Desea realizar otra operación? (S/N): ";
                    std::cin >> otro;
                } else {
                    otro = 'N';
                }

            } while (otro == 'S' || otro == 's');

            // Liberar la memoria de los nodos al salir
            Nodo<char>* temp = head;
            while (temp != nullptr) {
                Nodo<char>* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            break;
        }
        case 's':
        {
            Nodo<std::string>* head = nullptr;
            int opcionMenu;
            std::string otro;
            do {
                std::cout << "MENU:" << std::endl;
                std::cout << "1. Insertar en cualquier posición" << std::endl;
                std::cout << "2. Borrar primer nodo" << std::endl;
                std::cout << "3. Borrar último nodo" << std::endl;
                std::cout << "4. Borrar en cualquier posición" << std::endl;
                std::cout << "5. Visualizar lista" << std::endl;
                std::cout << "6. Salir" << std::endl;
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionMenu;

                switch (opcionMenu) {
                    case 1:
                    {
                        std::string valor;
                        int posicion;
                        std::cout << "Ingrese el dato para el nuevo nodo: ";
                        std::cin >> valor;
                        std::cout << "Ingrese la posición donde desea insertar el nodo: ";
                        std::cin >> posicion;
                        insertarEnPosicion(head, valor, posicion);
                        break;
                    }
                    case 2:
                        borrarPrimerNodo(head);
                        break;
                    case 3:
                        borrarUltimoNodo(head);
                        break;
                    case 4:
                    {
                        int posicion;
                        std::cout << "Ingrese la posición del nodo que desea borrar: ";
                        std::cin >> posicion;
                        borrarEnPosicion(head, posicion);
                        break;
                    }
                    case 5:
                        visualizarLista(head);
                        break;
                    case 6:
                        break;
                    default:
                        std::cout << "Opción no válida." << std::endl;
                        break;
                }

                if (opcionMenu != 6) {
                    std::cout << "¿Desea realizar otra operación? (S/N): ";
                    std::cin >> otro;
                } else {
                    otro = "N";
                }

            } while (otro == "S" || otro == "s");

            // Liberar la memoria de los nodos al salir
            Nodo<std::string>* temp = head;
            while (temp != nullptr) {
                Nodo<std::string>* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            break;
        }
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
    }

    // Pausa del sistema para que el programa no se cierre automáticamente
    std::cout << "Presione cualquier tecla para salir...";
    std::cin.ignore(); // Ignora cualquier carácter pendiente en el búfer
    std::cin.get();    // Espera hasta que el usuario presiona una tecla
}
