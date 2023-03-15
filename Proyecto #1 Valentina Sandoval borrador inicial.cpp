/*
Autor: Valentina Sandoval Aparicio
Fecha: 01/03/2023
Proyecto #1: Programacion avanzada

    La empresa Minosaurios Tech solicita el registro de sus empleados.
    La estructura de datos empleado:
        - Código númerico
        - Nombres
        - Apellidos
        - Celular

    Funciones
        - Registrar empleados: se debe almacenar en un fichero binario "Empleados.bin"
        - Agregar nuevos empleados: se verifica que el empleado no este, la informacion se adiciona al final del fichero
        - Mostrar los empleados registrados: se imprime en pantalla los empleados en orden alfabetico
        - Cambiar el numero de movil del empleado: con el codigo del empleado, si existe, se modifica
        - Despedir empleado: con el código, si existe, se elimina del binario. Se genera una carta de despido.txt
        - Mostrar empleados que han sido despedidos: se presenta un vector con los empleados despedidos

*/

#include <iostream>
#include <fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <vector>
#include <cstring>

using namespace std;
int const MAX = 100;

struct empleado
{
    int codigo;
    string nombres;
    string apellidos;
    long int celular;
};

int registro(empleado empleados[], int totalclientes)
{
    empleados[totalclientes];
    cout<<"Ingrese la cantidad de clientes que va a registrar"<<endl;
    cin>>totalclientes;

    cout<<"Ahora ingrese la informacion de cada cliente"<<endl;

    ofstream f;
    ifstream in;
    char resp;

    for(int i=0; i<totalclientes; i++)
    {
        cout<<"\n-----Cliente #"<<i+1<<"-----\n"<<endl;
        cout<<"Código: ";
        cin>>empleados[i].codigo;
        cout<<"Nombre: ";
        cin>>empleados[i].nombres;
        cout<<"apellidos: ";
        cin>>empleados[i].apellidos;
        cout<<"celular: ";
        cin>>empleados[i].celular;
    }

    //se abre el fichero para añadir datos al final
    f.open("empleados.bin", ios::binary);
    if (!f.is_open())
    {
        cout << "Error al crear el fichero empleados.bin" << endl;
    }

    f.write(reinterpret_cast<char*>(&empleados),sizeof(empleado));
    f.close();

    cout<<"empleado(s) registrado!"<<endl;

    cout<<"Mostrar empleados(S/N)? ";
    cin>>resp;

    if (resp == 's')
    {
        {
            for(int j=0; j<totalclientes; j++)
            {
                cout<<"\n-----Cliente #"<<j+1<<"-----\n"<<endl;
                cout<<"Código: ";
                cout<<empleados[j].codigo<<endl;
                cout<<"Nombre: ";
                cout<<empleados[j].nombres<<endl;
                cout<<"apellidos: ";
                cout<<empleados[j].apellidos<<endl;
                cout<<"celular: ";
                cout<<empleados[j].celular<<endl;
            }

        }
    }
    return totalclientes;
}

int agregar(empleado empleados[], int totalclientes)
{
    int clientesagregar;
    cout<<"Ingrese la cantidad de clientes que va a agregar"<<endl;
    cin>>clientesagregar;
    int aux=totalclientes;
    totalclientes = totalclientes + clientesagregar;
    string nombreagregar;
    int codigoagregar;
    bool encontrado = false;

    cout<<"Ahora ingrese la informacion de cada cliente"<<endl;

    for(int i=aux; i<totalclientes; i++)
    {
        cout<<"\n-----Cliente #"<<i+1<<"-----\n"<<endl;
        cout<<"Código: ";
        cin>>codigoagregar;
        cout<<"Nombre: ";
        cin>>nombreagregar;
        for (int p=0; p<aux; p++)
        {
            if(empleados[p].codigo!=codigoagregar && empleados[p].nombres!=nombreagregar)
            {
                encontrado = true;

            }
        }
        if (encontrado)
        {
            empleados[i].codigo = codigoagregar;
            empleados[i].nombres = nombreagregar;
            cout<<"apellidos: ";
            cin>>empleados[i].apellidos;
            cout<<"celular: ";
            cin>>empleados[i].celular;
        }
        else
        {
            cout<<"el empleado ya ha sido registrado previamente, no se puede agregar"<<endl;
            totalclientes--;
aaaaaaaaa
