#include <iostream>
#include <string>
#include <fstream>
using namespace std; 
#include "productos.h"

void consola::ingresoProducto(){
    cout<<"Ingrese el nombre de la consola: ";
    getline(cin, nombre);
 
    cout<<"Ingrese la cantidad de stock: ";
    cin>>stock;
    cin.ignore();
 
    cout<<"Ingrese el precio de la consola: ";
    cin>>precio;
    cin.ignore();
 
    cout<<"Ingrese el ID de la consola: ";
    getline(cin, ID);
 
    cout<<"Ingrese la capacidad de la consola (GB): ";
    cin>>capacidad;
    cin.ignore();
 
    cout<<"Ingrese la marca de la consola: ";
    getline(cin, marca);
 
    cout<<"Ingrese el año de salida de la consola: ";
    while(!(cin>>año) || año>2024){
        cin.clear();
        cout<<"Entrada invalida, ingrese un año valido (hasta 2024): ";
    }
    
    ofstream archivo ("consolas.txt", ios::app);
    if (archivo.is_open()){
        guardarEnArchivo(archivo);
        archivo.close();
        cout<<"Archivo guardado correctamente."<<endl;
    } else {
        cout<<"Error al abrir el archivo."<<endl;
    }
 
}

void consola::guardarEnArchivo(ofstream& archivo) const {
    archivo << nombre << endl
            << stock << endl
            << precio << endl
            << ID << endl
            << capacidad << endl
            << marca << endl
            << año << endl;
}

void consola::cargarDesdeArchivo(){
    ifstream archivo("consolas.txt");
    if (archivo.is_open()){
        string nombre;
        int stock;
        float precio;
        string ID;
        int capacidad;
        string marca;
        int año;
        
        while (getline(archivo, nombre)){
            archivo>>stock;
            archivo>>precio;
            archivo.ignore();
            getline(archivo, ID);
            archivo>>capacidad;
            archivo.ignore();
            getline(archivo, marca);
            archivo>>año;
            archivo.ignore();
            
            //muestro los datos leidos//
            cout << endl << "Consola: " << nombre << endl
                 << "Stock: " << stock << endl
                 << "Precio: " << precio << endl
                 << "ID: " << ID << endl
                 << "Capacidad: " << capacidad << " GB" << endl
                 << "Marca: " << marca << endl
                 << "Año: " << año << endl;
        }
        
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo correctamente." << endl;
    }
}

void consola::actualizarProducto(){
    string idBuscado;
    cout<<"Ingrese el ID del producto que desee actualizar: ";
    getline(cin, idBuscado);
    
    ifstream archivoLectura("consolas.txt");
    ofstream archivoTemporal("temporal.txt");
    
    if (archivoLectura.is_open() && archivoTemporal.is_open()){
        string nombre;
        int stock;
        float precio;
        string ID;
        int capacidad;
        string marca;
        int año;
        bool encontrado = false;
        
        while (getline(archivoLectura, nombre)){
            archivoLectura>>stock;
            archivoLectura>>precio;
            archivoLectura.ignore();
            getline(archivoLectura, ID);
            archivoLectura>>capacidad;
            archivoLectura.ignore();
            getline(archivoLectura, marca);
            archivoLectura>>año;
            archivoLectura.ignore();
            
            if (ID == idBuscado) {
                encontrado = true;
                int nuevaCantidad;
                float nuevoPrecio;
                cout << "Producto encontrado: " << nombre << endl;
                cout << "Ingrese la nueva cantidad de stock: ";
                cin >> nuevaCantidad;
                cin.ignore();
                cout << "Ingrese el nuevo precio: ";
                cin >> nuevoPrecio;
                cin.ignore();
                stock = nuevaCantidad;
                precio = nuevoPrecio;
                cout << "Producto actualizado." << endl;
            }
            
            archivoTemporal << nombre << endl
                            << stock << endl
                            << precio << endl
                            << ID << endl
                            << capacidad << endl
                            << marca << endl
                            << año << endl;
        }
        
        archivoLectura.close();
        archivoTemporal.close();
        
        remove("consolas.txt");
        rename("temporal.txt", "consolas.txt");
        
        if (!encontrado){
            cout << "Producto con ID: " << idBuscado << " no encontrado." << endl;
        }
    } else {
        cout << "No se puede abrir el archivo para lectura/escritura." << endl;
    }
}

