#include <iostream>
using namespace std;

class calculadora {
    private:
        int numero1, numero2;
    public:
        void guardarNumero(int, int);
        void Sumar(int, int);
        void Restar(int, int);
        void Multiplicar(int, int);
        void Dividir(int, int);      
};

int main()
{
    calculadora calculo;
    int x, y, z;
    calculo.guardarNumero(x, y);
    cout<<"Ingresar numero 1"<<endl;
    cin>>x;
    cout<<"Ingrese numero 2"<<endl;
    cin>>y;
    cout<<"Seleccione\n1-Suma\n2-Resta\n3-Multiplicacion\n4-Division"<<endl;
    cin>>z;
    if(z==1)calculo.Sumar(x, y);
    if(z==2)calculo.Restar(x, y);
    if(z==3)calculo.Multiplicar(x, y);
    if(z==4)calculo.Dividir(x, y);
    return 0;
}

void calculadora::guardarNumero(int numerador1, int numerador2){
    numero1=numerador1;
    numero2=numerador2;
}

void calculadora::Sumar(int numero1, int numero2){
    int resultado;
    resultado=numero1+numero2;
    cout<<"Resultado:"<<resultado<<endl;
}

void calculadora::Restar(int numero1, int numero2){
    int resultado;
    resultado=numero1-numero2;
    cout<<"Resultado:"<<resultado<<endl;
}

void calculadora::Multiplicar(int numero1, int numero2){
    int resultado;
    resultado=numero1*numero2;
    cout<<"Resultado:"<<resultado<<endl;
}

void calculadora::Dividir(int numero1, int numero2){
    float resultado;
    if(numero1==0 && numero2==0){
        cout<<"----DIVIDIENDO POR CERO----\n-----CERRANDO PROGRAMA-----"<<endl;
    }if(numero1!=0 && numero2!=0){
        resultado=(float)numero1/(float)numero2;
        cout<<"Resultado:"<<resultado<<endl;
    }
}

