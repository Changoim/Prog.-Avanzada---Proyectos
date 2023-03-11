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
        }
    }
    ofstream f;
    ifstream in;
    char resp;
    int conta = 0;

    //se abre el fichero para añadir datos al final
    f.open("empleados.bin", ios::app|ios::binary);
    if (f.fail())
    {
        cout << "Error al crear el fichero empleados.bin" << endl;
    }

    f.write(reinterpret_cast<char*>(&empleados),sizeof(empleado));
    f.close();

    cout << "Mostrar empleados(S/N)? ";
    cin>>resp;

    if (resp == 's')
    {
        in.open("empleados.bin", ios::binary);
        if(in.fail())
        {
            cout << "Error al abrir el fichero empleados.bin" << endl;
            system("pause");
            exit(1);
        }
        // Leemos el primer registro
        in.open("empleados.bin");
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
        in.close(); // Cerramos el fichero

    }
    return totalclientes;
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
    long int nuevoTelefono;
    for(int i=0; i<totalclientes; i++)
    {
        int existe=0;
        // Abrir archivo binario para lectura y escritura
        fstream archivo("empleados.bin", ios::in | ios::out | ios::binary);

        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
        }

        // Pedir el código del empleado a modificar
        int codigo;
        cout<<"Ingrese el código del empleado a modificar: ";
        cin>>codigo;

        // Buscar el empleado en el archivo
        bool encontrado = false;

        while (!encontrado && archivo.read((char*)&empleados, sizeof(empleado)))
        {
            if (empleados[i].codigo == codigo)
            {
                encontrado = true;
            }
        }

        // Si se encontró al empleado, pedir el nuevo número de teléfono y modificarlo en el archivo
        if (encontrado)
        {
            cout<<"Ingrese el nuevo número de teléfono: ";
            cin>>nuevoTelefono;
            // Regresar al inicio del registro encontrado
            archivo.seekp(-sizeof(empleado), ios::cur);

            archivo.write((char*)&empleados, sizeof(empleado));
            printf("Se modifico el precio para dicho producto.\n");
            existe=1;
             empleados[i].celular = nuevoTelefono;
            break;
        }
        archivo.read((char*)&empleados, sizeof(empleado));

        if (existe==0)
            printf("No existe el empleado con dicho codigo\n");
        archivo.close();


        cout << "El número de teléfono se ha modificado correctamente." << endl;
    }

}

int despedirempleado(empleado empleados[], int totalclientes, string *despedidos, int contador)
{
    int codigo;
    int j=0;

    cout<<"ingrese el codigo del empleado al que va a despedir"<<endl;
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
                file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                file<<"                                                                                                                                     "<<dia<<"/"<<mes<<"/"<<anio<<endl;
                file<<"Apreciado(a) "<<persona<<":"<<endl;
                file<<"\t El motivo de esta carta es comunicarte que, el día de hoy, la empresa Minosaurios Tech Inc. ha\t"<<endl;
                file<<"\t tomado la decisión de prescindir de tus servicios laborales como redactor web, puesto en el cual te has desempeñado desde el 3 de mayo de 2020.\t"<<endl;
                file<<"\t El efecto del despido se llevará a cabo el día "<<dia<<" de mes " << mes<< " del presente.\t"<<endl;
                file<<"\t Las razones de esta decisión se deben a los resultados de desempeño obtenidos en el periodo mayo-agosto de 2022.\t"<<endl;
                file<<"\t De acuerdo a lo especificado en el contrato de trabajo, durante los primeros tres meses de la relación laboral, el colaborador debía de producir 10 piezas escritas con un alcance de 20.000 lectores.\t"<<endl;
                file<<"\t No obstante, estos objetivos no fueron cumplidos en el periodo determinado y, de acuerdo con lo establecido en el artículo 52 del Estatuto de los Trabajadores, la empresa tiene la libertad de extinguir el contrato.\t"<<endl;
                file<<"\t Conforme a lo acordado en el artículo 53 del Estatuto de los Trabajadores, la empresa pondrá a tu disposición la parte correspondiente de los 20 días de salario por cada año trabajado,\t"<<endl;
                file<<"\t el cual asciende a una cantidad de €XXXX.XX.\t"<<endl;
                file<<endl;
                file<<endl;
                file<<"Saludos cordiales,"<<endl;
                file<<"Minosaurios Tech Inc."<<endl;
                file<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
            }

            j++;

            cout<<"Carta de despido creada"<<endl;

        }
        //  else
        //    cout<<"empleado no encontrado"<<endl;
    }
    contador =j;
    cout<<"a"<<endl;
    return contador;
}

void verdespedidos(empleado empleados[], int totalclientes, string *despedidos, int contador)
{
    cout<<"empleados despedidos: "<<endl;
    for (int j=0; j<contador; j++)
    {
        cout<<"\t"<<despedidos[j]<<endl;
    }
}

main()
{
    int opmenu;
    char op;
    empleado empleados[MAX];
    int totalclientes;
    string *despedidos;
    int contador = 0;
    despedidos = new string [contador];
    cout<<"\n----------BIENVENIDO A MINOSAURIOS TECH----------\n"<<endl;
    do
    {
        cout<<"MENU"<<endl;
        cout<<"Que desea hacer el dia de hoy?"<<endl;
        cout<<"Registrar empleados.(ingrese 1)"<<endl;
        cout<<"Agregar nuevos empleados.(ingrese 2)"<<endl;
        cout<<"Mostrar los empleados registrados.(ingrese 3)"<<endl;
        cout<<"Cambiar el número de celular de un empleado.(ingrese 4)"<<endl;
        cout<<"Despedir a un empleado.(ingrese 5)"<<endl;
        cout<<"Mostrar empleados que han sido despedidos.(ingrese 6)"<<endl;
        cin>>opmenu;

        switch (opmenu)
        {
        //registro de empleados
        case 1:
            cout<<"case abierto"<<endl;
            totalclientes = registro(empleados, totalclientes);

            break;

        case 2:

            cout<<"case 2 abierto"<<endl;
            totalclientes = agregar(empleados, totalclientes);


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
            contador = despedirempleado(empleados,totalclientes,despedidos,contador);

            break;

        case 6:

            cout<<"case 6 abierto"<<endl;
            verdespedidos(empleados, totalclientes, despedidos,contador);

            break;
        }
        cout<<"desea volver al menu?"<<endl;
        cin>>op;
    }
    while (op=='s');
}