void juegos::ingresoProducto(){
    cout<<"Ingrese el nombre del juego: ";
    getline(cin, nombre);
 
    cout<<"Ingrese la cantidad de stock: ";
    cin>>stock;
    cin.ignore();
 
    cout<<"Ingrese el precio del juego: ";
    cin>>precio;
    cin.ignore();
 
    cout<<"Ingrese el ID del juego: ";
    getline(cin, ID);
 
    cout<<"Ingrese nombre de la desarolladora: ";
    getline(cin, desarolladora);
 
    cout<<"Ingrese el peso (GB) del juego: ";
    cin>>peso;
    cin.ignore();
 
    cout<<"Ingrese la plataforma donde este disponible: ";
    getline(cin, plataforma);
    
    ofstream archivo ("juegos.txt", ios::app);
    if (archivo.is_open()){
        guardarEnArchivo(archivo);
        archivo.close();
        cout<<"Archivo guardado correctamente."<<endl;
    } else {
        cout<<"Error al abrir el archivo."<<endl;
    }
 
}

void juegos::guardarEnArchivo(ofstream& archivo) const {
    archivo << nombre << endl
            << stock << endl
            << precio << endl
            << ID << endl
            << desarolladora << endl
            << peso << endl
            << plataforma << endl;
}

void juegos::cargarDesdeArchivo(){
    ifstream archivo("juegos.txt");
    if (archivo.is_open()){
        string nombre;
        int stock;
        float precio;
        string ID;
        string desarolladora;
        int peso;
        string plataforma;
        
        while (getline(archivo, nombre)){
            archivo>>stock;
            archivo>>precio;
            archivo.ignore();
            getline(archivo, ID);
            getline(archivo, desarolladora);
            archivo>>peso;
            archivo.ignore();
            getline(archivo, plataforma);
            
            //muestro los datos leidos//
            cout << endl << "Juego: " << nombre << endl
                 << "Stock: " << stock << endl
                 << "Precio: " << precio << endl
                 << "ID: " << ID << endl
                 << "Desarolladora: " << desarolladora <<  endl
                 << "Peso: " << peso << endl
                 << "Plataforma: " << plataforma << endl;
        }
        
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo correctamente." << endl;
    }
}

void juegos::actualizarProducto(){
    string idBuscado;
    cout<<"Ingrese el ID del producto que desee actualizar: ";
    getline(cin, idBuscado);
    
    ifstream archivoLectura("juegos.txt");
    ofstream archivoTemporal("temporal.txt");
    
    if (archivoLectura.is_open() && archivoTemporal.is_open()){
        string nombre;
        int stock;
        float precio;
        string ID;
        string desarolladora;
        int peso;
        string plataforma;
        bool encontrado = false;
        
        while (getline(archivoLectura, nombre)){
            archivoLectura>>stock;
            archivoLectura>>precio;
            archivoLectura.ignore();
            getline(archivoLectura, ID);
            getline(archivoLectura, desarolladora);
            archivoLectura>>peso;
            archivoLectura.ignore();
            getline(archivoLectura, plataforma);
            
            if (ID == idBuscado) {
                encontrado = true;
                int nuevaCantidad;
                float nuevoPrecio;
                cout << "Producto encontrado: " << nombre << endl;
                cout << "Ingrese la nueva cantidad de stock: ";
                cin >> nuevaCantidad;
                cin.ignore();
                cout << "Ingrese el nuevo precio: ";
                cin >> nuevoPrecio;
                cin.ignore();
                stock = nuevaCantidad;
                precio = nuevoPrecio;
                cout << "Producto actualizado." << endl;
            }
            
            archivoTemporal << nombre << endl
                            << stock << endl
                            << precio << endl
                            << ID << endl
                            << desarolladora << endl
                            << peso << endl
                            << plataforma << endl;
        }
        
        archivoLectura.close();
        archivoTemporal.close();
        
        remove("juegos.txt");
        rename("temporal.txt", "juegos.txt");
        
        if (!encontrado){
            cout << "Producto con ID: " << idBuscado << " no encontrado." << endl;
        }
    } else {
        cout << "No se puede abrir el archivo para lectura/escritura." << endl;
    }
}

