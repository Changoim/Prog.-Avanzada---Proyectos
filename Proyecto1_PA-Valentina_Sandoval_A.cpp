/*
Autor: Valentina Sandoval Aparicio
Fecha: 10/03/2023
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
#include <string.h>

using namespace std;
int const MAX = 50;


//creacion de estructura
struct empleado
{
    int codigo;
    string nombres;
    string apellidos;
    long int celular;
};
vector <empleado*> v_despedidos;
empleado* punteroempleado = new empleado();

//funcion para registrar empleados (sobre escribe si existen registros)
int registro(empleado empleados[], int totalclientes)
{
    empleados[totalclientes];

    //se pide ingresar el total de clientes
    cout<<"Ingrese la cantidad de clientes que va a registrar"<<endl;
    cin>>totalclientes;

    cout<<"Ahora ingrese la informacion de cada cliente"<<endl;

    //para lectura y escritura de archivo
    ofstream f;
    ifstream in;
    char resp;

    //for para llenar el arreglo de tipo empleado
    for(int i=0; i<totalclientes; i++)
    {
        cout<<"\n-----empleado #"<<i+1<<"-----\n"<<endl;
        cout<<"Código: ";
        cin>>empleados[i].codigo;
        cout<<"Nombre: ";
        cin>>empleados[i].nombres;
        cout<<"apellidos: ";
        cin>>empleados[i].apellidos;
        cout<<"celular: ";
        cin>>empleados[i].celular;
    }

    //se abre el archivo binario para añadir datos
    f.open("empleados.bin", ios::binary);
    if (!f.is_open())
    {
        //en caso de no abrirse el archivo, se imprime:
        cout << "Error al crear el fichero empleados.bin" << endl;
    }

    //se escribe en el archivo binario y se cierra
    f.write(reinterpret_cast<char*>(&empleados),sizeof(empleado));
    f.close();

    cout<<"empleado(s) registrado!"<<endl;

    //se le pregunta al usuario si desea ver los usuarios que ingreso
    cout<<"Mostrar empleados(s/n)? ";
    cin>>resp;

    if (resp == 's')
    {
        {
            //se imprimen a traves de un for
            for(int j=0; j<totalclientes; j++)
            {
                cout<<"\n-----empleado #"<<j+1<<"-----\n"<<endl;
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
    //retorna el total de clientes
    return totalclientes;
}

//funcion para agregar empleados (escribe debajo de lo que haya)
int agregar(empleado empleados[], int totalclientes)
{
    int clientesagregar;
    //se pide ingresar el numero de clientes a aagregar
    cout<<"Ingrese la cantidad de clientes que va a agregar"<<endl;
    cin>>clientesagregar;
    //variable auxiliar para almacenar el total de clientes
    int aux=totalclientes;
    // a totalclientes se le asigna lo que tenia mas los clientes a agregar
    totalclientes = totalclientes + clientesagregar;
    string nombreagregar;
    int codigoagregar;
    string apellidos;
    long int celular;
    bool encontrado = false;
    int contador=0;

    cout<<"Ahora ingrese la informacion de cada cliente"<<endl;

    for(int i=aux; i<totalclientes; i++)
    {
        //se ingresa la informacion del empleado
        cout<<"\n-----empleado-----\n"<<endl;
        cout<<"Código: ";
        cin>>codigoagregar;
        cout<<"Nombre: ";
        cin>>nombreagregar;
        cout<<"apellidos: ";
        cin>>apellidos;
        cout<<"celular: ";
        cin>>celular;
        for (int p=0; p<aux; p++)
        {
            //se compara con un booleano
            if(empleados[p].codigo==codigoagregar)
            {
                encontrado = true;
                cout<<"empleado registrado anteriormente"<<endl;
                totalclientes--;

            }
        }
        // si son diferentes a los datos que hay (true) se registran los datos nuevos
        if (encontrado == false)
        {
            empleados[i].codigo = codigoagregar;
            empleados[i].nombres = nombreagregar;
            empleados[i].apellidos=apellidos;
            empleados[i].celular=celular;
        }
    }
    ofstream f;
    ifstream in;
    char resp;
    int conta = 0;

    //se abre el archivo binario para añadir datos al final
    f.open("empleados.bin", ios::app|ios::binary);
    if (f.fail())
    {
        cout << "Error al crear el fichero empleados.bin" << endl;
    }

    //se escribe en el archivo
    f.write(reinterpret_cast<char*>(&empleados),sizeof(empleado));
    f.close(); //se cierra el archivo

    cout << "Mostrar empleados(s/n)? ";
    cin>>resp;

    if (resp == 's')
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
    return totalclientes;
}

//funcion para imprimr los datos alfabeticamente (orden de los nombres)
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

    //impresion
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

//funcion para cambiar el celular de un empleado
void cambiarnumero(empleado empleados[], int totalclientes)
{
    long int nuevoTelefono;
    int codigo;
    bool encontrado = false;
    fstream archivo;
    int i=0;

    // Pedir el código del empleado a modificar

    cout<<"Ingrese el código del empleado a modificar: ";
    cin>>codigo;
    for(i=0; i<totalclientes; i++)
    {
        // Abrir archivo binario para lectura y escritura
        fstream archivo("empleados.bin", ios::in | ios::out | ios::binary);

        if (!archivo)
        {
            cerr << "Error al abrir el archivo." << endl;
        }

        // Buscar el empleado en el archivo

        while (!encontrado && archivo.read((char*)&empleados, sizeof(empleado)))
        {
            if (empleados[i].codigo == codigo)
            {
                encontrado = true;
            }
        }
    }
    // Si se encontró al empleado, pedir el nuevo número de teléfono y modificarlo en el archivo
    if (encontrado==true)
    {
        cout<<"Ingrese el nuevo número de teléfono: ";
        cin>>nuevoTelefono;
        // Regresar al inicio del registro encontrado
        archivo.seekp(-sizeof(empleado), ios::cur);

        //escribir en el archivo binario
        archivo.write((char*)&empleados, sizeof(empleado));
        //se le asigna el nuevo valor de celular en el arreglo de tipo empleado
        empleados[i].celular = nuevoTelefono;
    }
    archivo.read((char*)&empleados, sizeof(empleado));

    if (encontrado==false)
    {
        printf("No existe el empleado con dicho codigo\n");
        archivo.close();
    }

    cout<<endl;
    cout << "---El teléfono del empleado ha sido modificado correctamente---" << endl;
}

//funcion para despedir empleados (envia la carta de despido)
void despedirempleado(empleado empleados[], int totalclientes)
{
    ofstream file;
    fstream bin;
    fstream f_despedidos;
    empleado empty = {0,"","",0};
    string titulo = "Carta_Despido_";
    string extension = ".txt";
    int codigo;
    int dia, mes, anio;
    bool encontrado = false;
    string persona;
    int aux;
    cout<<"ingrese el codigo del empleado al que va a despedir"<<endl;
    cin>>codigo;
    for (int p=0; p<totalclientes;p++)
    {
        if(empleados[p].codigo==codigo)
        {
            aux=empleados[p].codigo;
            persona=empleados[p].nombres;
        }
    }
    bin.open("empleados.bin",ios::binary | ios::in | ios::out);
    f_despedidos.open("empleados_despedidos", ios :: in | ios :: binary | ios::app);

    if (bin.is_open())
    {
        while (bin.read(reinterpret_cast<char*>(&punteroempleado), sizeof(empleado)))
        {
            //busqueda del codigo ingresado
            if (aux == codigo)
            {
                //se pide la fecha de creacion de la carta
                cout<<"introduzca la fecha de generacion de la carta de despido"<<endl;
                cout<<"dia: ";
                cin>>dia;
                cout<<"mes: ";
                cin>>mes;
                cout<<"año: ";
                cin>>anio;
                //nombre del archivo
                string newS = titulo + persona + extension;
                f_despedidos.write((char *)&punteroempleado, sizeof(empleado));
                v_despedidos.push_back(punteroempleado);

                //se abre y escribe la carta en el archivo
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

                    bin.seekp(-sizeof(empleado), ios::cur);
                    bin.write(reinterpret_cast<char*>(&empty),sizeof(empleado));
                }
            }
        }
    }
    cout<<"Carta de despido creada"<<endl;
    bin.close();
    file.close();
    f_despedidos.close();

}

//impresion de empleadios despedidos
void verdespedidos(empleado empleados[])
{
    fstream f_despedidos2;
    empleado empl_aux;
    vector <empleado*> vec;
    f_despedidos2.open("empleados_despedidos", ios :: in | ios :: binary | ios::out);

    if (f_despedidos2.is_open())
    {
        while(f_despedidos2.read(reinterpret_cast<char*>(&punteroempleado), sizeof(empleado)))
        {
            vec.push_back(punteroempleado);
        }
    }

    for (int i = 0 ; i < vec.size() ; i++)
    {
        cout<<"-----Empleado #"<<i+1<<"-----"<<endl;
        cout<<"Código: "<<vec[i]->codigo<< endl;
        cout<<"Nombre: "<<vec[i]->nombres <<endl;
        cout<<"Apellidos: "<<vec[i]->apellidos << endl;
        cout<<"Celular: "<<vec[i]->celular << endl;
        cout<<endl;
    }

    f_despedidos2.close();
}

main()
{
    //declaracion de variables
    int opmenu;
    char op;
    empleado empleados[MAX];
    int totalclientes;
    string empleadosfuera[MAX];
    int j=0;
    string aux;
    //vector <empleado> v_despedidos;

    cout<<"\n----------BIENVENIDO A MINOSAURIOS TECH----------\n"<<endl;
    //do while para poder volver al menu
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
            totalclientes = registro(empleados, totalclientes);

            break;

        case 2:
            //agregar empleados
            totalclientes = agregar(empleados, totalclientes);

            break;

        case 3:
            //imprimir empleados registrados (todos sus datos)
            registrados(empleados, totalclientes);

            break;

        case 4:
            //cambiar el numero de un empleado buscandolo a traves de su codigo
            cambiarnumero(empleados, totalclientes);

            break;

        case 5:
            // despedir empleado (carta de despido)

            despedirempleado(empleados,totalclientes);
            break;

        case 6:
            //imprimir empleadios despedidios
            verdespedidos();

            break;
        }
        cout<<"desea volver al menu?s/n"<<endl;
        cin>>op;
    }
    while (op=='s');
    cout<<"vuelva pronto!!!"<<endl;
    delete[] punteroempleado;
}
