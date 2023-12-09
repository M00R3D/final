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

int main() {
    // Tipo de dato de la lista
    char opcionTipo;
    std::cout << "Elija el tipo de dato para la lista (i: int, c: char, s: string): ";
    std::cin >> opcionTipo;

    switch (opcionTipo) {
        case 'i':
        {
            Nodo<int>* head = nullptr;
            int otro;
            do {
                Nodo<int>* nuevoNodo = new Nodo<int>;
                std::cout << "Ingrese el dato para el nuevo nodo: ";
                std::cin >> nuevoNodo->dato;
                nuevoNodo->siguiente = nullptr;

                if (head == nullptr) {
                    head = nuevoNodo;
                } else {
                    Nodo<int>* temp = head;
                    while (temp->siguiente != nullptr) {
                        temp = temp->siguiente;
                    }
                    temp->siguiente = nuevoNodo;
                }

                std::cout << "¿Desea agregar otro nodo? (1: Sí, 0: No): ";
                std::cin >> otro;

            } while (otro == 1);

            visualizarLista(head);

            // Liberar la memoria de los nodos
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
            char otro;
            do {
                Nodo<char>* nuevoNodo = new Nodo<char>;
                std::cout << "Ingrese el dato para el nuevo nodo: ";
                std::cin >> nuevoNodo->dato;
                nuevoNodo->siguiente = nullptr;

                if (head == nullptr) {
                    head = nuevoNodo;
                } else {
                    Nodo<char>* temp = head;
                    while (temp->siguiente != nullptr) {
                        temp = temp->siguiente;
                    }
                    temp->siguiente = nuevoNodo;
                }

                std::cout << "¿Desea agregar otro nodo? (S/N): ";
                std::cin >> otro;

            } while (otro == 'S' || otro == 's');

            visualizarLista(head);

            // Liberar la memoria de los nodos
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
            std::string otro;
            do {
                Nodo<std::string>* nuevoNodo = new Nodo<std::string>;
                std::cout << "Ingrese el dato para el nuevo nodo: ";
                std::cin >> nuevoNodo->dato;
                nuevoNodo->siguiente = nullptr;

                if (head == nullptr) {
                    head = nuevoNodo;
                } else {
                    Nodo<std::string>* temp = head;
                    while (temp->siguiente != nullptr) {
                        temp = temp->siguiente;
                    }
                    temp->siguiente = nuevoNodo;
                }

                std::cout << "¿Desea agregar otro nodo? (S/N): ";
                std::cin >> otro;

            } while (otro == "S" || otro == "s");

            visualizarLista(head);

            // Liberar la memoria de los nodos
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

    return 0;
}