void mangas::ingresoProducto(){
    cout<<"Ingrese el nombre del manga: ";
    getline(cin, nombre);
 
    cout<<"Ingrese la cantidad de stock: ";
    cin>>stock;
    cin.ignore();
 
    cout<<"Ingrese el precio del manga: ";
    cin>>precio;
    cin.ignore();
 
    cout<<"Ingrese el ID del manga: ";
    getline(cin, ID);
 
    cout<<"Ingrese nombre del autor: ";
    getline(cin, autor);
 
    cout<<"Ingrese la cantidad de paginas: ";
    cin>>paginas;
    cin.ignore();
 
    cout<<"Ingrese el genero del manga: ";
    getline(cin, genero);
    
    ofstream archivo ("mangas.txt", ios::app);
    if (archivo.is_open()){
        guardarEnArchivo(archivo);
        archivo.close();
        cout<<"Archivo guardado correctamente."<<endl;
    } else {
        cout<<"Error al abrir el archivo."<<endl;
    }
 
}

void mangas::guardarEnArchivo(ofstream& archivo) const {
    archivo << nombre << endl
            << stock << endl
            << precio << endl
            << ID << endl
            << autor << endl
            << paginas << endl
            << genero << endl;
}

void mangas::cargarDesdeArchivo(){
    ifstream archivo("mangas.txt");
    if (archivo.is_open()){
        string nombre;
        int stock;
        float precio;
        string ID;
        string autor;
        int paginas;
        string genero;
        
        while (getline(archivo, nombre)){
            archivo>>stock;
            archivo>>precio;
            archivo.ignore();
            getline(archivo, ID);
            getline(archivo, autor);
            archivo>>paginas;
            archivo.ignore();
            getline(archivo, genero);
            
            //muestro los datos leidos//
            cout << endl << "Juego: " << nombre << endl
                 << "Stock: " << stock << endl
                 << "Precio: " << precio << endl
                 << "ID: " << ID << endl
                 << "Autor: " << autor <<  endl
                 << "Paginas: " << paginas << endl
                 << "Genero: " << genero << endl;
        }
        
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo correctamente." << endl;
    }
}

void mangas::actualizarProducto(){
    string idBuscado;
    cout<<"Ingrese el ID del producto que desee actualizar: ";
    getline(cin, idBuscado);
    
    ifstream archivoLectura("mangas.txt");
    ofstream archivoTemporal("temporal.txt");
    
    if (archivoLectura.is_open() && archivoTemporal.is_open()){
        string nombre;
        int stock;
        float precio;
        string ID;
        string autor;
        int paginas;
        string genero;
        bool encontrado = false;
        
        while (getline(archivoLectura, nombre)){
            archivoLectura>>stock;
            archivoLectura>>precio;
            archivoLectura.ignore();
            getline(archivoLectura, ID);
            getline(archivoLectura, autor);
            archivoLectura>>paginas;
            archivoLectura.ignore();
            getline(archivoLectura, genero);
            
            if (ID == idBuscado) {
                encontrado = true;
                int nuevaCantidad;
                float nuevoPrecio;
                cout << "Producto encontrado: " << nombre << endl;
                cout << "Ingrese la nueva cantidad de stock: ";
                cin >> nuevaCantidad;
                cin.ignore();
                cout << "Ingrese el nuevo precio: ";
                cin >> nuevoPrecio;
                cin.ignore();
                stock = nuevaCantidad;
                precio = nuevoPrecio;
                cout << "Producto actualizado." << endl;
            }
            
            archivoTemporal << nombre << endl
                            << stock << endl
                            << precio << endl
                            << ID << endl
                            << autor << endl
                            << paginas << endl
                            << genero << endl;
        }
        
        archivoLectura.close();
        archivoTemporal.close();
        
        remove("mangas.txt");
        rename("temporal.txt", "mangas.txt");
        
        if (!encontrado){
            cout << "Producto con ID: " << idBuscado << " no encontrado." << endl;
        }
    } else {
        cout << "No se puede abrir el archivo para lectura/escritura." << endl;
    }
}