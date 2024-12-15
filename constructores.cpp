#include <iostream>

using namespace std;

class puntos{
    private:
        int x;
        int y;
    public:        
        puntos(int new_x, int new_y); //constructor si se paso valor
        puntos(); //constructor si no se paso valor
        ~puntos(); //destructor del objeto
        void ingreso_valores(int, int);
        void resultado();
};

//constructores 
puntos::puntos(int new_x, int new_y): x(new_x), y(new_y){
    cout<<"se creo una clase con valor inicial"<<endl;
}
puntos::puntos():x(0), y(0){
    cout<<"se creo una clase sin valor inicial"<<endl;
}

//destructor
puntos::~puntos(){
    cout<<"se destruyo el constructor"<<endl;
}

int main()
{
    int seleccion;
    cout<<"1- Crear clase con valores"<<endl<<"2- Crear clase sin valores"<<endl;
    cin>>seleccion;
    if(seleccion==1){
        puntos punto1(20,20);
        punto1.resultado();
    }else if(seleccion==2){
        puntos punto2;
        int new_x, new_y;
        punto2.resultado();
        cout<<"ingrese valor de x"<<endl;
        cin>>new_x;
        cout<<"ingrese valor de y"<<endl;
        cin>>new_y;
        punto2.ingreso_valores(new_x,new_y);
        punto2.resultado();
    }
    
}

void puntos::ingreso_valores(int igualadorX, int igualadorY){
    x=igualadorX;
    y=igualadorY;
}

void puntos::resultado(){
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
}