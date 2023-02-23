/*
Taller #1
Autor: Valentina Sandoval Aparicio
Fecha:11/02/2023
*/

#include <iostream>
#include <vector>
#include<stdlib.h>
#include <fstream>
using namespace std;
int const MAX = 500;

//Estructura para datos de cliente (ejercicio #02)
struct datos
{
    string nombre;
    string apellido;
    int edad;
    long int ID;
    string direccion;
    long int telefono;
    int productos;
    double precio;
};

// funcion para generar numeros random
int random (int nrandom)
{
    // se genera un numero aleatorio entre 0 y 25
        nrandom = rand()%26;

    // retornoa el numero random
    return nrandom;
}

main()
{
    // declaracion de variables
    int op; // -> para ver las soluciones del taller
    int arreglo[10]; // -> arreglo de 10 elementos
    int nrandom=0; // -> numero que va a retornar la funcion
    int numero;
    char opmenu;
    int c; // -> numero de clientes
    char d;
    int j=0;
    int *p_numeros;
    p_numeros = arreglo;
    datos cliente [MAX];
    datos *cliente_factura;
    cliente_factura = cliente;
    //para el nombre del archivo
    ofstream file;
    string filename;
    string extension = ".txt";

    do
    {
        cout<<"\n----------BIENVENIDO----------\n"<<endl;
        cout<<"MENU"<<endl;
        cout<<"ver la solucion al ejercicio #1 (inserte 1)"<<endl;
        cout<<"ver la solucion al ejercicio #2 (inserte 2)"<<endl;
        cin>>op;

        // si el numero ingresado es 1 o 2 se entra al switch
        if (op == 1 || op == 2)
        {
            switch (op)
            {
            case 1:

                /*
                ejercicio #1
                1.- Crear un array con 10 elementos
                2.- Crear una funci�n para generar n�meros aleatorios entre 0 y 25
                3.- Llenar el array con 10 n�meros aleatorios
                4.- Crear un puntero
                5.- Imprimir el contenido del array usando el puntero
                6.- Imprimir las direcciones del contenido del array usando el puntero
                */

                // ciclo para llenar el arreglo
                for(int n=0; n<10; n++)
                {
                    // numero va a tomar el valor del numero random obtenido en la funcion.
                    numero = random (nrandom);

                    // se le asigna numero a el espacion (n) en el arreglo
                    arreglo[n]= numero;


                }

                //impresion del arreglo
                for (int i=0; i<10; i++)
                {
                    cout<<"elemento del arreglo ["<<i<<"]: "<<*p_numeros++<<endl;
                    cout<<"direccion del elemento: "<<p_numeros<<endl;
                }


                break;

            case 2:
                char op2;
                //se pide ingresar el nombre del archivo donde se guardaran las facturas
                cout<<"ingrese el nombre del archivo donde se va a imprimir la factura"<<endl;
                cin>> filename;
                string newS = filename + extension;

                /*
                Ejercicios #2
                Se desea capturar los datos de los clientes para ser impreso en la factura. Se requiere
                crear una estructura de datos, que encapsule los datos de los usuarios. Se requiere que
                el uso de la estructura sea a trav�s de punteros. Se requiere imprimir las facturas en
                un fichero de texto.
                */

                //se pregunta si se va a ingresar el numero de clientes
                cout<<"desea ingresar el numero de clientes? s/n"<<endl;
                cin>>op2;

                //si se hace, se pide que ingrese el numero
                if (op2 == 's')
                {
                    cout<<"ingrese el numero de clientes"<<endl;
                    cin>>c;

                    for (int i=0; i<c; i++)
                    {
                        //ingreso de informacion a traves de puntero
                        cout<<"ingrese la informacion del cliente #"<<i+1<<endl;
                        cout<<"nombre: ";
                        cin>>(*cliente_factura).nombre;
                        cout<<"apellido: ";
                        cin>>(*cliente_factura).apellido;
                        cout<<"edad: ";
                        cin>>(*cliente_factura).edad;
                        cout<<"ID: ";
                        cin>>(*cliente_factura).ID;
                        cout<<"direccion: ";
                        cin>>(*cliente_factura).direccion;
                        cout<<"telefono: ";
                        cin>>(*cliente_factura).telefono;
                        cout<<"total de productos: ";
                        cin>>(*cliente_factura).productos;
                        cout<<"total a pagar: ";
                        cin>>(*cliente_factura).precio;
                        *cliente_factura++;
                    }
                }

                //en caso de no conocer el numero de clientes se hace un do-while
                else if (op2 == 'n')
                {
                    c=0;
                    datos *cliente_factura1;
                    cliente_factura1 = cliente;
                    do
                    {
                        //ingreso de informacion por puntero hasta que el usuario desee
                        cout<<"ingrese la informacion del cliente #"<<c+1<<endl;
                        cout<<"nombre: ";
                        cin>>(*cliente_factura1).nombre;
                        cout<<"apellido: ";
                        cin>>(*cliente_factura1).apellido;
                        cout<<"edad: ";
                        cin>>(*cliente_factura1).edad;
                        cout<<"ID: ";
                        cin>>(*cliente_factura1).ID;
                        cout<<"direccion: ";
                        cin>>(*cliente_factura1).direccion;
                        cout<<"telefono: ";
                        cin>>(*cliente_factura1).telefono;
                        cout<<"total de productos: ";
                        cin>>(*cliente_factura1).productos;
                        cout<<"total a pagar: ";
                        cin>>(*cliente_factura1).precio;
                        *cliente_factura1++;
                        //contador de clientes
                        c++;

                        cout<<"desea ingresar otro usuario?"<<endl;
                        cin>>d;
                    }
                    while (d=='s');

                    cout<<"total de clientes: "<<c<<endl;

                }

                //en caso de ingresar algo distinto a s o n se dira que la letra ingresada no esta en el rango solicitado
                else
                    cout<<"la letra ingresada no esta en el rango"<<endl;

                //apertura del archivo (si hay algo en este, se guardara la informacion que tiene y se escribira debajo)
                file.open(newS,ios::app);
                if(file.is_open())
                {
                    //for para impresion de facturas
                    for (int v=0; v<c; v++)
                    {
                        //impresion de factura de cada usuario en el archivo
                        file<<"----------usuario #"<<v+1<<"----------"<<endl;
                        file<<"Nombre completo: "<<cliente[v].nombre<<" "<<cliente[v].apellido<<endl;
                        file<<"Edad: "<<cliente[v].edad<<endl;
                        file<<"ID: "<<cliente[v].ID<<endl;
                        file<<"Direccion: "<<cliente[v].direccion<<endl;
                        file<<"Telefono: "<<cliente[v].telefono<<endl;
                        file<<"Total de productos: "<<cliente[v].productos<<endl;
                        file<<"Total a pagar: $"<<cliente[v].precio<<endl;
                        file<<endl;
                    }
                }
                else
                {
                    //si el archivo no se encuentra o no se puede abrir se dira que se produjo un error
                    cerr<<"Error de apertura del archivo";
                }

                //cierre del archivo
                file.close();
                break;
            }
        }
        else
            //si se ingresa un numero distinto a los mostrados en el menu, se pondra que el numero no esta dentro de las opciones
            cout<<"el numero ingresado no entra en el rango de opciones"<<endl;

            //se pregunta si se desea volver al menu principal
        cout<<"desea volver al men� inicial?"<<endl;
        cin>>opmenu;
    }

    while (opmenu=='s');
}
