/*
---------------------------------------------------------------------------

Fecha: 30/01/2023
Autor: Valentina Sandoval Aparicio
Problema: "se tiene un gym que requiere un sistema
informatico para capturar los datos de sus clientes"

Caracteristicas:
- se crea un struct para hacer el tipo de dato que capture los datos
- se presenta que por cada dato, se imprime la pregunta y se captura.

---------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;
const int MAX = 500;

struct cliente
{
    string nombre;
    int edad;
    long int ID;
    double MasaCorporal;
    char genero;
    string correo;
    long long int movil;
    int cHijos;
    string direccion;
};

main ()
{
    char op='s';
    int i=0;
    cliente clientes[MAX];
    while (op=='s')
    {
        cout<<"Bienvenido! como se encuentra el dia de hoy?"<<endl;
        cout<<"Ingrese su nombre"<<endl;
        cin>>clientes[i].nombre;
        cout<<"Ingrese su edad"<<endl;
        cin>>clientes[i].edad;
        cout<<"Ingrese su identificacion"<<endl;
        cin>>clientes[i].ID;
        cout<<"Ingrese su masa corporal"<<endl;
        cin>>clientes[i].MasaCorporal;
        cout<<"Ingrese su genero (f/m)"<<endl;
        cin>>clientes[i].genero;
        cout<<"Ingrese su correo"<<endl;
        cin>>clientes[i].correo;
        cout<<"Ingrese su movil"<<endl;
        cin>>clientes[i].movil;
        cout<<"Ingrese cantidad de hijos"<<endl;
        cin>>clientes[i].cHijos;
        cout<<"Ingrese su direccion"<<endl;
        cin>>clientes[i].direccion;

        cout<<"Revise una ultima vez su informacion por favor"<<endl;
        cout<<"nombre: "<<clientes[i].nombre<<endl;
        cout<<"edad: "<<clientes[i].edad<<endl;
        cout<<"identificacion: "<<clientes[i].ID<<endl;
        cout<<"Masa corporal: "<<clientes[i].MasaCorporal<<"kg"<<endl;
        if (clientes[i].genero== 'f')
        {
            cout<<"Genero: femenino"<<endl;
        }
        else if (clientes[i].genero== 'm')
        {
            cout<<"Genero: masculino"<<endl;
        }
        cout<<"correo: "<<clientes[i].correo<<endl;
        cout<<"movil: "<<clientes[i].movil<<endl;
        cout<<"cantidad de hijos: "<<clientes[i].cHijos<<endl;
        cout<<"direccion: "<<clientes[i].direccion<<endl;
        i++;

        cout<<"Desea ingresar otro cliente? s/n"<<endl;
        cin>>op;
    }
    
    cout<<"numero de clientes: "<<i;
}

