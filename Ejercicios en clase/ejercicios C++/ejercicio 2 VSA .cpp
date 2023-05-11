/*
------------------------------------------------------------------
fecha: 06/02/23
Autor: Valentina Sandoval A.
problema:
- crear una estructura corta para pedir datos basicos del usuario
- crear una lista de palabras a ser usadas aleatoriamente
- almacenar palabras en un fichero
- leer y presentar en pantalla la lectura de un fichero
------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//se crea una estructura basicaa para la captura de datos de los usuarios

struct datos_usuarios
{
    string nombre;
    string apellido;
    int edad;
};


//se crea una lista, como conjunto de palabras disponibles para jugar
const string lista_palabras[] = {"hola","mañana","hoy","tarde","noche"};

//se crea la funcion principal
int main ()
{
    //se declaran variables a usar
    int i,j,cantidad;

    //se pude cuantos usuarios
    cout<<"ingrese el numro de usuarios que va a registrar"<<endl;
    cin>>cantidad;
    //se crea un objeto struct del tamaño cantidad
    datos_usuarios personas[cantidad];

    //se piden los datos de los usuarios
    //se escribe sobre un fichero: se usa "ofstream" para almacenar en el fichero
    //se crea el objeto tipo ofstream (digital) junto con el nombre del fichero (fisico)

    ofstream fichero_escritura ("pepito.txt");
    //se debe preguntar si hay espacio en memoria para abrir el fichero
    if (fichero_escritura.is_open())
    {
    for(i=0; i<cantidad; i++)
    {
        cout<<"\n ingrese nombre "<<": ";
        cin>>personas[i].nombre;
        fichero_escritura<<personas[i].nombre<<endl;
        cout<<"\n ingrese apellido "<<": ";
        cin>>personas[i].apellido;
        fichero_escritura<<personas[i].apellido<<endl;
        cout<<"\n ingrese edad "<<": ";
        cin>>personas[i].edad;
        fichero_escritura<<personas[i].edad<<endl;
    }
    }
    else
    {
        cout<<"no tiene permisos de escritura!!"<<endl;
    }

    fichero_escritura.close();

    //se imprimen los datos de los usuarios
        for(i=0; i<cantidad; i++)
    {
        cout<<"\n nombre "<<i+1<<": "<<personas[i].nombre<<endl;
        cout<<"\n apellido "<<i+1<<": "<<personas[i].apellido<<endl;
        cout<<"\n edad "<<i+1<<": "<<personas[i].edad<<endl;

        cout<<"archivo creado con exito"<<endl;
    }
}
