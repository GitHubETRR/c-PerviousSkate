#include <iostream>
#include "productos.h"
#include "tienda.h"
using namespace std;

// Definir constantes para las opciones de menú
#define OPCION_SALIR 0
#define INGRESAR_CONSOLA 1
#define INGRESAR_JUEGO 2
#define INGRESAR_MANGA 3
#define MOSTRAR_CONSOLA 1
#define MOSTRAR_JUEGO 2
#define MOSTRAR_MANGA 3
#define ACTUALIZAR_CONSOLA 1
#define ACTUALIZAR_JUEGO 2
#define ACTUALIZAR_MANGA 3
#define INGRESAR_PRODUCTO 1
#define MOSTRAR_PRODUCTO 2
#define ACTUALIZAR_PRODUCTO 3

void RavaStore::mostrarMenuPrincipal() {
    cout << "\n--- Rava Store ---" << endl;
    cout << "1. Ingresar productos" << endl;
    cout << "2. Mostrar productos" << endl;
    cout << "3. Actualizar productos" << endl;
    cout << "0. Salir del programa" << endl;
    cout << "Seleccione una opción: ";
}

void RavaStore::mostrarMenuIngreso() {
    cout << "\n--- Ingreso Productos ---" << endl;
    cout << "1. Ingresar consola" << endl;
    cout << "2. Ingresar juego" << endl;
    cout << "3. Ingresar manga" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}

void RavaStore::mostrarMenuMostrar() {
    cout << "\n--- Mostrar Productos ---" << endl;
    cout << "1. Mostrar consolas" << endl;
    cout << "2. Mostrar juegos" << endl;
    cout << "3. Mostrar mangas" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}

void RavaStore::mostrarMenuActualizar() {
    cout << "\n--- Actualizar Productos ---" << endl;
    cout << "1. Actualizar consola" << endl;
    cout << "2. Actualizar juego" << endl;
    cout << "3. Actualizar manga" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}

void RavaStore::ingresarProducto(int opcionIngreso) {
    switch (opcionIngreso) {
        case INGRESAR_CONSOLA: {
            consola nuevaConsola;
            nuevaConsola.ingresoProducto();
            break;
        }
        case INGRESAR_JUEGO: {
            juegos nuevoJuego;
            nuevoJuego.ingresoProducto();
            break;
        }
        case INGRESAR_MANGA: {
            mangas nuevoManga;
            nuevoManga.ingresoProducto();
            break;
        }
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
    }
}

void RavaStore::mostrarProducto(int opcionMostrar) {
    switch (opcionMostrar) {
        case MOSTRAR_CONSOLA:
            consola::cargarDesdeArchivo();
            break;
        case MOSTRAR_JUEGO:
            juegos::cargarDesdeArchivo();
            break;
        case MOSTRAR_MANGA:
            mangas::cargarDesdeArchivo();
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
    }
}

void RavaStore::actualizarProducto(int opcionActualizar) {
    switch (opcionActualizar) {
        case ACTUALIZAR_CONSOLA:
            consola::actualizarProducto();
            break;
        case ACTUALIZAR_JUEGO:
            juegos::actualizarProducto();
            break;
        case ACTUALIZAR_MANGA:
            mangas::actualizarProducto();
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
    }
}

void RavaStore::gestionarIngreso() {
    int opcionIngreso;
    do {
        mostrarMenuIngreso();
        cin >> opcionIngreso;
        cin.ignore();

        if (opcionIngreso != OPCION_SALIR)
            ingresarProducto(opcionIngreso);

    } while (opcionIngreso != OPCION_SALIR);
}

void RavaStore::gestionarMostrar() {
    int opcionMostrar;
    do {
        mostrarMenuMostrar();
        cin >> opcionMostrar;
        cin.ignore();

        if (opcionMostrar != OPCION_SALIR)
            mostrarProducto(opcionMostrar);

    } while (opcionMostrar != OPCION_SALIR);
}

void RavaStore::gestionarActualizar() {
    int opcionActualizar;
    do {
        mostrarMenuActualizar();
        cin >> opcionActualizar;
        cin.ignore();

        if (opcionActualizar != OPCION_SALIR)
            actualizarProducto(opcionActualizar);

    } while (opcionActualizar != OPCION_SALIR);
}

void RavaStore::ejecutar() {
    int opcionMenuPrincipal;

    do {
        mostrarMenuPrincipal();
        cin >> opcionMenuPrincipal;
        cin.ignore();

        switch (opcionMenuPrincipal) {
            case INGRESAR_PRODUCTO:
                gestionarIngreso();
                break;
            case MOSTRAR_PRODUCTO:
                gestionarMostrar();
                break;
            case ACTUALIZAR_PRODUCTO:
                gestionarActualizar();
                break;
            case OPCION_SALIR:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while (opcionMenuPrincipal != OPCION_SALIR);
}