/*
Taller #2
Autor: Valentina Sandoval Aparicio
Fecha:21/02/2023

Se desea hacer un aplicación que genere un conjunto de números aleatorios entre 0 y
20. En caso que el usuario quiera, se debe presentar un histograma sobre la frecuencia
de los números del conjunto de números aleatorios. La aplicación deberá presentar un
menú, que identifique en dos partes: a) presentar la generación del conjunto de
números aleatorios y b) presentar el histograma del conjunto de números aleatorios.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int maximo = 100; //constante para almacenamiento del arreglo

//struct para los resultados del arreglo creado, tamaño y numero mayor, ademas del puntero
struct resultados
{
    int max_valor;
    int tam_array;
    int *int_array;
};

//funcion para llenar el arreglo con numeros aleatorios
void generarvectoraleatorio(int arreglo[], resultados resultado, int i)
{
    int n;
    n = resultado.tam_array;
    for (i=0; i<n; i++)
        arreglo[i] = rand()%20;

    //impresion del arreglo usando el puntero
    for (i=0; i<n; i++)
    {
        cout<<*resultado.int_array<<"\t";
        *resultado.int_array++;
    }
    cout<<endl;
}
//funcion para buscar el numero mayor del arreglo
void busquedademayor (int arreglo[], resultados resultado)
{
    int s = resultado.tam_array;
    int pos;

    pos = arreglo[0];
    //ciclo para comparar los numeros
    for (int i = 0; i < s; i++)
    {

        if (pos < arreglo[i])
        {
            //si el numero en posicion i es mayor, ese valor sera el nuevo pos
            pos = arreglo[i];
        }

    }

    cout<<"Max: "<<pos<<endl;
    cout<<"Tamaño: "<<resultado.tam_array<<endl;


}

//funcion para conteo de numeros repetidos (histograma)
void cuenta(int arreglo[],resultados resultado, int b, int p)
{
    int x=0;
    int l;

    for (int i=0; i<resultado.tam_array; i++)
    {
        if(b == arreglo[i])
        {
            //x es la cantidad de veces que se repite el numero y l el numero repetido
            x++;
            l=arreglo[i];

        }

    }
    //impresion de la tabla e histograma (indice y valores)
    cout<<p<<"\t"<<l<<"\t";
    //ciclo para imprimir los * del histograma
    for (int d=0; d<x; d++)
        cout<<"*";

    cout<<endl;
}

//funcion para eliminar los numeros repetidos
void eliminar(int arreglo[],resultados resultado,int b)
{
    for (int i=0; i<resultado.tam_array; i++)
    {
        if(b==arreglo[i])
        {
            arreglo[i]=0;
        }

    }
}

main()
{
    //declaracion de variables principales
    int arreglo[maximo];
    resultados resultado;
    int i;
    srand(time(0));
    resultado.int_array = arreglo;
    int op;
    char op2;

    cout<<"\n----------BIENVENIDO----------\n"<<endl;

    do
    {
        cout<<"Ingrese la cantidad de numeros que desea generar"<<endl;
        cin>>resultado.tam_array;
        generarvectoraleatorio(arreglo,resultado,i);
        busquedademayor (arreglo, resultado);


            cout<<"MENU:"<<endl;
            cout<<"para visualizar el conjunto de numeros generados inserte (1)"<<endl;
            cout<<"para visualizar el histograma inserte (2)"<<endl;
            cin>>op;

            //switch case para ver opcioines
            switch (op)
            {
            case 1:
                //se imprime el arreglo con sus indices y valores
                cout<<"Arreglo creado"<<endl;
                cout<<"indice"<<"\t"<<"valor"<<endl;
                for (i=0; i<resultado.tam_array; i++)
                {
                    cout<<i<<"\t"<<arreglo[i]<<"\n";
                }
                cout<<endl;
                break;

            case 2:
                //titulo de las columnas de la tabla
                cout<<"indice  "<<"valor  "<<"Histograma"<<endl;

                int b;
                int p=0;
                for (int i=0; i<resultado.tam_array; i++)
                {
                    b=arreglo[i];
                    if(b!=0)
                    {
                        //llamado a funcion para contar numeros repetidos e imprimir
                        cuenta(arreglo,resultado,b,p);
                        //aumento del indice
                        p++;
                        //eliminar numeros repetidos
                        eliminar(arreglo,resultado,b);
                    }
                }

                break;

            }
        //do-while para volver al menu
        cout<<"desea volver al inicio?"<<endl;
        cin>>op2;
    }
    while(op2 == 's');

    cout<<"Hasta luego!"<<endl;
}


