/*
---------------------------------------------------------------------------------------

 Fecha: 01/02/2023
 Autor: Valentina Sandoval Aparicio
 Problema: Un gimnasio se propone a automatizar el proceso de registro. Se necesita
 solicitar el numero de usuarios a registrar inicialmente. Se debe solicitar la mayor
 cantidad de datos posibles, para ser usados posteriormente. De ser necesario, se
 recomienda preguntar datos adicionales sobre sus hijos (nombre, edad, entre otros,
 adicional). Se necesita que al final de la ejecución, se presente el nombre de los 10
 usuarios registrados satisfactoriamente.
  Tipo de datos
 solucion:
 - se hara un TDA general para la captura de datos del usuario.
 - se hara un TDA anidado, para la captura de datos de los hijos
 - se presentara todos los anuncios posibles descriptivos

-----------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

//se crea un TDA para los datos de los usuarios
struct cliente
{
    string nombre;
    int edad;
    long long int ID;
    double MasaCorporal;
    char genero;
    string correo;
    long long int movil;
    int cHijos;
    string direccion;
};

//TDA anidado para captura de datos del hijo
struct hijo_cliente
{
    string nombre;
    int edad;
    long long int ID;
};


main ()
{
    int personas;
    int p;
    cout<<"//////////Bienvenido! como se encuentra el dia de hoy?//////////"<<endl;
    cout<<"ingrese el numero de usuarios a registrar"<<endl;
    //declaracion de variables y solicitud de cantidad de personas a registrar
    cin>>personas;
    //arreglo para guardar la informacion del numero de personas solicitada
    cliente clientes[personas];

    //for para empezar a guardar la informacion
    for (int i=0; i<personas; i++)
    {
        cout<<i<<"-> Ingrese su nombre"<<endl;
        cin>>clientes[i].nombre;
        cout<<i<<"-> Ingrese su edad"<<endl;
        cin>>clientes[i].edad;
        cout<<i<<"-> Ingrese su identificacion"<<endl;
        cin>>clientes[i].ID;
        cout<<i<<"-> Ingrese su masa corporal"<<endl;
        cin>>clientes[i].MasaCorporal;
        cout<<i<<"-> Ingrese su genero (f/m)"<<endl;
        cin>>clientes[i].genero;
        cout<<i<<"-> Ingrese su correo"<<endl;
        cin>>clientes[i].correo;
        cout<<i<<"-> Ingrese su movil"<<endl;
        cin>>clientes[i].movil;
        cout<<i<<"-> Ingrese cantidad de hijos"<<endl;
        cin>>clientes[i].cHijos;
        p=clientes[i].cHijos;
        hijo_cliente hijo[p];
        if (clientes[i].cHijos!=0)

        {
            int n=1;
            for (int k=0; k<p; k++)
                {
                    cout<<"ingrese el nombre del hijo "<<n<<endl;
                    cin>>hijo[k].nombre;
                    cout<<"ingrese la edad del hijo "<<n<<endl;
                    cin>>hijo[k].edad;
                    cout<<"ingrese el ID de hijo "<<n<<endl;
                    cin>>hijo[k].ID;
                    n++;
                }
        }
        cout<<"Ingrese su direccion"<<endl;
        cin>>clientes[i].direccion;

        //imprime la informacion ingresada anteriormente
        cout<<" la informacion ingresada fue: "<<endl;
        cout<<"nombre: "<<clientes[i].nombre<<endl;
        cout<<"edad: "<<clientes[i].edad<<endl;
        cout<<"identificacion: "<<clientes[i].ID<<endl;
        cout<<"Masa corporal: "<<clientes[i].MasaCorporal<<"kg"<<endl;

        // imprime femenino o masculino dependiendo de la letra ingresada en genero f/m
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
        cout<<"Cantidad de hijos: "<<clientes[i].cHijos<<endl;
    }

    cout<<"usuarios registrados satisfactoriamente"<<endl;
    cout<<"los nombres de los usuarios registrados"<<endl;
    //imprime el nombre de los usuarios con un for
    for (int j=0; j<personas; j++)
    {
        cout<<clientes[j].nombre<<endl;
    }

    return 0;
}
