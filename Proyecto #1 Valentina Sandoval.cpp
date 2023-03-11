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

    cout<<"Ahora ingrese la informacion de cada cliente"<<endl;

    ofstream f;
    ifstream in;
    char resp;
    int conta = 0;

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

    // Entrada de datos
    for(int i=0; i<totalclientes; i++)
    {
        f<<"\n-----Cliente #"<<i+1<<"-----\n"<<endl;
        f<<"Código: ";
        f<<empleados[i].codigo<<endl;
        f<<"Nombre: ";
        f<<empleados[i].nombres<<endl;
        f<<"apellidos: ";
        f<<empleados[i].apellidos<<endl;
        f<<"celular: ";
        f<<empleados[i].celular<<endl;;
    }

    cin.clear();
    f.close();

    cout << "Mostrar empleados(S/N)? ";
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

empleado agregar(empleado empleados[], int totalclientes)
{
    cin>>totalclientes;
    empleados[500];

    int clientesagregar;
    cout<<"Ingrese la cantidad de clientes que va a registrar"<<endl;
    cin>>clientesagregar;

    int total=totalclientes+clientesagregar;

    cout<<"Ahora ingrese la informacion de cada cliente"<<endl;

    for(int i=totalclientes; i<total; i++)
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

    ofstream f;
    ifstream in;
    char resp;
    int conta = 0;

    //se abre el fichero para añadir datos al final
    f.open("empleados.bin", ios::out|ios::app|ios::binary);
    if (f.fail())
    {
        cout << "Error al crear el fichero empleados.dat" << endl;
    }

    // Entrada de datos
    for(int i=totalclientes; i<total; i++)
    {
        f<<"\n-----Cliente #"<<i+1<<"-----\n"<<endl;
        f<<"Código: ";
        f<<empleados[i].codigo<<endl;
        f<<"Nombre: ";
        f<<empleados[i].nombres<<endl;
        f<<"apellidos: ";
        f<<empleados[i].apellidos<<endl;
        f<<"celular: ";
        f<<empleados[i].celular<<endl;
    }

    cin.clear();
    f.close();

    cout << "Mostrar empleados(S/N)? ";
    cin>>resp;

    if (resp == 's')
    {
        in.open("empleados.bin", ios::binary);
        if(in.fail())
        {
            cout << "Error al abrir el fichero empleados.dat" << endl;
            system("pause");
            exit(1);
        }
        // Leemos el primer registro
        in.open("empleados.bin");
        {
            for(int j=0; j<total; j++)
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
        in.close(); // Cerramos el fichero

    }
}

void registrados(empleado empleados[], int totalclientes)
{
    empleado aux;
    //ordenamiento burbuja
    for (int i=0; i<totalclientes; i++)
    {
        for(int j=0; j<totalclientes; j++)
        {
            if (empleados[j].nombres>empleados[i].nombres)
            {
                aux=empleados[j];
                empleados[j]=empleados[i];
                empleados[i]=aux;
            }

        }
    }

    for (int v=0; v<totalclientes; v++)
    {
        cout<<"\n-----Cliente #"<<v+1<<"-----\n"<<endl;
        cout<<"Código: ";
        cout<<empleados[v].codigo<<endl;
        cout<<"Nombre: ";
        cout<<empleados[v].nombres<<endl;
        cout<<"apellidos: ";
        cout<<empleados[v].apellidos<<endl;
        cout<<"celular: ";
        cout<<empleados[v].celular<<endl;
    }

}

void cambiarnumero(empleado empleados[], int totalclientes)
{
    long int num;
    string nom;

    cout<<"ingrese el nombre del empleado al que va a modificar el numero telefonico"<<endl;
    cin>>nom;

    for(int i=0; i<totalclientes; i++)
    {
        if (empleados[i].nombres == nom)
        {
            cout<<"ingrese el nuevo numero telefonico"<<endl;
            cin>>num;

            empleados[i].celular = num;
            ofstream f;
            f.open("CartaDespido.txt");
            if (f.fail())
            {
                cout << "Error al crear el fichero carta de despido" << endl;
            }

            f<<empleados[i].celular<<endl;
            cin.clear();
            f.close();

        }
    }
}
void despedirempleado(empleado empleados[], int totalclientes)
{
    int codigo;
    int contador;

    cout<<"ingrese el codigo del empleado al que va a modificar el numero telefonico"<<endl;
    cin>>codigo;

    int dia, mes, anio;
    cout<<"introduzca la fecha de generacion de la carta de despido"<<endl;
    cout<<"dia: ";
    cin>>dia;
    cout<<"mes: ";
    cin>>mes;
    cout<<"año: ";
    cin>>anio;

    for(int i=0; i<totalclientes; i++)
    {
        cout<<"AAAAAAAAA"<<endl;
        if (empleados[i].codigo == codigo)
        {
            ofstream file;
            string empleado;
            string titulo = "Carta_Despido_";
            string extension = ".txt";
            string persona;
            persona = empleados[i].nombres;
            string newS = titulo + persona + extension;


            file.open(newS);
            if(file.is_open())
            {
                file<<"                                                                       "<<dia<<"/"<<mes<<"/"<<anio<<endl;
                file<<"Apreciado(a) "<<persona<<":"<<endl;
                file<<"\t El motivo de esta carta es comunicarte que, el día de hoy, la empresa Minosaurios Tech Inc. ha\t"<<endl;
                file<<"\ttomado la decisión de prescindir de tus servicios laborales como redactor web, puesto en el cual te has desempeñado desde el 3 de mayo de 2020.\t"<<endl;
                file<<"\tEl efecto del despido se llevará a cabo el día 31 de agosto del presente.\t"<<endl;
                file<<"\tLas razones de esta decisión se deben a los resultados de desempeño obtenidos en el periodo mayo-agosto de 2020.\t"<<endl;
                file<<"\tDe acuerdo a lo especificado en el contrato de trabajo, durante los primeros tres meses de la relación laboral, el colaborador debía de producir 10 piezas escritas con un alcance de 20.000 lectores.\t"<<endl;
                file<<"\tNo obstante, estos objetivos no fueron cumplidos en el periodo determinado y, de acuerdo con lo establecido en el artículo 52 del Estatuto de los Trabajadores, la empresa tiene la libertad de extinguir el contrato.\t"<<endl;
                file<<"\tConforme a lo acordado en el artículo 53 del Estatuto de los Trabajadores, la empresa pondrá a tu disposición la parte correspondiente de los 20 días de salario por cada año trabajado,\t"<<endl;
                file<<"\tel cual asciende a una cantidad de XXXX.XX.\t"<<endl;
                file<<endl;
                file<<endl;
                file<<"Saludos cordiales,"<<endl;
                file<<"Minosaurios Tech Inc."<<endl;
            }
        }
        else
            cout<<"empleado no encontrao"<<endl;
    }
}
void despedidos();

main()
{
    int opmenu;
    char op;
    empleado empleados[MAX];
    int totalclientes;
    cout<<"\n----------BIENVENIDO A MINOSAURIOS TECH----------\n"<<endl;
    do
    {
        cout<<"MENÚ"<<endl;
        cout<<"¿Que desea hacer el dia de hoy?"<<endl;
        cout<<"Registrar empleados.(ingrese 1)"<<endl;
        cout<<"Agregar nuevos empleados.(ingrese 2)"<<endl;
        cout<<"Mostrar los empleados registrados.(ingrese 3"<<endl;
        cout<<"Cambiar el número de celular de un empleado.(ingrese 4)"<<endl;
        cout<<"Despedir a un empleado.(ingrese 5)"<<endl;
        cout<<"Mostrar empleados que han sido despedidos.(ingrese 6)"<<endl;
        cout<<"Ingrese la cantidad de clientes que va a registrar"<<endl;
        cin>>totalclientes;
        cin>>opmenu;

        switch (opmenu)
        {
        //registro de empleados
        case 1:
            cout<<"case abierto"<<endl;
            registro(empleados, totalclientes);

            break;

        case 2:

            cout<<"case 2 abierto"<<endl;
            agregar(empleados, totalclientes);


            break;

        case 3:
            cout<<"case 3 abierto"<<endl;

            registrados(empleados, totalclientes);

            break;

        case 4:
            cout<<"case 4 abierto"<<endl;
            cambiarnumero(empleados, totalclientes);

            break;

        case 5:
            cout<<"case 5 abierto"<<endl;
            despedirempleado(empleados,totalclientes);


            break;

        case 6:

            cout<<"case 6 abierto"<<endl;


            break;
        }
        cout<<"desea volver al menu?"<<endl;
        cin>>op;
    }
    while (op=='s');
}

