#ifndef __PRODUCTOS_H__
#define __PRODUCTOS_H__

#include <string> 
#include <fstream> 
using namespace std;

class producto{
    protected:
        string nombre;
        int stock;
        float precio;
        string ID;
    public:
        virtual void ingresoProducto() = 0;
        virtual void guardarEnArchivo(ofstream& archivo) const = 0;
                
        //metodos set y get //
        void setStock (int nuevoStock) {stock = nuevoStock; }
        void setPrecio (float nuevoPrecio) {precio = nuevoPrecio; }
        int getStock() const {return stock; }
        float getPrecio() const {return stock; }
        
        virtual ~producto() = default;
};

//Herencias derivadas de producto// 

class consola: private producto{
    private:
        int capacidad;
        string marca;
        int año;
    public:
        void ingresoProducto() override;
        void guardarEnArchivo(ofstream& archivo) const override;
        static void cargarDesdeArchivo();
        static void actualizarProducto();
};

class juegos: public producto{
    private:
        string desarolladora;
        int peso;
        string plataforma;
    public:
        void ingresoProducto() override;
        void guardarEnArchivo (ofstream& archivo) const override;
        static void cargarDesdeArchivo();
        static void actualizarProducto();
};

class mangas: public producto{
    private:
        string autor;
        int paginas;
        string genero;
    public:
        void ingresoProducto() override;
        void guardarEnArchivo (ofstream& archivo) const override;
        static void cargarDesdeArchivo();
        static void actualizarProducto();   
};
#endif