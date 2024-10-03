#ifndef __TIENDA_H__
#define __TIENDA_H__

class RavaStore {
public:
    void mostrarMenuPrincipal();
    void mostrarMenuIngreso();
    void mostrarMenuMostrar();
    void mostrarMenuActualizar();
    void ejecutar();
private:
    void ingresarProducto(int opcionIngreso);
    void mostrarProducto(int opcionMostrar);
    void actualizarProducto(int opcionActualizar);
    void gestionarIngreso();
    void gestionarMostrar();
    void gestionarActualizar();
};
#endif